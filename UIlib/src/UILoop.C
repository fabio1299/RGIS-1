/******************************************************************************

GHAAS User Interface library V2.1
Global Hydrologic Archive and Analysis System
Copyright 1994-2018, UNH - CCNY/CUNY

UILoop.C

bfekete@ccny.cuny.edu

*******************************************************************************/

#include <UI.H>

static int _UILoopStop = false;

int UILoop() {
    XEvent event;

    XtAppNextEvent(UIApplicationContext(), &event);
    XtDispatchEvent(&event);

    if (_UILoopStop) {
        _UILoopStop = false;
        return (false);
    }
    else return (true);
}

void UILoopStopCBK(Widget widget, void *data, XmAnyCallbackStruct *callData) {
    _UILoopStop = true;
}
