BASE_SRC = ../../recipes/logging/Logging.cc ../../recipes/logging/LogStream.cc ../../recipes/thread/Thread.cc ../../recipes/datetime/Timestamp.cc
test:
	g++ EventLoop.cpp test.cpp $(BASE_SRC) -g -o test -I../../recipes/ -lpthread
clean:
	rm test
