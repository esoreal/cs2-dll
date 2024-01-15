#include "Windows.h"

#include <thread>
#include <cstdint>
#include <iostream>

uintptr_t base = (uintptr_t)GetModuleHandle("client.dll");

void log_console() {
	AllocConsole();
	FILE* file_config;
	freopen_s(&file_config, "CONOUT$", "w", stdout);

	std::cout << "[+] is this thing on?" << std::endl;
	std::cout << "[+] client.dll -> 0x" << base << std::endl;
	
	fclose(file_config);
}

BOOL WINAPI DllMain(
	HINSTANCE instance,
	DWORD reason,
	LPVOID reserved
)
{
	if (reason == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)log_console, 0, 0, 0);
	}
}