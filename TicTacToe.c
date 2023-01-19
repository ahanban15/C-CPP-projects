#include <stdio.h>
#include <stdlib.h>

char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void display();
void myTurn();
void insert(char index, char sym);
void begin();
int algo();
void end();

void display(){
    printf("\n\t\t%c\t|\t%c\t|\t%c\t\n", arr[0], arr[1], arr[2]);
    printf("\t----------------|---------------|----------------");
    printf("\n\t\t%c\t|\t%c\t|\t%c\t\n", arr[3], arr[4], arr[5]);
    printf("\t----------------|---------------|----------------");
    printf("\n\t\t%c\t|\t%c\t|\t%c\t\n", arr[6], arr[7], arr[8]);
}

void begin()
{
    char first;
    char index;
    char sym;

    fflush(stdin);
    printf("\nWho will start first? \n");
    scanf("%c", &first);

    fflush(stdin);
    printf("\nPlease enter your preferred index and symbol: \n");
    scanf("%c %c", &index, &sym);

    if((first == 'A' && sym != 'X') || (first == 'B' && sym != 'O'))
    {
        printf("\n\aWrong turn played!!!");
        begin();
    }
    else
    {
        insert(index, sym);
    }
}

void myTurn()
{
    char index;
    char sym;

    fflush(stdin);
    printf("\nNext player, please enter your preferred index and symbol: \n");
    scanf("%c %c", &index, &sym);

    insert(index, sym);
}

void insert(char index, char sym){
    int count = 0;
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] == index)
        {
            arr[i] = sym;
            count++;
        }
    }

    system("cls");
    printf("\n\t\tWelcome to Ahan's TIC TAC TOE Game!!!\n");
    display();

    int status;
    status = algo();

    if(status == 1)
    {
        printf("\n\nPlayer A WINS!!!\a\n");
        end();
    }

    else if(status == 2)
    {
        printf("\n\nPlayer B WINS!!!\a\n");
        end();
    }

    else if(status == 3)
    {
        if(count >= 9)
        {
            printf("\n\nIt's a DRAW!!!\a\n");
            end();
        }
        else
            myTurn();
    }
}

int algo()
{
    if((arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X') ||
    (arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X') ||
    (arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X') ||
    (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X') ||
    (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X') ||
    (arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X') ||
    (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X') ||
    (arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X'))
        return 1;
    else if((arr[0] == 'O' && arr[1] == 'O' && arr[2] == 'O') ||
    (arr[3] == 'O' && arr[4] == 'O' && arr[5] == 'O') ||
    (arr[6] == 'O' && arr[7] == 'O' && arr[8] == 'O') ||
    (arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O') ||
    (arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O') ||
    (arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O') ||
    (arr[0] == 'O' && arr[4 == 'O'] && arr[8] == 'O') ||
    (arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O'))
        return 2;
    else
        return 3;
}

int main()
{
    system("cls");
    printf("\n\t\tWelcome to Ahan's TIC TAC TOE Game!!!\n");

    display();

    printf("\n\nSymbol for Player A: 'X'\n");
    printf("\nSymbol for Player B: 'O'\n");

    begin();
    display();

    myTurn();
    display();

    return 0;
}

void end()
{
    printf("\nSelect an option from the following menu: \n");
    printf("1. Restart\n");
    printf("2. Exit\n");

    int option = 0;

    label:
    fflush(stdin);
    scanf("%d", &option);

    switch(option)
    {
        case 1:
        {
            for(int i = 0; i < 9; i++)
                arr[i] = 49 + i;
            main();
        }

        case 2:
        {
            printf("\n\nThanks a lot for using our services of playing Tic Tac Toe game.\n");
            printf("More games expected soon in the near future. GOOD BYE!!!\a\n");
            exit(1);
        }

        default:
        {
            printf("\n\aWrong choice, please enter option 1 or 2\n");
            goto label;
        }
    }
}
