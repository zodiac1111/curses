// 窗口演示
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <curses.h>
int main(int argc,char *argv[])
{
	WINDOW *win;
	
	if((initscr())==NULL)
    	{
		perror("initscr");
		exit(EXIT_FAILURE);
	}
	start_color();
	init_pair(COLOR_RED,COLOR_WHITE,COLOR_RED);
	init_pair(COLOR_BLUE,COLOR_WHITE,COLOR_BLUE);
        //   name   , forecolor,bgcolor
        init_pair(COLOR_GREEN,COLOR_BLACK,COLOR_GREEN); 
	init_pair(COLOR_MAGENTA,COLOR_WHITE,COLOR_MAGENTA);
	init_pair(COLOR_CYAN,COLOR_WHITE,COLOR_CYAN);
	init_pair(COLOR_YELLOW,COLOR_BLACK,COLOR_YELLOW);
	init_pair(COLOR_WHITE,COLOR_BLACK,COLOR_WHITE);
	refresh();
	curs_set(0);
	noecho();
	clear();
	win=newwin(LINES-10,COLS-10,5,5);
	wborder(win,0,0,0,0,0,0,0,0);
	wbkgd(win,' '|COLOR_PAIR(COLOR_BLUE));
	
	mvwaddstr(win,1,2,"This test Blue Window   ");
	touchwin(win);
	wrefresh(win);	
	sleep(1);
	wbkgd(win,' '|COLOR_PAIR(COLOR_YELLOW));
	mvwaddstr(win,1,2,"This test Yellow Window ");
	wrefresh(win);
	sleep(1);
	wbkgd(win,' '|COLOR_PAIR(COLOR_RED));
	mvwaddstr(win,1,2,"This test Red Window     ");
	wrefresh(win);
	sleep(1);
	
	wbkgd(win,' '|COLOR_PAIR(COLOR_GREEN));
	mvwaddstr(win,1,2,"This test Green Window   ");
	wrefresh(win);
	sleep(1);
	
	wbkgd(win,' '|COLOR_PAIR(COLOR_MAGENTA));
	mvwaddstr(win,1,2,"This test Magenta Window");
	wrefresh(win);
	sleep(1);
	
	wbkgd(win,' '|COLOR_PAIR(COLOR_CYAN));
	mvwaddstr(win,1,2,"This test Cyan  Window  ");
	wrefresh(win);
	sleep(1);
	
	wbkgd(win,' '|COLOR_PAIR(COLOR_WHITE));
	mvwaddstr(win,1,2,"This test White Window  ");
	wrefresh(win);
	sleep(1);
	
	delwin(win);
	printw("This is  printw\n");
        refresh();
        sleep(3);
	endwin();
}
