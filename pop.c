// 弹出窗口效果
#include <curses.h>

int main(void)
{
	int ch,x,y;
	WINDOW *win;

	initscr(); //  ←┐
	cbreak;    //   │ 启动 curses 模式
	noecho();  //   │
	nonl();    //  ←┘

	win=newwin(4,30,LINES/2-3, COLS/2-15);/* 建立一个新视窗, 其中LINES,COLS */
	wborder(win,0,0,0,0,0,0,0,0); // 设置边框
	//box(win,'|','-');                     /* 设置制表符 */

	//  颜色
	/*start_color();
	init_pair(0,COLOR_GREEN,COLOR_WHITE); 
	init_pair(1,COLOR_BLACK,COLOR_WHITE); 
	wbkgd(win,0);
	bkgd(1);
	*/
	//内容
	mvwaddstr(win,1,4,"This is another screen");
	mvwaddstr(win,2,2,"Press anykey to continue..");


	for (y=1;y<LINES-2;++y)     /* 以'@'填满萤幕 */
		for (x=1;x<COLS-2;++x)
			mvprintw(y,x,"X");
	for(;;) {
		refresh();
		ch=getch();
		switch(ch) {
		case 'q':                /* 按 'q' 键离开 */
			endwin();
			return 0;
		case '\t':              /* 按 [TAB] 键 呼叫另一视窗   */
			touchwin(win);        /* wrefresh() 前需 touchwin() */
			wrefresh(win);
			getch();              /* 按任意键关闭视窗 */
			touchwin(stdscr);
			break;
		default:
			break;
		}
	}
	return 0;
    
}
