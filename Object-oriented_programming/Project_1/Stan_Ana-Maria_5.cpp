#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Nod
{
    char info;
    Nod* next;
public:
    Nod();//constructor fara parametrii
    Nod(char caracter); //constructor cu parametru
    Nod(Nod&); // constructor cu copiere
    char get_info();
    Nod* get_next();
    void set_next(Nod* z);
    void set_info(char);
    friend class Coada_de_caractere;
    ~Nod(); // destructor


};
Nod::Nod()
{

    this->info = '0';
    this->next = NULL;

}

Nod::Nod(char caracter)
{
    this->info = caracter;
    this->next = NULL;
}

Nod::~Nod()
{
    delete next;
}
Nod::Nod(Nod &z)
{
    this->info=z.info;
    this->next=z.next;
}

char Nod::get_info()
{
    return info;
}
Nod* Nod::get_next()
{
    return next;
}
void Nod::set_next(Nod* z)
{
    this->next =z;
}
void Nod::set_info(char caracter)
{
    this->info = caracter;
}



//Clasa coada de caractere

class Coada_de_caractere
{
    Nod *first;
    Nod *last;
public:
    friend class Nod;
    Coada_de_caractere();
    Coada_de_caractere(Coada_de_caractere&);
    //~Coada_de_caractere();
    Nod* get_primul()   //get
    {
        return first;
    }
    Nod* get_ultimul()  //get
    {
        return last;
    }
    Nod* get_first()
    {
        return first->next; //am si acest geter pentru ca il folosesc in mai multe functii
    };
    Nod* get_last()
    {
        return last->next;
    };
    void set_last(Nod *aux) //set
    {
        last=aux;
    }
    void set_first(Nod *aux) //set
    {
        first= aux;
    }
    void popfirst(Nod *aux)
    {
        aux = first;
    }
    char get_firstcaracter()
    {
        return first->get_info(); //pentru a obtine primul caracter din stiva
    }
    char get_finfo()
    {
        return first->info;
    };
    char get_linfo()
    {
        return last->info;
    };
    friend void push(Coada_de_caractere &a);
    friend char pop(Coada_de_caractere &a);
    friend void afisare(ostream &out, Coada_de_caractere &a);
    friend ostream& operator<<(ostream &out, Coada_de_caractere& a);
    friend void citire(Coada_de_caractere &a);
    friend istream& operator>>(istream &in, Coada_de_caractere& a);
    friend Coada_de_caractere& operator+( Coada_de_caractere& a, Coada_de_caractere& b);
    friend Coada_de_caractere& operator-( Coada_de_caractere& a, Coada_de_caractere& b);


};

Coada_de_caractere::Coada_de_caractere()
{
    first = 0;
    last = 0;
}
Coada_de_caractere::Coada_de_caractere(Coada_de_caractere& z)
{
    this->first=z.get_first();
    this->last=z.get_last();
}
/*Coada_de_caractere::~Coada_de_caractere()
{
    Nod *p=first;
    Nod *q;
    while (p!=0)
    {
        q=p;
        p=p->next;
        delete q;
    }
    first=last=0;
}*/

//daca pun destructorul nu imi ruleaza bine suma/diferenta cand am mai mult de 3 cozi


void push(Coada_de_caractere& a, char x)
{
    Nod *aux = new Nod(x);
    if(a.get_ultimul()==NULL)  //daca coada este goala primul nod o sa fie egal cu ultimul adica cu aux
    {
        a.set_last(aux);
        a.set_first(aux);

    }
    else //aici este cazul cand coada nu este goala. Astfel, ultimul devine aux
    {
        (a.get_ultimul())->set_next(aux);
        a.set_last(aux);
    }

}

//la push am implementat mai intai o coada normala si dupa am schimbat pentru problema mea
/* am facut aceasta problema inainte de proiect
Am schimbat datele problemei facute de mine ca sa se potriveasca cu ce se cere in proiect
void push(node *&first, node *&last, int x)
{
    node *aux;

    aux = new node;
    aux->val = x;
    aux->next = NULL;

    if(last == NULL)
        first = last = aux;

    else{
        last->next = aux;
        last = aux;
    }
}*/


char pop(Coada_de_caractere& a)
{
    Nod* aux;
    aux = a.get_primul();
    char caracter;
    if(a.get_primul()==NULL) return -1; //la pop returnam caracterul de pe prima pozitie iar coada urca cu o pozitie(primul devine al doilea si etc)
    caracter = a.get_firstcaracter();
    a.set_first(a.get_first());
    if(a.get_primul()==NULL)
        a.set_last(NULL);

    return caracter;
}
/*
asta e programul pe care l-am facut pentru pop
Am schimbat in el cat sa se potriveasca cu cerinta proiectului
int pop(node *&first, node *&last)
{
    node *aux = first;
    int x;

    if (first == NULL) return -1;
    x = first->val;

    first = first->next;
    delete aux;

    if(first == NULL)
        last = NULL;

    return x;
}

*/

