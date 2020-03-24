#ifndef LISTA_H
#define LISTA_H

#include "Nod.h"
#include<iostream>
class Lista
{ Nod *start, *sfarsit;
	int marime;

    public:
        Lista();
        Lista(int);
        Lista(Lista&);
        void insertAtEnd(int);
        void insertAtStart(int);
        void insertAt(int,int);
        void print();
        void deleteAt(int);
        void deleteRight();
        void deleteLeft();
        void Suma();
        void Minim();
        void Maxim();
        void reverse();
        void Marime();
        void Cautare(int x);
        ~Lista();
        int operator[](int);
        Lista operator+(const Lista &);
        bool operator <(const Lista &);
        bool operator >(const Lista &);
        void operator*(int);
        friend std::istream& operator>>(std::istream&, Lista&);
        friend std::ostream& operator<<(std::ostream&, const Lista&);
        void operator=(const Lista&);

        };
#endif // LISTA_H
