#include<iostream>
#include "Nod.h"
#include "Lista.h"
#include <cassert>
using namespace std;

int main(){

Lista l(4);
l.insertAtStart(5);
l.insertAtEnd(3);
l.insertAtStart(9);
assert(l[0]==9);
l.insertAt(10,0);
l.deleteAt(1);
l.print();
l.Marime();
l.Suma();
l.Minim();
l.Maxim();
l.reverse();
Lista s(12);
s.insertAtStart(17);
l=l+s;
l.print();
l*2;
cout<<endl;
l.print();
l.insertAtEnd(10);
l.Cautare(10);
cout<<(l>s);
cout<<(l<s);
assert(l>s);
//assert(l<s);
assert(l[2]==10);
//assert(l[3]==2);
return 0;

}
