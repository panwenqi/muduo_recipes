#include "EventLoop.h"
#include "logging/Logging.h"
#include <assert.h>
#include <poll.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace muduo;
__thread EventLoop* t_loopInThisThread = 0;
const int kPollTimeMs = 10000;

EventLoop::EventLoop() : looping_(false), threadId_(CurrentThread::tid())
{
	cout << "EventLoop create " << this << " in thread " << threadId_ << endl;
	if(t_loopInThisThread)
	{
		cout << "Another EventLoop " << t_loopInThisThread << " exists in this thread " << threadId_ << endl;
	}else{
		t_loopInThisThread = this;
	}
}

EventLoop::~EventLoop()
{
	assert(!looping_);
	t_loopInThisThread = NULL;
}

void EventLoop::loop()
{
	assert(!looping_);
	assertInLoopThread();
	looping_ = true;

	::poll(NULL, 0, 5*1000);

	cout << "EventLoop " << this << " stop looping" << endl;
	looping_ = false;
}

void EventLoop::abortNotInLoopThread()
{
	cout << "EventLoop:: abortNotInLoopThread - EventLoop " << this 
	<< " was created in threadId_ = " << threadId_
    << ", current thread id = " <<  CurrentThread::tid() << endl;
}
