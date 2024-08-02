#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool check[9] = {false};
    int i, j;

    // ROW CHECKS !!
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] >= '0' && board[i][j] <= '9') {
                if (check[board[i][j] - '1'] == true)
                    return false;
                else
                    check[board[i][j] - '1'] = true;
            }
        }
        memset(check, 0, sizeof(check));
    }

    // COLUMNS CHECKS !!
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[j][i] >= '0' && board[j][i] <= '9') {
                if (check[board[j][i] - '1'] == true)
                    return false;
                else
                    check[board[j][i] - '1'] = true;
            }
        }
        memset(check, 0, sizeof(check));
    }

    // 3x3 BOXES CHECKS !!
    int boxRow = 0 , boxCol = 0;
    for(boxRow = 0; boxRow < 9; boxRow +=3 ){
        for(boxCol = 0; boxCol < 9; boxCol +=3){
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    if(board[boxRow+i][boxCol+j] >= '0' && board[boxRow+i][boxCol+j] <= '9'){
                        if(check[board[boxRow+i][boxCol+j] - '1'] == true)
                            return false;
                        else
                            check[board[boxRow+i][boxCol+j] - '1'] = true;
                    }
                }
            }
            memset(check, 0, sizeof(check));
        }
    }

    return true;    
}


bool OPisValidSudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 9; i++) {
        bool rowSet[9] = { false };
        bool colSet[9] = { false };
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                if (rowSet[num]) {
                    return false;
                }
                rowSet[num] = true;
            }
            if (board[j][i] != '.') {
                int num = board[j][i] - '1';
                if (colSet[num]) {
                    return false;
                }
                colSet[num] = true;
            }
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            bool subBoxSet[9] = { false };
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    if (board[i + m][j + n] != '.') {
                        int num = board[i + m][j + n] - '1';
                        if (subBoxSet[num]) {
                            return false;
                        }
                        subBoxSet[num] = true;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    
    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    int *menfou;
    bool x = isValidSudoku(board,9,menfou);

    return 0;
}