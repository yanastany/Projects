#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
//--------------------------PUNCT------------
class Punct
{
protected:
    float x;
    float y;
    static int nrpuncteplan;
public:
//-----------------constructori,destructori,setari,geteri------
    Punct();
    Punct(float,float);
    Punct(Punct&);
    ~Punct();
    void set_x(float i){this->x=i;};
    void set_y(float i){this->y=i;};
    float get_x(){return x;};
    float get_y(){return y;};
     static void numarObiecte(){ /// metoda statica de afisare a numarului de obiecte
        cout<<"Numarul de puncte in plan este: "<<nrpuncteplan;
    }
    static void stergere(){
    nrpuncteplan--;}

//--------------------------------Operatori-----------
    Punct& operator=(Punct &a);
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, Punct& a);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, Punct& a); ///supraincarcare pe <<
    friend class Patrat;

};
int Punct::nrpuncteplan;
Punct::Punct()
{
    this->x=0;
    this->y=0;
    nrpuncteplan=nrpuncteplan+1;
}

Punct::Punct(float a,float b)
{
    this->x=a;
    this->y=b;
    nrpuncteplan=nrpuncteplan+1;

}

Punct::Punct(Punct& a)
{
    this->x=a.x;
    this->y=a.y;
    nrpuncteplan=nrpuncteplan+1;
}
Punct::~Punct(){
x=0;
y=0;
}

void Punct::citire(istream &in){
    cout<<"Punct:"<<endl;
    cout<<"Cititi coordonata x: ";
    in>>x;
    cout<<"Cititi coordonata y: ";
    in>>y;
}

istream& operator>>(istream &in, Punct& a)
{
    a.citire(in);
    return in;
}

void Punct::afisare(ostream &out)
{
    out<<"Punctul este:"<<"("<<x<<","<<y<<")";
}

ostream& operator<<(ostream& out, Punct& a){
    a.afisare(out);
    return out;
}

Punct& Punct::operator=(Punct &a)
{
    x=a.x;
    y=a.y;
}

//--------------------------PATRAT------------
class Patrat
{
protected:
    Punct stanga_jos;
    float latura;
    bool valid;
public:
//-----------------constructori,destructori,setari,geteri------
    Patrat();
    Patrat(Punct,float);
    Patrat(Patrat&);
    ~Patrat();
    void set_punctstangajos(Punct x){this->stanga_jos=x;}
    void set_latura(float l){this->latura=l;}
    Punct& get_punctstangajos(){return stanga_jos;}
    float get_latura(){return latura;}
//--------------------------------Arie+Perimetru-------
    virtual void Perimetru(){cout<<"Perimetru Patratului este: "<< 4*latura<<endl;}
    virtual void Arie(){cout<<"Aria Patratului este: "<<latura*latura<<endl;}
//--------------------------------Operatori+altefunctii-----------
    Patrat& operator=(Patrat &a);
    virtual void forma(){cout<<"Patrat \n";}
    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    virtual void get_valid(){
        if (this->valid==true)
           cout<<"Patratul dat este valid \n";
        else
           cout<<"Patratul dat nu este valid \n";}
    friend istream& operator>>(istream &in, Patrat& a);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, Patrat& a); ///supraincarcare pe <<
};

Patrat::Patrat()
{
    this->stanga_jos.set_x(0);
    this->stanga_jos.set_y(0);
    this->latura = 0;
    this->valid=true;
}

Patrat::Patrat(Punct a,float l)
{
    this->stanga_jos=a;
    this->latura=l;
    //avem un singur punct in plan si o latura deci laca latura este >0 atunci patratul este valid(pentru ca il construim noi)
    if (l>0)
    {

        this->valid=true;
    }
    else
        this->valid=false;

}

Patrat::Patrat(Patrat& a)
{
    this->stanga_jos=a.stanga_jos;
    this->latura=a.latura;
    this->valid=a.valid;
}
Patrat::~Patrat(){
  stanga_jos.set_x(0);
  stanga_jos.set_y(0);
  latura=0;
  valid=0;
}

