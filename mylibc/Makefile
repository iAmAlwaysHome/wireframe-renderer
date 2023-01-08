CC = gcc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = myatoi.c\
	mybzero.c\
	myisalnum.c\
	myisalpha.c\
	myisascii.c\
	myisdigit.c\
	myisprint.c\
	mymemchr.c\
	mymemcmp.c\
	mymemcpy.c\
	mymemmove.c\
	mymemset.c\
	mystrchr.c\
	mystrlcat.c\
	mystrlcpy.c\
	mystrlen.c\
	mystrncmp.c\
	mystrnstr.c\
	mystrrchr.c\
	mytolower.c\
	mytoupper.c\
	mycalloc.c\
	mystrdup.c\
	mystrtrim.c\
	myitoa.c\
	mystrjoin.c\
	mystrmapi.c\
	mysubstr.c\
	mysplit.c\
	myputchar_fd.c\
	myputendl_fd.c\
	myputnbr_fd.c\
	myputstr_fd.c\
	mystriteri.c\
	mystrmapi.c\
	get_next_line_utils.c\
	get_next_line.c

BONUS = mylstadd_back.c\
	mylstadd_front.c\
	mylstclear.c\
	mylstdelone.c\
	mylstiter.c\
	mylstlast.c\
	mylstmap.c\
	mylstnew.c\
	mylstsize.c

MAN_OBJS = $(MANDATORY:.c=.o)
BON_OBJS = $(BONUS:.c=.o)
NAME = mylibc.a

ifdef WITH_BONUS
MAN_OBJS += $(BON_OBJS)
endif

all: $(NAME)

$(NAME): $(MAN_OBJS)
	ar r $(NAME) $(MAN_OBJS)

bonus:
	make all WITH_BONUS=1

clean:
	rm -f $(MAN_OBJS) $(BON_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus