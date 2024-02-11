#ifndef CXX_MEMORY_SHARED_POINTER_H
#define CXX_MEMORY_SHARED_POINTER_H

#include "DefaultDelete.h"
#include "RefCountedPointer.h"

namespace cxx_memory
{
    /*
    * @brief SharedPointer is a class that has shared ownership of a pointer.
    * 
    * @tparam PointerType The type of the pointer.
    * @tparam Deleter The type of the deleter.
    */
    template<typename PointerType, class Deleter = DefaultDelete>
    class SharedPointer
    {
    public: // Constructors and Destructor
        /*
        * @brief SharedPointer is the default constructor.
        * 
        * @param pointer The pointer to be managed.
         */
        inline SharedPointer(PointerType* pointer = nullptr);

        /*
        * @brief SharedPointer is the copy constructor.
        * 
        * @param other The other SharedPointer to copy from.
         */
        inline SharedPointer(const SharedPointer& other);

        /*
        * @brief SharedPointer is the destructor.
        * 
        * The destructor will release the pointer.
         */
        inline ~SharedPointer();

    public: // Public Member Functions
        /*
        * @brief Get returns the pointer.
        * 
        * @return The raw_pointer.
         */
        inline PointerType* GetRawPointer() const;

        /*
        * @brief Reset releases the current pointer and takes a new pointer.
         */
        inline void Reset(PointerType* pointer = nullptr);

        /*
        * @brief Swap swaps the current pointer with the other pointer.
        * 
        * @param other The other SharedPointer to swap with.
         */
        inline void Swap(SharedPointer& other);

        /*
        * @brief GetUseCount returns the use count of the pointer.
        * 
        * @return The use count.
         */
        inline int GetUseCount() const;

    public: // Operators
        SharedPointer& operator=(const SharedPointer& other)
        {
            if(this != &other)
            {
                m_Pointer->Release();
                m_Pointer = other.m_Pointer;
                m_Pointer->AddRef();
            }

            return *this;
        }

        PointerType* operator->() const
        {
            return this->GetRawPointer();
        }

        PointerType& operator*() const
        {
            return *this->GetRawPointer();
        }

    private: // Private Member Variables
        RefCountedPointer* m_Pointer;

    }; // class SharedPointer

}; // namespace cxx_memory

#include "SharedPointer.inl"

#endif // CXX_MEMORY_SHARED_POINTER_H