#include "stdafx.h"

#include "pyprocess.h"
#include "stladaptor.h"

namespace pykd {

///////////////////////////////////////////////////////////////////////////////

python::list TargetSystemAdapter::getProcessesList(kdlib::TargetSystem& system)
{
    std::vector<kdlib::TargetProcessPtr>  processLst;

    do {
        AutoRestorePyState  pystate;
        for ( unsigned long i = 0; i < system.getNumberProcesses(); ++i)
            processLst.push_back(system.getProcessByIndex(i));
    } while(false);

    return vectorToList(processLst);
}

///////////////////////////////////////////////////////////////////////////////

python::list TargetProcessAdapter::getThreadList(kdlib::TargetProcess& process)
{
    std::vector<kdlib::TargetThreadPtr>  threadLst;

    do {
        AutoRestorePyState  pystate;
        for ( unsigned long i = 0; i < process.getNumberThreads(); ++i)
            threadLst.push_back(process.getThreadByIndex(i));
    } while(false);

    return vectorToList(threadLst);
}

///////////////////////////////////////////////////////////////////////////////

python::list TargetProcessAdapter::getBreakpointsList(kdlib::TargetProcess& process)
{
    std::vector<pykd::Breakpoint*>  bpLst;

    do {
        AutoRestorePyState  pystate;
        for ( unsigned long i = 0; i < process.getNumberBreakpoints(); ++i)
            bpLst.push_back(new Breakpoint(process.getBreakpoint(i)));
    } while(false);

    return vectorToList(bpLst);
}

///////////////////////////////////////////////////////////////////////////////

python::list TargetProcessAdapter::getModulesList(kdlib::TargetProcess& process)
{
    std::vector<kdlib::ModulePtr >  moduleLst;

    do {
        AutoRestorePyState  pystate;
        for ( unsigned long i = 0; i < process.getNumberModules(); ++i)
            moduleLst.push_back(process.getModuleByIndex(i));
    } while(false);

    return vectorToList(moduleLst);
}

///////////////////////////////////////////////////////////////////////////////

python::list TargetThreadAdapter::getStack(kdlib::TargetThread& thread)
{

    std::vector<kdlib::StackFramePtr >  frameLst;

    do {
        AutoRestorePyState  pystate;
        kdlib::StackPtr  stack = thread.getStack();

        for (unsigned long i = 0; i < stack->getFrameCount(); ++i)
            frameLst.push_back(stack->getFrame(i));
    } while(false);

    return vectorToList(frameLst);
}

///////////////////////////////////////////////////////////////////////////////

}
