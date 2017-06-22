#include "piasimov.h"

#include <QDebug>

#include <KPluginFactory>

K_PLUGIN_FACTORY_WITH_JSON(PIAsimoVFactory, "piasimov.json", registerPlugin<PIAsimoV>(); )

PIAsimoV::PIAsimoV(QObject *parent, const QVariantList& args)
    : KDevelop::IPlugin(QStringLiteral("piasimov"), parent)
{
    Q_UNUSED(args);

    qDebug() << "Hello world, my plugin is loaded!";
}

// needed for QObject class created from K_PLUGIN_FACTORY_WITH_JSON
#include "piasimov.moc"
