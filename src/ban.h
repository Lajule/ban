#pragma once

#include <stdint.h>
#include <stdio.h>

#ifdef WIN32
#define ban_EXPORT __declspec(dllexport)
#else
#define ban_EXPORT
#endif

ban_EXPORT void ban(const char *, char *, size_t);
ban_EXPORT void bant(const char *, const char *, char *, size_t);
