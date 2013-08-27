/*
 最简单程序
*/
#include    <curses.h>
#define     ROW 10
#define     COL 20
void show(char *);
int main(void)
{
    char        *sign_1 = "|";
    char        *sign_2 = "/";
    char        *sign_3 = "-";
    char        *sign_4 = "\\"; 
    initscr();          /* turn on curses */
    clear();            /* clear screen for drawing */
	keypad(stdscr,TRUE);
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
		attron(A_BLINK|COLOR_PAIR(1)); //设置颜色
	}
    while(1) {          /* in a loop */
        show(sign_1);   /* draw sign_1 */
        show(sign_2);   /* draw sign_2 */
        show(sign_3);   /* draw sign_3 */
        show(sign_4);   /* draw sign_4 */
    }
    endwin();           /* reset the tty etc */
}
void show(char *sign)
{
/* 
 *  draw a sign and wait 1 second
 */
    move(ROW, COL);             /* move cursor for drawing */
    waddstr(stdscr, "Hello, world!");
    move(ROW+1, COL);
    addstr("Init:");
    addstr(sign);               /* add a string */
    move(LINES+1, COL);           /* move cursor */
    refresh();                  /* refresh window */
    usleep(1*1000*1000);                   /* sleep */
}
