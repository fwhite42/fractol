# Fetch the OS

OS	= $(shell uname)

# Use the value of $(OS) to determine which src folder shoudl be compiled

ifeq ($(OS),Darwin)
TARGET = libmlx-macos
endif

ifeq ($(OS),Linux)
TARGET	= libmlx-linux
SUN_TARGET = Linux
endif

# Phony rule to check the above

# Sets the vars

ARCHIVE		= libmlx.a
HEADER		= libmlx.h

# Define the rules to make header and archives

$(ARCHIVE): $(TARGET)/Makefile $(HEADER)
	$(MAKE) -C $(TARGET)
	cp $(TARGET)/libmlx$(SUB_TARGET).a libmlx.a

$(HEADER): $(TARGET)/mlx.h
	cp $(TARGET)/mlx.h libmlx.h

# Cleaners
fclean: clean
	$(RM) *.o
	$(RM) *.a
#	$(RM) *.h

# Run test
test: $(ARCHIVE)
	sh $(TARGET)/test/run_tests.sh
	gcc test.c -L. -lmlx -lX11 -lXext -o test
	./test
	$(RM) test

clean:
	$(MAKE) -C $(TARGET) clean

#.DEFAULT_GOAL	= $(ARCHIVE)
.PHONY: check_os
check_os:	
	@echo os:$(OS)
	@echo target:$(TARGET)
