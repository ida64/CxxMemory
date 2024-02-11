#pragma once

#include "DefaultDelete.h"

namespace cxx_memory
{
    /*
    * @brief UniquePointer is a class that owns a pointer and deletes it when it goes out of scope.
    * 
    * @tparam PointerType is the type of the pointer to be owned.
    * @tparam Deleter is the type of the deleter to be used.
     */
    template<typename PointerType, class Deleter = DefaultDelete>
    class UniquePointer
    { 
    public: // Constructors and Destructor
        /*
        * @brief UniquePointer is the constructor that takes a pointer and stores it.
        * @param pointer is the pointer to be stored.
         */
        UniquePointer(PointerType* pointer)
            : m_PointerValue(pointer)
        {
        }

        /*
        * @brief UniquePointer is the move constructor that moves the pointer from another UniquePointer.
        * @param other is the UniquePointer to move from.
         */
        UniquePointer(UniquePointer&& other) noexcept
            : m_PointerValue(other.m_PointerValue)
        {
            other.m_PointerValue = nullptr;
        }

        /*
        * @brief ~UniquePointer is the destructor that deletes the pointer.
         */
        ~UniquePointer()
        {
            if (m_PointerValue != nullptr)
            {
                Deleter()(m_PointerValue);
            }
        }

    public: // Operators
        /*
        * @brief operator= is the move assignment operator that moves the pointer from another UniquePointer.
        * 
        * @param other is the UniquePointer to move from.
        * @return UniquePointer& is the reference to this UniquePointer.
         */
        UniquePointer& operator=(UniquePointer&& other) noexcept
        {
            if(this != &other)
            {
                if(m_PointerValue != nullptr)
                {
                    Deleter()(m_PointerValue);
                }

                m_PointerValue = other.m_PointerValue;
                other.m_PointerValue = nullptr;
            }

            return *this;
        }

    public: // Public Member Functions
        PointerType* GetValue() const
        {
            return m_PointerValue;
        }

    private: // Private Member Variables
        PointerType* m_PointerValue;

    }; // class UniquePointer

}; // namespace cxx_memory