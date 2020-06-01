/**
 * @file
 *
 * Support for 128-bit integers in GCC and Clang.
 */

#ifndef __INT128_H__
#define __INT128_H__

/*
 * Standard
 */
#include <iostream>

/**
 * Overload the ostream operator << to support 128-bit integers.
 */
std::ostream&
operator<<( std::ostream& dest, const __int128 value )
noexcept;

#endif /* __INT128_H__ */