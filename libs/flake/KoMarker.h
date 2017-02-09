/* This file is part of the KDE project
   Copyright (C) 2011 Thorsten Zachmann <zachmann@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
*/

#ifndef KOMARKER_H
#define KOMARKER_H

#include <QMetaType>
#include <QSharedData>

#include "kritaflake_export.h"

class KoXmlElement;
class KoShapeLoadingContext;
class KoShapeSavingContext;
class QString;
class QPainterPath;
class KoShape;
class QPainter;

class  KRITAFLAKE_EXPORT KoMarker : public QSharedData
{
public:
    KoMarker();
    ~KoMarker();

    /**
     * Load the marker
     *
     * @param element The xml element containing the marker
     * @param context The shape loading context
     */
    bool loadOdf(const KoXmlElement &element, KoShapeLoadingContext &context);

    /**
     * Save the marker
     *
     * @return The reference of the marker.
     */
    QString saveOdf(KoShapeSavingContext &context) const;

    /**
     * Display name of the marker
     *
     * @return Display name of the marker
     */
    QString name() const;

    /**
     * Get the path of the marker
     *
     * It calculates the offset depending on the line width
     *
     * @param The width of the line the marker is attached to.
     * @return the path of the marker
     */
    QPainterPath path(qreal width) const;

    bool operator==(const KoMarker &other) const;

    enum MarkerCoordinateSystem {
        StrokeWidth,
        UserSpaceOnUse
    };

    void setCoordinateSystem(MarkerCoordinateSystem value);
    MarkerCoordinateSystem coordinateSystem() const;

    static MarkerCoordinateSystem coordinateSystemFromString(const QString &value);
    static QString coordinateSystemToString(MarkerCoordinateSystem value);

    void setReferencePoint(const QPointF &value);
    QPointF referencePoint() const;

    void setReferenceSize(const QSizeF &size);
    QSizeF referenceSize() const;

    bool hasAutoOtientation() const;
    void setAutoOrientation(bool value);

    // measured in radians!
    qreal explicitOrientation() const;

    // measured in radians!
    void setExplicitOrientation(qreal value);

    void setShapes(const QList<KoShape*> &shapes);
    QList<KoShape*> shapes() const;

    /**
     * @brief paintAtOrigin paints the marker at the position \p pos.
     *        Scales and rotates the masrker if needed.
     */
    void paintAtPosition(QPainter *painter, const QPointF &pos, qreal strokeWidth, qreal nodeAngle);

private:
    class Private;
    Private * const d;
};

Q_DECLARE_METATYPE(KoMarker*)

#endif /* KOMARKER_H */
