# Compiler settings
CC := g++
CFLAGS := -std=c++14 -Wall -Wextra -O3
LDFLAGS :=

# Directories
SRCDIR := src
INCDIR := headers
BUILDDIR := build
BINDIR := bin

# --------------------------------------
DIRNAME := $(shell basename "$(PWD)")
# --------------------------------------

# Files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.cpp=.o))
TARGET := $(BINDIR)/$(DIRNAME)

# Targets
all: $(TARGET)
	./exec.sh

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(wildcard $(INCDIR)/*.h)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(BUILDDIR) $(BINDIR)

.PHONY: all clean

