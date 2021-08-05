#pragma once

#include <stdint.h>
#include <stdio.h>

#ifdef WIN32
#define ban_EXPORT __declspec(dllexport)
#else
#define ban_EXPORT
#endif

#define DEFAULT_TPL "@NAME@ - @HOSTNAME@ - @OS@ - @CORES@ - @MEM@ - @TIME@"

#define ban(n, s, l) bant(n, DEFAULT_TPL, s, l)

ban_EXPORT void bant(const char *, const char *, char *, size_t);
