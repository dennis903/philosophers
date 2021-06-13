CC = gcc -lncurses -lpthread
TARGET = philo

OBJS =	./main.c	\
		./srcs/init.c	\
		./srcs/error.c	\
		./srcs/check_valid_arg.c	\
		./srcs/start.c	\
		./srcs/act_philo.c	\
		./srcs/time.c	\
		./srcs/ft_atoi.c	\
		./srcs/ft_strlen.c

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $@

clean :
	rm -rf $(TARGET)

fclean : clean
	rm -rf $(TARGET)

re : clean all