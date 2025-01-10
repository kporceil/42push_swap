NAME := push_swap

BONUSNAME := checker

override SRCDIR := srcs/

override BONUSSRCDIR := $(addprefix bonus/, $(SRCDIR))

override BUILDDIR := .build/

override BONUSBUILDDIR := $(addprefix bonus/, $(BUILDDIR))

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override BONUSOBJDIR := $(addprefix bonus/, $(OBJDIR))

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

override BONUSDEPDIR := $(addprefix bonus/, $(DEPDIR))

BASENAME := memory_utils parsing push_swap indexer sort sort_utils swap_mov_a \
			swap_mov_b

BONUSBASENAME := checker get_next_line get_next_line_utils memory_utils \
				 parsing push_swap swap_mov_a swap_mov_b swap_mov_ab

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override BONUSSRCS := $(addprefix $(BONUSSRCDIR), $(addsuffix .c, $(BONUSBASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override BONUSOBJS := $(addprefix $(BONUSOBJDIR), $(addsuffix .o, $(BONUSBASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override BONUSDEPS := $(addprefix $(BONUSDEPDIR), $(addsuffix .d, $(BONUSBASENAME)))

override LIBFT := libft/libft.a

override LDFLAGS := -lft

override LDLIBS := -L libft/

INCS := includes

CC := cc

CFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -I$(INCS)

DEPSFLAGS := -MD -MP -MF

LIBFLAGS := -lft

MAKEFLAGS += --no-print-directory

.PHONY: all
all: 
	@$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $(NAME) -g3

$(OBJDIR)%.o: $(SRCDIR)%.c | $(BUILDDIR) $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@ -g3

$(LIBFT): FORCE
	@$(MAKE) -C libft/

.PHONY: bonus
bonus:
	@$(MAKE) $(BONUSNAME) INCS="bonus/$(INCS)"

$(BONUSNAME): $(BONUSOBJS) $(LIBFT)
	$(CC) $(CLAGS) $(CPPFLAGS) $(BONUSOBJS) $(LDLIBS) $(LDFLAGS) -o $(BONUSNAME) -g3

$(BONUSOBJDIR)%.o: $(BONUSSRCDIR)%.c | $(BONUSBUILDDIR) $(BONUSOBJDIR) $(BONUSDEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(BONUSDEPDIR)$*.d -c $< -o $@ -g3

.PHONY: FORCE
FORCE:

$(BUILDDIR) $(OBJDIR) $(DEPDIR) $(BONUSBUILDDIR) $(BONUSDEPDIR) $(BONUSOBJDIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(MAKE) clean -C libft/
	rm -rf $(BUILDDIR)

.PHONY: bonusclean
bonusclean:
	@$(MAKE) clean -C libft/
	rm -rf $(BONUSBUILDDIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) fclean -C libft/
	rm -f $(NAME)

.PHONY: bonusfclean
bonusfclean: bonusclean
	@$(MAKE) fclean -C libft/
	rm -f $(BONUSNAME)

.PHONY: re
re: fclean all

-include $(DEPS)
