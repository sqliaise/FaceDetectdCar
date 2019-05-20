OBJS := main.o src/built-in.o
CFLAGS := -L ./lib/ -lctrlcar `pkg-config --cflags --libs opencv`
PWD := $(shell pwd)
INCLUDES := -I$(PWD)
GXX := @g++ $(INCLUDES) $(CFLAGS)
export CFLAGS
export INCLUDES
export GXX

TARGET := fdc_start
all : $(TARGET)
$(TARGET) : $(OBJS)
	@make -C lib
	$(GXX) $^ -o $@
	
%.o : %.cpp
	$(GXX) -c $<

src/built-in.o :
	@make -C src
	
.PHONY : clean
clean:
	rm -f *.o $(TARGET)
	rm -f $(PWD)/include/*.gch
	@make -C src clean
	@make -C lib clean
	


