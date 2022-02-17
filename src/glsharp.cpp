#include "glsharp.h"

unsigned int GLInitGlew(bool experimental)
{
	glewExperimental = experimental;
	return glewInit();
}