FLAGS   = -std=c99 -Wall
SOURCES = mycat.c
OBJECTS = mycat.o
EXEBIN  = mycat

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	cc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	cc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)
