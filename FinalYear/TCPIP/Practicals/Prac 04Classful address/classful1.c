#include<stdio.h>
#include<string.h>
#include <math.h>
double 
my_log(double x, int base) { 
    return log(x) / log(base); 
} 
int ClassA(){

}
int main(){
    char a[20];int mask[4];int array1[4];
    int i=0;
    int n,N,k,s,r;
    scanf("%s",a);
    char *arr = strtok(a,".");
    int array[20];
    while (arr != NULL)
    {
        array[i++] = atoi(arr);
        arr = strtok (NULL, ".");
    }
    printf("\n");
    printf("Enter no of subnets: \n");
    scanf("%d",&s);

    if(array[0]>191){
        N = 24+my_log(s, 2);
        r = N-24;
        array1[0]=255;
        array1[1]=255;
        array1[2]=255;
        if(r == 0){
            array1[3]=0;
        }
        else if(r == 1){
            array1[3]=128;
        }
        else if(r == 2){
            array1[3]=192;
        }
        else if(r == 3){
            array1[3]=224;        }
        else if(r == 4){
            array1[3]=240;
        }
        else if(r == 5){
            array1[3]=248;
        }
        else if(r == 6){
            array1[3]=252;
        }
        else if(r == 7){
            array1[3]=254;
        }
        int result[4];
    for ( i = 0; i < 4; i++)
    {
        result[i]=array[i]&array1[i];
    }
    for ( i = 0; i < 4; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
        


    }
    
}