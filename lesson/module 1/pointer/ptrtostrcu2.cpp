#include <iostream>
using namespace std;
struct record
{ int id;
 string name;
};
int main()
{ struct record data, *p;
 data.id=100;
 data.name="Somchai";
 p=&data;
 cout << p->id <<
 " " << p->name << endl;
}