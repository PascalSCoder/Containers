// AUTO GENERATED CODE
#pragma once
#include "VectorTest.hpp"

template<class T>
void VectorTest<T>::AddChecks()
{
	this->_checks.push_back((SubCheck){.func = &VectorTest<T>::CheckSize, .title = "Size"});
	this->_checks.push_back((SubCheck){.func = &VectorTest<T>::CheckCapacity, .title = "Capacity"});
	this->_checks.push_back((SubCheck){.func = &VectorTest<T>::CheckData, .title = "Data"});
}
// AUTO GENERATED CODE
