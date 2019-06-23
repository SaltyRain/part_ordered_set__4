//
//  main.cpp
//  part_ordered_set__4
//
//  Created by Тимур Гарипов on 23/06/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "partOrderedSet.hpp"

#define FILENAME "data.txt"

using namespace std;

void readFromFile (const char *filename, set &setName)
{
    ifstream f;
    f.open(filename); //открываем файл
    if (!f.is_open()) //если не получилось открыть файл
    {
        cout << "Файл не открыт" << endl;
        f.close();
        return;
    }
    int a;
    int b;
    while(!f.eof())
    {
        f >> a;
        f >> b;
        setName.insert(a, b);
    }
    f.close();
    
}
int main(int argc, const char * argv[]) {
    set mySet;
    readFromFile(FILENAME, mySet);
    mySet.print();
}
