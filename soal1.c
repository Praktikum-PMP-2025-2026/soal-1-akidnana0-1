#include <stdio.h>

void BubbleSort(int JumlahBilangan, int Bilangan[]){
   for (int i = 0; i < JumlahBilangan-1; i++){
       for (int j = 0; j < JumlahBilangan-i-1; j++){
           if (Bilangan[j] > Bilangan[j+1]){
               int temp = Bilangan[j];
               Bilangan[j] = Bilangan[j+1];
               Bilangan[j+1] = temp;
           }
       }
   }
}


int main(){
    int N = 0;
    int MAX = 0;
    scanf("%d", &N);
    int Array[N];


    for (int i = 0; i < N; i++){
        scanf("%d", &Array[i]);
    }
    for (int j = 0; j < N; j++){
        // int value_left;
        // int has_left = 1;
        // int value_right;
        // int has_right = 1;
        if (Array[j] == -1){
            if ((Array[j-1] != -1) && (Array[j+1] != -1)){
                Array[j] = (((double)Array[j-1] + (double)Array[j+1])/2);
            }
            else if ((Array[j-1] != -1) && (Array[j+1] == -1)){
                for (int k = 0; k < N; k++){
                    if (Array[j+k+1] != -1){
                        Array[j] = (((double)Array[j-1] + (double)Array[j+k+1])/2);
                        break;
                    }
                }
            }
            else if((Array[j-1] == -1) && (Array[j+1] != -1)){
                for (int k = 0; k < N; k++){
                    if (Array[j-k-1] != -1){
                        Array[j] = (((double)Array[j-k-1] + (double)Array[j+1])/2);
                        break;
                    }
                }
            }

        }
    }
    printf("RECOVERED ");
    for (int l = 0; l < N; l++){
        printf("%d ", Array[l]);
    }

    printf("\n");

    BubbleSort(N, Array);
    for (int p = 0; p < N; p++){
        if(Array[N-1]== -2){
            MAX = -2;
        }
        else if (Array[p] < -1){
            continue;
        }
        else {
            MAX = MAX + Array[p];
        }
    }

    printf("MAX_SUM %d", MAX);

    return 0;
}
