import re

input = open('VectorTestCases.cpp', 'r').readlines()

main = open('GEN_main.cpp', 'w')

pattern = r'void\s+Case.*\(\)'

print('// AUTO GENERATED CODE\n', file=main)
print('#include "VectorTest.hpp"', file=main)
print('#include <iostream>\n', file=main)
print('extern VectorTest<int> vectors;', file=main)

functions = []
for line in input:
	line = line.strip()
	if (re.match(pattern, line)):
		functions.append(line[line.find('Case'):line.find('(')])
		print(line + ';', file=main)

print('\nint main()\n{', file=main)
for function in functions:
	print('\tvectors.Run(' + function + ', "' + function + '");', file=main)

print('}', file=main)
