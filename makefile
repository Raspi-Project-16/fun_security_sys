CC=g++
SRCS=fun_security_sys.cpp\
	lightModule.cpp\
	soundModule.cpp\
	timeModule.cpp
OBJS=$(SRCS:.cpp=.o)
EXEC=test
start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -lwiringPi -lcpptimer -lrt

.cpp.o:
	$(CC) -o $@ -c $< -lwiringPi -lcpptimer -lrt

clean:
	rm -rf $(OBJS)
