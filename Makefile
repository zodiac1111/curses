# curses 库使用笔记
# curses 旧的实现,有些系统可能没有
# ncurses new curses  新的开源实现
# ncursesw new curses 宽字节实现 (UTF-8字符)
# 可能需要`setlocale(LC_ALL,"");`配合 
CC=gcc
LIB_CURSES= -lncursesw
EXES= hello cur pop first

OBJS = $(SRCS:.c = .o)

.PHONY:all clean $(EXES)

all:${EXES}

# 简单文件,可执行文件与c源文件同名,没有依赖,每次重新编译
$(EXES): 
	$(CC) -o $@  $@.c ${LIB_CURSES}

clean:
	rm -f $(EXES)
