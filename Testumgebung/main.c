#include <stdio.h>
#include <stdlib.h>
#include <time.h>




double getRandomNumber() {
    return (double)rand()/((double)RAND_MAX + 1);  //Random value between 0 and 1
}


void gl_mean ( double x , double * count , double * mean ) {
    *mean = (*count * *mean + x) / (*count + 1);


}

double getFloatingAverage(int *i, int *number) {
    double average = 1;
    srand(time(0) *(long)*i);           //the loop-counter is used as random seed

    for (int z = 0; z < *number; z++) { //number is used as loop limit to set the amount of repeats given to getRandomNumber
        gl_mean(getRandomNumber(), &z, &average);
    }

    return average;
}

int isLeapYear(int *year) {
    return (*year % 4 == 0 && !(*year % 100 == 0) || *year % 400 == 0); //if year % 4 = 0 AND not(year % 100 = 0) OR year % 400 = 0  --> Return 1 else 0
}


int main() {
int leapYeartest=0;
printf("Enter a year\n");
scanf("%d\n",&leapYeartest);
if (isLeapYear(&leapYeartest)){
    printf ("yo %d\n",leapYeartest);
}
else {printf("ne\n");}


    int number = 0, counter = 0;
printf("Seed for random numbers (between 1 and 1000) : \n");
scanf("%d\n",&number);


    for (int i = 0; i < number; i++) {
        printf("%f\n", getFloatingAverage(&i, &number));                   //probable reason why 2030'ish numbers
    }
    /*OLD METHOD
     *
     *
     */
    printf("Alte methode");
    srand (time(NULL));                                                   //echter zufall
    int a,r;
    long sum = 0;
    for (int z = 0; z<1000; z++) {                                     //neue schleife für durchschnitt
        sum=0;                                                           //summe auf null für immer neuen wert
        for (a = 0; a < 10000; a++) {
            r = rand() % 1000;
            //printf ("%d %d\n",a,r);                                      auskommentiert für kürzere laufzeit
            sum += r;
        }
        printf("%d %.1f\n",z, (float) sum / 10000);                         //float für genauere angabe /erste nachkommastelle
    }

    return 0;
    }
/*
 * TODO Find out why the output is always 2030'ish
 * Jimmy Neitzert 18.10.18 (22:23)
 *
 *
 */