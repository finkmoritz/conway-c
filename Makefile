IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

SRCDIR=src
ODIR=$(SRCDIR)/obj
LDIR =lib

LIBS=

_DEPS = conway.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = conway.o example.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

example: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 