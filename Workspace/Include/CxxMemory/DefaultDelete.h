/*
* MIT License
* 
* Copyright (c) paging 2024 DefaultDelete.h
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