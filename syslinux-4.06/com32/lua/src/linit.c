/*
** $Id: linit.c,v 1.14.1.1 2007/12/27 13:02:25 roberto Exp $
** Initialization of libraries for lua.c
** See Copyright Notice in lua.h
*/


#define linit_c
#define LUA_LIB

#include "lua.h"

#include "lualib.h"
#include "lauxlib.h"


static const luaL_Reg lualibs[] = {
  {"", luaopen_base},
  {LUA_LOADLIBNAME, luaopen_package},
  {LUA_TABLIBNAME, luaopen_table},
  {LUA_IOLIBNAME, luaopen_io},
#ifndef SYSLINUX
  {LUA_OSLIBNAME, luaopen_os},
#endif
  {LUA_STRLIBNAME, luaopen_string},
#if !defined LUA_NUMBER_INTEGRAL
  {LUA_MATHLIBNAME, luaopen_math},
#endif
  {LUA_DBLIBNAME, luaopen_debug},
#ifdef SYSLINUX
  {LUA_CPULIBNAME, luaopen_cpu},
  {LUA_DMILIBNAME, luaopen_dmi},
  {LUA_PCILIBNAME, luaopen_pci},
  {LUA_SYSLINUXLIBNAME, luaopen_syslinux},
  {LUA_VESALIBNAME, luaopen_vesa},
  {LUA_DHCPLIBNAME, luaopen_dhcp},
#endif
  {NULL, NULL}
};


LUALIB_API void luaL_openlibs (lua_State *L) {
  const luaL_Reg *lib = lualibs;
  for (; lib->func; lib++) {
    lua_pushcfunction(L, lib->func);
    lua_pushstring(L, lib->name);
    lua_call(L, 1, 0);
  }
}

