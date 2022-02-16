NAME	=	pipex

SRCS_F	=	main.c cmd_utils.c env_utils.c parsing.c errors.c pipex.c

SRCS_D	=	srcs/

SRCS	=	$(addprefix ${SRCS_D}, ${SRCS_F})

OBJS	=	$(SRCS:.c=.o)

INCL_D	=	includes/

LIB_D	=	libft/

LIBFT	=	${LIB_D}libft.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

all		:	${NAME}

bonus	:	${NAME}

%.o		:	%.c $(addprefix ${INCL_D}, pipex.h)
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCL_D} -I ${LIB_D}

${LIBFT}:
			make -C ${LIB_D}
			make bonus -C ${LIB_D}

${NAME}	:	${OBJS} ${LIBFT}
			${CC} ${OBJS} -o ${NAME} ${LIBFT}

clean	:
			${RM} ${OBJS}
			make clean -C ${LIB_D}

fclean	:	clean
			${RM} ${NAME}
			make fclean -C ${LIB_D}

re		:	fclean all

.PHONY	:	all clean fclean re
