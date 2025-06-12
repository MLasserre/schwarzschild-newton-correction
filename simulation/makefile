# Makefile

CC = gcc
CFLAGS = -std=c99 -W -Wall -Wextra -Wunused -Wshadow -Wconversion \
	 -Wmissing-prototypes -ffloat-store
LDFLAGS = 
LIBS = -lm

MAIN = simulation.c
SUB = scd_mb.c methode.c io.c matrix_tools.c

HEAD = $(SUB:.c=.h)
OBJ_MAIN = $(MAIN:.c=.o)
OBJ_SUB = $(SUB:.c=.o)
EXEC = $(MAIN:.c=)

$(EXEC): $(OBJ_MAIN) $(OBJ_SUB)
	$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ_SUB) $(LIBS) -o $@

$(OBJ_MAIN): $(MAIN) $(HEAD) precision.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_MAIN) : parametre.h
fcts.o : parametre.h

.PHONY : clean
clean :
	rm -f *.o *~

.PHONY : superclean
superclean : 
	rm -f *.out *.o *~ $(EXEC)


go : $(EXEC)
	./$(EXEC) < parametres_precession.in
