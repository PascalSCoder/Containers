import re

input = open('VectorTest.hpp', 'r').readlines()

tpp = open('GEN_VectorChecks.tpp', 'w')

pattern = r'bool\s+Check.*\(\)\s+const$'

lines = []
functions = []
titles = []
for line in input:
	line = line.strip()
	if re.match(pattern, line):
		begin = line.find("Check")
		end = line.find("(")

		lines.append(line)
		titles.append(line[begin + 5:end])
		functions.append(line[begin:end])



print('// AUTO GENERATED CODE', file=tpp)
print('#pragma once', file=tpp)
print('#include "VectorTest.hpp"\n', file=tpp)
print('template<class T>', file=tpp)
print('void VectorTest<T>::AddChecks()\n{', file=tpp)

for i in range(lines.__len__()):
	print('\tthis->_checks.push_back(SubCheck(&VectorTest<T>::' + functions[i] + ', "' + titles[i] + '"));', file=tpp)

print('}', file=tpp)
