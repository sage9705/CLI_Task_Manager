#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 250

void init_curses() {
    if (!initscr()) {
        fprintf(stderr, "Error initializing ncurses.\n");
        exit(EXIT_FAILURE);
    }
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void print_center(int y, char *text) {
    int x = (COLS - (int)strlen(text)) / 2;
    mvprintw(y, x, "%s", text);
}

void print_tasks(WINDOW *win, char tasks[MAX_TASKS][MAX_TASK_LENGTH], int numTasks) {
    werase(win);
    box(win, 0, 0);
    print_center(1, "Task Manager");

    if (numTasks == 0) {
        mvwprintw(win, 3, 2, "No tasks added yet.");
    } else {
        for (int i = 0; i < numTasks && i < LINES - 6; i++) {
            mvwprintw(win, i + 3, 2, "%d. %s", i + 1, tasks[i]);
        }
    }

    if (numTasks > LINES - 6) {
        mvwprintw(win, LINES - 3, 2, "(Scroll for more tasks)");
    }

    wrefresh(win);
}

void add_task(char tasks[MAX_TASKS][MAX_TASK_LENGTH], int *numTasks, WINDOW *task_win) {
    if (*numTasks < MAX_TASKS) {
        WINDOW *input_win = newwin(3, COLS - 4, LINES - 4, 2);
        box(input_win, 0, 0);
        mvwprintw(input_win, 1, 2, "Enter task: ");
        wrefresh(input_win);

        echo();
        nocbreak();
        wgetnstr(input_win, tasks[*numTasks], MAX_TASK_LENGTH - 1); // Limit input to avoid buffer overflow
        (*numTasks)++;
        cbreak();
        noecho();
        delwin(input_win);

        print_tasks(task_win, tasks, *numTasks);
    } else {
        mvprintw(LINES - 3, 2, "Task limit reached. Delete some tasks to add more.");
    }
}

/******************************/
/*Author: Kumahor Edem Godwin*/
/****************************/

void delete_task(char tasks[MAX_TASKS][MAX_TASK_LENGTH], int *numTasks, WINDOW *task_win) {
    if (*numTasks > 0) {
        WINDOW *input_win = newwin(3, COLS - 4, LINES - 4, 2);
        box(input_win, 0, 0);
        mvwprintw(input_win, 1, 2, "Enter the task number to delete: ");
        wrefresh(input_win);

        echo();
        nocbreak();
        int taskNumber;
        scanw("%d", &taskNumber);
        if (taskNumber > 0 && taskNumber <= *numTasks) {
            for (int i = taskNumber - 1; i < *numTasks - 1; i++) {
                strcpy(tasks[i], tasks[i + 1]);
            }
            (*numTasks)--;
        } else {
            mvprintw(LINES - 2, 2, "Invalid task number.");
        }
        cbreak();
        noecho();
        delwin(input_win);

        print_tasks(task_win, tasks, *numTasks);
    } else {
        mvprintw(LINES - 3, 2, "No tasks to delete.");
    }
}

void display_help() {
    mvprintw(LINES - 3, 2, "Controls: 'a' add task, 'd' delete task, 'q' to quit.");
    refresh();
}

void run_task_manager() {
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int numTasks = 0;
    int ch;

    WINDOW *task_win = newwin(LINES - 5, COLS - 4, 2, 2);
    box(task_win, 0, 0);
    refresh();

    print_tasks(task_win, tasks, numTasks);
    display_help();

    while (1) {
        ch = getch();

        if (ch == 'q') {
            break;
        } else if (ch == 'a') {
            add_task(tasks, &numTasks, task_win);
        } else if (ch == 'd') {
            delete_task(tasks, &numTasks, task_win);
        }
    }
}

int main() {
    init_curses();
    run_task_manager();
    endwin();
    return 0;
}
