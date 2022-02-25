import re

lines = open('VectorTest.hpp', 'r').readlines()

pattern = r'bool\s+Check.*\(\)\s+const$'

print('// AUTO GENERATED CODE')
print('#pragma once')
print('#include "VectorTest.hpp"\n')
print('template<class T>')
print('void VectorTest<T>::AddChecks()\n{')
for line in lines:
	line = line.strip()
	if re.match(pattern, line):
		begin = line.find("Check")
		end = line.find("(")

		title = line[begin + 5:end]
		line = line[begin:end]

		print('\tthis->_checks.push_back((SubCheck){.func = &VectorTest<T>::' + line + ', .title = "' + title + '"});')
print('}')
