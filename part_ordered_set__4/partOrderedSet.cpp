//
//  partOrderedSet.cpp
//  part_ordered_set__4
//
//  Created by Тимур Гарипов on 23/06/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include "partOrderedSet.hpp"

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
        _head->linked_node = addFollower(_head->next_el, _head->linked_node); //добавляет элемент next_el в linked_node
        _head->next_el->precursor_counter++; //у следующего элемента увеличивается число предшественников
    }
    
    node *temp_a = existEl(_head, a);
    node *temp_b = existEl(_head, b);
    node *input_place = _head->next_el; //все добавляем после головы //место вставки не важно
    if (temp_a == nullptr) //если не нашли
    {
        // добавляем новый элемент в список мн-ва
        temp_a = addToEnd(input_place, a);
        input_place = input_place->next_el;
    }
    if (temp_b == nullptr)
    {
        temp_b = addToEnd(input_place, b);
        input_place = input_place->next_el;
    }
    //добавляем отношение
    temp_a->linked_node = addFollower(temp_b, temp_a->linked_node);
    temp_b->precursor_counter++;
    
}

bool set:: sort()
{
    return false;
}

void set:: print() const
{
    
}



