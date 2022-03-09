#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;



class CArticol
{
protected:
    int cota;
    int nrexemplare;
    string nume;
    static int articole;
    const int Art;
//----------------------------------
public:
    /* const int idc;
     static int id;
     c():idc(++id){}
     c(c& x):idc(x.idc){
     }*/
    CArticol():Art(++articole)
    {
        this->cota=0;
        this->nrexemplare=0;
        this->nume="";
    }
    CArticol(int a, int b, string s):Art(articole)
    {
        this->cota=a;
        this->nrexemplare=b;
        this->nume=s;
        articole++;

    }

    CArticol(CArticol& a):Art(a.articole)
    {
        this->cota=a.cota;
        this->nrexemplare=a.nrexemplare;
        this->nume= a.nume;
        articole++;
    }
    ~CArticol(){
    cota=0;
    nrexemplare=0;
    nume="";
    }
//------------------------------
    int get_Art()
    {
        return this->Art;
    }
    void set_cota(int x)
    {
        this->cota=x;
    }
    void set_nrexemplare(int x)
    {
        this->nrexemplare=x;
    }
    void set_nume(string s)
    {
        this->nume=s;
    }
    int get_cota() const
    {
        return this->cota;
    }
    int get_nrexemplare()
    {
        return this->nrexemplare;
    }
    string get_nume()
    {
        return this->nume;
    }
    static void numarObiecte()  /// metoda statica de afisare a numarului de obiecte
    {
        cout<<"Numarul de articole: "<<articole;
    }
//   void nrOb()const
    //{
    //    cout<<Art;
    // }
//--------------------------------
    CArticol& operator=(CArticol &a);
    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    //virtual void tip()=0;
    virtual void tip(){cout<<"articol";}
    friend istream& operator>>(istream &in, CArticol& a);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, CArticol& a); ///supraincarcare pe <<
    friend class CBiblioteca;

};
int CArticol::articole=0;


/*CArticol::CArticol(){
    this->cota=0;
    this->nrexemplare=0;
    this->nume="";
    articole++;

}

CArticol::CArticol(CArticol& a){
    this->cota=a.cota;
    this->nrexemplare=a.nrexemplare;
    this->nume= a.nume;
    articole++;


}
CArticol::CArticol(int a, int b, string s){
    this->cota=a;
    this->nrexemplare=b;
    this->nume=s;
    articole++;

}*/


void CArticol::citire(istream &in)
{
    cout<<"Articol:"<<endl;
    cout<<"Cititi cota: ";
    in>>cota;
    cout<<"Cititi numarul de exemplare: ";
    in>>nrexemplare;
    cout<<"Cititi numele: ";
    in>>nume;

}

istream& operator>>(istream &in, CArticol& a)
{
    a.citire(in);
    return in;
}

void CArticol::afisare(ostream &out)
{
    //out<<"Elementele articolului: Cota:"<<cota<<" Numarul de exemplare: "<<nrexemplare<<" Numele: "<<nume<<end;
    out<<"Elementele articolului: "<<endl;
    out<<"Cota: "<<cota<<endl;
    out<<"Numarul de exemplare: "<<nrexemplare<<endl;
    out<<"Nume: "<<nume<<endl;

}

ostream& operator<<(ostream& out, CArticol& a)
{
    a.afisare(out);
    return out;
}

CArticol& CArticol::operator=(CArticol &a)
{
    cota=a.cota;
    nrexemplare=a.nrexemplare;
    nume=a.nume;
}


class CCarte:public CArticol
{
protected:
    string NumeAutor;
public:
    CCarte(int,int,string,string);
    CCarte(CCarte&);
    ~CCarte(){
    NumeAutor="";
    }
//---------------------------------
    void set_NumeAutor(string s)
    {
        this->NumeAutor=s;
    }
    string get_NumeAutor()
    {
        return this->NumeAutor;
    }
//----------------------------------
    CCarte& operator=(CCarte &a);
    virtual void tip()
    {
        cout<<"Tipul este: Carte \n";
    }
    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    friend istream& operator>>(istream &in, CCarte& a);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, CCarte& a); ///supraincarcare pe <<
};

CCarte::CCarte(int a=0,int b=0,string c="",string d=""):CArticol(a,b,c)
{
    NumeAutor=d;
}

