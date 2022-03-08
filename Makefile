# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 22:25:23 by aait-mas          #+#    #+#              #
#    Updated: 2022/03/04 16:33:54 by aait-mas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SERVER = server
CLIENT = client
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CLIENT_BONUS_SRC = client_bonus.c
SERVER_BONUS_SRC = server_bonus.c
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	
$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT)
	
$(SERVER): $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o $(SERVER)
	
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	$(CC) $(FLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_OBJ)
	$(CC) $(FLAGS) $(SERVER_BONUS_OBJ) -o $(SERVER_BONUS)

clean:
	rm -f *.o

fclean:	clean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re:	fclean all

