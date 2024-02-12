#include "SharedPointer.h"

namespace cxx_memory
{
    template<typename PointerType, class Deleter>
    inline SharedPointer<PointerType, Deleter>::SharedPointer(PointerType* pointer)
    {
        m_Pointer = new RefCountedPointer(pointer);
    }

    template<typename PointerType, class Deleter>
    inline SharedPointer<PointerType, Deleter>::SharedPointer(const SharedPointer& other)
    {
        m_Pointer = other.m_Pointer;
        m_Pointer->AddRef();
    }

    template<typename PointerType, class Deleter>
    inline SharedPointer<PointerType, Deleter>::SharedPointer(SharedPointer&& other)
    {
        m_Pointer = other.m_Pointer;
        other.m_Pointer = nullptr;
    }

    template<typename PointerType, class Deleter>
    inline SharedPointer<PointerType, Deleter>::~SharedPointer()
    {
        m_Pointer->Release();
        
        if(m_Pointer->GetReferenceCount() == 0)
        {
            delete m_Pointer;
        }
    }

    template<typename PointerType, class Deleter>
    inline PointerType* SharedPointer<PointerType, Deleter>::GetRawPointer() const
    {
        return static_cast<PointerType*>(m_Pointer->raw_pointer);
    }

    template<typename PointerType, class Deleter>
    inline void SharedPointer<PointerType, Deleter>::Reset(PointerType* pointer)
    {
        m_Pointer->Release();
        m_Pointer = new RefCountedPointer(pointer);
    }

    template<typename PointerType, class Deleter>
    inline void SharedPointer<PointerType, Deleter>::Swap(SharedPointer& other)
    {
        RefCountedPointer* temp = m_Pointer;
        m_Pointer = other.m_Pointer;
        other.m_Pointer = temp;
    }

    template<typename PointerType, class Deleter>
    inline int SharedPointer<PointerType, Deleter>::GetReferenceCount() const
    {
        return m_Pointer->GetReferenceCount();
    }

    template<class PointerType, class ...Arguments>
    SharedPointer<PointerType> MakeSharedPointer(Arguments && ...arguments)
    {
        PointerType* raw = new PointerType(std::forward<Arguments>(arguments)...);
        return SharedPointer<PointerType>(new PointerType(std::forward<Arguments>(arguments)...));
    }

} // namespace cxx_memory
