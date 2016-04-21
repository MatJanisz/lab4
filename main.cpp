#include <iostream>
#include "math.h"
#include <cstdlib>
using namespace std;
void to_digit(int n, int tab[])
{
   for(int i=5;i>=0;i--)
   {
       tab[i]=n % 10;
       n/=10;
   }
}
bool check_0_1(int n)
{
    while(n)
    {
        if ((n%10)!=1 && (n%10)!=0) return false;
        n/=10;
    }
    return true;
}
int product_global;
int lookfor_k(int n)
{
    int product=0, numerator=1;
    while(product<1000000) //szukam liczby k w zakresie <1-100000>
    {
        product=n*numerator;
        if(check_0_1(product))
        {
            product_global=product;
            return numerator;
        }
        numerator++;
    }
    return 0;
}

void write(int tab[])
{
    string single[]={"","jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"};
    string decimals[]={"","dziesiec","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat",
    "siedemdziesiat","osiemdziesiat","dziewiecdziesiat"};
    string dozen[]={"dziesiec","jedenascie","dwanasie","trzynascie","czternascie","pietnascie","szesnascie","siedemnascie",
    "osiemnascie","dziewietnascie"};
    string hundreds[]={"","sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset",
    "dziewiecset"};
    // na poczatku zapis slowny dla pierwszych 3 liczb
    if(tab[0]==0 && tab[1]==0 && tab[2]==0)
        cout<<"";
    else
        {
            cout<<hundreds[tab[0]]<<" ";
            if(tab[1]!=1)
            {
                cout<<decimals[tab[1]]<<" "<<single[tab[2]]<<" ";
            }
            else
                cout<<dozen[tab[2]]<<" ";
        if(tab[2]>1 && tab[2]<5) cout<<"tysiace ";
        else
        {
            if(tab[1]==1) cout<<"tysiecy ";
            else
                if(tab[0]==0 && tab[1]==0 && tab[2]==1)
                cout<<"tysiac ";
                    else cout<<"tysiecy ";
        }
        }
// algorytm analogiczny do powyzszego dla kolejnych 3 liczb
        if(tab[3]==0 && tab[4]==0 && tab[5]==0)
        cout<<"";
    else
        {
            cout<<hundreds[tab[3]]<<" ";
            if(tab[4]!=1)
            {
                cout<<decimals[tab[4]]<<" "<<single[tab[5]]<<" ";
            }
            else
                cout<<dozen[tab[5]]<<" ";
        }
    if(tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==0 && tab[4]==0 && tab[5]==0) cout<<" zero";
    cout<<endl;
}
int main(int argc, char *argv[])
{
    int digit[6];
    int pom=lookfor_k(atoi(argv[1]));
    cout<<"poszukiwane k to: "<<pom<<" ";
    to_digit(pom,digit);
    write(digit);
    cout<<"iloczyn: "<<product_global<<" ";
    to_digit(product_global,digit);
    write(digit);
    return 0;
}