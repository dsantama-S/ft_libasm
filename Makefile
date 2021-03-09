SRCS	= ft_strlen.s
CFLAGS	= -fmacho64
CC		= nasm
OBJS	= ${SRCS:.s=.o}
NAME	= libasm.a
RM		= rm -f

all:	${NAME}

$(NAME):		${OBJS}
				ar rcs ${NAME} ${OBJS}

%.o:			%.s
				${CC} ${CFLAGS} $<

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY : all clean fclean re