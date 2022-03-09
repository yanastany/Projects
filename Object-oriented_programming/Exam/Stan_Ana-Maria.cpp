/* Stan Ana-Maria Gnu Gcc Compiler - codeblocks versiunea 20.03  */


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
using namespace std;


class ColException: public exception
{
    public:
  virtual char* printareeroare() const throw()
  {
    cout<< "EROARE!!!";
  }
    virtual char* valgresit() const throw(){
    cout<<"Ati introdus o valoare gresita";
    }
} e;
///catch (ColException *e){e->printareeroare();delete e;}
//invatat din proiectul 3 si vorbit despre asta la ultimul laborator cu laborantul Gusatu Marian


class Malware{

protected:
    int rating;
    int zi;
    int luna;
    int an;
    string metodainfectare;
    vector <string> registrii;
public:
    Malware();
    Malware(int ratinga, int zia, int lunaa,int ana,string met, vector <string> r);
    Malware(Malware& m);
    ~Malware();
    int get_rating() const{
           return this->rating;
    }
     Malware& operator=(Malware &z){
    rating=z.rating;
    zi=z.zi;
    luna=z.luna;
    an = z.an;
    metodainfectare=z.metodainfectare;
    registrii =z.registrii;
}
    virtual void afisare(ostream &out);
    virtual void citire(istream &in);
    virtual void tipmalware()=0;
    virtual string tipmalware1()=0;
    friend istream& operator>>(istream &in, Malware& a);
    friend ostream& operator<<(ostream &out, Malware& a);

};

Malware::Malware(){
    this->rating=0;
    this->zi = 0;
    this->luna=0;
    this->an=0;
    this->metodainfectare = "";
    //this->registrii=0;
}
Malware::Malware(int ratinga, int zia, int lunaa, int ana,string met, vector <string> r)
{
    this->rating=ratinga;
    this->zi = zia;
    this->luna=lunaa;
    this->an=ana;
    this->metodainfectare = met;
    this->registrii=r;
}
Malware::Malware(Malware& m){
    this->rating=m.rating;
    this->zi = m.zi;
    this->luna=m.luna;
    this->an=m.an;
    this->metodainfectare = m.metodainfectare;
    this->registrii=m.registrii;
}
Malware::~Malware(){
    this->rating=0;
    this->zi = 0;
    this->luna=0;
    this->an=0;
    this->metodainfectare = "";
    registrii.clear();
}

void Malware::citire(istream &in)
{ int n;
    cout<<"Malware:"<<endl;
    cout<<"Cititi rating: ";
    in>>rating;
    cout<<"Cititi zi: ";
    in>>zi;
    cout<<"Cititi luna: ";
    in>>luna;
    cout<<"Cititi an: ";
    in>>an;
    cout<<"Cititi metoda de infectare: ";
    in>>metodainfectare;
    cout<<"Cititi numarul de registrii: ";
    cin>>n;
    int i;
    string x;
    //vector<string>::iterator i;
        for (i = 0; i <n; i++)
        {
            {   cout<<"Dati un registru: ";
                cin>>x;
                this->registrii.push_back(x);
            }
        }

}

istream& operator>>(istream &in, Malware& a)
{
    a.citire(in);
    return in;
}

void Malware::afisare(ostream &out)
{
    cout<<"Malware:"<<endl;
    cout<<"rating: ";
    out<<rating;
    cout<<endl;
    cout<<"zi: ";
    out<<zi;
    cout<<endl;
    cout<<"luna: ";
    out<<luna;
    cout<<endl;
    cout<<"an: ";
    out<<an;
    cout<<endl;
    cout<<"metoda de infectare: ";
    out<<metodainfectare;
    cout<<endl;
    vector<string>::iterator i; ///Creez un iterator
        for (i = registrii.begin(); i != registrii.end(); ++i)
        {
                cout << *i;
        }




}

ostream& operator<<(ostream& out,Malware& a)
{
    a.afisare(out);
    return out;
}

class rootkit:public virtual Malware{

protected:

    list<string> importuri;
    list<string> stringsemnificativ;

public:
    rootkit(int rating, int zi, int luna, int an,string met, vector <string> r);
    rootkit(rootkit& m);
    ~rootkit();
    list<string> getlist()const{
    return this->importuri;
    }
     void afisare(ostream &out);
     void citire(istream &in);
     void tipmalware(){
      cout<<"Rootkit";
     };
     string tipmalware1(){
         string s = "rootkit";
     return s;
     };
    friend istream& operator>>(istream &in, rootkit& a);
    friend ostream& operator<<(ostream &out, rootkit& a);

};

