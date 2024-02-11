# CxxMemory

a well meaning and purposeful alternative to STL smart pointers. 

## Features

- Shared Pointer
- Unique Pointer

that's it, **nothing else**.
## Usage

```cpp
#include <CxxMemory/SharedPointer.h>
#include <CxxMemory/UniquePointer.h>

cxx_memory::SharedPointer<int> mySharedNumber(new int(21));
cxx_memory::UniquePointer<int> myUniqueNumber(new int(21));
```

## Build

CxxMemory uses Premake5, read more: [premake.github.io](https://premake.github.io/).

tl;dr run `premake5 vs2022` for Visual Studio.

## License

Respect the [MIT](https://choosealicense.com/licenses/mit/) license, I won't ask again.
