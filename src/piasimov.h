#ifndef PIASIMOV_H
#define PIASIMOV_H

#include <interfaces/iplugin.h>

class PIAsimoV : public KDevelop::IPlugin
{
    Q_OBJECT

public:
    // KPluginFactory-based plugin wants constructor with this signature
    PIAsimoV(QObject* parent, const QVariantList& args);
};

#endif // PIASIMOV_H
