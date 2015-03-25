OBJS = blif_placer.o parser.o model.o placer.o composer.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

blif_placer : $(OBJS)
	$(CC) -I/usr/local/include $(LFLAGS) $(OBJS) -o blif_placer

blif_placer.o : blif_placer.cpp 
	$(CC) -I/usr/local/include $(CFLAGS) blif_placer.cpp

parser.o : ./includes/parser.h parser.cpp 
	$(CC) -I/usr/local/include $(CFLAGS) parser.cpp

model.o : ./includes/model.h model.cpp 
	$(CC) -I/usr/local/include $(CFLAGS) model.cpp

placer.o : ./includes/placer.h placer.cpp 
	$(CC) -I/usr/local/include $(CFLAGS) placer.cpp


composer.o : ./includes/composer.h composer.cpp 
	$(CC) -I/usr/local/include $(CFLAGS) composer.cpp

clean:
	\rm *.o *~ blif_placer