rootkit::rootkit(int rating=0, int zi=0, int luna=0, int an=0,string met="", vector <string> r = vector<string>()):Malware(rating,zi,luna,an,metodainfectare, registrii){

}

rootkit::~rootkit(){
    importuri.clear();
    stringsemnificativ.clear();
}
void rootkit::citire(istream &in)
{
    int n,i;
   Malware::citire(in);
   cout<<"dati numarul de importuri:";
   cin>>n;
   string x;
   for (i = 0; i <n; i++)
        {
            {   cout<<"Dati un import: ";
                cin>>x;
                this->importuri.push_back(x);
            }
        }

    cout<<"dati numarul de stringuri semnificative";
    cin>>n;
       for (i = 0; i <n; i++)
        {
            {   cout<<"Dati un string: ";
                cin>>x;
                this->stringsemnificativ.push_back(x);
            }
        }
}

istream& operator>>(istream &in, rootkit& a)
{
    a.citire(in);
    return in;
}

void rootkit::afisare(ostream &out)
{

    Malware::afisare(out);
    list<string>::iterator i;
        for (i = importuri.begin(); i != importuri.end(); ++i)
        {       cout<<"import:";
                out << *i;
        }

        for (i = stringsemnificativ.begin(); i != stringsemnificativ.end(); ++i)
        {       cout<<"string:";
                out << *i;
        }


}

ostream& operator<<(ostream& out,rootkit& a)
{
    a.afisare(out);
    return out;
}



class keylogger:public virtual Malware{

protected:

    list<string> functii;
    list<string> teste;

public:
    keylogger(int rating, int zi, int luna, int an,string met, vector <string> r);
    keylogger(keylogger& m);
    ~keylogger();

     void afisare(ostream &out);
     void citire(istream &in);
     void tipmalware(){
      cout<<"Keylogger";
     };
      string tipmalware1(){
         string s = "keylogger";
     return s;
     };
    friend istream& operator>>(istream &in, keylogger& a);
    friend ostream& operator<<(ostream &out, keylogger& a);

};

keylogger::keylogger(int rating=0, int zi=0, int luna=0, int an=0,string met="", vector <string> r = vector<string>()):Malware(rating,zi,luna,an,metodainfectare, registrii){

}

keylogger::~keylogger(){
    functii.clear();
    teste.clear();
}
void keylogger::citire(istream &in)
{
    int n,i;
   Malware::citire(in);
   cout<<"dati numarul de functii:";
   cin>>n;
   string x;
   for (i = 0; i <n; i++)
        {
            {   cout<<"Dati o functie: ";
                cin>>x;
                this->functii.push_back(x);
            }
        }

    cout<<"dati numarul de stringuri semnificative";
    cin>>n;
       for (i = 0; i <n; i++)
        {
            {   cout<<"Dati un string: ";
                cin>>x;
                this->teste.push_back(x);
            }
        }
}

istream& operator>>(istream &in, keylogger& a)
{
    a.citire(in);
    return in;
}

void keylogger::afisare(ostream &out)
{

    Malware::afisare(out);
    list<string>::iterator i;
        for (i = functii.begin(); i != functii.end(); ++i)
        {       cout<<"functie:";
                out << *i;
                cout<<endl;
        }

        for (i = teste.begin(); i != teste.end(); ++i)
        {       cout<<"test:";
                out << *i;
                cout<<endl;
        }


}

ostream& operator<<(ostream& out,keylogger& a)
{
    a.afisare(out);
    return out;
}


//kernel-keylogger
class kernelkey:public keylogger,public rootkit{

protected:

    bool ascundefisier;

public:
    kernelkey(int rating, int zi, int luna, int an,string met, vector <string> r,bool ascundefisier);
    kernelkey(kernelkey& m);
    ~kernelkey();

     void afisare(ostream &out);
     void citire(istream &in);
     void tipmalware(){
      cout<<"Kernel-keylogger";
     };
      string tipmalware1(){
         string s = "kernel-keylogger";
     return s;
     };
    friend istream& operator>>(istream &in, kernelkey& a);
    friend ostream& operator<<(ostream &out, kernelkey& a);

};

