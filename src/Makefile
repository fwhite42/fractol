###############################################################################
# Metadata
###############################################################################

## Generates library name (name from the folder name).
NAME		:= $(patsubst lib%,%,$(notdir $(CURDIR)))

## Generates archive name (from the value of $(NAME))
ARCHIVE		:= lib$(NAME).a

## List of getters
GMETHODS	= $(foreach fn, $(GETTERS), $(word 1, $(subst :, ,$(fn))))

## List of setters
SMETHODS	= $(foreach fn, $(SETTERS), $(word 1, $(subst :, ,$(fn))))

## Lis of all methods (MIND THAT THESE HAVE TO BE DEFINED OUTSIDE)
METHODS		+= $(GMETHODS) $(SMETHODS)

SOURCE		:= $(METHODS:%=$(NAME)_%.c)
OBJECTS		:= $(SOURCE:%.c=%.o)

.PHONY: check
check:
	@echo Module Name: $(NAME)
	@echo Getters:
	@echo $(GMETHODS:%=%)
	@echo Setters
	@echo $(SMETHODS:%=%)
	@echo Core Methods
	@echo $(filter-out $(GMETHOS) $(SMETHODS), $(METHODS:%=%));
	@echo Source Files:
	@echo $(SOURCE)
	@echo Object Files:
	@echo $(OBJECTS)

###############################################################################
# Implicit Rules
###############################################################################

## Implicit rules for compiling C programs
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -o3
CPPFLAGS	:= -I$(includedir) -I$(CURDIR)	

## Look inside $(includedir) for header files (if $(includedir) is defined)
ifdef (includedir)
CPPFLAGS	+= -I$(includedir)
endif

## Implicit rules for archiving objects
AR		:= ar
ARFLAGS		:= -rcs

###############################################################################
# Targets
###############################################################################

.DEFAULT_GOAL = all

.PHONY: all
all: $(ARCHIVE)

.PHONY: objects
objects: $(OBJECTS)

# Running "make re", (re)compiles the library, using implicit rules.
# Because $(OBJECTS) are automatically removed, this will always "relink"
.PHONY: re
re: fclean all

# Running "make $(NAME)" compiles and creates $(ARCHIVE)
.PHONY: $(NAME)
$(NAME): $(ARCHIVE)

# The command to generate the archive is simply "make re"
$(ARCHIVE): $(ARCHIVE)($(OBJECTS))

.PHONY: clean
clean:
	$(RM) *.o

.PHONY: fclean

fclean: clean
	$(RM) *.a
	$(RM) $(GMETHODS:%=$(NAME)_%.c)
	$(RM) $(SMETHODS:%=$(NAME)_%.c)


###############################################################################
# Wait what?

DEFINE	:= $(MAKE) -f ../../mk/define.mk

.PHONY: getters
getters:
	@printf "Generating getters for lib$(NAME)..."
	@for i in $(GETTERS:%=$(NAME)_%); do $(DEFINE) $$i; done > /dev/null
	@printf "done!\n"
.PHONY:setters
setters:	
	@printf "Generating setters for lib$(NAME)..."
	@for i in $(SETTERS:%=$(NAME)_%); do $(DEFINE) $$i; done > /dev/null
	@printf "done!\n"

$(GMETHODS:%=$(NAME)_%.c):%: getters
$(SMETHODS:%=$(NAME)_%.c):%: setters

.PHONY: touch_all
touch_all:
	touch $(METHODS:%=$(NAME)_%.c)	