void CCarte::citire(istream &in)
{
    CArticol::citire(in);
    cout<<"Numele autorului care a scris cartea: ";
    //in>>this->NumeAutor;
    string s;
    int i;
    cin>>s;
    for(i=0;i<s.length();i++)
    { try{
    if(s[i]>'z' || s[i]<'a')
            if(s[i]>'Z' || s[i]<'A')
             if(s[i]>'9' || s[i]<'0')
                if(s[i]!=' ' || s[i]!='-')
                    throw 1;
    }
    catch(int i){cout<<"Nume invalid";}}
    this->NumeAutor=s;


}
void CCarte::afisare(ostream &out)
{
    CArticol::afisare(out);
    out<<"Numele autorului este: ";
    out<<this->NumeAutor<<"\n";
}
istream& operator>>(istream& in,CCarte& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, CCarte& p)
{
    p.afisare(out);
    return out;
}
CCarte& CCarte::operator=(CCarte &a)
{
    cota=a.cota;
    nrexemplare=a.nrexemplare;
    nume=a.nume;
    NumeAutor=a.NumeAutor;
}
//-------------------------------------
class CCD:public CArticol
{
protected:
    string Continut; //film,muzica
public:
    CCD(int,int,string,string);
    CCD(CCD&);
    ~CCD(){
    Continut="";
    }
//---------------------------------
    void set_Continut(string s)
    {
        this->Continut=s;
    }
    string get_Continut()
    {
        return this->Continut;
    }
//----------------------------------
    CCD& operator=(CCD &a);
    virtual void tip()
    {
        cout<<"Tipul este: CD \n";
    }
    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    friend istream& operator>>(istream &in, CCD& a);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, CCD& a); ///supraincarcare pe <<
};

CCD::CCD(int a=0,int b=0,string c="",string d=""):CArticol(a,b,c)
{
    Continut=d;
}

void CCD::citire(istream &in)
{
    CArticol::citire(in);
    cout<<"Tipul de CD: ";

     string s;
    int i;
    cin>>s;
    for(i=0;i<s.length();i++)
    { try{
    if(s[i]>'z' || s[i]<'a')
            if(s[i]>'Z' || s[i]<'A')
             if(s[i]>'9' || s[i]<'0')
                if(s[i]!=' ' || s[i]!='-')
                throw 1;
    }
    catch(int i){cout<<"Continut invalid";}}
    this->Continut=s;


}
void CCD::afisare(ostream &out)
{
    CArticol::afisare(out);
    out<<"Tipul de CD: ";
    out<<this->Continut<<"\n";
}
istream& operator>>(istream& in,CCD& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, CCD& p)
{
    p.afisare(out);
    return out;
}
CCD& CCD::operator=(CCD &a)
{
    cota=a.cota;
    nrexemplare=a.nrexemplare;
    nume=a.nume;
    Continut=a.Continut;
}
//-----------------------------------------------
class CRevista:public CArticol
{
protected:
    string LunaAparitiei;
public:
    CRevista(int,int,string,string);
    CRevista(CRevista&);
    ~CRevista(){
    LunaAparitiei="";
    }
//---------------------------------
    void set_Luna(string s)
    {
        this->LunaAparitiei=s;
    }
    string get_Luna()
    {
        return this->LunaAparitiei;
    }
//----------------------------------
    CRevista& operator=(CRevista &a);
    virtual void tip()
    {
        cout<<"Tipul este: Revista \n";
    }
    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    friend istream& operator>>(istream &in, CRevista& a);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, CRevista& a); ///supraincarcare pe <<
};

CRevista::CRevista(int a=0,int b=0,string c="",string d=""):CArticol(a,b,c)
{
    LunaAparitiei=d;
}

void CRevista::citire(istream &in)
{
    CArticol::citire(in);
    cout<<"Luna de apartitie a revistei: ";
    in>>this->LunaAparitiei;

}
void CRevista::afisare(ostream &out)
{
    CArticol::afisare(out);
    out<<"Numele autorului este: ";
    out<<this->LunaAparitiei<<"\n";
}
istream& operator>>(istream& in,CRevista& p)
{
    p.citire(in);
    return in;
}
ostream& operator<<(ostream& out, CRevista& p)
{
    p.afisare(out);
    return out;
}
CRevista& CRevista::operator=(CRevista &a)
{
    cota=a.cota;
    nrexemplare=a.nrexemplare;
    nume=a.nume;
    LunaAparitiei=a.LunaAparitiei;
}


