CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClapTrap.cpp 

OBJS = $(SRCS:.cpp=.o)

TARGET = Serena,MyLove!

all: $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) scavTrap.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
