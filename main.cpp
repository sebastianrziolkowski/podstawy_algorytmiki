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
    cout<<"Œrednia mlecznoœæ w stadzie:"<<sum/stado.n<<endl;
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

    for(int i=1;i<stado.n;i++)
    {
        if(stado.stado[i].mlecznosc>krowa.mlecznosc)
        {
            while(!index.empty())
            index.pop();
            index.push(i);
            krowa=stado.stado[i];
        }
        else if(stado.stado[i].mlecznosc==krowa.mlecznosc)
        {
            index.push(i);
        }
    }
    for(int i=0;i<index.size();i++)
    {
        cout<<"Rozmiar stosu"<<index.size()<<endl;
        int p = index.top();
        index.pop();
        cout<<"Najbardziej mleczna krowa to "<<stado.stado[p].imie <<" która daje "<< stado.stado[p].mlecznosc <<" mleka i ma "<< stado.stado[p].wiek << " lat."<<endl;
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

int main()
{
    //ZAD_5
    /*
    TKlient klient = SetData();
    GetData(klient);
    */

    //ZAD_6
    TStado stado = SetStado();
    AverageMilkiness(stado);
    Calves(stado);
    SupremeMilkiness(stado);
    MAsFirstLetter(stado);
    MilkinessHigherThan(stado, GetMilkness());

    return 0;
}
