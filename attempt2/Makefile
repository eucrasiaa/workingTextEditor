CC = gcc
CFLAGS = -g -Wall -Wextra -Iinclude
# LDFLAGS = $(shell pkg-config --libs sdl2)
# CFLAGS += $(shell pkg-config --cflags sdl2)

SRC=src
# all .c
SRCS=$(wildcard $(SRC)/*.c)
# *.c -> *.o
OBJS = $(SRCS:$(SRC)/%.c=obj/%.o)

TARGET=weditor

run: $(TARGET)
	./weditor


val: $(TARGET)
	valgrind ./weditor

gdb: $(TARGET)
	gdb ./weditor

clean:
	rm -rf ./obj/* & rm weditor 
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) -fsanitize=address

obj/%.o: $(SRC)/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
