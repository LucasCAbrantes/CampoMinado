#include <iostream>
#include<stdlib.h>
#include <time.h>
#define Nmax 40
using namespace std;
void campoMinasUsuario(char M[Nmax][Nmax],int n,int m)
{

    for (int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            M[i][j]='.';

}

void campoNull(int M[Nmax][Nmax],int n,int m,int minasmax)
{
    int cont=0;
    for (int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            M[i][j]=0;

}
void Mostrarcampo(char M[Nmax][Nmax],int n,int m)
{
int linha=1;
    for (int i=0; i<n; i++)
    {
    cout << linha << "  ";
    if (linha<10)
    cout<<" ";

        for(int j=0; j<m; j++)
        {
            cout<<M[i][j];

        }
        cout<<endl;
        linha++;
    }
}
void GerarMinas(int M[Nmax][Nmax],int n,int m,int minasmax)
{
    int x,y;
    for(int i=0; i<minasmax; i++)
    {
        x=rand()%n;
        y=rand()%m;
        M[x][y]=1;

    }
}
int main()
{
    int Campo[Nmax][Nmax]= {}, n,m,nivel,Minasmax,minascont=0;
    char campoUsuario[Nmax][Nmax];



    cout <<"Escolha o nivel de dificuldade "<<
         endl<<"1-Iniciante 2-Intermediario";
    cin>>nivel;

    if(nivel==1)
    {
        n=8;
        m=n;
        Minasmax=10;
    }
    if(nivel==2)
    {
        n=16;
        m=n;
        Minasmax=40;

    }
    srand(time(NULL));
    campoNull(Campo,n,m,Minasmax);
    GerarMinas(Campo,n,m,Minasmax);
    campoMinasUsuario(campoUsuario,n,m);
    Mostrarcampo(campoUsuario,n,m);


    return 0;
}
