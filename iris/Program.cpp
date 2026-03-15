
#include "IrisApplication.hpp"

#include <Windows.h>

#if defined(_CONSOLE)
int main(int, const char**)
#else
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
#endif
{
	PROFILE_ATTACH_LOG();
	PROFILE_APPINFO("Iris Application");

	IrisApplication iris;
	return iris.Run();
}