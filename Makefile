# curses 库使用笔记
all:
	gcc hello.c -lcurses
	#gcc -o bullseye bullseye.c -lcurses
cur:cur.c
	gcc $< -o $@ -lcurses
pop:pop.c
	gcc $< -o $@ -lcurses
first:first.c
	gcc $< -o $@ -lcurses
clean:
	rm -f cur a.out pop first
