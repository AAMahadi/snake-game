CC = gcc
CFLAGS = -Wall -Iinclude -Ilib/raylib/src
RAYLIB_DIR = lib/raylib/src
RAYLIB_LIB = $(RAYLIB_DIR)/libraylib.a

LDFLAGS = -L$(RAYLIB_DIR) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/main.c src/snake.c src/food.c
OBJS = $(SRCS:.c=.o)
TARGET = build

.PHONY: all clean run

all: $(TARGET)

$(RAYLIB_LIB):
	$(MAKE) -C $(RAYLIB_DIR) RAYLIB_LIBTYPE=STATIC

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) $(RAYLIB_LIB)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
	$(MAKE) -C $(RAYLIB_DIR) clean