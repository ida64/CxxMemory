/*
* MIT License
* 
* Copyright (c) paging 2024 RefCountedPointer.h
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
#ifndef CXX_MEMORY_REF_COUNTED_POINTER_H
#define CXX_MEMORY_REF_COUNTED_POINTER_H

namespace cxx_memory
{
    /*
    * @brief: A reference counted pointer class.
    */
    class RefCountedPointer
    {
    public: // Constructors and Destructor
        RefCountedPointer(void* pointer)
            : raw_pointer(pointer)
            , reference_count(1)
        {
        }

        RefCountedPointer(const RefCountedPointer& other)
            : raw_pointer(other.raw_pointer)
            , reference_count(other.reference_count)
        {
            ++this->reference_count;
        }

        RefCountedPointer(const RefCountedPointer&& other) noexcept
            : raw_pointer(other.raw_pointer)
            , reference_count(other.reference_count)
        {
            ++this->reference_count;
        }

        ~RefCountedPointer()
        {
            if(--reference_count == 0)
            {
                delete this->raw_pointer;
            }
        }

    public: // Public Member Functions
        void AddRef()
        {
            ++this->reference_count;
        }

        void Release()
        {
            if(--this->reference_count == 0)
            {
                delete this->raw_pointer;
            }
        }

        int GetReferenceCount() const
        {
            return this->reference_count;
        }

    public: // Public Member Variables
        void* raw_pointer;
        int reference_count;

    }; // class RefCountedPointer

} // namespace cxx_memory

#endif // CXX_MEMORY_REF_COUNTED_POINTER_H