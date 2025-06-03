.DEFAULT_GOAL := all
.PHONY: all

CXX=clang++
COMPILE_FLAGS=$(CXXFLAGS) -g3 -std=c++17

BUILDDIR := build
SRCDIR := src

HDRS := $(addprefix $(SRCDIR)/, \
	Bond.h \
	Instrument.h \
	Stock.h \
)

SRCS := $(addprefix $(SRCDIR)/, \
	main.cpp \
	Bond.cpp \
	Stock.cpp \
)

all: $(BUILDDIR)/pnl

$(BUILDDIR)/pnl: $(SRCS) | $(BUILDDIR)
	$(CXX) $(COMPILE_FLAGS) $^ -o $(BUILDDIR)/pnl

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