Patrat& Patrat::operator=(Patrat &a)
{
    stanga_jos=a.stanga_jos;
    latura=a.latura;
    valid=a.valid;
}
void Patrat::citire(istream &in){

    in>>stanga_jos;
    cout<<"latura: ";
    in>>latura;
    if (latura>0)
    {
        this->valid=true;
    }
    else
        this->valid=false;
}

istream& operator>>(istream &in, Patrat& a)
{
    a.citire(in);
    return in;
}

void Patrat::afisare(ostream &out)
{
    out<<stanga_jos<<"\nlungimea laturei este: "<<latura<<endl;
}

ostream& operator<<(ostream& out, Patrat& a){
    a.afisare(out);
    return out;
}

//--------------------------DREPTUNGHI------------

class Dreptunghi:public virtual Patrat
{
protected:
    float latura2;
   bool valid;
public:
//-------------------Constructori---------------
    Dreptunghi(Punct,float,float);
    Dreptunghi(Dreptunghi &a):Patrat(){
    this->stanga_jos.set_x(a.stanga_jos.get_x());
    this->stanga_jos.set_y(a.stanga_jos.get_y());
    this->latura2=a.latura2;
    this->latura=a.latura2;
    this->valid = a.valid;
    }
    ~Dreptunghi();
    float get_latura2(){return this->latura2;}
    void set_latura2(float l){this->latura2=l;}
//--------------operatori-------
    void citire(istream &in);
    void afisare(ostream &out);
    void forma(){cout<<"Dreptunghi \n";}
    friend istream& operator>>(istream&, Dreptunghi&);
    friend ostream& operator<<(ostream&, Dreptunghi&);
    Dreptunghi& operator=(Dreptunghi &a);
//--------------Arie+perimetru-----------
    void Arie(){cout<<"Aria dreptunghiului este: "<<latura2*latura<<endl;}
    void Perimetru(){cout<<"Perimetru dreptunghiului este: "<<latura2*2+latura*2<<endl;}
//-------------------GetValid-----------------------
    void get_valid(){
        if (this->valid==1)
            cout<<"Dreptunghiul dat este valid \n";
        else
            cout<<"Dreptunghiul dat nu este valid \n";}

};
Dreptunghi::Dreptunghi(Punct a,float l1=0.0,float l2=0):Patrat(a,l1)
{
    latura2=l2;
    Punct::stergere();
    Punct::stergere();

}

Dreptunghi::~Dreptunghi()
{
    latura2=0;
    valid=0;
}

void Dreptunghi::citire(istream &in)
{
    Patrat::citire(in);
    cout<<"Latura2 a dreptunghiului:";
    in>>this->latura2;
    if(latura2>0 && latura>0)
        this->valid=true;
    else
        this->valid=false;
}
void Dreptunghi::afisare(ostream &out)
{
    Patrat::afisare(out);
    out<<"Lungimea laturei 2 este:";
    out<<this->latura2<<"\n";
}
istream& operator>>(istream& in,Dreptunghi& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Dreptunghi& p)
{
    p.afisare(out);
    return out;
}
Dreptunghi& Dreptunghi::operator=(Dreptunghi &a)
{
    stanga_jos=a.stanga_jos;
    latura=a.latura;
    latura2=a.latura2;
    valid=a.valid;
}
//------------------ROMB--------------------
class Romb:public virtual Patrat
{
protected:
    Punct colt_opus;
    bool valid;
public:
//-------------Constructori-Destructori------------
    Romb(Punct,float);
    Romb(Romb &a){
    this->stanga_jos.set_x(a.stanga_jos.get_x());
    this->stanga_jos.set_y(a.stanga_jos.get_y());
    this->colt_opus=a.colt_opus;
    this->latura=a.latura;
    this->valid = a.valid;
    }
    ~Romb();
    Punct& get_punctopus(){return this->colt_opus;}
    void set_punctopus(Punct a){this->colt_opus=a;}
//--------------------------------------------
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Romb&);
    friend ostream& operator<<(ostream&, Romb&);
    Romb& operator=(Romb &a);
    void forma(){cout<<"Romb \n";}
    void get_valid(){
    if (this->valid==1)
           cout<<"Rombul dat este valid \n";
        else
            cout<<"Rombul dat nu este valid \n";
    }
    void Arie(){
    float d1,d2,c;
    c = (colt_opus.get_x()-stanga_jos.get_x())*(colt_opus.get_x()-stanga_jos.get_x())+(colt_opus.get_y()-stanga_jos.get_y())*(colt_opus.get_y()-stanga_jos.get_y());
    d1 = sqrt(c);//facem distanta dintre 2 puncte pentru a afla cat este diagonala dintre cele 2 puncte date
    cout<<d1<<" ";
    d2= 2*sqrt((latura*latura-(d1*d1/4)));
    cout<<d2;
    cout<<"Aria rombului este: "<<d1*d2/2<<endl;
    }
    void Perimetru(){cout<<"Perimetru rombului este: "<<latura*4<<endl;}

};

