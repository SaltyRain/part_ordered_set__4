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

using namespace std;

//struct node
//{
//    // для списка множества - указатель на следующий эл-т в множестве
//    // для списка последователей - указатель на элемент из списка множества
//    node *el;
//    // для списка множества - указатель на список последователей
//    // для списка последователей - указатель на следующий элемент списка последователей
//    node *next;
//    node ()
//    {
//        el = nullptr;
//        next = nullptr;
//    }
//)
//}

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
    unsigned int counter; //колличество предшественников
    node ()
    {
        data = 0;
        counter = 0;
    }
    node (int d): data(d)
    {
        counter = 0;
    }
};

class set
{
public:
    set();
    ~set();
    void print() const;
    bool sort();
private:
    node *_head;
    
};

#endif /* partOrderedSet_hpp */
