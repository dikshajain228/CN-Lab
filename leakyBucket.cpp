#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>

#define bucketsize 512
using namespace std;

void bktInput(int packsize,int outputrate);
int main()
{
 int op,pktsize;
 cout<<"enter output rate :";
 cin>>op;
 for(int i=1;i<=5;i++)
 {
 usleep(rand()%1000);
 pktsize=rand()%1000;
 cout<<"\n packet no "<<i<<"\t packet size "<<pktsize<<"\n";
 bktInput(pktsize,op);
 }
 return 0;
 }
 
 void bktInput(int a,int b)
 {
  if(a>bucketsize)
  cout<<"overflow";
  else{
     usleep(500);
     while(a<b)
     {
     cout<<b<<" bytes outputted";
     a=a-b;
     usleep(500);
     }
  }
 }    
