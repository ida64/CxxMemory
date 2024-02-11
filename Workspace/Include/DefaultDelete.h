#ifndef CXX_MEMORY_DEFAULT_DELETE_H
#define CXX_MEMORY_DEFAULT_DELETE_H

namespace cxx_memory
{
    /*
    * @brief DefaultDelete is a struct that contains a templated operator() to delete a pointer.
     */
    struct DefaultDelete
    {
        /*
        * @brief operator() is a templated function that deletes a pointer.
        * @param pointer is a pointer to be deleted.
         */
        template<typename PointerType>
        void operator()(PointerType* pointer)
        {
            delete pointer;
        }

    }; // struct DefaultDelete

} // namespace cxx_memory

#endif // CXX_MEMORY_DEFAULT_DELETE_H