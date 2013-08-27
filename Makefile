# curses 库使用笔记
all:
	gcc hello.c -lcurses
	#gcc -o bullseye bullseye.c -lcurses
cur:cur.c
	gcc cur.c -o $@ -lcurses
clean:
	rm -f cur a.out
