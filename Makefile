libf = utils/ft_printf/libftprintf.a
libf_dir = utils/ft_printf
s_utils = utils/ft_atoi.c
o_utils = $(s_utils:.c=.o)

all:client server

client:$(o_outils) $(libf)
	gcc client.c $(libf) $(o_utils) -o client

server:$(o_outils) $(libf)
	gcc client.c $(libf) $(o_utils) -o client
%.o:%.c
	gcc $(CFLAGS) -c $< -o $@
%.a:
	make $(libf_dir)

