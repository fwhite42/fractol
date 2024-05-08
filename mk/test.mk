test/%: test/%.c $(LIBRARY_FILES)
	@echo "Compiling test: $@"
	@$(CC) $(CPPFLAGS) -o $@ $< $(call reverse, $(LIBRARY_FILES)) -lX11 -lXext> /dev/null
	@echo "Compiled !"
	@echo
	@echo .................................................... TEST START
	@echo
	@$@
	@$(RM) $@ > /dev/null
	@echo
	@echo .................................................... TEST END
	@echo

.PHONY: test
test: $(REQ_TEST:%=test/%)
