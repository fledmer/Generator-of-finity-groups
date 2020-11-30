#include "group.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define END;
void GroupGenerator::GroupPrint()
{
    cout << "   ";
    for(int x = 0;x < size;x++)
    {
        cout << "X" << x <<" ";
    }
    cout << endl;
    for(int y = 0; y < size;y++)
    {
        cout<<"X" << y << " ";
        for(int x = 0; x < size;x++)
        {
            cout << Matrix[y][x] << "  ";

        }
        cout << endl << endl;

    }
}

void GroupGenerator::FindType()
{
    for(int y = 0;y < size;y++)
    {
        for(int x = 0; x < size;x++)
        {
            for(int z = 0; z < size;z++)
            {
                if(Matrix[Matrix[y][x]][z] != Matrix[y][Matrix[x][z]])
                {
                    return;
                }


            }
        }
    }
    groupCount++;
    if(print) GroupPrint();
}

void GroupGenerator::Generate_all_group(int x,int y,int neutral)
{
    if(x == neutral)
    {
        Generator(x+1,y,neutral);
        return;
    }
    if(y == neutral)
    {
        if(y == size-1)
        {
            FindType(); //Сгенерирован последний эллемент матрицы, начинаем проверку на группу.
            return;
        }
        Generator(0,y+1,neutral);
        return;
    }
    if(x == size)
    {
        if(y == size-1)
        {
            FindType(); //Сгенерирован последний эллемент матрицы, начинаем проверку на группу.
            return;
        }
        Generator(0,y+1,neutral);
        return;
    }
    for(int x1 = 0; x1 < size; x1++) //Перебор
    {
        if(x1 == x || x1 == y)
            goto end;

        for(int x2 = x; x2 > 0;x2--) //Проверка на повторения
        {
            if(Matrix[y][x2-1] == x1)
            {
                goto end;
            }
        }
        for(int y1 = y; y1 > 0;y1--) //Проверка на повторения
        {
            if(Matrix[y1-1][x] == x1)
            {
                goto end;
            }
        }

        Matrix[y][x] = x1;
        Generator(x+1,y,neutral);

        end: END;
    }

}

GroupGenerator::GroupGenerator(int size,bool print)
{
    this->size = size;
    this->print = print;
    for(int i = 0; i < size;i++)
    {
        vector<int> vector(size);
        Matrix.push_back(vector);
    }
    for(int y =0; y < size;y++)
    {
        for(int x = 0; x < size;x++)
        {
            Matrix[y][x] = x;
            Matrix[x][y] = x;
        }
        Generator(0,0,y);
    }
}
