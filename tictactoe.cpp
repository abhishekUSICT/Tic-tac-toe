#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
char b[31][61];
void build()   // this function builds initial layout
{
   int i,j,f=0;
   for(j=0;j<=30;j++)
   {
      for(i=0;i<=60;i++)
      {
        if(j%10==0 && j!=0 && j!=30)
        b[j][i]='-';
        else
        b[j][i]=' ';
        if(i%20==0 && i!=0 && i!=60)
        b[j][i]='|';
      }
   }
}
void update(int a,int x) // updates the layout for every iteration
{
    int i,j;
    for(i=0;i<=30;i++)
    {
        for(j=0;j<=60;j++)
        {
            if(x==0)
            {
                if(a==1)
                {
                    if((i==2 || i==8) && (j>=4) && (j<=16))
                    b[i][j]='*';
                    if((j==4 || j==16) && i>=2 && i<=8)
                    b[i][j]='|';
                }
                else
                {
                    if(j==2*i && i>=2 && i<=8)
                    b[i][j]='\\';
                    if(2*i+j==20 && i>=2 && i<=8)
                    b[i][j]='/';
                }
            }
            else if(x==3)
            {
                if(a==1)
                {
                    if((i==12 || i==18) && (j>=4) && (j<=16))
                    b[i][j]='*';
                    if((j==4 || j==16) && i>=12 && i<=18)
                    b[i][j]='|';
                }
                else
                {
                    if(j==2*(i-10) && i>=12 && i<=18)
                    b[i][j]='\\';
                    if(2*i+j==40 && i>=12 && i<=18)
                    b[i][j]='/';
                }
            }
            else if(x==6)
            {
                if(a==1)
                {
                    if((i==22 || i==28) && (j>=4) && (j<=16))
                    b[i][j]='*';
                    if((j==4 || j==16) && i>=22 && i<=28)
                    b[i][j]='|';
                }
                else
                {
                    if(j==2*(i-20) && i>=22 && i<=28)
                    b[i][j]='\\';
                    if(2*(i-20)+j==20 && i>=22 && i<=28)
                    b[i][j]='/';
                }
            }
            else if(x==1)
            {
                if(a==1)
                {
                    if((i==2 || i==8) && (j>=24) && (j<=36))
                    b[i][j]='*';
                    if((j==24 || j==36) && i>=2 && i<=8)
                    b[i][j]='|';
                }
                else
                {
                    if(j-20==2*i && i>=2 && i<=8)
                    b[i][j]='\\';
                    if(2*i+j==40 && i>=2 && i<=8)
                    b[i][j]='/';
                }
            }
            else if(x==2)
            {
                if(a==1)
                {
                    if((i==2 || i==8) && (j>=44) && (j<=56))
                    b[i][j]='*';
                    if((j==44 || j==56) && i>=2 && i<=8)
                    b[i][j]='|';
                }
                else
                {
                    if(j-40==2*i && i>=2 && i<=8)
                    b[i][j]='\\';
                    if(2*i+j==60 && i>=2 && i<=8)
                    b[i][j]='/';
                }
            }
            else if(x==8)
            {
                if(a==1)
                {
                    if((i==22 || i==28) && (j>=44) && (j<=56))
                    b[i][j]='*';
                    if((j==44 || j==56) && i>=22 && i<=28)
                    b[i][j]='|';
                }
                else
                {
                    if(j-40==2*(i-20) && i>=22 && i<=28)
                    b[i][j]='\\';
                    if(2*i+j==100 && i>=22 && i<=28)
                    b[i][j]='/';
                }
            }
            else if(x==7)
            {
                if(a==1)
                {
                    if((i==22 || i==28) && (j>=24) && (j<=36))
                    b[i][j]='*';
                    if((j==24 || j==36) && i>=22 && i<=28)
                    b[i][j]='|';
                }
                else
                {
                    if(j-20==2*(i-20) && i>=22 && i<=28)
                    b[i][j]='\\';
                    if(2*i+j==80 && i>=22 && i<=28)
                    b[i][j]='/';
                }
            }
            else if(x==4)
            {
                if(a==1)
                {
                    if((i==12 || i==18) && (j>=24) && (j<=36))
                    b[i][j]='*';
                    if((j==24 || j==36) && i>=12 && i<=18)
                    b[i][j]='|';
                }
                else
                {
                    if(j-20==2*(i-10) && i>=12 && i<=18)
                    b[i][j]='\\';
                    if(2*i+j==60 && i>=12 && i<=18)
                    b[i][j]='/';
                }
            }
            else if(x==5)
            {
                if(a==1)
                {
                    if((i==12 || i==18) && (j>=44) && (j<=56))
                    b[i][j]='*';
                    if((j==44 || j==56) && i>=12 && i<=18)
                    b[i][j]='|';
                }
                else
                {
                    if(j-40==2*(i-10) && i>=12 && i<=18)
                    b[i][j]='\\';
                    if(2*i+j==80 && i>=12 && i<=18)
                    b[i][j]='/';
                }
            }
        }
    }
}
void print() // prints current layout
{
   int i,j;
   for(i=0;i<=5;i++)
   cout<<endl;
   for(j=0;j<=30;j++)
   {
      for(i=0;i<=10;i++)
      cout<<" ";
      for(i=0;i<=60;i++)
      cout<<b[j][i];
      cout<<endl;
   }
}
int main()
{
int a[9]={0},i=0,x,w=0;
build(); // initial
print(); // build and print
cout<<endl;
while(1)
{
    if(w%2==0)
    {
        cout<<"\tPlayer 1 : ";
        cin>>x;
        if(x<=9 && a[x-1]==0)
        a[x-1]=1;
        else
        {
            cout<<"\n\tEnter a valid number in range (1,9)\n";
            continue;
        }
    }
    else
    {
        cout<<"\tPlayer 2 : ";
        cin>>x;
        if(x<=9 && a[x-1]==0)
        a[x-1]=2;
        else
        {
            cout<<"\n\tEnter a valid number in range (1,9)\n";
            continue;
        }
    }
    w++;
    system("cls"); // clear screen
    update(a[x-1],x-1);
    print();
    cout<<endl;
    if(a[0]>0)
    {
        if(a[0]==a[1] && a[0]==a[2]) // horizontal
        {
            if(a[0]==1)
                cout<<"\tPlayer 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
        }
        if(a[0]==a[4] && a[0]==a[8]) // diagnol
        {
            if(a[0]==1)
                cout<<"Player 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
        }
        if(a[0]==a[3] && a[0]==a[6]) // vertical
        {
            if(a[0]==1)
                cout<<"Player 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
        }
    }
    if(a[4]>0)
    {
        if(a[2]==a[4] && a[4]==a[6]) // diagnol
        {
            if(a[4]==1)
                cout<<"Player 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
        }
        if(a[1]==a[4] && a[4]==a[7]) // vertical
        {
            if(a[4]==1)
                cout<<"Player 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
        }
        if(a[3]==a[4] && a[4]==a[5]) // horizontal
        {
            if(a[4]==1)
                cout<<"Player 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
        }
    }
    if(a[8]>0)
    {
         if(a[6]==a[7] && a[7]==a[8]) // horizontal
         {
             if(a[8]==1)
                cout<<"Player 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
         }
         if(a[2]==a[5] && a[5]==a[8]) // vertical
         {
             if(a[8]==1)
                cout<<"Player 1 wins ! ";
            else
                cout<<"Player 2 wins ! ";
            cout<<endl;
            getchar();
            break;
         }
    }
    for(i=0;i<9;i++) // if all boxes are filled or not
    {
       if(a[i]==0)
       break;
    }
    if(i==9) // if all boxes are filled and no one has won
    {
        cout<<"\n\tIt's a draw match !\n";
        getchar();
        break;
    }
}
return 0;
}
