//
//  partOrderedSet.cpp
//  part_ordered_set__4
//
//  Created by Тимур Гарипов on 23/06/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include "partOrderedSet.hpp"
#include <iostream>

using namespace std;

set:: set()
{
    
}

set:: ~set()
{
    
}

void set:: insert(int a, int b)
{
    if (_head == nullptr) //если список пустой
    {
        //добавляем элементы в список мн-ва
        _head = new node(a);
        addToEnd(_head, b);
        //создаем список последователей
        _head->followers_node = addFollower(_head->next_el, _head->followers_node); //добавляет элемент next_el в followers_node
        _head->next_el->precursor_counter++; //у следующего элемента увеличивается число предшественников
        return;
    }
    
    node *temp_a = existEl(_head, a);
    node *temp_b = existEl(_head, b);
    node *input_place = searchLast(_head);
    if (temp_a == nullptr) //если не нашли
    {
        // добавляем новый элемент в список мн-ва
        temp_a = addToEnd(input_place, a);
        input_place = input_place->next_el;
    }
    if (temp_b == nullptr)
    {
        temp_b = addToEnd(input_place, b);
    }
    //добавляем отношение
    temp_a->followers_node = addFollower(temp_b, temp_a->followers_node);
    temp_b->precursor_counter++;
    
}

bool set:: sort()
{
    node *temp = _head; //исходная голова
    node *new_head = nullptr; //новая голова
    
    node *prev = nullptr;
    node *set_el = nullptr; //элемент списка множества
    
    sub_node *follower; //элемент списка последователей
    
    while (temp != nullptr) //пока есть узлы в графе
    {
        if (temp->precursor_counter == 0)
        {
            //если пустой - добавляем первый, иначе добавляем после
            new_head == nullptr ? (new_head = temp) : (set_el->next_el = temp);
            
            if (temp->followers_node != nullptr) //если есть последователи
            {
                follower = temp->followers_node;
                while (follower != nullptr) //пока не закончились последователи
                {
                    follower->next_el->precursor_counter--; //уменьшаем число предшественников
                    follower = follower->followers_node; //переходим к следующему
                }
                temp->followers_node = delFollowersList(temp->followers_node); //удаляем список последователей
            }
            //удаляем свяли из списка множества
            temp == _head ? (_head = _head->next_el) : (prev->next_el = temp->next_el);
            
            temp->next_el = nullptr;
            set_el = temp;
            temp = _head;
            prev = nullptr;
            continue;
        }
        prev = temp;
        temp = temp->next_el;
    }
    if (_head != nullptr)
    {
        //чистим оба множества
        _head = delSet(_head);
        new_head = delSet(new_head);
        return false; //сортировка не удалась
    }
    _head = new_head;
    return true;
  
}

void set:: print() const
{
    if (_head == nullptr)
        return;
    node *temp = _head;
    while (temp != nullptr)
    {
        cout << "Значение: " << temp->data << ", число предшественников: " << temp->precursor_counter << endl;
        if (temp->followers_node != nullptr)
        {
            cout << "Последователи: ";
            sub_node* temp2 = temp->followers_node;
            while (temp2 != nullptr)
            {
                cout << temp2->next_el->data << " ";
                temp2 = temp2->followers_node;
            }
        }
        temp = temp->next_el;
        cout << endl << endl;
    }
}


node* set:: addToEnd(node *tail, int value)
{
    tail->next_el = new node(value);
    return tail->next_el;
}

sub_node* set:: addFollower(node *el, sub_node *followers_head)
{
    if (followers_head == nullptr)
    {
        followers_head = new sub_node(el, nullptr);
        return followers_head;
    }
    sub_node *newEl = new sub_node(el, followers_head->followers_node);
    followers_head->followers_node = newEl;
    return followers_head;
}

node* set:: existEl(node *head, int d)
//проверить, существует ли элемент d в списке head. Если существует -> возвращает этот элемент, иначе возвр. nullptr
{
    if (head->data == d)
    {
        return head;
    }
    node *temp = head->next_el;
    while (temp != nullptr)
    {
        if (temp->data == d)
            return temp;
        
        temp = temp->next_el;
    }
    return nullptr; //элемент не найден
}

node* set:: searchLast(node *head)
{
    node *temp = head;
    while (temp->next_el != nullptr)
        temp = temp->next_el;
    return temp;
}

sub_node* set:: delFollowersList(sub_node *head)
{
    sub_node *temp1;
    sub_node *temp2 = head;
    while (temp2 != nullptr)
    {
        temp1 = temp2;
        temp2 = temp2->followers_node;
        delete temp1;
    }
    head = nullptr;
    return head;
}

node* set:: delSet(node *head)
{
    node *temp1;
    node *temp2 = head;
    while (temp2 != nullptr)
    {
        temp1 = temp2;
        temp2 = temp2->next_el;
        if (temp1->followers_node != nullptr) //есть последователи
            temp1->followers_node = delFollowersList(temp1->followers_node);
        delete temp1;
    }
    head = nullptr;
    return head;
}
