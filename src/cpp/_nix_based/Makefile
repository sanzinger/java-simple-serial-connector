
ARCH = x86_64
SO_EXT = .so
VERSION = 2.8
SO_NAME = libjSSC-$(VERSION)_$(ARCH)$(SO_EXT)


SRCS = jssc.cpp set_baudrate.cpp
OBJS = $(SRCS:.c=.o)
INCLUDES = -I$(JAVA_HOME)/include/linux/ -I$(JAVA_HOME)/include/
CFLAGS =  -fPIC -shared
CXX = g++

$(SO_NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(SO_NAME) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $<  -o $@
