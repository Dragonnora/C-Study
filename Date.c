#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 50
void convertStr(char *dateStr);

typedef enum _month {
    January=1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
} month;

int main(void)
{
    char date[LEN];  // date buffer
    printf("Enter a date (ex. March 1 1994): \n\r");
    fgets(date, LEN, stdin);

    convertStr(date);

    return 0;
}

void convertStr(char *dateStr)
{
    month month_num;
    char *token;

    // build a nice copy
    char copy[LEN] = {0};
    strcpy(copy, dateStr);
    
    // Token will have just the month
    token = strtok(dateStr, " ");
    //printf("Month:%5s\n\r", token);
    // Map the month to a day
    if (strncmp("Jan", token, strlen("Jan")) == 0)
        month_num = January;
    else if (strncmp("Feb", token, strlen("Feb")) == 0)
        month_num = February;
    else if (strncmp("Mar", token, strlen("Mar")) == 0)
        month_num = March;
    else if (strncmp("Apr", token, strlen("Apr")) == 0)
        month_num = April;
    else if (strncmp("May", token, strlen("May")) == 0)
        month_num = May;
    else if (strncmp("Jun", token, strlen("Jun")) == 0)
        month_num = June;
    else if (strncmp("Jul", token, strlen("Jul")) == 0)
        month_num = July;
    else if (strncmp("Aug", token, strlen("Aug")) == 0)
        month_num = August;
    else if (strncmp("Sep", token, strlen("Sep")) == 0)
        month_num = September;
    else if (strncmp("Oct", token, strlen("Oct")) == 0)
        month_num = October;
    else if (strncmp("Nov", token, strlen("Nov")) == 0)
        month_num = November;
    else if (strncmp("Dec", token, strlen("Dec")) == 0)
        month_num = December;
    else
    {
        printf("Invalid month entered, are you sure it was capitalized?\n");
        return;
    }

    // Token will be the day
    token = strtok(NULL, " ");
    //printf("Day:%5s\n\r", token);
    unsigned int day = (unsigned int) atoi(token);     // atoi take a string -> integer
    if (day ==0 || day > 31 || (month_num == February && day >28) )
    {
        printf("This is not a valid day for this month");
        return;
    }

    // Token will be the year
    token = strtok(NULL, " ");
    unsigned int year = (unsigned int) atoi(token);
    //printf("Year:%5s\n\r", token);

    printf("%s = %d/%d/%d", copy, month_num, day, year);
}
