/*
    KWin - the KDE window manager
    This file is part of the KDE project.

    SPDX-FileCopyrightText: 2016 Roman Gilg <subdiff@gmail.com>

    SPDX-License-Identifier: GPL-2.0-or-later
*/
#ifndef KWIN_DRM_OBJECT_CRTC_H
#define KWIN_DRM_OBJECT_CRTC_H

#include "drm_object.h"

#include <QSharedPointer>

namespace KWin
{

class DrmBackend;
class DrmBuffer;
class DrmDumbBuffer;
class GammaRamp;
class DrmGpu;

class DrmCrtc : public DrmObject
{
public:
    DrmCrtc(DrmGpu *gpu, uint32_t crtcId, int resIndex);

    bool init() override;

    enum class PropertyIndex : uint32_t {
        ModeId = 0,
        Active,
        Count
    };

    int resIndex() const {
        return m_resIndex;
    }

    QSharedPointer<DrmBuffer> current() {
        return m_currentBuffer;
    }
    QSharedPointer<DrmBuffer> next() {
        return m_nextBuffer;
    }
    void setNext(const QSharedPointer<DrmBuffer> &buffer) {
        m_nextBuffer = buffer;
    }

    void flipBuffer();
    bool blank(DrmOutput *output);

    int gammaRampSize() const {
        return m_crtc->gamma_size;
    }
    bool setGammaRamp(const GammaRamp &gamma);

private:
    DrmScopedPointer<drmModeCrtc> m_crtc;
    int m_resIndex;

    QSharedPointer<DrmBuffer> m_currentBuffer;
    QSharedPointer<DrmBuffer> m_nextBuffer;
    DrmDumbBuffer *m_blackBuffer = nullptr;
};

}

#endif

