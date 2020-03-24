#include "Nod.h"
#include<iostream>
Nod::Nod()
{
	info = 0;
	dreapta = NULL;
	stanga=NULL;
}

Nod::Nod(int i, Nod* n, Nod*x) {
	info = i;
	stanga = n;
	dreapta =x;
}
Nod *Nod::getNext(){
   return dreapta;

}
int Nod::getInfo(){
return info;
}




