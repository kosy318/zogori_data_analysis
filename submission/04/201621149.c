#include "timebomb.h"
#include <stdlib.h>

typedef struct Tree{
    int self;
    struct Tree *left;
    struct Tree *right;
} Tree;

int main(){
    box_ready();

    int N, result, this;
    N = box_size();

    int N2 = 0;
    int double_box[20] = {1};
    while (double_box[N2] < N){
        double_box[N2 + 1] = double_box[N2] * 2;
        N2++;
    }
    N2++;

    Tree ***First = (Tree ***)malloc(sizeof(Tree **) * N2);
    First[0] = (Tree **)malloc(sizeof(Tree *) * N);
    for (int i = 0; i < N; i++){
        First[0][i] = (Tree *)malloc(sizeof(Tree));
        First[0][i]->left = First[0][i]->right = NULL;
        First[0][i]->self = i+1;
    }

    int N3 = N;
    for (int i = 1; i < N2; i++){
        int Nend = (N3 + 1) / 2;
        First[i] = (Tree **)malloc(sizeof(Tree) * Nend);

        for (int j = 0; j < Nend; j++){
            First[i][j] = (Tree *)malloc(sizeof(Tree));
            
            First[i][j]->left = First[i - 1][j * 2];
            if (j*2+1 >= N3){
                First[i][j]->right = NULL;
                First[i][j]->self = First[i - 1][j * 2]->self;
            }else{
                First[i][j]->right = First[i - 1][j * 2 + 1];
                int left_idx = First[i - 1][j * 2]->self;
                int right_idx = First[i - 1][j * 2 + 1]->self;

                First[i][j]->self = (box_comp(left_idx, right_idx) == 1) ? left_idx : right_idx;
            }
        }

        N3 = (N3 + 1) / 2;
    }

    Tree *now = First[N2 - 1][0];
    Tree *next;
    int second_max;

    if (now->self == now->left->self){
        next = now->left;
        second_max = now->right->self;
    }
    else{
        next = now->right;
        second_max = now->left->self;
    }

    while(now->left != NULL || now->right != NULL){
        next = now->left;
        if (now->right != NULL){
            int check_val;
            if (now->self == now->left->self){
                next = now->left;
                check_val = now->right->self;
            }
            else{
                next = now->right;
                check_val = now->left->self;
            }
            second_max = (box_comp(second_max, check_val) == 1) ? second_max : check_val;
        }
        now = next;
    }

    box_report(second_max);
    return 0;
}
