define split
	$(strip $(word $1, $(subst $2,$3,$4)))
endef

define get_library
	$(call split,1,_, ,$(call split,1,:, ,$1))
endef

define get_verb
	$(call split,2,_, ,$(call split,1,:, ,$1))
endef

define get_name
	$(call split,3,_, ,$(call split,1,:, ,$1))
endef

define get_type
	$(call split,2,:, ,$1)
endef

LIBRARY	:= $(strip $(call get_library, $(data)))
VERB	:= $(strip $(call get_verb, $(data)))_
NAME	:= $(strip $(call get_name, $(data)))
TYPE	:= $(strip $(call get_type, $(data)))

ifeq ($(strip $(NAME)), )
NAME	:= $(subst _,,$(VERB))
VERB	= 
endif

CORE_TYPE	:= $(subst *,,$(TYPE))
PTR_TYPE	:= $(patsubst $(CORE_TYPE)%,%, $(TYPE))

ARG1		:= void *self
ARG2		:= $(CORE_TYPE) $(PTR_TYPE)$(NAME)

ATTRIBUTE	:= ((t_$(LIBRARY) *)self)->$(NAME)

ifneq ($(strip $(VERB)), )
ARGS		:= ($(ARG1), $(ARG2))
RETURN_TYPE	:= void\\t
BODY		:= {\n\t$(ATTRIBUTE) = $(NAME);\n}
else
ARGS		:= ($(ARG1))
RETURN_TYPE	:= $(CORE_TYPE)\\t$(PTR_TYPE)
BODY		:= {\n\treturn ($(ATTRIBUTE));\n}
endif

INCLUDE		:= \#include\"lib$(LIBRARY).h\"\n\n
FN_NAME		:= $(LIBRARY)_$(VERB)$(NAME)


PROTO		:= $(RETURN_TYPE)$(FN_NAME)$(ARGS)\n

## Definies the value of each macro, using the fragments
C_FILE 		:= $(INCLUDE)$(PROTO)$(BODY)
C_FILE_PATH	:= $(path)$(FN_NAME).c


definition:
	@echo "$(C_FILE)" > $(C_FILE_PATH)
%:
ifeq ($(strip $(data)), )
	$(MAKE) -f $(word 1, $(MAKEFILE_LIST)) data=$@ definition
endif
