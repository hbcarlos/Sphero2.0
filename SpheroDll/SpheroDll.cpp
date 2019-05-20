// SpheroDll.cpp : Define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include <iostream>
#include "Sphero.h"

#define SPHERO_LIB extern "C" __declspec(dllexport)
//#define SPHERO_LIB extern "C" __declspec(dllimport)

SPHERO_LIB Sphero* SpheroCreate(std::string name) {
	return new Sphero(name);
}

//======================================================================================================================

SPHERO_LIB void SpheroDelete(Sphero* sphero) {
	Sphero* sp = (Sphero*)sphero;
	delete sp;
}