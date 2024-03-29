// ARBL_Praktikum_4.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include "Semaphor.h"
#include <mutex>



using namespace std;


Semaphor *semaphor;
mutex mtx;

void kleinbuchstaben() {
	//mtx.lock();
	semaphor->wait();
	for (int i = 97; i <= 122; i++) {
		cout << char(i);
	}
	cout << endl;
	//mtx.unlock();
	semaphor->notify();
}

void grossbuchstaben() {
	//mtx.lock();
	semaphor ->wait();
	
	for (int i = 65; i <= 90; i++) {
		cout << char(i);
	}
	
	cout << endl;
	//mtx.unlock();
	semaphor ->notify();
}

void natuerliche_zahlen() {
	//mtx.lock();
	
	semaphor -> wait();
	
	for (int i = 0; i <= 32; i++) {
		cout << i << " ";
	}
	cout << endl;
	semaphor -> notify();
	//mtx.unlock();
}

void hello_World() {
	
	semaphor->wait();
	cout << "Hello World to Mutex" << endl;
	semaphor->notify();
}

int main()
{
	semaphor = new Semaphor();
	
	thread t1(kleinbuchstaben);
	thread t2(grossbuchstaben);
	thread t3(natuerliche_zahlen);
	//thread t4(hello_World);
	
	t1.join();
	t2.join();
	t3.join();
	//t4.join();

	system("PAUSE");
	delete semaphor;
	return 0;

}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

