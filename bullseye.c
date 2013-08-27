#include <curses.h>
#include <signal.h>
static void finish(int sig);
int main(int argc,char **argv)
{
	(void)sigaction(SIGINT,finish);
	initscr();
	keypad(stdscr,TRUE);
	(void)nonl();
	(void)cbreak();
	(void)noecho();
	if(has_colors()){
		start_color();
		init_pair(0,COLOR_BLACK,COLOR_BLACK);
		init_pair(1,COLOR_GREEN,COLOR_BLACK);
		init_pair(2,COLOR_RED,COLOR_BLACK);
		init_pair(3,COLOR_CYAN,COLOR_BLACK);
		init_pair(4,COLOR_WHITE,COLOR_BLACK);
		init_pair(5,COLOR_MAGENTA,COLOR_BLACK);
		init_pair(6,COLOR_BLUE,COLOR_BLACK);
		init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	}
	attron(A_BLINK|COLOR_PAIR(2));
	move(LINES/2+1,COLS-4);
	addstr("Eye");
	refresh();
	sleep(2);
	move(LINES/2-3,COLS/2-3);
	addstr("Bulls");
	refresh();
	sleep(2);
	finish(0);
	
		
}
static void finish (int sig)
{
	endwin();
	//exit(0);
}
