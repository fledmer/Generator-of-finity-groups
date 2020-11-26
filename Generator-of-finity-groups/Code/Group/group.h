#ifndef GROUP_H
#include <string>
#include <vector>
#define GROUP_H


class GroupGenerator
{
    void FindType();
    void GroupPrint();
    void Generator(int x,int y,int neutral);
    bool print;
public:
    int size;
    int groupCount;
    GroupGenerator(int size,bool print);
    std::vector<std::vector<int>> Matrix;
};

#endif // GROUP_H