Romb::Romb(Punct a,float l1=0.0):Patrat(a,l1)
{
    colt_opus=a;
    if (latura==sqrt((colt_opus.get_x()-stanga_jos.get_x()-latura)*(colt_opus.get_x()-stanga_jos.get_x()-latura)-(colt_opus.get_y()-stanga_jos.get_y())-(colt_opus.get_y()-stanga_jos.get_y())))
       this->valid=1;
    else
       this->valid=0;
    Punct::stergere();
    Punct::stergere();
}
Romb::~Romb(){
colt_opus.set_x(0);
colt_opus.set_y(0);
valid=0;
}

void Romb::citire(istream &in)
{
    Patrat::citire(in);
    cout<<"Punctul opus:";
    in>>this->colt_opus;

    if (latura==sqrt((colt_opus.get_x()-stanga_jos.get_x()-latura)*(colt_opus.get_x()-stanga_jos.get_x()-latura)-(colt_opus.get_y()-stanga_jos.get_y())-(colt_opus.get_y()-stanga_jos.get_y())))
       this->valid=1;
    else
       this->valid=0;
}
void Romb::afisare(ostream &out)
{
    Patrat::afisare(out);
    out<<"Punctul opus este:";
    out<<this->colt_opus<<"\n";
}
istream& operator>>(istream& in,Romb& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Romb& p)
{
    p.afisare(out);
    return out;
}
Romb& Romb::operator=(Romb &a)
{
    stanga_jos=a.stanga_jos;
    latura=a.latura;
    colt_opus=a.colt_opus;
    valid=a.valid;
}


//-----------------------Paralelogram-------------

class Paralelogram:public Dreptunghi, public Romb
{
protected:
    bool valid;
public:
    Paralelogram(Punct a,float l1=0):Patrat(a,l1),Dreptunghi(a,l1,l1),Romb(a,l1)
    {
       if ((((stanga_jos.get_y()-stanga_jos.get_y())/(stanga_jos.get_x()+latura-stanga_jos.get_x()))*((stanga_jos.get_y()+latura2-stanga_jos.get_y())/(stanga_jos.get_x()-stanga_jos.get_x())))!=-1)
       this->valid=1;
   else
        this->valid=0;
    }


    Paralelogram(Paralelogram &b);

   /* Paralelogram(Paralelogram &a){
        this->stanga_jos.set_x(a.stanga_jos.get_x());
    this->stanga_jos.set_y(a.stanga_jos.get_y());
    this->colt_opus=a.colt_opus;
    this->latura=a.latura;
    this->valid = a.valid;
    this->latura2=a.latura2;

    }*/

