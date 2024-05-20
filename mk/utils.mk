.SECONDEXPANSION:

define reverse
$(if $(1),$(call reverse,$(wordlist 2,$(words $(1)),$(1)))) $(firstword $(1))
endef
