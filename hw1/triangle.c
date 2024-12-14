#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

int part(int vetor[], int low, int high){
    int pivot = vetor[high];
    int i = (low-1);

    for(int j = low; j<=high - 1; j++){
        if(vetor[j]<pivot){
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i+1], &vetor[high]);
    return (i+1);
}

void qs(int vetor[], int low, int high){
    if(low<high){
        int indicepivot = part(vetor, low, high);

        qs(vetor, low, indicepivot-1);
        qs(vetor, indicepivot+1, high);
    }
}


int main(){

    int n;
    scanf("%d", &n);

    int segmentos[n];
    int cont0=0;
    int flag_val=0;
    for(int i=0; i<n; i++){
        scanf("%d", &segmentos[i]);
        
        if(segmentos[i]==0){
            cont0++;
        }
    }
    

    qs(segmentos, 0, n-1);
    
    /*for(int i=0; i<n; i++){
        printf("%d", segmentos[i]);
    }*/

    for(int i=0; i<n; i++){
        if(segmentos[i]==0 && n<4 || cont0>n/2){
            flag_val=0;
            printf("NO");
            return 0;
        }
        
        if(pow(segmentos[i],2)+ pow(segmentos[i+1],2)==pow(segmentos[i+2],2)){
            flag_val=1;
            printf("YES");
            return 0;
        }
        if(segmentos[i]+segmentos[i+1]>segmentos[i+2] && segmentos[i+1]+segmentos[i+2]>segmentos[i] && segmentos[i]+segmentos[i+2]>segmentos[i+1]){
            flag_val=1;
            printf("YES");
            return 0;
        }
        if(segmentos[i]==segmentos[i+1] && segmentos[i]==segmentos[i+2]){
            flag_val=1;
            printf("YES");
            return 0;
        }
        else{
            flag_val=0;
        }
    }

    if(flag_val==1){
        printf("YES");
    }
    else printf("NO");



    return 0;
}