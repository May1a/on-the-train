SRC := srcs
INCLUDE := include

all: libft.a

libft.a: $(SRC)/ft_putchar.o $(SRC)/ft_swap.o $(SRC)/ft_putstr.o $(SRC)/ft_strlen.o $(SRC)/ft_strcmp.o:
	ar rc libft.a $(SRC)/ft_putchar.o $(SRC)/ft_swap.o $(SRC)/ft_putstr.o $(SRC)/ft_strlen.o $(SRC)/ft_strcmp.o

$(SRC)/ft_putchar.o: $(SRC)/ft_putchar.c $(INCLUDE)/ft.h
	cc -Qunused-arguments -Wall -Wextra -Werror -c $(SRC)/ft_putchar.c -o $(SRC)/ft_putchar.o

$(SRC)/ft_swap.o: $(SRC)/ft_swap.c $(INCLUDE)/ft.h
	cc -Qunused-arguments -Wall -Wextra -Werror -c $(SRC)/ft_swap.c -o $(SRC)/ft_swap.o

$(SRC)/ft_putstr.o: $(SRC)/ft_putstr.c $(INCLUDE)/ft.h
	cc -Qunused-arguments -Wall -Wextra -Werror -c $(SRC)/ft_putstr.c -o $(SRC)/ft_putstr.o

$(SRC)/ft_strlen.o: $(SRC)/ft_strlen.c $(INCLUDE)/ft.h
	cc -Qunused-arguments -Wall -Wextra -Werror -c $(SRC)/ft_strlen.c -o $(SRC)/ft_strlen.o

$(SRC)/ft_strcmp.o: $(SRC)/ft_strcmp.c $(INCLUDE)/ft.h
	cc -Qunused-arguments -Wall -Wextra -Werror -c $(SRC)/ft_strcmp.c -o $(SRC)/ft_strcmp.o

clean:
	rm \
	$(SRC)/ft_strcmp.o \
	$(SRC)/ft_strlen.o \
	$(SRC)/ft_putstr.o \
	$(SRC)/ft_swap.o   \
	$(SRC)/ft_putchar.o
