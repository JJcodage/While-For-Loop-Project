#include <stdio.h>
#include <stdlib.h>




int main()
{


char fn[100];

int max,i,j,k;
j=0;
k=0;
FILE *myfile;
char filename[100];
gets(filename);
myfile = fopen(filename,"r");     

fscanf(myfile,"%d",&i);               
i++;
int array[i][i];
fscanf(myfile,"%d",&max);      // to take input from file

for(j=1;j<i;j++)
        for(k=1;k<i;k++)
                array[j][k]=0;    // array values which are ''0''

for(int counter=0;counter<max;counter++)
{
        fscanf(myfile,"%d %d",&j,&k);
        array[j][k]=1;
        array[k][j]=1;
}                                      // array values which are ''1''

for(int j=1;j<i;j++)
        for(int k=1;k<i;k++)
                printf("%d-%d   %d\n",j,k,array[j][k]);    //check part
                
/* missing normalizing part*/

float P[i],Pold[i];
for(j=0;j<i;j++)
P[j]=1/(float)i;
for(j=0;j<i;j++)
Pold[j]=P[j];       //float converting part

for(j=0;j<i;j++)
printf("%lf", P[j]);            

while(abs(P[1]-Pold[1])>=0.000001)
{for(j=0;j<i;j++)
                for(k=0;k<i;k++)
                                P[j]+=(float)array[j][k]*(float)Pold[k];   //£ part
                
for(j=0;j<i;j++)
Pold[j]=P[j];                                  //new value of P                     
}                                                    
                                

for(j=0;j<i;j++)
printf("\n%d ----- %lf\n", j,P[j]);        //last output
                             
system("PAUSE");

}


