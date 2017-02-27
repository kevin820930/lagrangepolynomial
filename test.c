#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include "mylagrange.h"

int main(){

    int i=0;
    int pointsnum=10;
    long double data[100][2];

    for(i=0;i<100;i++){
	data[i][0]=0;
	data[i][1]=0;
    }

    for (i=0;i<10;i++){
	data[i][0]=(i+2)*i;
	data[i][1]=i*i-1*(i-2)+i*i*i+5;
    }

    lagrange(data,pointsnum);


}

