/*************************************************************************/
/*  platform_refcount.h                                                  */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2019 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2019 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#include "safe_refcount.h"

#if defined(IPHONE_ENABLED)

#define REFCOUNT_T int
#define REFCOUNT_GET_T int const volatile &

#include <libkern/OSAtomic.h>

inline int atomic_conditional_increment(volatile int *v) {
	return (*v == 0) ? 0 : OSAtomicIncrement32(v);
}

inline int atomic_decrement(volatile int *v) {
	return OSAtomicDecrement32(v);
}

#elif defined(SYMBIAN_ENABLED)

#include <e32atomics.h>

inline int atomic_conditional_increment(volatile int *v) {
	return (*v == 0) ? 0 : __e32_atomic_add_rlx32(v, 1);
}

inline int atomic_decrement(volatile int *v) {
	return __e32_atomic_add_rlx32(v, -1);
}

#endif
