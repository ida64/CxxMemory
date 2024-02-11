# CxxMemory

a well meaning and purposeful alternative to STL smart pointers. 
## Features

- Shared Pointer
- Unique Pointer

that's it, **nothing else**.
## Usage

```cpp
#include <SharedPointer.h>
#include <UniquePointer.h>

cxx_memory::SharedPointer<int> mySharedNumber(new int(21));
cxx_memory::UniquePointer<int> myUniqueNumber(new int(21));
```


## Build

CxxMemory uses Premake5, simply run `premake5 vs2022` for Visual Studio.

Read more: [premake.github.io](https://premake.github.io/)
## License

CxxMemory falls under the [MIT](https://choosealicense.com/licenses/mit/) license.
