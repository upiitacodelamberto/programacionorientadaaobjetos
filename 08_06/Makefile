CC=g++
#LD=ld

ROOTFS=.
ROOTBIN=$(ROOTFS)/bin

APP_SRCS:=$(wildcard *.cpp)

all: bin/test

bin/test: $(APP_SRCS:%.cpp=obj/%.o)
	@mkdir -p $(dir $@)
	$(CC) -o $@ $^

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $<

clean:
	find $(ROOTBIN) -type f ! -name .empty -print -delete
	rm -rfv obj
