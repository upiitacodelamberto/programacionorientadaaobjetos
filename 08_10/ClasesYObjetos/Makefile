INCLUDE_DIRS:= ./ include/
SOURCE_DIRS:=  src/
LIBS = -L/usr/lib/ -lm -ldl -lcppunit
DEBUG = -g

##CFILES:= main.cpp modelo.cpp String_Tokenizer.cpp prueba.cpp hacerPruebas.cpp
##CFILES:= modelo.cpp String_Tokenizer.cpp prueba.cpp hacerPruebas.cpp
#CFILES:= modelo.cpp hacerPruebas.cpp String_Tokenizer.cpp
CFILES:= main.cpp modelo.cpp String_Tokenizer.cpp
##TARGET = conteosdinamicos
#TARGET = pruebas
TARGET = testpoo
INCLUDE_FLAGS:=$(patsubst %,-I%,$(INCLUDE_DIRS))

CC=g++

LFLAGS=-Wall $(DEBUG)
CFLAGS= $(INCLUDE_FLAGS)
vpath %.h $(INCLUDE_DIRS)
vpath %.cpp $(SOURCE_DIRS)

vpath %.o objects

COBJECTS:= $(patsubst %.cpp,%.o,$(CFILES)) 
#ASMOBJECTS:= $(patsubst %.S,%.o,$(ASM_FILES))

all: $(TARGET).out 
#all: $(TARGET) dummprueba mmain
#all:  pruebas
objects:
	mkdir objects

#$(TARGET).out: objects $(COBJECTS) 
$(TARGET): objects $(COBJECTS) 
	$(CC) -o $@ $(LFLAGS) objects/*.o $(LIBS)

$(COBJECTS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o objects/$@

#$(ASMOBJECTS): %.o: %.S
#	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o objects/$@

#pruebas:src/hacerPruebas.cpp src/prueba.cpp
#	$(CC) $(CPPFLAGS) $? -o pruebas

dummprueba:src/dummdriver.cpp src/String_Tokenizer.cpp src/modelo.cpp
	$(CC) -I./include $^ -o $@

mmain:src/main.cpp src/String_Tokenizer.cpp src/modelo.cpp
	$(CC) -I./include $^ -o $@

.PHONY:  
clean:
	rm -frv objects pruebas dummprueba testpoo testpoo.out
#	rm $(TARGET).out
	
