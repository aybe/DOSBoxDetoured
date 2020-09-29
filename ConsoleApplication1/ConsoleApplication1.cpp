#include <iostream>
#include <Windows.h>

int main()
{
	// this won't work, obviously ...
	// GetProcAddress(GetModuleHandle(L"ntvdm64.dll"), "NtVdm64CreateProcessInternalW");

	HMODULE module = GetModuleHandle(L"KernelBase.dll");

	if (module == NULL)
	{
		std::cout << "Couldn't get module handle, GetLastError is " << GetLastError() << "\n";
		return 1;
	}

	FARPROC address = GetProcAddress(module, "CreateProcessInternalW");

	if (address == NULL)
	{
		std::cout << "Couldn't get proc address, GetLastError is " << GetLastError() << "\n";
		return 1;
	}

	std::cout << "Time to celebrate ?";
	return 0;
}