//-----------BIBLIOTECA------------------
class CBiblioteca
{
    list <CArticol *> obiecte;
public:
    CBiblioteca();
    ~CBiblioteca();
    void addArticol(CArticol *&x)
    {
        //x->set_imprumut(true);
        this->obiecte.push_back(x);
    }
    void printArticole()
    {
        list<CArticol *>::iterator i; ///Creez un iterator
        cout << "---------------------------------------------------------------\n";
        for (i = obiecte.begin(); i != obiecte.end(); ++i)   ///De la inceputul listei pana la final, parcurg si afisez continutul iteratorului
        {
            {
                cout << (**i);
                (**i).tip();
                cout<<(**i).nrexemplare<<endl;
            }
        }
    }
    void imprumutaArticol(int cod)
    {
        list<CArticol *>::iterator i; ///Creez un iterator
        cout << "---------------------------------------------------------------\n";
        for (i = obiecte.begin(); i != obiecte.end(); ++i)   ///De la inceputul listei pana la final, parcurg si afisez continutul iteratorului
        {
            if((**i).cota==cod)
            {
                //(**i).set_imprumut(false);;
                if((**i).nrexemplare>0)
                {
                    (**i).nrexemplare--;
                    break;
                }
            }

        }
    }
    void restituieArticol(int cod)
    {
        list<CArticol *>::iterator i; ///Creez un iterator
        cout << "---------------------------------------------------------------\n";
        for (i = obiecte.begin(); i != obiecte.end(); ++i)   ///De la inceputul listei pana la final, parcurg si afisez continutul iteratorului
        {
            if((**i).cota==cod)
            {
                //(**i).set_imprumut(false);;

                (**i).nrexemplare++;
                break;

            }
        }
    }
    friend class CArticol;
};

CBiblioteca::CBiblioteca()
{

}

CBiblioteca::~CBiblioteca()
{
 obiecte.erase(obiecte.begin(),obiecte.end());
}

/*template <typename T>
void tempafis(int a, T b)
{
    cout<<*b;
}

template <class Cls>
class CException
{
public:
   void printErrMessage(){
   cout<<"Eroare";
   }
};*/


class CException: public exception
{
    public:
  virtual char* printErrMessage() const throw()
  {
    return "My exception happened";
  }
} e;

template <class tem> class Raft{
    vector<tem> v;
    int id;
    public:
        Raft(){
        id=0;
        }
        Raft(tem i)
        {   id=0;
            v.push_back(i);
            id++;
        }
        void Adg(tem i){
            v.push_back(i);
            id++;
        }


         friend ostream &operator<<(ostream &out, Raft<tem> &c)
    {

        for (int i = 0; i < c.id; i++)
        {
            cout << *c.v[i]<<endl;
        }
        return out;
    }
};


