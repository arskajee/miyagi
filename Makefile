CC        := clang++
SRCDIR    := src
BUILDDIR  := build
TARGETDIR := bin
TARGET    := bin/miyagi

SRCEXT  := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS  := -g -Wall -std=gnu++11
INC     := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) -o $(TARGET) $^"; $(CC) -o $(TARGET) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
