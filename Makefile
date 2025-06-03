.DEFAULT_GOAL := all
.PHONY: all

BUILDDIR := build
SRCDIR := src
TESTSRCDIR := test

CXX=clang++
COMPILE_FLAGS=$(CXXFLAGS) -g3 -std=c++17
TEST_COMPILE_FLAGS=$(CXXFLAGS) -std=c++17 -Wall -Wextra -pthread -I $(SRCDIR)
TEST_LIBS = -lgtest -lgtest_main -lpthread

HDRS := $(addprefix $(SRCDIR)/, \
	Bond.h \
	Instrument.h \
	Stock.h \
)

SRCS := $(addprefix $(SRCDIR)/, \
	Bond.cpp \
	Stock.cpp \
)

all: $(BUILDDIR)/pnl

$(BUILDDIR)/pnl: $(SRCDIR)/main.cpp $(SRCS) | $(BUILDDIR)
	$(CXX) $(COMPILE_FLAGS) $^ -o $(BUILDDIR)/pnl

TEST_SRCS = $(addprefix $(TESTSRCDIR)/, \
	test_stock.cpp test_bond.cpp \
	test_instrument.cpp )

test: $(BUILDDIR)/pnltest
	$(BUILDDIR)/pnltest

$(BUILDDIR)/pnltest: $(TEST_SRCS) $(SRCS)| $(BUILDDIR)
	$(CXX) $(TEST_COMPILE_FLAGS) $(TEST_LIBS) $^ -o $(BUILDDIR)/pnltest

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
