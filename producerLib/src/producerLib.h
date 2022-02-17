#pragma once

#ifdef WIN32
  #define producerLib_EXPORT __declspec(dllexport)
#else
  #define producerLib_EXPORT
#endif

producerLib_EXPORT void producerLib();
