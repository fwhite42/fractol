# Fetch the OS

OS	= $(shell uname)

# Use the value of $(OS) to determine which src folder shoudl be compiled

ifeq ($(OS),MacOS)
TARGET = libmlx-macos
endif

ifeq ($(OS),Linux)
TARGET	= libmlx-linux
endif

# Phony rule to check the above

.PHONY: check_os
check_os:	
	@echo os:$(OS)
	@echo target:$(TARGET)

# Sets the vars

ARCHIVE		= libmlx.a
HEADER		= libmlx.h
.DEFAULT_GOAL	= $(ARCHIVE)

# Define the rules to make header and archives

$(ARCHIVE): $(TARGET)/Makefile
	$(MAKE) -C $(TARGET)
	cp $(TARGET)/libmlx_Linux.a libmlx.a

$(HEADER): $(TARGET)/mlx.h
	cp $(TARGET)/mlx.h libmlx.h

# Cleaners

fclean:
	$(RM) *.o
	$(RM) *.a

# Run test

test: $(ARCHIVE)
	sh $(TARGET)/test/run_tests.sh
	gcc test.c -L. -lmlx -lX11 -lXext -o test
	./test
	$(RM) test
