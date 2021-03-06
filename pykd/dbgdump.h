#pragma once

#include <string>

/////////////////////////////////////////////////////////////////////////////////

void
dbgLoadDump( const std::wstring &dumpName );

void
startProcess( const std::wstring  &processName );

void
attachProcess( ULONG  processId );

void
attachKernel( const std::wstring  param );

/////////////////////////////////////////////////////////////////////////////////
