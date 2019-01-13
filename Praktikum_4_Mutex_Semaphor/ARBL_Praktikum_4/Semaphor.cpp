#include "pch.h"
#include "Semaphor.h"
#include <iostream>
#include <thread>


void Semaphor::notify()
{
	std::unique_lock<std::mutex> lck(mtx);
	++counter;
	cv.notify_one();
}

void Semaphor::wait()
{
	std::unique_lock<std::mutex> lck(mtx);
	if (counter == 0) {

		cv.wait(lck);
	}

	--counter;

}