    ~Paralelogram();
    void get_valid()
    {
        if (this->valid==1)
           cout<<"Paralelogramul dat este valid \n";
       else
          cout<<"Paralelogramul dat nu este valid \n";
    }
    void forma(){cout<<"Paralelogram \n";}
    void citire(istream& in)
    {
        Patrat::citire(in);
        cout<<"latura2=";
        in>>this->latura2;
        cout<<"Punct opus:";
        in>>this->colt_opus;
        if (latura2==sqrt((colt_opus.get_x()-stanga_jos.get_x()-latura)*(colt_opus.get_x()-stanga_jos.get_x()-latura)-(colt_opus.get_y()-stanga_jos.get_y())-(colt_opus.get_y()-stanga_jos.get_y())))
       this->valid=1;
    else
       this->valid=0;

    }
    void afisare(ostream& out)
    {
        Patrat::afisare(out);
        out<<"latura2=";
        out<<this->latura2<<endl;
        out<<"Punct opus:";
        out<<this->colt_opus;
        out<<endl;
    }
        friend istream& operator>>(istream &in, Paralelogram& a);  ///supraincarcare pe >>
        friend ostream& operator<<(ostream &out, Paralelogram& a); ///supraincarcare pe <<
        Paralelogram& operator=(Paralelogram &a);
        void Perimetru()
        {
            cout<<"Perimetrul paralelogramului este: "<<2*latura2+2*latura<<endl;
        }
        void Arie()
        {
                float a,b,c,inaltimea,modul,fractiejos; //ax+by+c=0  calculam distanta de la un punct la o dreapta pentru a afla inaltimea
                Punct dreapta_jos;
                dreapta_jos.set_x(stanga_jos.get_x()+latura);
                dreapta_jos.set_y(stanga_jos.get_y());
                a=stanga_jos.get_y()-dreapta_jos.get_y();
                b=dreapta_jos.get_x()-stanga_jos.get_x();
                c=dreapta_jos.get_x()*stanga_jos.get_y()-dreapta_jos.get_y()*stanga_jos.get_x();
                //cout<<a<<" "<<b<<" "<<c;
                modul = colt_opus.get_x()*a+b*colt_opus.get_y()+c;
                if(modul<0) modul=modul*(-1);
                fractiejos=sqrt(a*a+b*b);
                inaltimea=modul/fractiejos;
                cout<<"Aria Paralelogramului este: "<<inaltimea*latura<<endl;
        }
};


Paralelogram::~Paralelogram(){
valid = 0;
}

istream& operator>>(istream& in,Paralelogram& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Paralelogram& p)
{
    p.afisare(out);
    return out;
}
Paralelogram& Paralelogram::operator=(Paralelogram &a)
{
    stanga_jos=a.stanga_jos;
    latura=a.latura;
    latura2=a.latura2;
    colt_opus=a.colt_opus;
    valid=a.valid;
}

//---------------------------Trapez------------------

class Trapez:public Paralelogram
{
protected:
    float baza2;
    bool valid;
public:
    //-------------INITIALIZARE--------------
    Trapez(Punct a,float l=0):Paralelogram(a,l)
    {
        this->baza2=l;
        Punct::stergere();
    }
  /*  Trapez(Trapez &a){
         this->stanga_jos.set_x(a.stanga_jos.get_x());
    this->stanga_jos.set_y(a.stanga_jos.get_y());
    this->colt_opus=a.colt_opus;
    this->latura=a.latura;
    this->valid = a.valid;
    this->latura2=a.latura2;
    this->baza2=a.baza2;
    }*/
    ~Trapez();

    //---------------SET-GET-------------
        void set_baza2(float l){this->baza2=l;}
        float get_baza(){return this->baza2;}

