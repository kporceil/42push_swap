override SRCDIR := ./

override BUILDIR := build/

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

CC := cc

CFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -I.

DEPSFLAGS := -MD -MP -MF

