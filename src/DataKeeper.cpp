#include <Windows.h>
#include "DataKeeper.h"

#define Kilobytes(Value) ((Value) * 1024LL)
#define Megabytes(Value) ((Value) * 1024LL * 1024LL)

DataKeeper::DataKeeper()
{
	const LPVOID baseAddress = (LPVOID)1073741824;
	memory = VirtualAlloc(baseAddress, sizeof(Data), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	//*(float*)memory = 18.f;
	GameData = (Data*)memory;
}
DataKeeper::~DataKeeper() 
{ 
	VirtualFree(memory, sizeof(Data), MEM_RELEASE);
};