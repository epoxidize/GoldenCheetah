/*
 * Copyright (c) 2010 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_LTMChartParser_h
#define _GC_LTMChartParser_h 1
#include "GoldenCheetah.h"

#include <QXmlDefaultHandler>
#include <QDialog>

#include "LTMSettings.h"
#include "LTMTool.h"

class LTMChartParser : public QXmlDefaultHandler
{

public:
    static void serialize(QString, QList<LTMSettings>);

    // unmarshall
    bool startDocument();
    bool endDocument();
    bool endElement( const QString&, const QString&, const QString &qName );
    bool startElement( const QString&, const QString&, const QString &name, const QXmlAttributes &attrs );
    bool characters( const QString& str );
    QList<LTMSettings> getSettings();

protected:
    QString buffer;
    LTMSettings setting;
    MetricDetail metric;
    int red, green, blue;
    QList<LTMSettings> settings;
};
#endif
