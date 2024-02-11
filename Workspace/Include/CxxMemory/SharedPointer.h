/*
* MIT License
* 
* Copyright (c) paging 2024 SharedPointer.h
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
 */
#ifndef CXX_MEMORY_SHARED_POINTER_H
#define CXX_MEMORY_SHARED_POINTER_H

#include <CxxMemory/DefaultDelete.h>
#include <CxxMemory/RefCountedPointer.h>

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
        * @brief GetReferenceCount returns the use count of the pointer.
        * 
        * @return The reference count.
         */
        inline int GetReferenceCount() const;

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