
PROGRAM=main-lcd-simul
CPPFLAGS+=-g -std=c++11 -Wall

# detect opencv lib
OPENCVLIB=$(strip $(shell pkgconf --list-package-names | grep opencv ))

ifeq ($(OPENCVLIB),)

all:
	@echo OpenCV lib not found!
	@exit 

else

CPPFLAGS+=$(shell pkgconf --cflags $(OPENCVLIB))
LDFLAGS+=$(shell pkgconf --libs-only-L $(OPENCVLIB))
LDLIBS+=$(shell pkgconf --libs-only-l $(OPENCVLIB))

all: $(PROGRAM) 

endif

$(PROGRAM): $(PROGRAM).cpp lcd_lib.cpp lcd_lib.h graph_class.hpp graph_struct.hpp
	g++ $(CPPFLAGS) $(PROGRAM).cpp lcd_lib.cpp -o $@ $(LDFLAGS) $(LDLIBS)

clean: 
	rm -rf $(PROGRAM)

run: 
	./$(PROGRAM)