#include <stdio.h>
#include <stdlib.h>


void gameBoard(char board[3][3]){
    printf("\t  1      2      3\n");
     printf("\t------------------\n");
  for(int i=0;i < 3;i++){
    printf("\t %c   | %c   | %c   |\n",board[i][0],board[i][1],board[i][2]);
    printf("\t------------------\n");
  }
}
int isRowAndColValid(int value,char name[8]){
     while(value > 3 || value < 1){
        printf("Invalid range for %s:",name);
        scanf("%d",&value);
    }
    return value;
}

int checkWinner(char board[3][3]){
    int gameEnd = 0;
    char winner = '\0';
   for(int i=0; i < 3 ; i++){
    if(board[i][0]!= '\0' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
        winner = board[i][0];
     }
   }
   for(int i=0; i < 3 ; i++){
     if (board[0][i]!= '\0' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
        winner = board[0][i];
     }
   }
   if (board[0][0]!= '\0' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
      winner = board[0][0];
   }
   if(board[0][2]!= '\0' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
      winner = board[0][2];
   }

   if(winner == 'X'){
      printf("Player 1 won\n");
      gameEnd = 1;
    }
    else if(winner == 'O'){
      printf("Player 2 won\n");
      gameEnd = 1;
    }
   return gameEnd;
}

int main(){
    char mainboard[3][3] = {0};
    int playtimes = 0;
    int row = 0;
    int col = 0;
    char playerSign = 'X';
    int gameEnd = 0;
    int playerNumber =1;
    printf("Welcome to the tic tac toe game \n\n");
    gameBoard(mainboard);
    while(gameEnd == 0 && playtimes <= 9){
        printf("Player %d select your row:",playerNumber);
        scanf("%d",&row);
        row = isRowAndColValid(row,"row");
        printf("Player %d select your column:",playerNumber);
        scanf("%d",&col);
        col=isRowAndColValid(col,"column");
        system("cls");

        while(mainboard[row-1][col-1] != '\0'){
            gameBoard(mainboard);
            printf("Box contains a letter\n");
            printf("Player %d select your row:",playerNumber);
            scanf("%d",&row);
            row=isRowAndColValid(row,"row");
            printf("Player %d select your column:",playerNumber);
            scanf("%d",&col);
            col=isRowAndColValid(col,"column");
            system("cls");
        }
        mainboard[row-1][col-1] =  playerSign;
        if(playerSign == 'X'){
            playerNumber = 2;
            playerSign = 'O';

        }
        else{
            playerNumber = 1;
            playerSign = 'X';
        }
        gameBoard(mainboard);
        gameEnd = checkWinner(mainboard);
        if(playtimes == 9 && gameEnd == 0){
            printf("It's a draw");
            gameEnd = 1;
        }
        else{
          playtimes++;
        }
    }
    return 0;
}

