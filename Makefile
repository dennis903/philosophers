CC = gcc -lncurses
TARGET = philo

OBJS =	./main.c	\
		./srcs/init.c	\
		./srcs/error.c	\
		./srcs/check_valid.c	\
		./srcs/start.c	\
		./srcs/act_philo.c

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all