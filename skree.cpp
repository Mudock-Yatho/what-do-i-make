/*
	This code is evil.
*/
#include "pch.h"
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <thread>
#include <vector>
void Output(int Core, int ins) {
	for (int count = 1; count < ins + 1; count++) {
		std::cout << "[ " << Core << " ] " << count << "\n";
	}
	return;
}
int main() {
	SetConsoleTitle(L"Penis");
	const unsigned int Cores = std::thread::hardware_concurrency();
	std::cout << "Cores detected: " << Cores << "\n";
	std::cout << "How many instructions: ";
	int ins;
	while (!(std::cin >> ins) || ins <= 0) {
		std::cout << "Please enter a positive number above 0 for the instructions amount.\nHow many instructions: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	if (ins + 1 > Cores) {
		const int InstructionPerCore = (ins) / Cores;
		std::cout << "Instructions for each core: " << InstructionPerCore << "\n";
		std::vector<std::thread> threads(Cores);
		for (int Core = 0; Core < Cores; Core++) {
			threads[Core] = std::thread(Output, Core + 1, InstructionPerCore);
		}
		for (int Core = 0; Core < Cores; Core++) {
			threads[Core].join();
		}
		std::cout << "Took: " << std::chrono::duration_cast<std::chrono::seconds> (std::chrono::steady_clock::now() - begin).count() << "s using " << Cores << " threads.\n";
	} else {
		std::cout << "Using single-thread mode.\n";
		Output(1, ins);
		std::cout << "Took: " << std::chrono::duration_cast<std::chrono::seconds> (std::chrono::steady_clock::now() - begin).count() << "s using single-thread.\n";
	}
	system("pause");
	return 0;
}
