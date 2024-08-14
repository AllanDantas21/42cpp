CC = g++

CFLAGS = -Wall -Wextra -Werror #-std=c++98

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = Harl
all: $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
