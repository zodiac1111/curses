# curses 库使用笔记
# curses 旧的实现,有些系统可能没有
# ncurses new curses  新的开源实现
# ncursesw new curses 宽字节实现 (UTF-8字符)
CC=gcc
LIB_CURSES= -lncursesw
EXES= hello cur pop first
OBJS = $(SRCS:.c = .o)
.PHONY:all clean sub
all:${EXES}
$(EXES):
	$(CC) -o $@  $@.c ${LIB_CURSES}
clean:
	rm -f $(EXES)
