//
//  partOrderedSet.hpp
//  part_ordered_set__4
//
//  Created by Тимур Гарипов on 23/06/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#ifndef partOrderedSet_hpp
#define partOrderedSet_hpp

#include <stdio.h>
#include <cstring>

struct node; //список множества (все имеющиеся элементы)
struct sub_node;

// базовая структура
struct sub_node {
    node *next_el; //указывает на следующий элемент списка множества
    // для списка предшественников указывает на последователя
    sub_node *followers_node;  //список множеств -> указывает на список последователей
                            //список предшественников -> указывает на следующий в списке последователей
    sub_node()
    {
        next_el = nullptr;
        followers_node = nullptr;
    }
    sub_node(node *elem, sub_node *sub): next_el(elem), followers_node(sub) {};
};

// наследуемая структура
struct node: sub_node  //описывает список множества
{
    int data; //значение
    unsigned int precursor_counter; //колличество предшественников
    node ()
    {
        data = 0;
        precursor_counter = 0;
    }
    node (int d): data(d)
    {
        precursor_counter = 0;
    }
};

class set
{
public:
    set();
    ~set();
    void print() const;
    bool sort();
    void insert(int a, int b); //вставить пару
private:
    node *_head;
    
    node* addToEnd(node *tail, int value); //добавить элемент в конец списка
    sub_node* addFollower(node *follower, sub_node *followers_head); //добавить последователя
    node* existEl(node *head, int d); //проверить, существует ли элемент d в списке head. Если существует -> возвращает этот элемент, иначе возвр. nullptr
    node* searchLast(node *head); 
    
};

#endif /* partOrderedSet_hpp */
