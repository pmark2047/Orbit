/**********************************************************************
* Source File:
*    Orbit Lab
* Author:
*    Peyton and Jackson
* Summary:
*    Orbit
************************************************************************/

#include "test.h"

#include <iostream>
using namespace std;

/*********************************
 * MAIN - Where it all begins...
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   // run all the unit tests
   testRunner();
   
   return 0;
}