void tip2(CArticol *&p, int &i) {
    int c;
    cout<<"\n";
    cout<<"1.Carte \n"<<"2.CD \n"<<"3.Revista \n";
    cout<<"Introduceti numarul dorit: "<<i+1<<": ";
    cin>>c;
    try{

            if(c==1){
                p=new CCarte;
                cin>>*p;
                i++;
            }
            else
                if (c==2){
                    p=new CCD;
                    cin>>*p;
                    i++;
                }
                else
                    if(c==3){
                     p=new CRevista;
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
        cout<<"Nu ati introdus un obiect valid.\n ";
    }
}


//https://www.cplusplus.com/doc/tutorial/exceptions/

void menu_output()
{
    cout<<"\n Nume Prenume Grupa - Proiect - Nume proiect: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Exemplul dat: ";
    cout<<"\n";
    cout<<"2. Citirea si afisarea a n elemente de tipuri diferite:";
    cout<<"\n";
    cout<<"3. TEMPLATE: Citirea si afisarea a n obiecte:";
    cout<<"\n";
    cout<<"4. Schimbarea unui articol intr-o carte, revista sau CD, iar apoi citirea si afisarea acesteia(dynamic_cast)";
    cout<<"\n";
    cout<<"5. Un upcast";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
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
            try
            {
                CBiblioteca B;
                CArticol *C1 = new CCarte (1000, 10, "Programarein C++");
                CArticol *C2 = new CCarte (1001, 15, "Programarein Java");
                CArticol *C3 = new CCD (1002, 8, "Documentatie electronicaC++");
                CArticol *C4 = new CCD (1003, 8, "Documentatie electronicaJava");
                CArticol *C5 = new CCD (1004, 8, "Documentatie electronicaRetele");
                B.addArticol (C1);
                B.addArticol (C2);
                B.addArticol(C3);
                B.printArticole ();
                B.addArticol (C4);
                B.addArticol (C5);
                B.imprumutaArticol (1001);
                B.printArticole ();
                B.imprumutaArticol(1002);
                B.printArticole ();
                B.restituieArticol(1001);
                B.printArticole ();
            } catch (CException *e){e->printErrMessage();delete e;}
            int cont;
            cout<<"Doriti sa afisati numar de articole create?\n"<<"1.Da\n"<<"2.Nu\n";
            cin>>cont;
            try{
                if(cont!=1 && cont!=2)
                    throw 'a';
                else
                    if(cont ==1)
                {
                    CArticol::numarObiecte();
                }
                else
                    if(cont==2) break;}
            catch (char i){cout<<"Alegere invalida";}

        }
        if (option==2)
        {
            CArticol **v; ///vezi mai jos pentru a intelege
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;
        v=new CArticol*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
                                                                                                                            /// sau il pot face regizor/actor)
        for(int i=0;i<n;)
            tip2(v[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa

        cout<<"\nAfisam tipul articolului:\n";
        for(int i=0;i<n;i++){
            v[i]->tip();
            cout<<"\n"<<*v[i]; ///afisez personalul de pe pozitia i
            cout<<"--------------------------\n";
        }
        int cont;
            cout<<"Doriti sa afisati numar de articole create?\n"<<"1.Da\n"<<"2.Nu\n";
            cin>>cont;
            try{
                if(cont!=1 && cont!=2)
                    throw 'a';
                else
                    if(cont ==1)
                {
                    CArticol::numarObiecte();
                }
                else
                    if(cont==2) break;}
            catch (char i){cout<<"Alegere invalida";}
        }
        if (option==4)
        {
            cout<<"Intoduceti in ce doriti sa transformati baza:\n"<<"1.Carte\n"<<"2.Revista\n"<<"3.CD\n";
            int i;
            cin>>i;
            if(i==1){
                CArticol *bp;
                CCarte *dp,d_ob;

                bp =  dynamic_cast<CArticol*>(&d_ob);
                cout<<"Schimbarea a avut loc iar articolul este acum: ";
                bp->tip();
                cin>>*bp;
                cout<<*bp;
            }
            else
                if(i==2){
                    CArticol *bp;
                    CRevista *dp,d_ob;
                    bp =  dynamic_cast<CArticol*>(&d_ob);
                    cout<<"Schimbarea a avut loc iar articolul este acum: ";
                    bp->tip();
                    cin>>*bp;
                    cout<<*bp;
                }
                else
                    if(i==3){
                        CArticol *bp;
                        CCD *dp,d_ob;
                        bp =  dynamic_cast<CArticol*>(&d_ob);
                        cout<<"Schimbarea a avut loc iar articolul este acum: ";
                        bp->tip();
                        cin>>*bp;
                        cout<<*bp;

                }
             int cont;
            cout<<"Doriti sa afisati numar de articole create?\n"<<"1.Da\n"<<"2.Nu\n";
            cin>>cont;
            try{
                if(cont!=1 && cont!=2)
                    throw 'a';
                else
                    if(cont ==1)
                {
                    CArticol::numarObiecte();
                }
                else
                    if(cont==2) break;}
            catch (char i){cout<<"Alegere invalida";}
        }
        if (option==3)
        {       Raft <CArticol*> rf;
                int n;
                cout<<"Introduceti numarul de obiecte citite: ";
                cin>>n;int a;
                for(int i=0;i<n;i++){
                    cout<<"1.Carte \n"<<"2.CD \n"<<"3.Revista \n";
                    cout<<"Introduceti numarul dorit: "<<i<<": ";

                    cin>>a;
                    if(a==1){
                        CArticol *b=new CCarte;
                        cin>>*b;
                        rf.Adg(b);
                    }else
                        if(a==2){
                           CArticol *b=new CCD;
                        cin>>*b;
                        rf.Adg(b);
                        }else
                        if(a==3){
                           CArticol *b=new CRevista;
                        cin>>*b;
                        rf.Adg(b);
                        }
                }
                cout<<rf;
            int cont;
            cout<<"Doriti sa afisati numar de articole create?\n"<<"1.Da\n"<<"2.Nu\n";
            cin>>cont;
            try{
                if(cont!=1 && cont!=2)
                    throw 'a';
                else
                    if(cont ==1)
                {
                    CArticol::numarObiecte();
                }
                else
                    if(cont==2) break;}
            catch (char i){cout<<"Alegere invalida";}

        }
        if (option==5)
        {
            CArticol *x=new CCarte;
            cin>>*x;
            cout<<*x;
            int cont;
            cout<<"Doriti sa afisati numar de articole create?\n"<<"1.Da\n"<<"2.Nu\n";
            cin>>cont;
            try{
                if(cont!=1 && cont!=2)
                    throw 'a';
                else
                    if(cont ==1)
                {
                    CArticol::numarObiecte();
                }
                else
                    if(cont==2) break;}
            catch (char i){cout<<"Alegere invalida";}
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
