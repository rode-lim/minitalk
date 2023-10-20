# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 03:00:38 by rode-lim          #+#    #+#              #
#    Updated: 2023/10/20 03:00:38 by rode-lim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server 
CLIENT = client

Srv		=	server.c \
			utils.c

clnt =	client.c \
		utils.c

OBJS	=	${Srv:.c=.o}
OBJC	=	${clnt:.c=.o}
CC =cc
RM =rm -rf
CFLAGS = -Wall-Werror-Wextra-g-fsanitize=address

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
			make -C $(LIBFT_PATH) 
			${CC} ${CFLAGS} $(OBJS) ${LIBFT} -o $(SERVER)
			
$(CLIENT): $(OBJC)
			make -C $(LIBFT_PATH) 
			${CC} ${CFLAGS} $(OBJC) ${LIBFT} -o $(CLIENT)
clean:
	$(RM)	$(OBJS) $(OBJC)
	@make clean -C ${LIBFT_PATH}
fclean: clean
		@rm -rf $(CLIENT) $(SERVER)
		@make fclean -C ${LIBFT_PATH}
 
re:	fclean all 