kernelkey::kernelkey(int rating=0, int zi=0, int luna=0, int an=0,string met="", vector <string> r = vector<string>(),bool ascundefisier=false):Malware(rating,zi,luna,an,metodainfectare, registrii),keylogger(),rootkit(){
   // this->ascundefisier=ascundefisier;
}

kernelkey::~kernelkey(){
    ascundefisier=false;
}
void kernelkey::citire(istream &in)
{
    int n,i;
   Malware::citire(in);
   cout<<"dati numarul de functii:";
   cin>>n;
   string x;
   for (i = 0; i <n; i++)
        {
            {   cout<<"Dati o functie: ";
                cin>>x;
                this->functii.push_back(x);
            }
        }

    cout<<"dati numarul de stringuri semnificative";
    cin>>n;
       for (i = 0; i <n; i++)
        {
            {   cout<<"Dati un string: ";
                cin>>x;
                this->teste.push_back(x);
            }
        }
         cout<<"dati numarul de importuri:";
   cin>>n;

   for (i = 0; i <n; i++)
        {
            {   cout<<"Dati un import: ";
                cin>>x;
                this->importuri.push_back(x);
            }
        }

    cout<<"dati numarul de stringuri semnificative";
    cin>>n;
       for (i = 0; i <n; i++)
        {
            {   cout<<"Dati un string: ";
                cin>>x;
                this->stringsemnificativ.push_back(x);
            }
        }

}

istream& operator>>(istream &in, kernelkey& a)
{
    a.citire(in);
    return in;
}

void kernelkey::afisare(ostream &out)
{

    Malware::afisare(out);
    list<string>::iterator i;
        for (i = functii.begin(); i != functii.end(); ++i)
        {       cout<<"functie:";
                out << *i;
                cout<<endl;
        }

        for (i = teste.begin(); i != teste.end(); ++i)
        {       cout<<"test:";
                out << *i;
                cout<<endl;
        }
                for (i = importuri.begin(); i != importuri.end(); ++i)
        {       cout<<"import:";
                out << *i;
        }

        for (i = stringsemnificativ.begin(); i != stringsemnificativ.end(); ++i)
        {       cout<<"string:";
                out << *i;
        }


}

ostream& operator<<(ostream& out,kernelkey& a)
{
    a.afisare(out);
    return out;
}

class ransomware:public  Malware{

protected:

    int ratingcriptare;
    int procent;

public:
    ransomware(int rating, int zi, int luna, int an,string met, vector <string> r,int criptare, int procentu);
    ransomware(rootkit& m);
    ~ransomware();

     void afisare(ostream &out);
     void citire(istream &in);
     void tipmalware(){
      cout<<"ransomware";
     };
      string tipmalware1(){
         string s = "ransomware";
     return s;
     };
    friend istream& operator>>(istream &in, ransomware& a);
    friend ostream& operator<<(ostream &out, ransomware& a);

};

ransomware::ransomware(int rating=0, int zi=0, int luna=0, int an=0,string met="", vector <string> r = vector<string>(),int cripare=0,int procentu =0):Malware(rating,zi,luna,an,metodainfectare, registrii){
 this->ratingcriptare=cripare;
 this->procent=procentu;
}

ransomware::~ransomware(){
    this->ratingcriptare=0;
 this->procent=0;
}
void ransomware::citire(istream &in)
{
    int n,i;
   Malware::citire(in);
   cout<<"dati rating criptare";
   in>>ratingcriptare;
   cout<<"dati procent:";
   in>>procent;
}

istream& operator>>(istream &in, ransomware& a)
{
    a.citire(in);
    return in;
}

void ransomware::afisare(ostream &out)
{

    Malware::afisare(out);
    cout<<"rating criptare:";
    out<<ratingcriptare;
    cout<<"procent:";
    out<<procent;


}

ostream& operator<<(ostream& out,ransomware& a)
{
    a.afisare(out);
    return out;
}

class calculator{

  protected:
    const int icd;
    static int id;
    list <Malware*> lista1;
    int ratingfinal;

public:
    calculator():icd(++id){
    ratingfinal=0;

    }
    void adaugaMalinlista(Malware* &a){
    lista1.push_back(a);
    }

    const int returnid() const{
    return icd;
    }


