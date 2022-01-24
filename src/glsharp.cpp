#include "glsharp.h"

extern "C" unsigned int GLInitGlew(bool experimental)
{
	glewExperimental = experimental;
	return glewInit();
}
