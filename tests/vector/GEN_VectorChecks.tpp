// AUTO GENERATED CODE
#pragma once
#include "VectorTest.hpp"

template<class T>
void VectorTest<T>::AddChecks()
{
	this->_checks.push_back(SubCheck(&VectorTest<T>::CheckSize, "Size"));
	this->_checks.push_back(SubCheck(&VectorTest<T>::CheckCapacity, "Capacity"));
	this->_checks.push_back(SubCheck(&VectorTest<T>::CheckData, "Data"));
}
