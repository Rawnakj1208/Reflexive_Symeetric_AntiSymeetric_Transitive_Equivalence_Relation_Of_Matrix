#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include <time.h>
int main(void)
{
    clock_t tic = clock();
    int **arr;
    int i,n,j,k,p,q;
    double time_spend;
     srand(time(0));
    printf("Enter the dimension of the matrix: ");
    scanf("%d",&n);
    arr = malloc (sizeof(int*) * n);
    for (i=0; i<n; i++)
    {
        arr[i] = calloc(n,sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        p=rand()%n;
        q=rand()%n;
        arr[p][q]=1;
    }
   for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            printf("%d ",arr[j][k]);
        }
        printf("\n");
    }
    int isequivalence=1;
    int isReflexive;
    for(i = 0; i < n;i++){//o(n)
        int isReflexive=1;
        for(j = 0; j < n;j++){
         if(arr[i][j]==0){
         isReflexive=0;
      }
    }
    }
    if(isReflexive==1){
        printf("Reflexive");
    }
    else{
        printf("Not Reflexive");
    }


    printf("\n");


    int isSymmetric=1;
    for(i = 0; i < n; i++)   //o(n^2)
    {
        for(j = 0; j < n; j++)
        {
            if(arr[i][j]!=arr[j][i])
                isSymmetric=0;
        }


        }
    if(isSymmetric==1){
        printf("Relation is Symeetric");
    }
    else{
        printf("Relation is not Symeetric");
    }

     printf("\n");


     int isAntiSymmetric=1;
    for(i = 0; i < n; i++)   //o(n^2)
    {
        for(j = 0; j < n; j++)
        {
            if(arr[i][j]!=0 &&arr[j][i]!=0 &&(i!=j))
                isAntiSymmetric=0;
        }


        }
    if(isAntiSymmetric==1){
        printf("Relation is AntiSymeetric");
    }
    else{
        printf("Relation is not AntiSymeetric");
    }

    printf("\n");

     int isTransitive =1;
    for(i = 0; i < n;i++) {   // o(n^3)
        for(j = 0; j < n;j++){
          for( int k=0;k<n;k++){
               if(arr[i][j] && arr[j][k] && !arr[k][i])
                 isTransitive=0;

          }
        }
    }

    if(isTransitive==1){
        printf("Relation is Transitive");
    }
    else{
        printf("Relation is not Transitive");
    }
    printf("\n");

    if(!isReflexive || !isTransitive || !isSymmetric)
    isequivalence=0;
    if(isequivalence==1){
        printf("Relation is Equivalence");
    }
    else{
        printf("Relation is not Equivalence");
    }
    printf("\n");

    clock_t toc = clock();

    float total_time = (double)(toc - tic)*1000 / CLOCKS_PER_SEC;
    printf("Time elapsed in milisecond: %f", total_time);
    return 0;
}

