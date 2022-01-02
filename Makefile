# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 23:49:14 by moulmado          #+#    #+#              #
#    Updated: 2022/01/03 00:41:43 by moulmado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = mandatory/client.c
SERVER = mandatory/server.c
B_CLIENT = bonus/client_bonus.c
B_SERVER = bonus/server_bonus.c
CLIENT_B = client_bonus
SERVER_B = server_bonus
UTILS = utils/minitalk_utils.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -rf

all : client server
	@echo "███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗"
	@echo "████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝"
	@echo "██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░"
	@echo "██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░"
	@echo "██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗"
	@echo "╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝"
	
client : $(CLIENT)
	$(CC) $(CFLAGS) $(CLIENT) $(UTILS) -o $@
	
server : $(SERVER)
	$(CC) $(CFLAGS) $(SERVER) $(UTILS) -o $@

clean :
	$(RM) client server client_bonus server_bonus
	@echo "CLEANED"

bonus :  bonus_client bonus_client
	@echo "successfuly made bonus files"

bonus_client : $(B_CLIENT)
	$(CC) $(CFLAGS) $(B_CLIENT) $(UTILS) -o $(CLIENT_B)

bonus_server : $(B_SERVER)
	$(CC) $(CFLAGS) $(B_SERVER) $(UTILS) -o $(SERVER_B)
	
re : clean client server
	