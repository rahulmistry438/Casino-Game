#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash=100;
void playgame(int betting_amount)
{
        char A[3]={'J','K','L'};
        int playerschoice,i;
        srand(time(NULL));
        for(i=1;i<=10;i++)
        {

            int x=rand()%3;
            int y=rand()%3;
            int temp=A[x];
            A[x]=A[y];
            A[y]=temp;
        }
        printf("\nShuffling is done");
        printf("\nWhat is the position of King,1,2 or 3 ?");
        scanf("%d",&playerschoice);
        if(A[playerschoice-1]=='K')
        {

            cash=cash+2*betting_amount;
            printf("You win.\nPosition of Cards='%c','%c','%c'\nYour current balance=$%d\n",A[0],A[1],A[2],cash);
        }
        else
        {
            cash=cash-betting_amount;
            printf("You Lose.\nPosition of Cards='%c','%c','%c'\nYour current balance=$%d\n",A[0],A[1],A[2],cash);
        }
}
int main()
{
    int betting_amount;
    printf("......Welcome to my casino......");
    printf("\nTotal Cash=$%d",cash);
    while(cash>0)
    {
        printf("\nWhat is your betting amount ?");
        scanf("%d",&betting_amount);
        if(betting_amount=0||betting_amount>cash)
            break;
        else
        {
            playgame(betting_amount);
        }
        printf("\nGame Over");
        getch();
        return 0;
    }
}
