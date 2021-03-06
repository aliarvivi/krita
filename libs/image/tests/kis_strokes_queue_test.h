/*
 *  Copyright (c) 2011 Dmitry Kazakov <dimula73@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __KIS_STROKES_QUEUE_TEST_H
#define __KIS_STROKES_QUEUE_TEST_H

#include <QtTest>
#include "kis_types.h"
#include "kis_stroke_job_strategy.h"

class KisStrokesQueueTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testSequentialJobs();
    void testConcurrentSequentialBarrier();
    void testExclusiveStrokes();
    void testBarrierStrokeJobs();
    void testStrokesOverlapping();
    void testImmediateCancel();
    void testOpenedStrokeCounter();
    void testAsyncCancelWhileOpenedStroke();
    void testStrokesLevelOfDetail();
    void testLodUndoBase();
    void testLodUndoBase2();
    void testMutatedJobs();
    void testUniquelyConcurrentJobs();

private:
    struct LodStrokesQueueTester;
    static void checkJobsOverlapping(LodStrokesQueueTester &t, KisStrokeId id, KisStrokeJobData::Sequentiality first, KisStrokeJobData::Sequentiality second, bool allowed);
};

#endif /* __KIS_STROKES_QUEUE_TEST_H */
