//SEAN DROKE
//CIS 3374
//LAB 7


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void CreateBoard(void);
char CurrentPlayer(void);
void ChangePlayer(void);
void MakeMoveF(void);
void MakeMove(int column, int row);
bool SpaceInUse(int column, int row);

char board[3][3];
char currentPlayer;
int column;
int row;

int main(void){

    //UNIT TEST 1 - CREATE BOARD
    CreateBoard();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            assert(board[i][j] == 'z');
        }
    }

    //UNIT TEST 2 - ASSERT CURRENT PLAYER IS X
    assert(CurrentPlayer() == 'x');

    //UNIT TEST 3 - ASSERT CURRENT PLAYER IS O
    ChangePlayer();
    assert(CurrentPlayer() == 'o');
    ChangePlayer();

    //UNIT TEST 4 - ASSERT THAT CURRENT PLAYER PLACES AN X ON THE BOARD
    MakeMove(2,2);
    assert(board[2][2] == 'x');
    
    //UNIT TEST 5 - ASSERT THAT CURRENT PLAYER PLACES AN O ON THE BOARD
    ChangePlayer();
    MakeMove(1,1);
    assert(board[1][1] == 'o');

    //UNIT TEST 6 - ASSERT THAT SPOT IS UNOCCUPIED
    assert(SpaceInUse(0,0) == false);

    printf("6/6 Tests Passed");

}

void CreateBoard(void){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = 'z';
        }
    }
}

char CurrentPlayer(void){
    if(!currentPlayer){
        currentPlayer = 'x';
    }
    return currentPlayer;
}

void ChangePlayer(void){
    if(currentPlayer == 'x'){
        currentPlayer = 'o';
    }
    else if(currentPlayer == 'o'){
        currentPlayer = 'x';
    }
    else{
        printf("Error Null or Unknown Player");
    }
}


//FUNCTIONAL METHOD FOR ACCEPTANCE TESTING
void MakeMoveF(void){
    printf("\nEnter the column you'd like to mark: ");
    scanf("%d", &column);
    printf("\nEnter the row you'd like to mark: ");
    scanf("%d", &row);

    if(!SpaceInUse(column, row)){
        board[column][row] = CurrentPlayer();
    }
    else{
        printf("\nError in column/row validation, please try again");
    }
}

//UNIT TESTED METHOD
void MakeMove(int column, int row){
    if(!SpaceInUse(column, row)){
        board[column][row] = CurrentPlayer();
    }
    else{
        printf("\nError in column/row validation, please try again");
    }
}

bool SpaceInUse(int column, int row){
    if(board[column][row] == 'z'){
        return false;
    }
    else{
        return true;
    }
}
