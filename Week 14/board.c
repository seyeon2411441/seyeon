//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12
#define MAX_COIN        4
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------


static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void)
{
    int i;
    
    //variable initialization
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;//보드의 모든 칸 0으로 초기화
        board_coin[i] = 0;//보드의 각 칸에 코인 0으로 초기화
    }
    
// ----- EX. 5 : shark ------------
    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation

    for(i=0;i<N_COINPOS;i++){//COINPOS=모든 칸의 총 코인 개수
    	int coinboard;
    	while(1){
    		coinboard=rand()%N_BOARD;//보드의 위치 랜덤으로 선택
    		if (board_coin[coinboard]==0){//그 칸에 코인이 없으면
    			board_coin[coinboard]=rand()%(MAX_COIN+1);//랜덤코으로 인 수 배치
			    break;
			}
		}
    	// 0부터 COINMAX까지 랜덤 배치
	}

    return N_COINPOS;
}
// ----- EX. 3 : board ------------

// ----- EX. 5 : shark ------------
int board_stepShark(void) //상어 전진 명령
{
	int i;
	int sharkPos;
	sharkPos=rand()%(MAX_SHARKSTEP+1);
	shark_position+=sharkPos;
	
	if(shark_position>=N_BOARD){
		shark_position=N_BOARD-1;
	}
	
	for(i=0;i<shark_position;i++){
		board_status[i]=BOARDSTATUS_NOK;
	}
	return sharkPos;
	
	
}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{

    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------
