all : libctrlcar.so
%.so : %.c
	@gcc --shared $^ -o $@
.PHONY : clean
clean:
	rm -f *.so
