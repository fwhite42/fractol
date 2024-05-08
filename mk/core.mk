###############################################################################
# Metadata
###############################################################################

## Name of the project, but also name of the executable made by this makefile
NAME		?= $(notdir $(CURDIR))

## Phony fn used to print the name
.PHONY: check_name
check_name:
	@echo Project Name: $(NAME)

###############################################################################
# Targets
###############################################################################

## Run "make" to run "make all"
.DEFAULT_GOAL	:= all

## Run "make all" to run "make $(NAME)"
.PHONY: all
all:		$(NAME)

## Run "make re" to recompile everything from zero.
.PHONY: re
re:		fclean all

###############################################################################
# Directories
###############################################################################

## The prefix directory is the "path/to/root/of/the/project"
prefix		?= $(CURDIR)

## Sets the default values for installation directories (if they are missing)
includedir	?= $(prefix)/include
libdir		?= $(prefix)/lib
bindir		?= $(prefix)/bin

## Sets the default value for the source directory
srcdir		?= $(prefix)/src

## Defines the various directory lists
INSTALLDIRS	:= $(includedir) $(libdir) $(bindir)

## Defines a list with all directories that may be created by make
MAKEABLE_DIRS	:= $(INSTALLDIRS)

## Command to create directories (the "-p" flag is not posix)
MKDIR_P		:= mkdir -p

## Rule to make directories
$(MAKEABLE_DIRS):%:
	$(MKDIR_P) $@

.PHONY: check_dirs
check_dirs:
	@echo Source Directory \(where source libs are found\): $(srcdir)
	@echo Command to create directories: $(MKDIR_P)
	@echo Direcotires that may be created by this makefile:
	@echo $(MAKEABLE_DIRS)
###############################################################################
# Dependecies
###############################################################################

## List of target library names, computed from stems.
LIBRARIES 	:= $(RARIES:%=lib%)

## List of library archives paths
LIBRARY_FILES	:= $(LIBRARIES:%=$(libdir)/%.a)

## List of library headers paths
HEADERS		:= $(LIBRARIES:%=$(includedir)/%.h)

###############################################################################
# Rules to expose headers
###############################################################################
.SECONDEXPANSION:
## Individual headers are installed from their source, with a copy
$(HEADERS):$(includedir)/%.h	: $(srcdir)/$$*/$$*.h $(includedir)
	cp $(srcdir)/$*/$*.h $(includedir)/$*.h

## Phony rule to make all required headers
.PHONY: headers
headers: $(HEADERS)

###############################################################################
# Rules to expose libraries
## Compiles an individual library and installs the archive
$(LIBRARY_FILES):$(libdir)/%.a: $(srcdir)/%/Makefile $(libdir) $(HEADERS)
	$(MAKE) -C $(dir $<) includedir=$(includedir)
	cp $(srcdir)/$*/$*.a $(libdir)/$*.a

## Phony rule to make all required archives
.PHONY: libraries
libraries: $(LIBRARY_FILES)

###############################################################################
# Implicit rules
###############################################################################

## Implicit rules for compiling .c files
CC		?= gcc
CFLAGS		?= -Wall -Werror -Wextra
CPPFLAGS	?= -Iinclude 

###############################################################################
# Library linking
###############################################################################

## Tells make to look for .a files inside the $(libdir)
vpath %.a $(libdir)

## Tells make that to resolve -l%, it needs to make the corresponding lib
-l%: $(lib)/lib%.a
	@echo Linked $< !

## Reverse the order of a list, libraries need to be linked in reverse order
## with respect to their compilation.

define reverse
$(if $(1),$(call reverse,$(wordlist 2,$(words $(1)),$(1)))) $(firstword $(1))
endef

LINKS	:= $(call reverse, $(RARIES:%=-l%))

ifeq ($(X11), TRUE)
LINKS	+= -lX11 -lXext
endif

.PHONY: check_links
check_links:
	@echo Source Libraries: $(LIBRARIES)
	@echo All Linked Libraries: $(LINKS)

###############################################################################
# Main rule
###############################################################################

## $(NAME) is compiled with implicit rules from $(NAME).c. 
$(NAME):	$(NAME).c $(LINKS) -lm

###############################################################################
# Cleaners
###############################################################################

.PHONY:
clean: ;

## Calls "make fclean" inside EACH library folder
.PHONY: fclean
fclean: clean
	@for lib in $(LIBRARIES:%=$(srcdir)/%); do $(MAKE) -C $$lib fclean; done
	$(RM) -r $(includedir) $(libdir) $(bindir)
	$(RM) $(NAME)

###############################################################################
# Assets
###############################################################################

assetsdir	?= assets

.PHONY: maps
maps:
	$(MAKE) -C assets/map

.PHONY: check
check: check_name check_dirs check_links
