#include <iostream>
#include <stdlib.h>
#include <stack>
#include <fstream>

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

bool average(string fileName)
{
    ifstream file;
    file.open(fileName.c_str());
    if(!file.good())
        return false;
    int even=0, odd=0, number;
    while(file.good())
    {
        file>>number;
        if(number%2==0)
            even+=number;
        else odd+=number;
    }
    cout<<"Even: "<<even<<" Odd: "<<odd<<endl;
}

int zad_7(string fileName)
{
    int counter=0;
    string text,temp;
    ifstream file;
    file.open(fileName.c_str());

    while (!file.eof())
    {
        getline (file, temp);
        text.append (temp);
    }

    for(int i=0;i<text.size();i++)
    {
        if(text[i]=='!' && text[i+1]=='=')
            counter++;
    }
    return counter;
}


//ZAD_9

void zad_9(string fileName)
{
    int caseCounter[26];
    int HcaseCounter[26];
    for(int i=0;i<26;i++){
        caseCounter[i]=0;
        HcaseCounter[i]=0;
    }
    int spaces=0;
    int numbers=0;
    int counter=0;
    int lowerCase=0;
    int highCase=0;
    string text,temp;
    ifstream file;
    file.open(fileName.c_str());

    while (!file.eof())
      {
        getline (file, temp);
        text.append (temp);
      }
    cout<<"Size: "<<text.size()<<endl;

    for(int i=0;i<text.size();i++)
    {
        if(text[i]>96 && text[i]<123)
        {
            lowerCase++;
            caseCounter[(text[i]-97)]++;
        }

        if(text[i]>64 && text[i]<91)
        {
            highCase++;
            HcaseCounter[(text[i]-65)]++;
        }

        if(text[i]>47 && text[i]<59)
        {
            numbers++;
        }
        if(text[i]==32)
            spaces++;

    }

    cout<<"Lower case: "<<lowerCase<<endl<<endl;
    for(int i=0;i<26;i++)
    {
        cout<<char(i+97)<<": "<<caseCounter[i]<<endl;
    }
    cout<<endl<<endl;
    for(int i=0;i<26;i++)
    {
        cout<<char(i+65)<<": "<<HcaseCounter[i]<<endl<<endl;
    }
    cout<<"Letter: "<<highCase+lowerCase<<endl<<endl;
    cout<<"Numbers: "<<numbers<<endl<<endl;
    cout<<"Spaces: "<<spaces<<endl<<endl;
}


int main()
{
    //ZAD_5

    TKlient klient = SetData();
    GetData(klient);

    //ZAD_6
    TStado stado = SetStado();
    AverageMilkiness(stado);
    Calves(stado);
    SupremeMilkiness(stado);
    MAsFirstLetter(stado);
    MilkinessHigherThan(stado, GetMilkness());
    Youngest(stado);


    //ZAD_10
    cout<<endl;
    HEX(50000);

    //ZAD_11
    wyswietl(100,5);
    //ZAD_13
    cout<<"Zad 13: "<< zad_13(10)<<endl;

    //PLIKI
    //ZAD_3
    average("liczbyC.txt");
    //ZAD_7
    cout<<zad_7("test_7.txt")<<endl;
    //ZAD_9
    string fileName;
    cout<<"Podaj nazwe pliku do zad_9->pliki: "; cin>>fileName; cout<<endl;
    zad_9(fileName+".txt");
    return 0;
}
