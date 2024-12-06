//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};
int player_arrival[N_PLAYER];//코인이 동일할 때 먼저 도착하는 사람이 winner임을 구하기위한한 내가 만든 배열
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;//게임 끝났다고 초기변수 설정
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)//플레이어가 살아있다면
        {
            flag_end = 0;//게임 안끝남
            break;
        }
    }
    
    return flag_end;
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player)//플레이어 위치 출력
{
    
    
    for (int i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);//플레이어의 첫 번째 이름 글자 출력
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerArrival(int player){
	//도착하는 순서에 따라 player들이 1,2,3 으로 배치됨 
	int order=1;
	
	if(player_position[N_PLAYER]==20){
		player_arrival[N_PLAYER]=order++;
	}
		
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
    	//플레이어마다 각각 이름, 위치,보유 코인, 상태 출력
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);//각 플레이어의 위치 출력
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
        	//플레이어가 죽었을 때
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;//        
		}
    }
}
// ----- EX. 5 : shark ------------

// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
	int i;
	int cnt=0;//살아있는 플레이어에 대한 변수 초기화 
	for (i=0;i<N_PLAYER;i++){
		if (player_status[i]==PLAYERSTATUS_END){
			cnt++;
		}
	}
	return cnt;
}

int getWinner(void)
{
	int i;
	int winner;
	int max_coin=-1;
	int min_arrival=0;
	for (i=0;i<N_PLAYER;i++){
		if (player_coin[i]>max_coin){
			max_coin=player_coin[i];
			winner=i;//승리자를 해당 i의 인덱스로 설정
		}
		//코인의 개수가 같을 때, 먼저 도착한 사람이 승리자가 됨
		else if(player_coin[i]==max_coin){
			if (player_arrival[i]<min_arrival){
				winner=i;
			}
		}
	}
	
	return winner;
	
	
}


// ----- EX. 6 : game end ------------


int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0;
    
    int pos=0;

// ----- EX. 1 : Preparation------------
    srand(time(NULL));//난수생성기 초기화
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    //플레이어 이름 설정
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;

// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1)%N_PLAYER;//현재 턴의 플레이어가 LIVE상태가 아니면  다음 플레이어 순서로 넘어감
            continue;
        }
        
// ----- EX. 4 : player ------------
        
        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);//주사위 굴림
// ----- EX. 4 : player ------------
        dieResult = rolldie();//함수호출해서 dieResult에 저장
        
        
        //step 2-3. moving
        
        if (player_position[turn]+dieResult>N_BOARD-1){
        	player_position[turn]=20;
        	player_status[turn]=PLAYERSTATUS_END;
        	printf("Die result: %d, %s moved to 20\n", dieResult, player_name[turn]);
		    }  // 플레이어의 위치에서 주사위결과를 더했을 때, 위치가 20이상이면 위치는 20으로 설정, 상태 END로 변경
		else {
			player_position[turn]+=dieResult;//plqyer_position값에 주사위 결과 더하기
		    printf("Die result : %d, %s moved to %d\n", dieResult, player_name[turn],player_position[turn]);
	        }
        coinResult=board_getBoardCoin(player_position[turn]);//현재 위치의 코인을 줍는 함수 호출
        player_coin[turn]+=coinResult;//player_coin에 습득한 coin 추가 
        if (coinResult>0){
        	
		printf("Congratulations. %s collects %d coins\n ",player_name,coinResult);
	    }//습득한 코인이 있으면 출력

    
        
        //step 2-5. end process
        turn=(turn+1)%N_PLAYER;//다음 플레이어차례 
        
        
        if (turn==0){
        	int shark_position=board_stepShark();
        	printf("Shark moved to %d\n", shark_position);
        	//상어 위치 출력
        	checkDie();
		}
		
		
		
// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    
    //step 3. game end process
    printf("GAME END!!\n");
    printf("%i players are alive! winner is %s\n", getAlivePlayer(), player_name[getWinner()]);
// ----- EX. 6 : game end ------------
    
// ----- EX. 2 : structuring ------------

    return 0;
    
}
