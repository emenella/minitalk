GCC := @gcc -Wall -Wextra -Werror
AR := @ar -rsv
GNL := ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
LIBFT := ./libft/ft_atoi.c ./libft/ft_isalnum.c ./libft/ft_isdigit.c ./libft/ft_itua.c ./libft/ft_lstclear.c ./libft/ft_lstlast.c ./libft/ft_lstsize.c ./libft/ft_memcmp.c ./libft/ft_memset.c ./libft/ft_putnbr_fd.c ./libft/ft_strchr.c ./libft/ft_strlcat.c ./libft/ft_strmapi.c ./libft/ft_strrchr.c ./libft/ft_tolower.c ./libft/ft_bzero.c ./libft/ft_isalpha.c ./libft/ft_isprint.c ./libft/ft_lstadd_back.c ./libft/ft_lstdelone.c ./libft/ft_lstmap.c ./libft/ft_memccpy.c ./libft/ft_memcpy.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_strdup.c ./libft/ft_strlcpy.c ./libft/ft_strncmp.c ./libft/ft_strtrim.c ./libft/ft_toupper.c ./libft/ft_calloc.c ./libft/ft_isascii.c ./libft/ft_itoa.c ./libft/ft_lstadd_front.c ./libft/ft_lstiter.c ./libft/ft_lstnew.c ./libft/ft_memchr.c ./libft/ft_memmove.c ./libft/ft_putendl_fd.c ./libft/ft_split.c  ./libft/ft_strjoin.c ./libft/ft_strlen.c  ./libft/ft_strnstr.c ./libft/ft_substr.c ./libft/ft_islower.c ./libft/ft_isupper.c
NAME := ../libft.a
OBJ := $(GNL:.c=.o) $(LIBFT:.c=.o)
HEADER := ./libft/libft.h ./get_next_line/get_next_line.h
COM_STRING  = "Compiling"
COM_COLOR   = \033[0;34
NO_COLOR    = \033[m
OBJ_COLOR   = \033[0;36m

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@printf "%b" "\033[0;32m libft is done !$(NO_COLOR)\n"

%.o: %.c $(HEADER) $(SRC)
	@printf "%b" "\033c";
	@printf "%b" "$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
	$(GCC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@printf "%b" "\033[0;32m clean libft$(NO_COLOR)\n"

fclean:
	@rm -f $(NAME) $(OBJ)
	@printf "%b" "\033[0;32m fclean libft$(NO_COLOR)\n"

re: fclean all
