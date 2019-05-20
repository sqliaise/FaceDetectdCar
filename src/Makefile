OBJS := detect_face.o ctrl_car.o frame_handle.o
TARGET := built-in.o
all : $(TARGET)
$(TARGET) : $(OBJS)
	ar crv built-in.o $^
%.o : %.cpp
	$(GXX) -c $<

.PHONY : clean
clean:
	rm -f *.o
