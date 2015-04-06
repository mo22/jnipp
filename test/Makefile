DEFAULT: all
.PHONY: all

CPPFLAGS = \
	-std=c++11 \
	-stdlib=libstdc++ \
	-I$(JAVA_HOME)/include \
	-I$(JAVA_HOME)/include/darwin \
	-I/Users/mmoeller/workspace/devkit/v8android/v8/include \
	-I/Users/mmoeller/workspace/devkit/v8android/v8

LDFLAGS = \
	-stdlib=libstdc++ -lstdc++ \
	-shared \
	/Users/mmoeller/workspace/devkit/v8android/v8/out/x64.release/libicuuc.a \
	/Users/mmoeller/workspace/devkit/v8android/v8/out/x64.release/libicui18n.a \
	/Users/mmoeller/workspace/devkit/v8android/v8/out/x64.release/libicudata.a \
	/Users/mmoeller/workspace/devkit/v8android/v8/out/x64.release/libv8_libbase.a \
	/Users/mmoeller/workspace/devkit/v8android/v8/out/x64.release/libv8_libplatform.a \
	/Users/mmoeller/workspace/devkit/v8android/v8/out/x64.release/libv8_base.a \
	/Users/mmoeller/workspace/devkit/v8android/v8/out/x64.release/libv8_snapshot.a \

JAVACFLAGS = -g

%.class: %.java
	javac $(JAVACFLAGS) $<

%.o: %.cpp *.h
	clang -c $(CPPFLAGS) $< -o $@

libTest.dylib: $(OBJS)
	clang -o $@ $(LDFLAGS) $^

all: Test.class libTest.dylib
	@rm *.log 2>/dev/null || true
	java Test

clean:
	rm *.class *.dylib *.o

generate:
	javac generate.java
	java generate java.lang.String JavaTest

