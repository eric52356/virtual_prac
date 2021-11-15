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

int have_card[2]={0,0}; //1. have card 2. play three-title card
void enter_player_name(int playercount,struct player current_player[]);
void get_cards(int playercount,struct player current_player[]);
void choose_discads(int playercount,struct player current_player[]);
void choose_card_to_play(int playercount,struct player current_player[],int store_cards[],int have_card[],int first_play);
int check_playcard(struct player current_player[],int playercount,int store_cards[],int first_play);
int penalty_count(int store_cards[]);
void print_players_cards(struct player current_player[]);
int who_win(int store_cards[],int first_play);
//struct player createNewNode(int playercount);
int main()
{
    int playercount=0;
    //int store_cards[ALL_PLAYERS]={};
    struct player current_player[ALL_PLAYERS];
    srand((unsigned)time(NULL));
    //rand()%(CARDS_MAX-CARDS_MIN+1)+CARDS_MIN;
    for(playercount=0;playercount<ALL_PLAYERS;playercount++)
    {
        printf("enter player %d name : ",playercount);
        enter_player_name(playercount,current_player);
    }
    printf("-----------------------------------------\n");
    get_cards(playercount,current_player);
    print_players_cards(current_player);
    //choose_discads(playercount,&current_player[playercount]);
    int round=0;
    int i=0;
    int first_play=0;
    int penalty=0;
    int player_penalty[ALL_PLAYERS]={0};
    playercount=0;
    while(round<10)
    {
        int store_cards[ALL_PLAYERS]={0};
        printf("              ROUND %d\n",round);
        for(i=0;i<ALL_PLAYERS;i++)
        {
            if(i==0)
            {
                have_card[0]=0;
                choose_card_to_play(playercount,current_player,store_cards,have_card,first_play);
                //printf("%d\n",store_cards[first_play]);
                //first_play=playercount;
            }
            else
            {
                have_card[0]=check_playcard(current_player,playercount,store_cards,first_play);
                choose_card_to_play(playercount,current_player,store_cards,have_card,first_play);
                //printf("%d\n",store_cards[first_play]/10);
                //printf("%d\n",store_cards[playercount]);
            }
            playercount++;
            if(playercount>3)
            {
                playercount=0;
            }
        }
        penalty=penalty_count(store_cards);
        printf("penalty add:%d\n",penalty);
        player_penalty[who_win(store_cards,first_play)]+=penalty;
        printf("-----------------------------------------\n");
        /*if(playercount>3)
        {
            playercount=0;
        }*/
        print_players_cards(current_player);
        round++;
        printf("PENALTY:");
        for(int s=0;s<ALL_PLAYERS;s++)
        {
            printf("%d ",player_penalty[s]);
        }
        printf("\n");
        first_play=who_win(store_cards,first_play);
        printf("who win : %d\n",first_play);
        playercount=first_play;
    }            
    return 0;
}

void enter_player_name(int playercount,struct player current_player[])
{
    current_player[playercount].number=playercount;
    scanf("%s",current_player[playercount].name);
    //fgets(current_player[playercount].name,sizeof(current_player->name),stdin);
}
void get_cards(int playercount,struct player current_player[])
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
        current_player[playercount].cards[cards_index]=card_number[i];
        //printf("%d ",current_player[playercount].cards[cards_index]);
        cards_index++;
        if(i%PLAYER_CARDS==9)
        {
            playercount++;
            //printf("\n");
            cards_index=0;
        }
        i++;
    }
            //printf("Hands : ");
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
void choose_card_to_play(int playercount,struct player current_player[],int store_cards[],int have_card[],int first_play)
{
    int choose,i;
    int wrongcard=1;
    printf("Player %d : ",playercount);
    scanf("%d",&choose);
    for(i=0;i<PLAYER_CARDS;i++)
    {
        if(have_card[0])
        {
            if(have_card[1]==0&&choose/10==3)
            {
                wrongcard=1;
                //printf("you have card and 3 is not be played!\n");
                break;
            }
            else
            {
                if(current_player[playercount].cards[i]==choose&&choose/10==store_cards[first_play]/10)
                {
                    current_player[playercount].cards[i]=0;
                    store_cards[playercount]=choose;
                    wrongcard=0;
                }
            }
        }
        else
        {
            if(current_player[playercount].cards[i]==choose)
            {
                if(store_cards[first_play]!=0&&choose/10==3)
                {
                    have_card[1]=1;
                }
                if(have_card[1]==0&&choose/10==3)
                {
                    wrongcard=1;
                    //printf("you don't have card but 3 is not be played!\n");
                }
                else
                {
                    current_player[playercount].cards[i]=0;
                    store_cards[playercount]=choose;
                    wrongcard=0;
                    //printf("you don't have card!\n");
                }
            }
        }
    }
    if(wrongcard)
    {
        printf("Wrong card\n");
        choose_card_to_play(playercount,current_player,store_cards,have_card,first_play);
    }
}
int check_playcard(struct player current_player[],int playercount,int store_cards[],int first_play)
{
    for(int i=0;i<PLAYER_CARDS;i++)
    {
        if((current_player[playercount].cards[i])/10==store_cards[first_play]/10)
        {
            return 1;
        }
    }
    return 0;
}
int penalty_count(int store_cards[])
{
    int penalty=0;
    for(int i=0;i<ALL_PLAYERS;i++)
    {
        if(store_cards[i]==47)
        {
            penalty+=7;
        }
        if(store_cards[i]/10==3)
        {
            penalty++;
        }
    }
    return penalty;
}
void print_players_cards(struct player current_player[])
{
    int a,b;
    for(a=0;a<ALL_PLAYERS;a++)
    {
        printf("Player %d : ",a);
        for(b=0;b<PLAYER_CARDS;b++)
        {
            printf("%2d ",current_player[a].cards[b]);
        }
        printf("\n");
    }
}
int who_win(int store_cards[],int first_play)
{
    int playercount=first_play;
    int player_win=0;
    for(int i=0;i<ALL_PLAYERS;i++)
    {
        if(playercount>3)
        {
            playercount=0;
        }
        if(store_cards[playercount]>store_cards[first_play]&&store_cards[playercount]/10==store_cards[first_play]/10)
        {
            player_win=playercount;
            first_play=playercount;
        }
        playercount++;
    }
    //printf("who win:%d\n",player_win);
    return player_win;
}
/*struct player createNewNode(int playercount)
{
    struct player *temp = (player*) malloc(sizeof(player));
    temp->number = playercount;
    temp->next_player = NULL;
    return *temp;
}*/