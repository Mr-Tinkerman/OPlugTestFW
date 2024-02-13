# OPlugTest Framework

This is a very simple testing framework I built out of my need to test my main
project, and the desire to use a small, unbloated testing framework.  While
this project was only intended to be used by me personally, I've decided to
make this public for others looking for a small and simple test framework. As
this is still in heavy development, expect breaking changes until I declare it
to be officially been released.

-------------------------------------------------------------------------------

### Installation

Clone the project into your project.  I typically put external dependencies in
a separate subdirectory.
```bash
# Inside your project's root directory

git clone https://github.com/Mr-Tinkerman/OPlugTestFW.git vendor/OPlugTestFW
```
```
.../
vendor/
  - OPlugTestFW/
    - example.cmake
    - OPTest.cmake
    - OPTest.hpp
    - testMain.cpp
.../
```

Copy the example.cmake file into the subdirectory containing your tests and
rename it to CMakeLists.txt
```bash
cp vendor/OPlugTestFW/example.cmake tests/CMakeLists.txt
```

OPTest.cmake will need to be included in your project and you will need to add
your test subdirectory.
```cmake
# Root CMakeLists.txt

include(vendor/OPlugTestFW/OPTest.cmake)
...

add_subdirectory(tests)
```


### Usage

Making a new test is as simple as including the OPTest.hpp file and adding a
test with the macro ADD_X_TEST, where X is the type of the test.
```cpp
// example-unit-test.cpp

#include "OPTest.hpp"

ADD_UNIT_TEST()
{
    // Test Code
    // Future me will create Macros to perform assertions
}
```

Inside tests/CMakeLists.txt, you will need to add the tests with the
add_optest(TEST_GROUP TESTS) function (that was included in OPTest.cmake).
```cmake
add_optest(UnitTests, example-unit-test.cpp, ex2.cpp)

--- OR ---

add_optest(UnitTests, example-unit-test.cpp)
add_optest(UnitTests, ex2.cpp)
```

This will compile the tests independently and in groups defined by the given
TEST_GROUP parameter.  By default, the binaries are outputted to a subdirectory
of the project's bin directory.
```
- bin/tests/
  - example-unit-test
  - ex2
  - UnitTests
```
