# The final executable
PROGRAM = traffic.x

# The source files (*.cc)
SRCS = TrafficLight.cc Controller.cc

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

###############
#### TESTS ####

TRAFF_SRCS=TrafficLight_testbench.cc monitor.cc TrafficLight.cc input_gen.cc
TRAFF_OBJS = $(TRAFF_SRCS:.cc=.o)
TRAFF_EXE=TrafficLight_testbench

$(TRAFF_EXE): $(TRAFF_OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(TRAFF_EXE) $(TRAFF_OBJS) $(LIBS)

clean:
	rm -f $(OBJS) $(TRAFF_OBJS) $(EXE) *~
