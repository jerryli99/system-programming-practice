#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LEN 1024

void show_cmds(void);
void usr_input(char *usr_cmd, int length);
void apply_cmd(char *usr_cmd);

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);


//this struct is from the book...
struct {
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] =
{
    {"new", new_cmd},
    {"open", open_cmd},
    {"close", close_cmd},
    {"close all", close_all_cmd},
    {"save", save_cmd},
    {"save as", save_as_cmd},
    {"print", print_cmd},
    {"exit", exit_cmd}
};


int main(void)
{
    char usr_cmd[INPUT_LEN];
    show_cmds();

    do {
        memset(usr_cmd, 0, INPUT_LEN);
        usr_input(usr_cmd, INPUT_LEN);
        apply_cmd(usr_cmd);
    } while ((strcmp(usr_cmd, "quit")) != 0);


    return (0);
}

void show_cmds(void)
{
    size_t size = sizeof(file_cmd) / sizeof(file_cmd[0]);
    printf("Commands:\n");
    for (int index = 0; index < size; index++)
    {
        printf("%s\n", file_cmd[index].cmd_name);
    }
    printf("-------------------\n");
    return;
}

void usr_input(char *usr_cmd, int length)
{
    printf("Enter command\n");
    fgets(usr_cmd, length, stdin);
    usr_cmd[strlen(usr_cmd) - 1] = '\0';
}

void apply_cmd(char *usr_cmd)
{
    size_t size = sizeof(file_cmd) / sizeof(file_cmd[0]);
    for (int index = 0; index < size; index++) 
    {
        if (strcmp(usr_cmd, file_cmd[index].cmd_name) == 0)
        {
            file_cmd[index].cmd_pointer();
        }
    }
}

void new_cmd(void)
{
    printf("Called new_cmd\n");
}

void open_cmd(void)
{
    printf("Called open_cmd\n");
}

void close_cmd(void)
{
    printf("Called close_cmd\n");
}

void close_all_cmd(void)
{
    printf("Called close_all_cmd\n");
}

void save_cmd(void)
{
    printf("Called save_cmd\n");
}

void save_as_cmd(void)
{
    printf("Called save_as_cmd\n");
}

void save_all_cmd(void)
{
    printf("Called save_all_cmd\n");
}

void print_cmd(void)
{
    printf("Called print_cmd\n");
}

void exit_cmd(void)
{
    printf("Called exit_cmd\n");
    exit(EXIT_SUCCESS);
}