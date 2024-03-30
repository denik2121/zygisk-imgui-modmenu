#ifndef HOOK_MACROS
#define HOOK_MACROS
#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

const char *libName = OBFUSCATE("libil2cpp.so");
const char *unitylibName = OBFUSCATE("libunity.so");

#define HOOK(offset, ptr, orig) MSHookFunction((void *)getAbsoluteAddress(libName, string2Offset(OBFUSCATE(offset))), (void *)ptr, (void **)&orig)
#define HOOK_LIB(lib, offset, ptr, orig) MSHookFunction((void *)getAbsoluteAddress(OBFUSCATE(lib), string2Offset(OBFUSCATE(offset))), (void *)ptr, (void **)&orig)

//Obfuscate offset
#define OBFUSCATEOFFSET(str) string2Offset(OBFUSCATE(str)) //Encrypt offset

#endif //Macros For Hook
