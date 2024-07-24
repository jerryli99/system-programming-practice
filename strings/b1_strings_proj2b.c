/**
 * @brief Most of the code here was copied from the book ch13.
 *        The goal here is to allow the user to enter a day, a 24 hour time, and a reminder.
 *        The printed reminder list should be sorted first by day, then by time. 
 * 
 *        Hence ignore most of the programming style here...
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */
#define DAY_LEN 2       /* max number of digits in a day "dd" */
#define TIME_LEN 6      /* max length of a 24 hr time including space " hh:mm" */

int read_line(char str[], int n);
bool is_valid_time(int hour, int minute);
bool is_valid_day(int day);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+3];
  char day_str[DAY_LEN + TIME_LEN + 1], msg_str[MSG_LEN+1];
  int hour, minute, day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }
    //modified----------------------------------------------------------------
    printf("Enter day, time, and reminder: ");
    if (scanf("%2d", &day) != 1) {
      printf("Invalid input. Please enter a valid day (1-31).\n");
      while (getchar() != '\n'); /* Flush buffer */
      continue;
    }

    if (day == 0) {
      break;
    }

    if (!is_valid_day(day)) {
      printf("Error: day must be between 1 and 31.\n");
      while (getchar() != '\n'); /* Flush buffer */
      continue;
    }

    if (scanf(" %2d:%2d", &hour, &minute) != 2) {
      printf("Invalid time format. Please enter time in hh:mm format.\n");
      while (getchar() != '\n'); /* Flush buffer */
      continue;
    }

    if (!is_valid_time(hour, minute)) {
      printf("Error: hour must be between 0 and 23, and minute must be between 0 and 59.\n");
      while (getchar() != '\n'); /* Flush buffer */
      continue;
    }

    sprintf(day_str, "%2d %2.2d:%.2d", day, hour, minute);
    //-----------------------------------------------------------------------------

    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Time  Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n) //this is from the book...
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

//my code----------------------------------------------------
/**
 * @brief This function will check to see if the user input hour and minute is correct.
 * 
 * @param hour An integer representing hours in a day (between 0 and 23 inclusive).
 * @param minute An intger representing minutes in an hour (between 0 and 59 inclusive).
 * 
 * @return Returns boolean values true or false.
 */
bool is_valid_time(int hour, int minute) {
  return (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59);
}

/**
 * @brief This function will check to see if the user input day is correct.
 * 
 * @param hour An integer representing the day between 1 and 31 inclusive
 * 
 * @return Returns boolean values true or false.
 */
bool is_valid_day(int day) {
  return day >= 1 && day <= 31;
}
//---------------------------------------------------------