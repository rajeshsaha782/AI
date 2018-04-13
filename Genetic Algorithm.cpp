#include<iostream>
#include <sstream>
#include <stdlib.h>
#include<math.h>
#include <time.h>
#include<string>
using namespace std;

string population[4]= {"01101","11000","01000","10011"};
int x[4];
int count_iterations=0;

template <typename T>
string NumberToString(T pNumber)
{
    ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}
int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) );
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}
void Decimal_Binary(int number)
{
    int remainder;

    if(number <= 1)
    {
        cout << number;
        return;
    }


    remainder = number%2;
    Decimal_Binary(number >> 1);//right shift
    cout << remainder;
}
int Binary_Decimal(string b)
{
    int d=0;
    for(int i=4,j=0; i>=0; i--,j++)
    {
        if(b[i]=='1')
        {
            d=d+pow(2,j);
        }

    }
    return d;
}
void sortPopulation()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(Binary_Decimal(population[j])<Binary_Decimal(population[j+1]))
            {
                swap(population[j],population[j+1]);

            }
        }
    }



}
void setX()
{
    sortPopulation();
    for(int i=0; i<4; i++)
    {
        x[i]=Binary_Decimal(population[i]);
        cout<<x[i]<<endl;
    }
    cout<<"----------------"<<count_iterations<<endl;
}
void cross_over(int p,int q,int position)
{
    string p1=population[p],q1=population[q];

    population[p]=p1.substr(0,position)+q1.substr(position,5-position);
    population[q]=q1.substr(0,position)+p1.substr(position,5-position);
}
void Inversion()
{
    int s;
    for(int i=0; i<4; i++)
    {
        string I,popo;
        s=random(0,3);
        popo=population[i];
        I=popo.substr(s,1);

        if(I=="0")
        {
            I="1";
        }
        else
        {
            I="0";
        }

        population[i]=popo.substr(0,s)+I+popo.substr(s+1,4-s);

        //cout<<s<<" "<<population[i]<<endl;
    }
}

void Genetic()
{
    setX();
    int s1=random(0,3),s2=random(0,3),position=random(0,3);
    //cout<<s1<<" "<<s2<<" "<<position<<endl;
    //cout<<population[s1]<<" "<<population[s2];
    cross_over(s1,s2,position);
    Inversion();
    //setX();
}


int main()
{
    // setX();
    bool f=true;


    while(f)
    {
        Genetic();
        count_iterations++;
        for(int i=0; i<4; i++)
        {
            if(x[i]==31)
            {
                f=false;
                cout<<"Found "<<x[i]<<" iterations="<<count_iterations<<endl;
                break;
            }
        }
    }




}
