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
#include <fstream>

struct node; //список множества (все имеющиеся элементы)
struct sub_node;

// базовая структура
struct sub_node {
    node *next_el; //указывает на следующий элемент в текущем списке
    sub_node *linked_node;  //список множеств -> указывает на список последователей
                            //список последователей -> указывает на элемент списка множества
    sub_node()
    {
        next_el = nullptr;
        linked_node = nullptr;
    }
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
    node *addFollower(node *follower, sub_node *followers_head); //добавить последователя
    node *existEl(node *head, int d); //проверить, существует ли элемент d в списке head. Если существует ->позвращает этот элемент, иначе возвр. nullptr
    
};

#endif /* partOrderedSet_hpp */
