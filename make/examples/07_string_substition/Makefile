foo := a.o b.o c.o l.a
one := $(patsubst %.o, %.c, $(foo))

all:
	@echo ${foo}
	@echo ${one}