int isempty(Coada_de_caractere& a)
{
    if(a.get_primul()==NULL) return -1; //daca coada este goala, adica primul element este egal cu null, returnam -1
    return 1;
}


void afisare(ostream &out, Coada_de_caractere &a)
{
    while (isempty(a)!=-1)
    {
        out<<pop(a)<<" ";
    }

}

ostream& operator<<(ostream &out,Coada_de_caractere &a)
{
    afisare(out,a);
    return out;
}

void citire(Coada_de_caractere &a)
{
    char s[250];
    cin.getline(s,250);
    for(int i =0; i<strlen(s); i++)
    {
        push(a,s[i]);
    }
}

istream& operator>>(istream& in,Coada_de_caractere& a)
{
    citire(a);
    return in;
}


inline Coada_de_caractere& operator+(Coada_de_caractere &a,Coada_de_caractere &b)
{
    Coada_de_caractere f;

    char d;
    while(a.get_primul()!=NULL)
    {
        d =a.get_firstcaracter();
        push(f,d);
        a.set_first(a.get_first());
    }
    while(b.get_primul()!=NULL)
    {
        d =b.get_firstcaracter();
        push(f,d);
        b.set_first(b.get_first());
    }
    a=f;
    return a;
}
inline Coada_de_caractere& operator-(Coada_de_caractere &a,Coada_de_caractere &b)
{
    Coada_de_caractere f;
    char d,e;

    while(a.get_primul()!=NULL && b.get_primul()!=NULL )
    {
        d = a.get_firstcaracter();
        e = b.get_firstcaracter();
        if(d>e)
            push(f,d);
        else
            push(f,e);
        a.set_first(a.get_first());
        b.set_first(b.get_first());
    }
    a=f;
    return a;
}

void menu_output(){
    cout<<"\n STAN ANA-MARIA, GRUPA 141 - Proiect I - Nume proiect: Tema 5. Clasa -Coada_de_caractere- (implementata dinamic) \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citirea si afisarea unei cozi"; cout<<"\n";
    cout<<"2. Citirea si afisarea a n cozi, n>0"; cout<<"\n";
    cout<<"3. Citirea si afisarea sumei a n cozi, n>=2"; cout<<"\n";
    cout<<"4. Citirea si afisarea diferentei a n cozi, n>=2"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;

    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {

            cin.get();
            Coada_de_caractere a;
            cout<<"Introduceti elementele cozii, fara spatii intre elemente: ";
            cin>>a;
            cout<<"Elementele cozii sunt: "<<a;
        }
        if (option==2)
        {

            int n,i;
            cout<<"Introduceti numarul de cozi: ";
            cin>>n;
            cin.get();
            if(n<1)
                cout<<"Numarul de cozi este prea mic! Introduceti un numar de cozi mai mare sau egal cu 1!";
            else
            {
                Coada_de_caractere *a= new Coada_de_caractere[n];
            for(i = 0;i<n;i++)
            {   cout<<"Introduceti elementele cozii nr."<<i+1<<",fara spatii intre elemente: ";
                cin>>a[i];
            }

            for(i = 0;i<n;i++)

                cout<<"Elementele cozii nr."<<i+1<<" sunt: "<<a[i]<<endl;
            }

        }
        if (option==3)
        {
            int n,i;
            cout<<"Introduceti numarul de cozi: ";
            cin>>n;
            cin.get();
            if(n<2)
                cout<<"Numarul de cozi este prea mic! Introduceti un numar de cozi mai mare sau egal cu 2!";
            Coada_de_caractere *a= new Coada_de_caractere[n];
            for(i = 0;i<n&&n>1;i++)
            {
                cout<<"Introduceti elementele cozii nr."<<i+1<<",fara spatii intre elemente: ";
                cin>>a[i];
            }

            Coada_de_caractere suma;
            if(n>1)
            {a[0]+a[1];
            for(i = 2;i<n;i++)
                 a[0]+a[i];
            cout<<"Suma cozilor este: "<<a[0];
            }



        }
        if (option==4)
        {
           int n,i;
           cout<<"Introduceti numarul de cozi: ";
            cin>>n;
            cin.get();
            if(n<2)
                cout<<"Numarul de cozi este prea mic! Introduceti un numar de cozi mai mare sau egal cu 2!";

            Coada_de_caractere *a= new Coada_de_caractere[n];
            for(i = 0;i<n&&n>1;i++)
            {
                cout<<"Introduceti elementele cozii nr."<<i+1<<",fara spatiu: ";
                cin>>a[i];
            }

            Coada_de_caractere dif;
            if(n>1)
            {
                 a[0]-a[1];
            for(i = 2;i<n;i++)
                a[0]-a[i];
            cout<<"Diferenta cozilor este: "<<a[0];
            }

        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>5)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

int main()
{
    menu();
   return 0;
}
