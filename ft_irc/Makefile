#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := ircserv
CC         := c++
FLAGS    := -Wall -Wextra -Werror -std=c++98 -g -D_GLIBCXX_DEBUG
 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/Server.cpp \
                          src/main.cpp \
                          src/Channel.cpp \
                          src/Utils.cpp \
                          src/Client.cpp \
						  src/Error.cpp \
						  src/commands/JOIN.cpp \
						  src/commands/MODE.cpp \
						  src/commands/KICK.cpp \
						  src/commands/INVITE.cpp \
						  src/commands/PART.cpp \
						  src/commands/TOPIC.cpp \
						  src/commands/QUIT.cpp \
						  src/commands/PRIVMSG.cpp \

                          
OBJS        := ${SRCS:.cpp=.o}

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all


################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/Server.cpp \
                          src/main.cpp \
                          src/Channel.cpp \
                          src/Utils.cpp \
                          src/Client.cpp \
						  src/Error.cpp \
						  src/commands/JOIN.cpp \
						  src/commands/MODE.cpp \
						  src/commands/KICK.cpp \
						  src/commands/TOPIC.cpp \
						  src/commands/INVITE.cpp \
						  src/commands/QUIT.cpp \
						  src/commands/PART.cpp \
						  src/commands/PRIVMSG.cpp \
                        
OBJS        := ${SRCS:.cpp=.o}

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}
