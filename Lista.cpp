#include "Lista.h"
#include<iostream>
using namespace std;

Lista::Lista() {
	start = sfarsit = NULL;
	marime = 0;
}

Lista::Lista(int x)
{
	start = sfarsit = new Nod(x, NULL,NULL);
	marime = 1;
}

Lista::Lista(Lista& l)
{
	start = sfarsit = NULL;
	marime = 0;
	Nod* p =l.start;
	int i=l.marime;
	while (i!=0) {
	    insertAtEnd(p->info);
        p=p->dreapta;
        i--;
	}


}


void Lista::insertAtEnd(int x) {
	insertAt(x, marime );
}

void Lista::insertAtStart(int x) {
	insertAt(x, 0);
}

void Lista::insertAt(int x, int i) {
	if (start == NULL) {
		start = sfarsit = new Nod(x, NULL, NULL);
		marime = 1;
		return;
	}
	Nod* p = new Nod(x, NULL, NULL);

	if (i ==0) {

	   start->stanga=p;
	   p->dreapta=start;
	   start=p;
	   start->stanga=sfarsit;
	   sfarsit->dreapta=start;
	   marime++;
	   return;
	 }

	if (i >= marime||i<0) {

	    sfarsit->dreapta=p;
	    p->stanga=sfarsit;
		sfarsit = p;
		p->dreapta=start;
		start->stanga=sfarsit;
	   marime++;
		return;
	 }

	Nod* o = start;
	Nod* ptr=new Nod;
	for (int j = i; j >= 1; j--) {
        ptr = o;
		o = o->dreapta;
	}
	ptr->dreapta=p;
	p->stanga=ptr;
	p->dreapta= o;
	o->stanga=p;
	marime++;
}
void Lista::deleteAt(int i) {
    Nod *s=new Nod, *ptr=new Nod;

if(i<0||i>=marime-1){
    s=sfarsit;
    ptr=sfarsit->stanga;
    ptr->dreapta=start;
    start->stanga=ptr;
    sfarsit=ptr;
    delete s;
    marime--;
    return;

}

s=start;
for(int j=0;j<i;j++){
    s=s->dreapta;
}
  ptr=s->stanga;
  ptr->dreapta=s->dreapta;
  s->dreapta->stanga=ptr;
  marime--;
  if(i==0)
    start=ptr->dreapta;
  delete s;
}
void Lista::deleteRight(){
deleteAt(marime);
}

void Lista::deleteLeft(){
deleteAt(0);
}

void Lista::print() {
    Nod *p = start;
	for(int i=1;i<=marime;i++){
		cout << p->info << " ";
		p = p->dreapta;
        cout <<" ";}

}

void Lista::Marime(){
    cout<<endl<< marime;
}

void Lista::Suma(){
Nod *s=start;
int S=0;
for(int j=0;j<marime;j++){
     S+=s->info;
    s=s->dreapta;
}
cout<<endl<<S;
}

void Lista::Cautare(int x){
Nod *s=start;
int pos=0;
bool flag = false;
for(int j=0;j<marime;j++){

      if (s->info == x) {
         cout<<endl<<"Element "<<x<<" found at position: "<<pos;
         flag = true;
      }
      s = s->dreapta;
      pos++;
   }
   if (!flag)
      cout<<"Element not found in the list"<<endl;


}


void Lista::Minim(){

Nod *s=start;
int m=s->info;
for(int j=1;j<marime;j++){
    s=s->dreapta;
    if(s->info<m)
        m=s->info;

}
cout<<endl<<m;
}

void Lista::Maxim(){

Nod *s=start;
int m=s->info;
for(int j=1;j<marime;j++){
    s=s->dreapta;
    if(s->info>m)
        m=s->info;

}
cout<<endl<<m;
}

void Lista::reverse(){

  if (start == sfarsit && start == NULL) {
    cout<<"The List is empty, nothing to reverse"<<endl;
    return;
   }
    Nod *p1=new Nod;
    Nod *p2=new Nod;
    p1=start;
    p2=p1->dreapta;
    p1->dreapta=NULL;

    while (p2!=start){
        p2->stanga=p2->dreapta;
        p2->dreapta=p1;
        p1=p2;
        p2=p2->stanga;

    }
    sfarsit=start;
    start=p1;
   cout<<endl<<"List Reversed"<<" ";
   print();

}

Lista Lista::operator+(const Lista &o){

Lista l(*this);
Nod *p=o.start;
int i=o.marime;
while(i!=0){
    l.insertAtEnd(p->info);
    p=p->dreapta;
    i--;
}
cout<<endl;
return l;

}

bool Lista::operator<(const Lista &o){
cout<<endl;

Lista l(*this);
Nod *s=l.start;
int S=0;
for(int j=0;j<l.marime;j++){
     S+=s->info;
    s=s->dreapta;
}

s=o.start;
int S2=0;
for(int j=0;j<o.marime;j++){
     S2+=s->info;
    s=s->dreapta;
}

  return S<S2;

}


bool Lista::operator>(const Lista &o){
cout<<endl;

Lista l(*this);
Nod *s=l.start;
int S=0;
for(int j=0;j<l.marime;j++){
     S+=s->info;
    s=s->dreapta;
}

s=o.start;
int S2=0;
for(int j=0;j<o.marime;j++){
     S2+=s->info;
    s=s->dreapta;
}

  return S>S2;

}




void Lista::operator*(int i){

Nod *p=start;
int j=marime;
while(j!=0){
 p->info=p->info*i;
 p=p->dreapta;
 j--;
}

}

int Lista::operator[](int i){
if (i<0||i>=marime)
    return -1;
    Nod *p=start;
    for(int j=i;j>0;j--) {
        p=p->dreapta;
    }
   return p->info;
}

std::istream& operator>>(std::istream& in, Lista& v){
  v=Lista();
  int size;
  in>>size;
  int x;
  for(int i=1;i<=size;i++){
    in>>x;
    v.insertAtEnd(x);

  }
return in;
}

std::ostream& operator<<(std::ostream& out, const Lista& v) {
  Nod *q=v.start;
  int i=v.marime;
  while(i!=0){
      out<<q->getInfo()<< " ";
      q=q->getNext();
      i--;
  }

return out;
}

void Lista::operator=(const Lista& o){

  start = sfarsit = NULL;
	marime = 0;
	Nod* p =o.start;
	int i=o.marime;
	while (i!=0) {
	    insertAtEnd(p->info);
        p=p->dreapta;
        i--;
	}


}


Lista::~Lista(){
  Nod *p=start, *o;
  int i=marime;
  while(i!=0){
    o=p;
    p=p->dreapta;
    delete o;
    i--;
  }

  start=sfarsit=NULL;
  marime=0;

}