    void get_valid()
    {
        if (this->valid==1)
            cout<<"Trapezul dat este valid \n";
        else
            cout<<"Trapezul dat nu este valid \n";

    }
    //-----------Alte-functii-------------
    void forma(){cout<<"Trapez \n";}
    void citire(istream& in)
    {
        Paralelogram::citire(in);
        cout<<"Baza2 a Trapezului:";
        in>>this->baza2;
        if (0==((stanga_jos.get_y()+latura-stanga_jos.get_y()-latura)/(stanga_jos.get_x()+latura-stanga_jos.get_x())))
        this->valid=true;
    else
        this->valid=false;
    }
    void afisare(ostream& out)
    {
        Paralelogram::afisare(out);
        out<<"Baza2 a Trapezului:";
        out<<this->baza2;
        out<<endl;
    }
        friend istream& operator>>(istream &in, Trapez& a);  ///supraincarcare pe >>
        friend ostream& operator<<(ostream &out, Trapez& a); ///supraincarcare pe <<
        Trapez& operator=(Trapez &a);
        void Arie(){
                float a,b,c,inaltimea,modul,fractiejos; //ax+by+c=0  calculam distanta de la un punct la o dreapta pentru a afla inaltimea
                Punct dreapta_jos;
                dreapta_jos.set_x(stanga_jos.get_x()+latura);
                dreapta_jos.set_y(stanga_jos.get_y());
                a=stanga_jos.get_y()-dreapta_jos.get_y();
                b=dreapta_jos.get_x()-stanga_jos.get_x();
                c=dreapta_jos.get_x()*stanga_jos.get_y()-dreapta_jos.get_y()*stanga_jos.get_x();
                cout<<a<<" "<<b<<" "<<c;
                modul = colt_opus.get_x()*a+b*colt_opus.get_y()+c;
                if(modul<0) modul=modul*(-1);
                fractiejos=sqrt(a*a+b*b);
                inaltimea=modul/fractiejos;
                cout<<"Aria trapezului este: "<<inaltimea*latura<<endl;

        }

        void Perimetru(){
        float laturaramasa;
            Punct dreapta_jos;
            dreapta_jos.set_x(stanga_jos.get_x()+latura);
            dreapta_jos.set_y(stanga_jos.get_y());
            laturaramasa=sqrt((colt_opus.get_x()-dreapta_jos.get_x())*(colt_opus.get_x()-dreapta_jos.get_x())+(colt_opus.get_y()-dreapta_jos.get_y())*(colt_opus.get_y()-dreapta_jos.get_y()));
            cout<<"Perimetrul trapezului este:"<<latura2+latura+baza2+laturaramasa<<endl;
        }
};

Trapez::~Trapez()
{
    baza2 = 0;
    valid = 0;
}

istream& operator>>(istream& in,Trapez& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Trapez& p)
{
    p.afisare(out);
    return out;
}
Trapez& Trapez::operator=(Trapez &a)
{
    stanga_jos=a.stanga_jos;
    latura=a.latura;
    latura2=a.latura2;
    colt_opus=a.colt_opus;
    baza2=a.baza2;
    valid=a.valid;
}
//------------------TIP OBIECT-----------

void tip(Patrat *&p, int &i) {
    int c;
    cout<<"\n";
    cout<<"1.Patrat \n"<<"2.Dreptunghi \n"<<"3.Romb \n"<<"4.Paralelogram \n"<<"5.Trapez \n";
    cout<<"Introduceti numarul dorit: "<<i+1<<": ";
    cin>>c;
    Punct o;
    Punct::stergere();
    try{
        if(c==1){
                 p=new Patrat;
                cin>>*p;
                i++;

        }
        else
            if(c==2){
                p=new Dreptunghi(o,0,0);
                cin>>*p;
                i++;
            }
            else
                if (c==3){
                    p=new Romb(o,0);
                    cin>>*p;
                    i++;
                }
                else
                    if(c==4){
                     p=new Paralelogram(o,0);
                    cin>>*p;
                    i++;
                    }
                    else
                        if(c==5){
                        p=new Trapez(o,0);
                        cin>>*p;
                        i++;
                        }
                        else
                            throw 10;
    }
    catch (bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus o forma valida.\n ";
    }
}





//----------------------------MENIU---------

