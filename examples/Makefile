CXX=gcc

SRCDIR=.
OBJDIR=.

_INCDIRS=../include \
				 /home/jsnguyen/programs/cspice/include

INCDIRS=$(addprefix -I,$(_INCDIRS))

_LIBDIRS=../lib

LIBDIRS=$(addprefix -L,$(_LIBDIRS))

CSPICE_LIB = /home/jsnguyen/programs/cspice/lib/cspice.a

_LIBS=orr m
LIBS=$(addprefix -l,$(_LIBS))

CXXFLAGS=-O3 -Wall $(INCDIRS)

_COMMA=,
_RPATHS=$(addprefix -Wl$(_COMMA)-rpath$(_COMMA),$(_LIBDIRS))
LDFLAGS=-O3 $(INCDIRS) $(LIBDIRS) $(_RPATHS) $(LIBS) $(CSPICE_LIB)

_SRCFILES=cspice_test.c

SRCS=$(addprefix $(SRCDIR)/,$(_SRCFILES))

_OBJFILES=$(_SRCFILES:%.c=%.o)
OBJS=$(addprefix $(OBJDIR)/,$(_OBJFILES))

EXES=$(_SRCFILES:%.c=%.exe)

all: $(EXES)

%.exe : $(OBJDIR)/%.o
	$(CXX) $< -o $@ $(LDFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CXX) $< -c -o $@ $(CXXFLAGS)

.SECONDARY: $(OBJS)
.PHONY: clean

clean:
	rm $(OBJDIR)/*.o
	rm *.exe
