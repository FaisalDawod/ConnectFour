/*
Connect Four --Full Game--
This game is built using the C programming language, using functions, each of which has a specific function.
©Copyright: Faisal Ahmad Dawod
*/
#include <stdio.h>

int checkWin(char grid[][7]){

  // checking rows
  for(int i=0;i<6;i++){
    char current=grid[i][0];
    int rowCnsec=0;
    for(int j=0;j<7;j++){
      if(current==grid[i][j] && grid[i][j] != ' '){
        rowCnsec++;
        if(rowCnsec==4)
          return 1;
      }
      else{
        current=grid[i][j];
        rowCnsec=1;
      }
    }
  }

  // check columns
  for(int j=0;j<7;j++){
    char current=grid[0][j];
    int colConsec=0;
    for(int i=0;i<6;i++){
      if(current==grid[i][j] && grid[i][j] != ' '){
        colConsec++;
        if(colConsec==4)
          return 1;
      }
      else{
        current=grid[i][j];
        colConsec=1;
      }
    }
  }
 
  // check top Left side: going upright
  for(int i=5;i>=0;i--){
    int consecutive=0;
    int y=i;
    int x=0;
    char current=grid[y][x];
    while(y>=0){
      if(grid[y][x]==current && grid[y][x] != ' '){
        consecutive++;
        if(consecutive==4)
          return 1;
      }
      else{
        consecutive=1;
        current=grid[y][x];
      }
    x++;
    y--;
    }
  }

  // check bottom right side: going upright
  for(int j=0;j<7;j++){
    int y=6-1;
    int x=j;
    int consecutive=0;
    int current=grid[y][x];
 
    while(x<6 && y>=0){
      if(grid[y][x]==current && grid[y][x] != ' '){
        consecutive++;
        if(consecutive==4)
          return 1;
      }
      else{
        consecutive = 1;
        current = grid[y][x];
      }
    x++;
    y--;
    }
  }
 
  // check bottom left side going up-left
  for(int j=7-1;j>0;j--){
    int x=j;
    int y=6-1;
    int current=grid[y][x];
    int consecutiveCount=0;
 
    while(x>=0 && y>=0){
      if(grid[y][x]==current && grid[y][x] != ' '){
        consecutiveCount++;
        if (consecutiveCount == 4)
          return 1;
      }
      else{
        consecutiveCount = 1;
        current = grid[y][x];
      }
    x--;
    y--;
    }
  }

  // check bottom right side going up-left
  for(int row=1;row<6;row++){
    int x =7-1;
    int y =row;
    int consecutive=0;
    int current=grid[y][x];
 
    while(y>=0){
      if(grid[y][x]==current && grid[y][x] != ' '){
        consecutive++;
        if(consecutive==4)
          return 1;
      }
      else{
        consecutive = 1;
        current = grid[y][x];
      }
    x--;
    y--;
    }
  }

  return 0;
}

// a function to show the grid
void printBoard(char grid[][7]){
  for (int i=0;i<6;i++){
    for (int j=0; j<7;j++){
      printf("|%c",grid[i][j]);
    }
  printf("|\n");
  }
}

void initBoard(char s[6][7]){
  //fill the grid with blank space
  for (int i=0;i<6;i++){
    for (int j=0;j<7;j++){
      s[i][j] = ' ';
    }
  }
}

//prompt player 1
void player1(char grid[][7], int x, int y){
  printBoard(grid);
    
  printf("Player 1 please drop a red disk at column (0–6): ");
  scanf("%d",&y);
  if (grid[x][y]==' ')
    grid[x][y]='R';
  else{
    while (grid[x][y] != ' ')x--;
    grid[x][y]='R';
  }
}

//prompt player 2
void player2(char grid[][7],int x,int y){
  printBoard(grid);
 
  printf("Player 2 please drop a yellow disk at column (0–6): ");
  scanf("%d",&y);
  if (grid[x][y] == ' ')
    grid[x][y]='Y';
  else{
    while (grid[x][y] != ' ')x--;
    grid[x][y]='Y';
  }     
}

//check if it's a draw
int cheakDraw(char grid[][7]){
  int count=0;
  for (int i=0;i<7;i++){
    if (grid[0][i] != ' ' && grid[1][i] != ' ' && grid[2][i] != ' ' && grid[3][i] != ' ' && grid[4][i] != ' ' && grid[5][i] != ' '){
      count++;
    }
  }
    if(count==7){
      return 1;
    }
  return 0;
}


int main(void) {

  char grid[6][7];
  initBoard(grid);
  
  //to check the winner
    int winner1 = 0;
    int winner2 = 0;

    while (!cheakDraw(grid)){
     int x=5;
     int y=0;
     player1(grid, x, y);
     if (checkWin(grid)){
      winner1 = 1;
      break;
     }
     player2(grid, x, y);
     if (checkWin(grid)){
      winner2 = 1;
      break;
     }
    }

    printBoard(grid);
    if (winner1 == 1){
      printf("Player 1 wins \n");
    }
    else if (winner2 == 1){
      printf("Player 2 wins \n");
    }
    else{
      printf("It's a draw \n");
    }

  return 0;
}