void menu_output(){
    cout<<"\n Stan Ana Maria Grupa 141 - Proiect 2 - Nume proiect: Tema 5 \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citirea si afisarea a n forme geometrice,n>0"; cout<<"\n";
    cout<<"2. Citirea si afisarea perimetrului a n forme"; cout<<"\n";
    cout<<"3. Citirea si afisarea ariei a n forme"; cout<<"\n";
    cout<<"4. Citirea si verificarea a n forme"; cout<<"\n";
    cout<<"5. Afisarea perimetrului si al ariei unui paralelogram care provine din un trapez (Un downcast)"; cout<<"\n";
    cout<<"6. Afisarea perimetrului si al ariei unui dreptunghi care provine din un patrat (Un upcast)"; cout<<"\n";
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
            Patrat **v; ///vezi mai jos pentru a intelege
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;
        v=new Patrat*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
                                                                                                                            /// sau il pot face regizor/actor)
        for(int i=0;i<n;)
            tip(v[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa

        cout<<"\nAfisam numele formelor:\n";
        for(int i=0;i<n;i++){
            v[i]->forma();
            cout<<"\n"<<*v[i]; ///afisez personalul de pe pozitia i
            cout<<"--------------------------\n";
        }

        int c;
        cout<<"Doriti sa afisati numarul de puncte in plan, diferite de origine? \n"<<"1.Da \n"<<"2.Nu \n";
        cin>>c;
        if(c==1)
            Punct::numarObiecte();


        }
        if (option==2)
        {
            Patrat **v; ///vezi mai jos pentru a intelege
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;
        v=new Patrat*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
                                                                                                                            /// sau il pot face regizor/actor)
        for(int i=0;i<n;)
            tip(v[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa

        cout<<"\nAfisam numele formelor:\n";
        for(int i=0;i<n;i++){
            v[i]->Perimetru();
        }

         int c;
        cout<<"Doriti sa afisati numarul de puncte in plan, diferite de origine? \n"<<"1.Da \n"<<"2.Nu \n";
        cin>>c;
        if(c==1)
            Punct::numarObiecte();

        }
        if (option==3)
        {
           Patrat **v; ///vezi mai jos pentru a intelege
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;
        v=new Patrat*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
                                                                                                                            /// sau il pot face regizor/actor)
        for(int i=0;i<n;)
            tip(v[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa

        cout<<"\nAfisam numele formelor:\n";
        for(int i=0;i<n;i++){
            v[i]->Arie();
        }

         int c;
        cout<<"Doriti sa afisati numarul de puncte in plan, diferite de origine? \n"<<"1.Da \n"<<"2.Nu \n";
        cin>>c;
        if(c==1)
            Punct::numarObiecte();

        }
        if (option==4)
        {
           Patrat **v; ///vezi mai jos pentru a intelege
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;
        v=new Patrat*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
                                                                                                                            /// sau il pot face regizor/actor)
        for(int i=0;i<n;)
            tip(v[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa

        cout<<"\nAfisam numele formelor:\n";
        for(int i=0;i<n;i++){
            v[i]->get_valid();
        }

         int c;
        cout<<"Doriti sa afisati numarul de puncte in plan, diferite de origine? \n"<<"1.Da \n"<<"2.Nu \n";
        cin>>c;
        if(c==1)
            Punct::numarObiecte();
        }
        if (option==5)
        {
           Punct o;
            Punct::stergere();
           ///downcast
            Trapez *c=(Trapez*)new Paralelogram(o,0);
            c->set_punctstangajos(o);
            c->set_latura(0);
            c->set_baza2(0);
            cout<<"\n";
            //Trapez *b(o,0);
            cin>>*c;
            cout<<"Forma este:";
            c->forma();
            c->Perimetru();
            c->Arie();

        }
        if (option==6)
        {
        Punct a;
        Punct::stergere();
        Patrat *x=new Dreptunghi(a,0,0);
        cin>>*x;
        cout<<*x;
        cout<<"Forma este: ";
            x->forma();
            x->Perimetru();
            x->Arie();

        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>6)
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
}
