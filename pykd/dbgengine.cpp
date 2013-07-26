#include "stdafx.h"

#include "kdlib/dbgengine.h"
#include "kdlib/typeinfo.h"

#include "dbgengine.h"

namespace pykd {

///////////////////////////////////////////////////////////////////////////////

kdlib::ExecutionStatus targetGo()
{
    kdlib::ExecutionStatus  status;

    PyThreadState*    state = PyEval_SaveThread();

    status = kdlib::targetGo();

    PyEval_RestoreThread( state );

    return status;
}

///////////////////////////////////////////////////////////////////////////////

void targetBreak()
{
    PyThreadState*    state = PyEval_SaveThread();

    kdlib::targetBreak();

    PyEval_RestoreThread( state );
}

///////////////////////////////////////////////////////////////////////////////

kdlib::ExecutionStatus targetStep()
{
    kdlib::ExecutionStatus  status;

    PyThreadState*    state = PyEval_SaveThread();

    status =  kdlib::targetStep();

    PyEval_RestoreThread( state );

    return status;
}

///////////////////////////////////////////////////////////////////////////////

kdlib::ExecutionStatus targetStepIn()
{
    kdlib::ExecutionStatus  status;

    PyThreadState*    state = PyEval_SaveThread();

    status = kdlib::targetStepIn();

    PyEval_RestoreThread( state );

    return status;
}

///////////////////////////////////////////////////////////////////////////////

kdlib::PROCESS_DEBUG_ID startProcess( const std::wstring  &processName )
{
    kdlib::PROCESS_DEBUG_ID  id;

    PyThreadState*    state = PyEval_SaveThread();

    id = kdlib::startProcess(processName);

    PyEval_RestoreThread( state );

    return id;

}

///////////////////////////////////////////////////////////////////////////////

kdlib::PROCESS_DEBUG_ID attachProcess( kdlib::PROCESS_ID pid )
{
    kdlib::PROCESS_DEBUG_ID  id;

    PyThreadState*    state = PyEval_SaveThread();

    id = kdlib::attachProcess(pid);

    PyEval_RestoreThread( state );

    return id;
}

///////////////////////////////////////////////////////////////////////////////

void loadDump( const std::wstring &fileName )
{
    PyThreadState*    state = PyEval_SaveThread();

    kdlib::loadDump(fileName);

    PyEval_RestoreThread( state );
}

///////////////////////////////////////////////////////////////////////////////

std::wstring debugCommand( const std::wstring &command )
{
    PyThreadState*    state = PyEval_SaveThread();

    std::wstring outstr = kdlib::debugCommand(command);

    PyEval_RestoreThread( state );

    return outstr;
}

///////////////////////////////////////////////////////////////////////////////

unsigned long long evaluate( const std::wstring  &expression )
{
    PyThreadState*    state = PyEval_SaveThread();

    unsigned long long result = kdlib::evaluate(expression);

    PyEval_RestoreThread( state );

    return result;
}

///////////////////////////////////////////////////////////////////////////////

python::tuple getSourceLine( kdlib::MEMOFFSET_64 offset )
{
    std::wstring  fileName;
    unsigned long  lineno;
    long  displacement;

    kdlib::getSourceLine( fileName, lineno, displacement, offset );

    return python::make_tuple( fileName, lineno, displacement );
}

///////////////////////////////////////////////////////////////////////////////

python::tuple findSymbolAndDisp( ULONG64 offset )
{
    kdlib::MEMDISPLACEMENT  displacement = 0;
    std::wstring  symbolName = kdlib::findSymbol( offset, displacement );
    return python::make_tuple(symbolName,displacement);
}

///////////////////////////////////////////////////////////////////////////////

kdlib::SystemInfo getSystemVersion()
{
    kdlib::SystemInfo sysInfo;
    kdlib::getSystemInfo( sysInfo );
    return sysInfo;
}

///////////////////////////////////////////////////////////////////////////////

std::wstring printSystemVersion( kdlib::SystemInfo& sysInfo )
{
    std::wstringstream sstr;

    sstr << L"Major Version: " << sysInfo.majorVersion << std::endl;
    sstr << L"Minor Version: " << sysInfo.minorVersion << std::endl;;
    sstr << L"Description: " << sysInfo.buildDescription << std::endl;

    return sstr.str();
}

///////////////////////////////////////////////////////////////////////////////

} //end namespace pykd
