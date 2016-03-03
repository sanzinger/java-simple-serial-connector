
ifneq (,$(findstring arm,$(shell uname -m)))
ARCH = armhf
else
ARCH = x86_64
endif

SO_EXT = .so
VERSION = 2.8
SO_NAME = libjSSC-$(VERSION)_$(ARCH)$(SO_EXT)


SRCS = jssc.cpp setCustomBaudrate.cpp
OBJS = $(SRCS:.c=.o)
INCLUDES = -I$(JAVA_HOME)/include/linux/ -I$(JAVA_HOME)/include/
CFLAGS =  -fPIC -shared -O3
CXX = g++

$(SO_NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(SO_NAME) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $<  -o $@
