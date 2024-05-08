HEADER	= lib$(NAME).h
UCNAME	= $(shell echo $(NAME) | tr a-z A-Z)


define split_ptr_type
$(subst *,,$1):$(subst $(subst *,,$1),,$1)
endef


define append_line
	echo $1 #>> $2
endef

null	:=
space	:= $(null) $(null)
$(space) := $(space)

$(HEADER):
	@$(call append_line,"#ifndef $(UCNAME)_H",$@)
	@$(call append_line,"# define $(UCNAME)_H\n",$@)
	@$(call append_line,"typedef struct s_$(NAME)",$@)
	@$(call append_line,"{",$@)
	@$(call append_line,"$(subst ;$(space),;\n$(null),$(FIELDS:%=\t%))",$@)
	@$(call append_line,"}\tt_$(NAME);",$@)
	@$(call append_line,"$(METHODS:%=%)",$@)
	@$(call append_line,"#endif",$@)

$(CREATE_NULL).c:
	$(call append_line,"#include\"libft.h\"",$@)
	$(call append_line,"#include\"$(HEADER)\"",$@)
	$(call append_line,,$@)
	$(call append_line,"void\t*$(CREATE_NULL)(void)",$@)
	$(call append_line,"{",$@)
	$(call append_line,"\tvoid\t*ptr;",$@)
	$(call append_line,,$@)
	$(call append_line,"\tptr = ft_calloc(1,sizeof(t_$(NAME)));",$@)
	$(call append_line,"\treturn (ptr);",$@)
	$(call append_line,"}",$@)


$(NAME).c:
	$(call append_line,"#include\"$(HEADER)\"",$@)
	$(call append_line,,$@)
	$(call append_line,"t_$(NAME)\tgame(void *self)",$@)
	$(call append_line,"{",$@)
	$(call append_line,"\treturn (t_$(NAME) *(self))",$@)
	$(call append_line,"}",$@)


define FIELDS
	void	**list;
	void	*ptr;
	int	nbr;
endef

define METHODS
	void	*create_null(void);
	void	*destroy(void *self);
endef	
CLASS = $(FIELDS:%=%)
