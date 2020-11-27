#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include "Group/group.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

//Итерация присуща человеку, а рекурсия - богу.
//- Л. Дойч

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Input size and printout: 5 1" << Qt::endl;
    QString ans; cin >> ans;
    int size = ans.toInt(); cin >> ans;
    int print = ans.toInt();
    GroupGenerator groupGenerator(size,print);
    cout <<"Group cout: " << groupGenerator.groupCount << Qt::endl;
    return a.exec();
}
