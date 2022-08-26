NAME = philo

CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -pthread

INCLUDES	= -I$(HEADERS) -lpthread

HEADERS			= $(addprefix $(HEADER_DIR), $(HEADER_LIST))
HEADER_DIR		= ./inc/
HEADER_LIST		= philo.h

SRCS			= $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_DIR			= ./src/
SRC_LIST		= main.c\
					error.c\
					argument.c\
					atoi.c\
					monitor.c\
					mutex.c\
					philosopher.c\
					destroy.c\
					dealloc.c\
					time.c\
					philo_routine.c\
					print.c\
					usleep.c\
					monitor_routine.c


OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_DIR			= ./obj/
OBJ_LIST		= $(patsubst %.c, %.o, $(SRC_LIST))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDES)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $^
	mv $(OBJ_LIST) $(OBJ_DIR)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re