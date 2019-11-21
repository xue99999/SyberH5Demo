#include "SyberH5Framework_Workspace.h"
#include "syberh5helpper.h"
#include <QQmlContext>
#include <QDebug>

SyberH5Framework_Workspace::SyberH5Framework_Workspace()
    : CWorkspace()
{
    m_view = SYBEROS::SyberosGuiCache::qQuickView();
    QObject::connect(m_view->engine(), SIGNAL(quit()), qApp, SLOT(quit()));

    syberH5Helper = new SyberH5Helpper(this);

    m_view->engine()->rootContext()->setContextProperty("syberH5Helper", syberH5Helper);


    m_view->create();

    m_view->setSource(QUrl("qrc:/qml/main.qml"));

//    fib2Start();
//    newArrStart();
}

void SyberH5Framework_Workspace::onLaunchComplete(Option option, const QStringList& params)
{
    Q_UNUSED(params)

    switch (option) {
    case CWorkspace::HOME:
        m_view->showFullScreen();
        qDebug()<< "Start by Home";
        break;
    case CWorkspace::URL:
        m_view->showFullScreen();

        break;
    case CWorkspace::EVENT:
        m_view->showFullScreen();

        break;
    case CWorkspace::DOCUMENT:
        m_view->showFullScreen();

        break;
    default:
        break;
    }
}

