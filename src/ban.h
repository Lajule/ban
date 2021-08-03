#pragma once

#ifdef WIN32
  #define ban_EXPORT __declspec(dllexport)
#else
  #define ban_EXPORT
#endif

ban_EXPORT void ban(const char *);
