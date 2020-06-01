/**
 * @file
 */

#include "int128.h"

/*
 * http://stackoverflow.com/a/25115163
 */
std::ostream& operator<<(std::ostream& os, const __int128 i) noexcept
{
    std::ostream::sentry s(os);
    if (s) {
        unsigned __int128 tmp = i < 0 ? -i : i;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (i < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len) {
            os.setstate(std::ios_base::badbit);
        }
    }
    return os;
}