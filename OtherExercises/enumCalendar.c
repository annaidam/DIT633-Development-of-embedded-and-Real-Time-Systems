#include <stdio.h>
#include <unistd.h>

enum Day {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

enum Week {
    WEEK1 = 1,
    WEEK2 = 2,
    WEEK3 = 3,
    WEEK4 = 4,
    WEEK5 = 5,
};

int main() {
    enum Day startDay;
    enum Week startWeek;

    scanf("%u", &startWeek);
    while(getchar() != '\n');
    scanf("%u", &startDay);

    if (startWeek > 5 || startWeek < 1) {
        printf("invalid week\n");
        return 0;
    } else if (startDay > 7 || startDay < 1) {
        printf("invalid day");
        return 0;
    } else if ((startWeek > 5 || startWeek < 1) && (startDay > 7 || startDay < 1)) {
        printf("invalid week and day");
        return 0;
    }

    while(startWeek <= 5) {
        printf("Week %d,", startWeek);

        switch(startDay) {
            case MONDAY:
                printf(" Monday\n");
                startDay++;
                break;
            case TUESDAY:
                printf(" Tuesday\n");
                startDay++;
                break;
            case WEDNESDAY:
                printf(" Wednesday\n");
                startDay++;
                break;
            case THURSDAY:
                printf(" Thursday\n");
                startDay++;
                break;
            case FRIDAY:
                printf(" Friday\n");
                startDay++;
                break;
            case SATURDAY:
                printf(" Saturday\n");
                startDay++;
                break;
            case SUNDAY:
                printf(" Sunday\n");
                startWeek++;
                startDay = MONDAY;
                break;
        }
        sleep(1);
    }
    return 0;
};