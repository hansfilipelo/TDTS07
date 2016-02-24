# The final executable
PROGRAM = traffic.x

# The source files (*.cc)
SRCS = TrafficLight.cc Controller.cc

##################################
## DO NOT CHANGE ANYTHING BELOW ##
##################################

SYSTEMC = /home/TDTS07/sw/systemc/lib-linux64

LIBDIR = -L. -L.. -L$(SYSTEMC)
LIBS = -Wl -Bstatic -lsystemc -Wl -Bdynamic -lm -lpthread
LDFLAGS = -g

CC = g++
OPT = -O3
CFLAGS = -Wno-deprecated
EXE = $(PROGRAM)

INCDIR= -I. -I.. -I/home/TDTS07/sw/systemc/include

OBJS = $(SRCS:.cc=.o)

.SUFFIXES: .cc .o .x

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(EXE) $(OBJS) $(LIBS)

###############
#### TESTS ####


# TrafficLight_testbench ----------------------

TRAFF_FOLDER=TrafficLight_testbench
TRAFF_SRCS=$(TRAFF_FOLDER)/TrafficLight_testbench.cc $(TRAFF_FOLDER)/monitor.cc TrafficLight.cc $(TRAFF_FOLDER)/input_gen.cc
TRAFF_OBJS = $(TRAFF_SRCS:.cc=.o)
TRAFF_EXE=TL_testbench

$(TRAFF_EXE): $(TRAFF_OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(TRAFF_EXE) $(TRAFF_OBJS) $(LIBS)

# Controller_testbench ----------------------

CONTR_FOLDER=Controller_testbench
CONTR_SRCS=$(CONTR_FOLDER)/Controller_testbench.cc $(CONTR_FOLDER)/monitor.cc Controller.cc $(CONTR_FOLDER)/input_gen.cc
CONTR_OBJS = $(CONTR_SRCS:.cc=.o)
CONTR_EXE=C_testbench

$(CONTR_EXE): $(CONTR_OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(CONTR_EXE) $(CONTR_OBJS) $(LIBS)


# system_testbench_random ----------------------

SYS_FOLDER=system_testbench_random
SYS_SRCS=$(SYS_FOLDER)/TrafficSystem_testbench.cc $(SYS_FOLDER)/monitor.cc Controller.cc TrafficLight.cc $(SYS_FOLDER)/input_gen.cc $(SYS_FOLDER)/constants.cc
SYS_OBJS = $(SYS_SRCS:.cc=.o)
SYS_EXE=sys_testbench_random

$(SYS_EXE): $(SYS_OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(SYS_EXE) $(SYS_OBJS) $(LIBS)

# system_testbench_independent ----------------------

SYS_IND_FOLDER=system_testbench_independent
SYS_IND_SRCS=$(SYS_IND_FOLDER)/TrafficSystem_testbench.cc $(SYS_IND_FOLDER)/monitor.cc Controller.cc TrafficLight.cc $(SYS_IND_FOLDER)/input_gen.cc
SYS_IND_OBJS = $(SYS_IND_SRCS:.cc=.o)
SYS_IND_EXE=sys_testbench_independent

$(SYS_IND_EXE): $(SYS_IND_OBJS)
	$(CC) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $(SYS_IND_EXE) $(SYS_IND_OBJS) $(LIBS)


clean:
	rm -f *.o $(TRAFF_FOLDER)/*.o $(TRAFF_EXE) $(CONTR_FOLDER)/*.o $(CONTR_EXE) $(SYS_FOLDER)/*.o $(EXE) $(SYS_EXE) $(SYS_IND_OBJS) $(SYS_IND_EXE) $() *~
