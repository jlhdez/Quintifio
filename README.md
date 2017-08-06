# Quintifio
## Introduction
`**TODO**`
## Setup
+ The project was setup with the `1.64.0` version of boost
+ Once dowloading `boost`, follow the [Getting started with boost](http://www.boost.org/doc/libs/1_54_0/more/getting_started/windows.html#id29)
guide to build the binary libraries.
   + When executing `b2`, I used `b2 link=shared`
+ Visual Studio  needs to link to the new libraries
 + Go to Project-> project Properties
   + In C/C++ -> General add the include folder from OpenCV, e.g. `C:\boost\boost_1_64_0`, to Additional Include Directories
    + In Linker -> General add the lib folder from OpenCV, e.g. `C:\boost\boost_1_64_0\stage\lib`, to Additional Library Directories
+ Test a program like the below

```c++
#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Usage: tut2 path\n";
		return 1;
	}

	path p(argv[1]);  // avoid repeated path construction below

	if (exists(p))    // does path p actually exist?
	{
		if (is_regular_file(p))        // is path p a regular file?
			cout << p << " size is " << file_size(p) << '\n';

		else if (is_directory(p))      // is path p a directory?
			cout << p << " is a directory\n";

		else
			cout << p << " exists, but is not a regular file or directory\n";
	}
	else
		cout << p << " does not exist\n";

	return 0;
}
```

## Resources
1. [Getting started with boost](http://www.boost.org/doc/libs/1_54_0/more/getting_started/windows.html#id29)
1. [b2 execution examples](http://www.boost.org/build/doc/html/bbv2/overview/invocation.html)
