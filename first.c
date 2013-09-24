#include <ncurses.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	initscr();                 /* 初始化,进入 NCURSES 模式  */
	printw("Hello World !!!你好,世界."); /* 在虚拟屏幕上打印 Hello, World! */
	//mvaddch(2,3,'a'|A_BOLD);
	refresh();                 /* 将虚拟屏幕上的内容写到显示器上,并刷新 */
	getch();                   /* 等待用户输入 */
	endwin();                  /* 退出 NCURSES 模式 */
	return 0;
}