    /*void afisareratingfinal(){
        int r=0,s;
        list<Malware*>::iterator i;
        for (i = lista1.begin(); i != lista1.end(); ++i)
        {
            if((*i)->tipmalware1()=="rootkit")
            {
                    for(s=0;s<(*i)->getlist().size();s++)
                    {
                        if ((*i).importuri[s]=="SSDT")
                            r=r+100;
                    }
            }
        }*/






};

int calculator::id=0;






void adg(Malware *&p, int &i) {
    int c;
    cout<<"\n";
    cout<<"1.rootkit \n"<<"2.keylogger \n"<<"3.kernel-key \n"<<"4.ransom \n";
    cout<<"Introduceti numarul dorit: "<<i+1<<": ";
    cin>>c;
    try{

            if(c==1){
                p=new rootkit;
                cin>>*p;
                i++;
            }
            else
                if (c==2){
                    p=new keylogger;
                    cin>>*p;
                    i++;
                }
                else
                    if(c==3){
                     p=new kernelkey;
                    cin>>*p;
                    i++;
                    }
                        else
                            if(c==3){
                     p=new ransomware;
                    cin>>*p;
                    i++;
                    }
                        else
                            throw 2;
    }
    catch (ColException *e){
        e->printareeroare();
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus un malware valid.\n ";
    }
}


//meniu inspirat din resursele laborantului MARIAN GUSATU
void outputm(){
    cout<<"Test de laborator - Stan Ana Maria GR 141\n";
    cout<<"~~~~~~~~~~~~~~Alegeti o actiune din meniu~~~~~~~~~~~~\n";
    cout<<"1. citirea si afisarea a n Malwareruri(upcast) \n";
    cout<<"2. adaugati un malware in calculator\n";
    cout<<"3. adaugati n malware in calculator";
    cout<<"4. \n";
    cout<<"5. \n";
    cout<<"0. EXIT.\n";
}
void meniu()
{
int o=0;
    do
    {
        calculator cal;

         outputm();

        cout<<"\n Alegeti numarul: ";
        cin>>o;

        if (o==1)
        {
            Malware **v;
    int n;
    cout<<"Introduceti numarul de obiecte citite: ";
    cin>>n;
        v=new Malware*[n];
        for(int i=0;i<n;i++)
            adg(v[i],i);

        cout<<"\nAfisam tipul articolului:\n";
        for(int i=0;i<n;i++){
            v[i]->tipmalware();
            cout<<"\n"<<*v[i];
            cout<<"--------------------------\n";
        }
        if (o==2)
        {
            int c;
            Malware *p;
    cout<<"\n";
    cout<<"1.rootkit \n"<<"2.keylogger \n"<<"3.kernel-key \n"<<"4.ransom \n";
    cout<<"Introduceti numarul dorit: "<<": ";
    cin>>c;
    try{

            if(c==1){
                p=new rootkit;
                cin>>*p;

            }
            else
                if (c==2){
                    p=new keylogger;
                    cin>>*p;

                }
                else
                    if(c==3){
                     p=new kernelkey;
                    cin>>*p;

                    }
                        else
                            if(c==3){
                     p=new ransomware;
                    cin>>*p;

                    }
                        else
                            throw 2;
        cal.adaugaMalinlista(p);
    }
    catch (ColException *e){
        e->printareeroare();
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus un laware valid.\n ";
    }
        }
        if (o==3)
        {  **v = new calculator*[n];

             int n,i;
            int c;
            Malware *p;
    cout<<"\n";
    cout<<"numarul de malwareuri";
    cin>>n;
    for (i=0;i<n;i++)
    {
    cout<<"1.rootkit \n"<<"2.keylogger \n"<<"3.kernel-key \n"<<"4.ransom \n";
    cout<<"Introduceti numarul dorit: "<<": ";
    cin>>c;


            if(c==1){
                p=new rootkit;
                cin>>*p;

            }
            else
                if (c==2){
                    p=new keylogger;
                    cin>>*p;

                }
                else
                    if(c==3){
                     p=new kernelkey;
                    cin>>*p;

                    }
                        else
                            if(c==3){
                     p=new ransomware;
                    cin>>*p;

                    }

        cal.adaugaMalinlista(p);
    }


        }
        if (o==4)
        {

        }
        if (o==5)
        {

        }
        if (o==0)
        {
            cout<<"\nProgramul se inchide\n";
        }
        if (o<0||o>5)
        {
            throw 'a';
        }
        cout<<"\n";
        system("pause");
        system("cls");
        }



    }
    while(o!=0);
}

int main()
{
    meniu();
    return 0;
}
