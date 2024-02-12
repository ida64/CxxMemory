#include <CxxMemory/UniquePointer.h>

namespace cxx_memory
{
	template<typename PointerType, class Deleter>
	inline cxx_memory::UniquePointer<PointerType, Deleter>::UniquePointer(PointerType* pointer)
		: pointer_value(pointer)
	{
	}

	template<typename PointerType, class Deleter>
	inline UniquePointer<PointerType, Deleter>::UniquePointer(UniquePointer&& other) noexcept
		: pointer_value(other.pointer_value)
	{
		other.pointer_value = nullptr;
	}

	template<typename PointerType, class Deleter>
	inline UniquePointer<PointerType, Deleter>::~UniquePointer()
	{
		if(pointer_value != nullptr)
		{
			Deleter()(pointer_value);
		}
	}

	template<class PointerType, class ...Arguments>
	UniquePointer<PointerType> MakeUniquePointer(Arguments && ...arguments)
	{
		return UniquePointer<PointerType>(new PointerType(std::forward<Arguments>(arguments)...));
	}

} // namespace cxx_memory
