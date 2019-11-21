#ifndef __SYBERH5FRAMEWORK_WORKSPACE__
#define __SYBERH5FRAMEWORK_WORKSPACE__

#include <QQuickView>
#include <QQuickWindow>
#include <QQmlEngine>
#include <QQmlComponent>
#include <SyberosGuiCache>
#include <cgui_application.h>
#include <cworkspace.h>
#include "syberh5helpper.h"

using namespace SYBEROS;

class SyberH5Framework_Workspace : public CWorkspace
{
    Q_OBJECT

private:
    QQuickView *m_view;
    SyberH5Helpper *syberH5Helper;

public:
    SyberH5Framework_Workspace();

    // 应用启动结束时，回调此函数。根据传入的option，应用可以区分启动的方式。
    void onLaunchComplete(Option option, const QStringList& params);

};


#endif //__SYBERH5FRAMEWORK_WORKSPACE__
