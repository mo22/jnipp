DEFAULT: all
.PHONY: all

_java.h JavaTest.class: JavaTest.java
	javac ../generate.java
	javac JavaTest.java
	java -cp ..:. generate java.lang.String JavaTest


CPPFLAGS = \
	-std=c++11 \
	-stdlib=libstdc++ \
	-I.. \
	-I$(JAVA_HOME)/include \
	-I$(JAVA_HOME)/include/darwin \

LDFLAGS = \
	-stdlib=libstdc++ -lstdc++ \
	-shared

JAVACFLAGS = -g

%.class: %.java
	javac $(JAVACFLAGS) $<

%.o: %.cpp _java.h ../jnipp.h
	clang -c $(CPPFLAGS) $< -o $@

libTest.dylib: test.o
	clang -o $@ $(LDFLAGS) $^

all: Test.class libTest.dylib
	@rm *.log 2>/dev/null || true
	java Test

clean:
	rm *.class *.dylib *.o


