#pragma once
#include <chrono>
#include <thread>
#include <condition_variable>
#include <mutex>
class Semaphor
{
public:

	std::mutex mtx;
	std::condition_variable cv;
	int counter = 1; // anzahl Threads, die gleichzeitig laufen k�nnen
	void wait();
	void notify();
	
};

