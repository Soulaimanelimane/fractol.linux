SRC=Mandatory/fractol.c Mandatory/ft_atoi.c Mandatory/mandel_julia.c Mandatory/draw.c Mandatory/ft_strcmp.c
BSRC= bonus/fractol_bonus.c bonus/draw_bonus.c bonus/buring_ship_bonus.c bonus/ft_strcmp_bonus.c

OBJ= ${SRC:.c=.o}
BOBJ= ${BSRC:.c=.o}

CC= cc 
CFLAGS=  -Wall -Wextra -Werror  
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

NAME = fractol
BONUS = fractol_bonus
 
all:${NAME}

%bonus.o:%bonus.c bonus/fractol_bonus.h
	${CC} ${CFLAGS} -c $< -o $@

%.o:%.c  Mandatory/fractol.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:${OBJ} 
	${CC}  ${OBJ}  ${MLX_FLAG}   -o ${NAME}

bonus:${BONUS}

${BONUS}:${BOBJ}
	${CC}  ${BOBJ}  ${MLX_FLAG}   -o ${BONUS}

clean:
	rm -rf ${OBJ} ${BOBJ}
fclean:clean
	rm -rf ${NAME} ${BONUS}

re:fclean all

.PHONY: clean