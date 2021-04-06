NAME = libasm.a
CFLAGS = -Wall -Werror -Wextra -I. -c
NFLAGS = -f macho64
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s  ft_strdup.s
OBJ = $(SRC:.s=.o)

%.o:%.s
	nasm $(NFLAGS) $<

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -c main.c
	gcc main.o $(OBJ)

clean:
	rm -f $(OBJ) main.o

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: clean fclean all re
