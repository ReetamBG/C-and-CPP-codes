#include <stdio.h>

int main(){
    int matrix[4][4] = {{0, 1, 1, 0},
                         {1, 0, 0, 1},
                         {1, 0, 0, 0},
                         {0, 1, 0, 0}};
    
    char alphabet[4] = {'A', 'B', 'C', 'D'};

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(matrix[i][j] == 1){
                printf("%c is connected to %c\n", alphabet[i], alphabet[j]);
            }
        }
    }

    return 0;
}