#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book{
    char id[5];
    char name[30];
}Book;

typedef struct date{
    int day;
    int month;
    int year;
}

typedef struct lib{
    struct book Book;
    struct date issue_date;
    struct date return_date;
}

/*
FILE *fp;
char ch;
fp = fopen("lib.txt", "w+");

if(fp == NULL)
    printf("Error in opening file\n");

while(1)
{
    ch = fgetc(fp);
    if(ch == EOF)
        exit(1);
}
*/
void display();
void add();

void display()
{
    FILE *fp;
    //char ch;
    fp = fopen("lib.txt", "w+");

    if(fp == NULL)
        printf("Error in opening file\n");
/*
    while(1)
    {
        ch = fgetc(fp);
        if(ch == EOF)
            printf("No records!\n");
    }
*/
    struct book b1;
    while(1)
    {
        fscanf(fp, "%s %s", b1.id, b1.name);
      //  if((strcmp("0", b1.id) == 0) && (strcmp("nil", b1.name) == 0))
          //  break;

        fprintf(fp, "%s %s", b1.id, b1.name);
    }
    fclose(fp);
}

void add()
{
    FILE *fp;
    //char ch;
    fp = fopen("lib.txt", "w+");

    if(fp == NULL)
        printf("Error in opening file!\n");
    /*
    while(1)
    {
        ch = fgetc(fp);
        if(ch == EOF)
            exit(1);
    }*/

    struct book b1;

    printf("Enter the id of book: ");
    scanf("%s", b1.id);

    printf("Enter the name of book: ");
    scanf("%s", b1.name);

    fprintf(fp, "%s %s", b1.id, b1.name);

    //fflush(stdin);
    fclose(fp);
}

int main()
{
    int option = 0;
    do{
        printf("\nMenu:\n");
        printf("1. Display record\n");
        printf("2. Add a record\n");
        printf("3. Drop a record\n");
        printf("4. Search any book\n");
        printf("5. Calculate fine\n");
        printf("6. Exit\n");

        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                display();
                break;

            case 2:
                add();
                break;

            case 3:

                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            default:
                printf("Wrong option\n");
        }
    }while(option != 6);


    return 0;
}

