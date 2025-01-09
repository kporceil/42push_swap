NAME := push_swap

override SRCDIR := ./

override BUILDDIR := .build/

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

BASENAME := memory_utils parsing push_swap indexer sort sort_utils swap_mov_a \
			swap_mov_b

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override LIBFT := libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -I.

DEPSFLAGS := -MD -MP -MF

LIBFLAGS := -lft

MAKEFLAGS += --no-print-directory

.PHONY: all
all: 
	@$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CLAGS) $(CPPFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -g3

$(OBJDIR)%.o: $(SRCDIR)%.c | $(BUILDDIR) $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@ -g3

$(LIBFT): FORCE
	@echo "[STEP] Make LIBFT"
	@$(MAKE) -C libft/

.PHONY: FORCE
FORCE:

$(BUILDDIR) $(OBJDIR) $(DEPDIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(MAKE) clean -C libft/
	rm -rf $(BUILDDIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) fclean -C libft/
	rm -f $(NAME)

.PHONY: re
re: fclean all

-include $(DEPS)
