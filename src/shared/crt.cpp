//
// MIT License
//
// Copyright (c) 2019 Rokas Kupstys
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
#include <cstddef>
#include <malloc.h>
#include <new>
#include <cassert>


void* pmalloc(std::size_t count)
{
    void* p = nullptr;
    for (; p == nullptr; p = malloc(count));
    return p;
}

void* operator new  ( std::size_t count )                                            { return pmalloc(count); }
void* operator new[]( std::size_t count )                                            { return pmalloc(count); }
void* operator new  ( std::size_t count, std::align_val_t al)                        { return pmalloc(count); }
void* operator new[]( std::size_t count, std::align_val_t al)                        { return pmalloc(count); }
void* operator new  ( std::size_t count, const std::nothrow_t& tag)                  { return pmalloc(count); }
void* operator new[]( std::size_t count, const std::nothrow_t& tag)                  { return pmalloc(count); }
void* operator new  ( std::size_t count, std::align_val_t al, const std::nothrow_t&) { return pmalloc(count); }
void* operator new[]( std::size_t count, std::align_val_t al, const std::nothrow_t&) { return pmalloc(count); }

void operator delete  ( void* ptr )                                                  { free(ptr);             }
void operator delete[]( void* ptr )                                                  { free(ptr);             }
void operator delete  ( void* ptr, std::align_val_t al )                             { free(ptr);             }
void operator delete[]( void* ptr, std::align_val_t al )                             { free(ptr);             }
void operator delete  ( void* ptr, std::size_t sz )                                  { free(ptr);             }
void operator delete[]( void* ptr, std::size_t sz )                                  { free(ptr);             }
void operator delete  ( void* ptr, std::size_t sz, std::align_val_t al )             { free(ptr);             }
void operator delete[]( void* ptr, std::size_t sz, std::align_val_t al )             { free(ptr);             }

extern "C" void __cxa_pure_virtual()
{
    assert(false);
}

// Related to exceptions. This project does not use exceptions
extern "C" void __register_frame_info (__attribute__((unused)) const void *, __attribute__((unused)) struct object *) {}
extern "C" void *__deregister_frame_info (__attribute__((unused)) const void *) { return nullptr; }
