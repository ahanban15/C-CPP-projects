#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define DELAY 1000

//template data type of time representation
typedef struct time{
    int hour;
    int minute;
    int second;
}time;

//default value initializations
time Time = {0};
time Alarm = {0};
char name[100];

//function prototype declarations
void set_time();
void alarm();
void user_name();
void calculate_12_AM();
void calculate_12_PM();
void calculate_24();

//function to receive start time and alarm
void set_time()
{
    printf("\nWhat's the time now?\nPlease set the time for us in the chosen form in HH:MM:SS format:\n");
    scanf("%d %d %d", &Time.hour, &Time.minute, &Time.second);

    printf("\nNow %s, please set your alarm in the chosen form in HH:MM:SS format:\n", name);
    scanf("%d %d", &Alarm.hour, &Alarm.minute);
}

//function to match alarm conditions
void alarm()
{
    if((Alarm.hour == Time.hour) && (Alarm.minute == Time.minute))
        printf("\aIts Alarm time %s\a\n", name);
}

//function to input user's name
void user_name()
{
    printf("\nWhat's your beautiful name?");
    gets(name);
}

//function to display time as 12 hour format for AM
void calculate_12_AM()
{
    if(Time.hour > 24 || Time.minute > 60 || Time.second > 60){
        printf("\aTime Invalid\n");
        exit(0);
    }

    //infinite loop
    while(1)
    {
        if(Time.second > 59)
        {
            Time.minute++;
            Time.second = 0;
        }

        if(Time.minute > 59)
        {
            Time.hour++;
            Time.minute = 0;
        }

        if(Time.hour > 11)
        {
            Time.hour = 1;
            calculate_12_PM();
        }

        system("cls");  //clearscreen

        printf("\n%s, the Time is:\n", name);
        printf("%02d:%02d:%02d AM\n", Time.hour, Time.minute, Time.second);

        Time.second++;

        Sleep(DELAY);   //delay increment by 1000 milliseconds
        alarm();
    }
}

//function to display time as 12 hour format for PM
void calculate_12_PM()
{
    if(Time.hour > 24 || Time.minute > 60 || Time.second > 60){
        printf("\aTime Invalid\n");
        exit(0);
    }

    //infinite loop
    while(1)
    {
        if(Time.second > 59)
        {
            Time.minute++;
            Time.second = 0;
        }

        if(Time.minute > 59)
        {
            Time.hour++;
            Time.minute = 0;
        }

        if(Time.hour > 11)
        {
            Time.hour = 0;
            calculate_12_AM();
        }

        system("cls");  //clearscreen

        printf("\n%s, the Time is:\n", name);
        printf("%02d:%02d:%02d PM\n", Time.hour, Time.minute, Time.second);

        Time.second++;

        Sleep(DELAY);   //delay increment by 1000 milliseconds
        alarm();
    }
}

//function to display time as 24 hour format
void calculate_24()
{
    if(Time.hour > 24 || Time.minute > 60 || Time.second > 60){
        printf("\aTime Invalid\n");
        exit(0);
    }

    //infinite loop
    while(1)
    {
        if(Time.second > 59)
        {
            Time.minute++;
            Time.second = 0;
        }

        if(Time.minute > 59)
        {
            Time.hour++;
            Time.minute = 0;
        }

        if(Time.hour > 23)
            Time.hour = 0;

        if(Time.hour >= 12)
        {
            system("cls");  //clearscreen

            printf("\n%s, the Time is:\n", name);
            printf("%02d:%02d:%02d PM\n", Time.hour, Time.minute, Time.second);

            Time.second++;

            Sleep(DELAY);   //delay increment by 1000 milliseconds
            alarm();
        }
        else
        {
            system("cls");  //clearscreen

            printf("\n%s, the Time is:\n", name);
            printf("%02d:%02d:%02d AM\n", Time.hour, Time.minute, Time.second);

            Time.second++;

            Sleep(DELAY);   //delay increment by 1000 milliseconds
            alarm();
        }
    }
}

//main function block
int main()
{
    printf("Welcome to the Banergy Clock Systems\n");
    user_name();
    printf("\nHello %s\n", name);

    //menu of options of time format
    int option;
    printf("\n%s, you want the time in which format?\nPlease choose the correct option:\n", name);
    printf("1.12 hour form at AM\n");
    printf("2.12 hour form at PM\n");
    printf("3.24 hour form\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            set_time();
            calculate_12_AM();
            break;

        case 2:
            set_time();
            calculate_12_PM();
            break;

        case 3:
            set_time();
            calculate_24();
            break;

        default:
            printf("Invalid option!\n");
    }
    return 0;
}

