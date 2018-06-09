#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;


//Zad_5

struct TAdres
{
    string ulica ;
    int nrdom, nrmieszk;
};

struct TKlient
{
    string imie, nazwisko;
    TAdres adres;
};

TKlient SetData()
{
    TKlient klient;
    cout<<"Podaj imie:";
    cin>>klient.imie;
    cout<<"Podaj nazwisko:";
    cin>>klient.nazwisko;
    cout<<endl<<"Podaj ulice:";
    cin>>klient.adres.ulica;
    cout<<endl<<"Podaj numer domu:";
    cin>>klient.adres.nrdom;
    cout<<endl<<"Podaj numer mieszkania:";
    cin>>klient.adres.nrmieszk;
    cout<<endl;
    return klient;
}

void GetData(TKlient klient)
{
    cout<<"Imie: "<<klient.imie<<endl;
    cout<<"Nazwisko: "<<klient.nazwisko<<endl;
    cout<<"Ulica: "<<klient.adres.ulica<<endl;
    cout<<"Numer domu: "<<klient.adres.nrdom<<endl;
    cout<<"Numer mieszkania: "<<klient.adres.nrmieszk<<endl;
}


//Zad_6

    const int nmax=50;

    struct TKrowa
    {

        string imie;
        double wiek;
        double mlecznosc;
    };

    struct TStado
    {
        int n;
        TKrowa stado[nmax];
    };

TStado SetStado()
{
    TStado stado;
    cout<<"Rozmiar stada:";
    cin>>stado.n;
    if(stado.n>0)
    {
        for(int i=0;i<stado.n;i++)
        {
            cout<<"Imie "<<i+1<<" krowy:";
            cin>>stado.stado[i].imie;
            cout<<endl<<"Wiek krowy:";
            cin>>stado.stado[i].wiek;
            cout<<endl<<"Mlecznosc krowy:";
            cin>>stado.stado[i].mlecznosc;
            cout<<endl;
        }
    }
    return stado;
}

void AverageMilkiness(TStado stado)
{
    double sum=0;

    for(int i=0;i<stado.n;i++)
    {
        sum=sum+stado.stado[i].mlecznosc;
    }
    cout<<"Srednia mlecznosc w stadzie:"<<sum/stado.n<<endl;
}

void Calves(TStado stado)
{
    double sum=0;

    for(int i=0;i<stado.n;i++)
    {
        if(stado.stado[i].wiek<2)
            sum++;
    }
    cout<<"W stadzie jest "<<sum<<" mlodych krowek"<<endl;
}

void SupremeMilkiness(TStado stado)
{
    stack <int> index;
    TKrowa krowa = stado.stado[0];
    index.push(0);

    for(int i=1;i<stado.n;i++)
    {
        if(stado.stado[i].mlecznosc>krowa.mlecznosc)
        {
            while(!index.empty())
                {
                    index.pop();
                }
            index.push(i);
            krowa=stado.stado[i];
        }
        else if(stado.stado[i].mlecznosc==krowa.mlecznosc)
        {
            index.push(i);
        }
    }
    while(!index.empty())
    {
        int p = index.top();
        index.pop();
        cout<<"Najbardziej mleczna krowa to "<<stado.stado[p].imie <<" ktora daje "<< stado.stado[p].mlecznosc <<" mleka i ma "<< stado.stado[p].wiek << " lat."<<endl;
    }
}


void Youngest(TStado stado)
{
    stack <int> index;
    TKrowa krowa = stado.stado[0];
    index.push(0);

    for(int i=1;i<stado.n;i++)
    {
        if(stado.stado[i].wiek<krowa.wiek)
        {
            while(!index.empty())
                {
                    index.pop();
                }
            index.push(i);
            krowa=stado.stado[i];
        }
        else if(stado.stado[i].wiek==krowa.wiek)
        {
            index.push(i);
        }
    }
    while(!index.empty())
    {
        int p = index.top();
        index.pop();
        cout<<"Najmlodsza krowa to "<<stado.stado[p].imie <<" ktora daje "<< stado.stado[p].mlecznosc <<" mleka i ma "<< stado.stado[p].wiek << " lat."<<endl;
    }
}

void GetStado(TStado stado)
{
    cout<<"Rozmiar stada wynosi:"<<stado.n<<"."<<endl;
    for(int i=0;i<stado.n;i++)
    {
        cout<<"Krowa numer: "<<i+1<<endl;
        cout<<"Imie: "<< stado.stado[i].imie<<endl;
        cout<<"Mlecznosc: "<<stado.stado[i].mlecznosc<<endl;
        cout<<"Wiek: "<<stado.stado[i].wiek<<endl;
    }
}

void MAsFirstLetter(TStado stado)
{
    int sum=0;

    for(int i=0;i<stado.n;i++)
    {
        if(stado.stado[i].imie[0]=='M')
            sum++;
    }
    cout<<"W stadzie jest "<<sum<<" krow na litere M"<<endl;
}

double GetMilkness()
{
    double milkness;
    cout<<"Podaj mlecznosc:"<<endl;
    cin>>milkness;
    return milkness;
}

void MilkinessHigherThan(TStado stado, double milkness)
{
    int sum=0;

    for(int i=0;i<stado.n;i++)
    {
        if(stado.stado[i].mlecznosc>milkness)
            sum++;
    }
    cout<<sum<< " ilosc krow dajacych wiecej mleka niz " << milkness<<endl;
}


//ZAD_10

int HEX(int n)
{
        if(n>0)
     {
         HEX(n/16);
         if(n%16>9)
            switch(n%16)
            {
               case 10:
                  cout<<"A"; break;
               case 11:
                  cout<<"B"; break;
               case 12:
                  cout<<"C"; break;
               case 13:
                  cout<<"D"; break;
               case 14:
                  cout<<"E"; break;
               case 15:
                  cout<<"F"; break;
            }
         else
               cout << n%16;
     }
}


//ZAD_11
int wyswietl(int n, int p)
{
    if(p>0 && p<11)
    {
        if(n>0)
     {
        wyswietl(n/p,p);
        cout << n%p;
     }
    }
    else cout<<"Wrong second input"<<endl; return 0;
}

//ZAD_13
int zad_13(int n)
{
    if(n==0) return 2;
    if(n==1) return 1;
    if(n>=2) return (2/(2+zad_13(n-1)*zad_13(n-2)));
}

int main()
{
    //ZAD_5
    /*
    TKlient klient = SetData();
    GetData(klient);
    */

    //ZAD_6
    //TStado stado = SetStado();
    //AverageMilkiness(stado);
    //Calves(stado);
    //SupremeMilkiness(stado);
    //MAsFirstLetter(stado);
    //MilkinessHigherThan(stado, GetMilkness());
    //Youngest(stado);


    //ZAD_10
//    HEX(50000);

    //ZAD_11
// wyswietl(100,5);
    //ZAD_13
//      cout<<"Zad 13: "<< zad_13(10)<<endl;

    //PLIKI
    //ZAD_3
    //ZAD_7
    //ZAD_9
    return 0;
}
