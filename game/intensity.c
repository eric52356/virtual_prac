#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARDS 40
#define PLAYER_CARDS 10
#define ALL_PLAYERS 4
#define DISCARDS 3

#define CARDS_MIN 10
#define CARDS_MAX 49

struct player{
    int number;
    char name[32];
    int cards[10];
    int discards[3];
    //struct player *next_player;
};

void enter_player_name(int playercount,struct player *current_player[ALL_PLAYERS]);
void get_cards(int playercount,struct player *current_player[]);
void choose_discads(int playercount,struct player current_player[]);
void choose_card_to_play(int playercount,struct player *current_player[]);
//struct player createNewNode(int playercount);

int main()
{
    int playercount=0;
    struct player *current_player[ALL_PLAYERS];
    current_player[0] = (struct player*)malloc(sizeof(struct player));
    current_player[1] = (struct player*)malloc(sizeof(struct player));
    current_player[2] = (struct player*)malloc(sizeof(struct player));
    current_player[3] = (struct player*)malloc(sizeof(struct player));        
    current_player[3]->number=3;
    srand((unsigned)time(NULL));
    //rand()%(CARDS_MAX-CARDS_MIN+1)+CARDS_MIN;
    for(playercount=0;playercount<ALL_PLAYERS;playercount++)
    {
        enter_player_name(playercount,&current_player[playercount]);
        printf("%d\n",playercount);
    }
    get_cards(playercount,&current_player[playercount]);
    //choose_discads(playercount,&current_player[playercount]);
    int round=0;
    while(round<10)
    {
        choose_card_to_play(playercount,&current_player[playercount]);
        round++;
    }
    free(current_player[0]);
    free(current_player[1]);
    free(current_player[2]);
    free(current_player[3]);            
    return 0;
}

void enter_player_name(int playercount,struct player *current_player[ALL_PLAYERS])
{
    printf("playercount:%d\n",playercount);
    printf("count0:%d\n",current_player[0]->number);
    printf("count1:%d\n",current_player[1]->number);
    printf("count2:%d\n",current_player[2]->number);
    printf("count3:%d\n",current_player[3]->number);
    current_player[playercount]->number=playercount;
    printf("gaga\n");
    char temp[50];
    scanf("%s",temp);
    printf("peko\n");
    //printf("%s\n",current_player[playercount].name);
    //fgets(current_player[playercount].name,sizeof(current_player->name),stdin);
}
void get_cards(int playercount,struct player *current_player[])
{
    int card_number[TOTAL_CARDS];
    int i=0,j=0;
    for(i=0;i<TOTAL_CARDS;i++)
    {
        do{
            card_number[i]=rand()%(CARDS_MAX-CARDS_MIN+1)+CARDS_MIN;
            for(j=0;j<i;j++)
            {
                if(card_number[i]==card_number[j])
                {
                    break;
                }
            }
        }while(j!=i);
    }
    i=0;
    int cards_index=0;
    playercount=0;
    while(i<TOTAL_CARDS)
    { 
        current_player[playercount]->cards[cards_index]=card_number[i];
        printf("%d ",current_player[playercount]->cards[cards_index]);
        cards_index++;
        if(i%PLAYER_CARDS==9)
        {
            playercount++;
            printf("\n");
            cards_index=0;
        }
        i++;
    }
}
void choose_discads(int playercount,struct player current_player[])
{
    int store_discard[ALL_PLAYERS][DISCARDS];
    int i=0;
    for(playercount=0;playercount<ALL_PLAYERS;playercount++)
    {
        for(i=0;i<DISCARDS;i++)
        {
            store_discard[playercount][i]=current_player[playercount].cards[i];
            printf("%d ",current_player[playercount].cards[i]);
        }
        printf("\n");
    }
}
void choose_card_to_play(int playercount,struct player *current_player[])
{
    int choose,i;
    int wrongcard=1;
    playercount=0;
    scanf("%d",&choose);
    for(i=0;i<PLAYER_CARDS;i++)
    {
        //printf("%d\n",current_player[playercount].cards[i]);
        if(current_player[playercount]->cards[i]==choose)
        {
            printf("%d\n",current_player[playercount]->cards[i]);
            current_player[playercount]->cards[i]=0;
            wrongcard=0;
        }
    }
    if(wrongcard)
        printf("Wrong card\n");
}
/*struct player createNewNode(int playercount)
{
    struct player *temp = (player*) malloc(sizeof(player));
    temp->number = playercount;
    temp->next_player = NULL;
    return *temp;
}*/