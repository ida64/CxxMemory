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

            this->raw_pointer = nullptr;
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