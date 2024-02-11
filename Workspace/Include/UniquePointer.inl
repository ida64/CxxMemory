#include "UniquePointer.h"

namespace cxx_memory
{
	template<typename PointerType, class Deleter>
	inline cxx_memory::UniquePointer<PointerType, Deleter>::UniquePointer(PointerType* pointer)
		: m_PointerValue(pointer)
	{
	}

	template<typename PointerType, class Deleter>
	inline UniquePointer<PointerType, Deleter>::UniquePointer(UniquePointer&& other) noexcept
		: m_PointerValue(other.m_PointerValue)
	{
		other.m_PointerValue = nullptr;
	}

	template<typename PointerType, class Deleter>
	inline UniquePointer<PointerType, Deleter>::~UniquePointer()
	{
		if(m_PointerValue != nullptr)
		{
			Deleter()(m_PointerValue);
		}
	}

} // namespace cxx_memory
