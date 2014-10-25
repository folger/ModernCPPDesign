make_subdir := ./UnitTest/maker/ ./maker/

all :
	@for subdir in $(make_subdir); do\
		$(MAKE) -C $$subdir;\
	done;

.PHONY : clean
clean :
	@for subdir in $(make_subdir); do\
		$(MAKE) -C $$subdir clean;\
	done;
