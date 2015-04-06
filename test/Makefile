DEFAULT: all
.PHONY: all

_java.h: JavaTest.class
	../generate/generate -cp . java.lang.String JavaTest

CPPFLAGS = \
	-std=c++11 \
	-stdlib=libc++ \
	-O3 \
	-ffunction-sections -fdata-sections \
	-gfull -fno-rtti \
	-fvisibility=hidden -fvisibility-inlines-hidden \
	-I.. \
	-I$(JAVA_HOME)/include \
	-I$(JAVA_HOME)/include/darwin \
	-I/opt/local/include/

LDFLAGS = \
	-stdlib=libc++ -lc++ \
	-O3 \
	-Wl,-dead_strip \
	-shared

JAVACFLAGS = -g

%.class: %.java
	javac $(JAVACFLAGS) $<

%.o: %.cpp _java.h ../jnipp.h
	clang -c $(CPPFLAGS) $< -o $@

libTest.dylib: test.o
	clang -o $@ $(LDFLAGS) $^
	strip -S -x $@

all: Test.class JavaTest.class libTest.dylib
	@rm *.log 2>/dev/null || true
	java Test

clean:
	rm *.class *.dylib *.o


