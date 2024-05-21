include	$(MK)/utils.mk

# Metadata
NAME			?= $(notdir $(CURDIR))

# Directories
prefix			?= $(CURDIR)
includedir		?= $(prefix)/include
libdir			?= $(prefix)/lib
bindir			?= $(prefix)/bin
srcdir			?= $(prefix)/src

INSTALLDIRS		:= $(includedir) $(libdir) $(bindir)
MAKEABLE_DIRS	:= $(INSTALLDIRS)
MKDIR_P			:= mkdir -p

LIBRARIES		:= $(RARIES:%=lib%)
LIBRARY_FILES	:= $(LIBRARIES:%=$(libdir)/%.a)
LINK_LIBRARIES	:= $(call reverse, $(LIBRARY_FILES))
HEADERS			:= $(LIBRARIES:%=$(includedir)/%.h)

# Rules
$(MAKEABLE_DIRS):%:
	$(MKDIR_P) $@

.SECONDEXPANSION:
$(HEADERS):$(includedir)/%.h: $(srcdir)/$$*/$$*.h $(includedir)
	cp $(srcdir)/$*/$*.h $(includedir)/$*.h
define archive_path
$(srcdir)/$1/$1.a
endef

SLIB	:= $(foreach lib, $(LIBRARIES), $(call archive_path,$(lib)))

.PHONY: $(SLIB)
$(SLIB):%: $(srcdir)
	$(MAKE) -C $(dir $@) includedir=$(includedir)

$(LIBRARY_FILES):$(libdir)/%.a: $(HEADERS) $(call archive_path,$$*) | $(libdir)
	install -C -v -m 644 $(srcdir)/$*/$*.a $(libdir)/

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -o3
CPPFLAGS	:= -I$(includedir)
vpath %.a	$(libdir)

OS	= $(shell uname)
ifeq ($(OS),Darwin)
CPPFLAGS += -framework OpenGl -framework AppKit

endif

ifeq ($(OS),Linux)
LINK_LIBRARIES += -lX11 -lXext -lm
endif

fuck:
	echo $(OS)


$(NAME)		:$(NAME).c $(LIBRARY_FILES)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ $(LINK_LIBRARIES) -o $@

# Phonies
.PHONY: all
all:		$(NAME)

.PHONY: re
re:		fclean all


.PHONY: libraries
libraries: $(LIBRARY_FILES)

.PHONY: headers
headers: $(HEADERS)

.PHONY: clean
clean: ;

.PHONY: fclean
fclean: clean
	@for lib in $(LIBRARIES:%=$(srcdir)/%); do $(MAKE) -C $$lib fclean; done
	$(RM) -r $(includedir) $(libdir) $(bindir)
	$(RM) $(NAME)
