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


TRAFF_FOLDER=TrafficLight_testbench
TRAFF_SRCS=$(TRAFF_FOLDER)/TrafficLight_testbench.cc $(TRAFF_FOLDER)/monitor.cc TrafficLight.cc $(TRAFF_FOLDER)/input_gen.cc
TRAFF_OBJS = $(TRAFF_SRCS:.cc=.o)
TRAFF_EXE=TL_testbench

$(TRAFF_EXE): $(TRAFF_OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(TRAFF_EXE) $(TRAFF_OBJS) $(LIBS)

CONTR_FOLDER=Controller_testbench
CONTR_SRCS=$(CONTR_FOLDER)/Controller_testbench.cc $(CONTR_FOLDER)/monitor.cc Controller.cc $(CONTR_FOLDER)/input_gen.cc
CONTR_OBJS = $(CONTR_SRCS:.cc=.o)
CONTR_EXE=C_testbench

$(CONTR_EXE): $(CONTR_OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(CONTR_EXE) $(CONTR_OBJS) $(LIBS)

clean:
	rm -f *.o $(TRAFF_FOLDER)/*.o $(TRAFF_EXE) $(CONTR_FOLDER)/*.o $(CONTR_EXE) $(EXE) *~
