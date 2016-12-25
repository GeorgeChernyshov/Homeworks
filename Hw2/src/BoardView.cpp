#include "BoardView.h"
#include <cstdio>
#include <cstdlib>

View::View(Board &b, bool show) : board_(b), show_(show){
}

void View::showBoard(){
    for(int i = 0; i < 10; i++){    
        for(int j = 0; j < 10; j++){       
            if(board_.tiles_[j][i] == -1){
                printf(".");
            }
            
            if(board_.tiles_[j][i] == 0){
                printf("O");
            }
            
            if(board_.tiles_[j][i] == 1){
                printf("X");
            }
        }
        
        printf("\n");
    }
    
    printf("\n");
}

void View::doGameCycle(){
    int x, y;
    char playerID = 0;
    bool done;
    while(board_.isWin() == play){
        done = false;
        if(show_){
            showBoard();
        }
        
        while(done == false){
            if(playerID == 1){
                printf("X move: ");
            }
            
            if(playerID == 0){
                printf("O move: ");
            }
            
            scanf("%d %d", &y, &x);
            
            if(board_.canMove(x, y) == 0){
                board_.move(x, y, playerID);
                done = true;
            }else{
                if(x == -1 && y == -1){
                    printf("Good Bye\n");
                    exit(1);
                }
                printf("Bad Move!\n");
            }
        }
        
        state status = board_.isWin();
        if(status == x_wins){
            if(show_){
                showBoard();
            }
            printf("X wins!\n");
        }
        
        if(status == o_wins){
            if(show_){
                showBoard();
            }
            printf("O wins!\n");
        }
        
        if(status == draw){
            if(show_){
                showBoard();
            }
            printf("Draw!\n");
        }
        
        playerID = 1 - playerID;
    }
}
