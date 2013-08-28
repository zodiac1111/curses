# curses 库使用笔记
# curses 旧的实现,有些系统可能没有
# ncurses new curses  新的开源实现
# ncursesw new curses 宽字节实现 (UTF-8字符)
all:
	gcc hello.c -lncursesw
	#gcc -o bullseye bullseye.c -lcurses
cur:cur.c
	gcc $< -o $@ -lncursesw
pop:pop.c
	gcc $< -o $@ -lncursesw
first:first.c
	gcc $< -o $@ -lncursesw
clean:
	rm -f cur a.out pop first
