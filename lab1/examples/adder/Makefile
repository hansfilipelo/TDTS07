# The final executable
PROGRAM = adder.x

# The source files (*.cc)
SRCS = adder.cc

##################################
## DO NOT CHANGE ANYTHING BELOW ##
##################################

SYSTEMC = /usr/local/Cellar/systemc/2.3.1/

LIBDIR = -L. -L.. -L$(SYSTEMC)/lib
LIBS = -Wl -Bstatic -lsystemc -Wl -Bdynamic -lm -lpthread
LDFLAGS = -g

CC = g++
OPT = -O3
CFLAGS = -Wno-deprecated
EXE = $(PROGRAM)

INCDIR= -I. -I.. -I$(SYSTEMC)/include

OBJS = $(SRCS:.cc=.o)

.SUFFIXES: .cc .o .x

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(EXE) $(OBJS) $(LIBS)

.cc.o:
	$(CC) -c $(CFLAGS) $(INCDIR) $< -o $@

clean:
	rm -f $(OBJS) $(EXE) *~
