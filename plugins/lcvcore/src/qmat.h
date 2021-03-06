/****************************************************************************
**
** Copyright (C) 2014-2017 Dinu SV.
** (contact: mail@dinusv.com)
** This file is part of Live CV Application.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
****************************************************************************/

#ifndef QMAT_H
#define QMAT_H

#include <QQuickItem>
#include "opencv2/core.hpp"
#include "qlcvcoreglobal.h"

class QMatAccess;

class Q_LCVCORE_EXPORT QMat : public QQuickItem{

    Q_OBJECT
    Q_ENUMS(Type)

public:
    enum Type{
        CV8U  = CV_8U,
        CV8S  = CV_8S,
        CV16U = CV_16U,
        CV16S = CV_16S,
        CV32S = CV_32S,
        CV32F = CV_32F,
        CV64F = CV_64F
    };

public:
    explicit QMat(QQuickItem *parent = 0);
    QMat(cv::Mat *mat, QQuickItem *parent = 0);
    ~QMat();

    cv::Mat* cvMat();

    static QMat* nullMat();
    static void  cleanUp();

public slots:
    QMatAccess* data();
    QSize       dataSize() const;
    QMat*       createOwnedObject();
    QMat*       cloneMat();

private:
    cv::Mat* m_cvmat;

    static QMat* m_nullMat;
    
};

inline cv::Mat *QMat::cvMat(){
    return m_cvmat;
}

#endif // QMAT_H
