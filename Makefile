IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

SRCDIR=src
ODIR=$(SRCDIR)/obj

LDIR=lib

TSTDIR=test
TSTODIR=$(TSTDIR)/obj

LIBS=

_DEPS = conway.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = conway.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_TSTOBJ = test.o
TSTOBJ = $(patsubst %,$(TSTODIR)/%,$(_TSTOBJ))

# EXAMPLE #
$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

example: $(OBJ) $(ODIR)/example.o
	$(CC) -o $(SRCDIR)/$@ $^ $(CFLAGS) $(LIBS)

# TEST #
$(TSTODIR)/%.o: $(TSTDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ) $(TSTOBJ)
	$(CC) -o $(TSTDIR)/$@ $^ $(CFLAGS) $(LIBS)

# CLEAN #
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(TSTODIR)/*.o *~ core $(INCDIR)/*~ $(SRCDIR)/example $(TSTDIR)/test