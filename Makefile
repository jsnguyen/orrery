CXX=gcc

SRCDIR=src
OBJDIR=build

_INCDIRS=include \
				 /home/jsnguyen/programs/cspice/include

INCDIRS=$(addprefix -I,$(_INCDIRS))

_LIBDIRS=lib

CSPICE_LIB = /home/jsnguyen/programs/cspice/lib/cspice.a

LIBDIRS=$(addprefix -L,$(_LIBDIRS))

_LIBS=m 
LIBS=$(addprefix -l,$(_LIBS))

CXXFLAGS=-O3 -Wall $(INCDIRS) -fPIC 
LDFLAGS=-O3 -shared $(INCDIRS) $(LIBDIRS) $(LIBS) $(CSPICE_LIB)

_SRCFILES=orrery.c

SRCS=$(addprefix $(SRCDIR)/,$(_SRCFILES))

_OBJFILES=$(_SRCFILES:%.c=%.o)
OBJS=$(addprefix $(OBJDIR)/,$(_OBJFILES))

LIBDIR=lib
LIB=liborr.so

DIRGUARD=@mkdir -p $(@D)

all: $(LIBDIR)/$(LIB)

$(LIBDIR)/$(LIB) : $(OBJS)
	$(DIRGUARD)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(DIRGUARD)
	$(CXX) $< -c -o $@ $(CXXFLAGS) 

.SECONDARY: $(OBJS)
.PHONY: clean

clean:
	rm $(OBJDIR)/*.o
	rm $(LIBDIR)/*.so
	rmdir $(OBJDIR) $(LIBDIR)
