#ifndef NOD_H
#define NOD_H


class Nod
{  int info;
   Nod* stanga;
   Nod* dreapta;
    public:
        Nod();
        Nod(int, Nod*,Nod*);
        Nod* getNext();
        int getInfo();
 friend  class Lista;
};

#endif // NOD_H
