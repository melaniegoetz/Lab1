#include <iostream>
#include <math.h>

int main(int argC, char** argB) {

    if (argC != 6) {
        printf("Wrong number of parameters");
        exit(0);
    }

    int N = atoi(argB[1]);  //atoi casts from string to int

    if (!(N>0 && N<100000000)) {
        printf("The value of N is incorrect");
        exit(0);
    }

    // Declare variables
    FILE *finputA;
    FILE *finputB;
    FILE *foutputC;
    FILE *foutputD;
    char car;

    finputA = fopen(argB[2], "r");
    if (finputA == NULL)
    {
        printf("Error while opening fileA.txt \n");
        return -1;
    }

    finputB = fopen(argB[3], "r");
    if (finputB == NULL)
    {
        printf("Error while opening fileB.txt \n");
        return -1;
    }

    foutputC = fopen(argB[4], "w");
    if (foutputC == NULL)
    {
        printf("Error while opening fileC.txt \n");
        return -1;
    }

    foutputD = fopen(argB[5], "w");
    if (foutputD == NULL)
    {
        printf("Error while opening fileD.txt \n");
        return -1;
    }


    float varA;
    float varB;
    int cols = 0;

    while (fscanf(finputA, "%f", &varA) != EOF && fscanf(finputB, "%f", &varB) != EOF) {

        printf("%.6f", varA);
        printf(" \n");
        printf("%.6f", varB);
        printf(" \n");


        if(varA <  varB) {
            fprintf(foutputD, "%g ", varA);
        }

        else if(varB < varA) {
            fprintf(foutputD, "%g ", varB);
        }


        else if(varB == varA) {
            fprintf(foutputD, "%g ", varB);
        }

        else {
            fprintf(foutputD, "%g ", NAN);
        }

        cols++;
        if (cols % N == 0) {
            fprintf(foutputD,"\n");
        }
    }


    float a; //a
    float b; //b
    int col = 0;
    while (fscanf(finputA, "%f", &a) != EOF && fscanf(finputB, "%f", &b) != EOF) {

        if(a == 0 || b == 0){
            fprintf(foutputC, "%g ", 0.0);
        }
        else if(a == INFINITY || a == -INFINITY || b == INFINITY || b == -INFINITY) {
            fprintf(foutputC, "%g ", NAN);
        }
        //else : NAN = NAN


        col++;
        if (cols % N == 0) {
            fprintf(foutputD,"\n");
        }
    }


    return 0;
}