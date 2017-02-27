#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "mylagrange.h"

void lagrange(long double indata[][2],int time){

    long double ans=0,tmp=0;
    long double finalanser[100];
    int i,j,power=0,choicenum;
    int havechoice[100];
    long double L0[100];
    choicenum=0;
    long double anser[100][100];
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            anser[i][j]=0;
	}
    }

    for(i=0;i<100;i++){
	havechoice[i]=0;
        L0[i]=1;
        finalanser[i]=0;
    }

    printf("initial:\n");
    for(i=0;i<time;i++){
        for(j=0;j<2;j++){
            printf("%Lf ",indata[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    calculate(indata,time,havechoice,anser,choicenum);

    for(i=0;i<time;i++){
	for(j=0;j<time;j++){
	    if(i!=j){
		tmp=indata[i][0]-indata[j][0];
	        L0[i]=L0[i]*tmp;	
	    }
	}
    }

    for(i=0;i<time;i++){
	for(j=0;j<time;j++){
	    finalanser[i]=finalanser[i]+((anser[j][i]*indata[j][1])/L0[j]);
	}
    }
    printf("\n");

    printf("f(x)=");
    for(i=0;i<time;i++){
	printf("%Lfx^%d",finalanser[i],time-i-1);
	if(i!=time-1 && finalanser[i+1]>=0){
	        printf("+");
	}
    }
    printf("\n");
    for(i=0;i<time;i++){
	for(j=0;j<time;j++){
            ans=ans+finalanser[j]*(pow(indata[i][0],(time-j-1)));
	}
	printf("y: %Lf=%Lf\n",indata[i][1],ans);
        ans=0;
    }
}

void calculate(long double indata[][2],int time,int havechoice[100],long double anser[100][100],int choicenum){
    int flag=1;
    int i=0,j=0;
    int count=0;
    if(choicenum!=time+1){
	if(choicenum==0 || choicenum==1){
	    i=0;
	}
	else{
	    i=havechoice[choicenum-1]+1;
	}
        for(;i<time;i++){
            for(j=0;j<choicenum;j++){ //ensure choice no repeat
	        if(i==havechoice[j]){
		    flag=0;
	        }
            }
            if(flag!=0){
		havechoice[choicenum]=i;
	        count=choicenum+1;
                calculate(indata,time,havechoice,anser,count);
		if(choicenum!=0){
		    int k;
		    long double multitemp=1;
		    for(k=1;k<count;k++){
			multitemp=multitemp*indata[havechoice[k]][0]*-1;
		    }
		    anser[havechoice[0]][choicenum]+=multitemp;
		}
	        else{
		    anser[havechoice[0]][0]=1;
		}
            }
	    flag=1;	
        }
    }
}
