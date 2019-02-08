//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2019 Werner Schweer and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENCE.GPL
//=============================================================================

#ifndef __PLUGIN_API_EXCERPT_H__
#define __PLUGIN_API_EXCERPT_H__

#include "libmscore/excerpt.h"
#include "scoreelement.h"

namespace Ms {

namespace PluginAPI {

class Score;

//---------------------------------------------------------
//   Excerpt
//    Wrapper class for Excerpt
//
//   This is based on the wrapper in scoreelement.h, which
//   we cannot use here, because Ms::Excerpt is not derived
//   from Ms::ScoreElement.
//---------------------------------------------------------

class Excerpt : public QObject {
    Q_OBJECT
    Q_PROPERTY(Ms::PluginAPI::Score* partScore READ partScore)
    Q_PROPERTY(QString               title     READ title)

    Ownership _ownership;

protected:
    Ms::Excerpt* const e;

 public:
    Excerpt(Ms::Excerpt* _e = nullptr, Ownership own = Ownership::PLUGIN)
       : QObject(), _ownership(own), e(_e) {}
    Excerpt(const Excerpt&) = delete;
    Excerpt& operator=(const Excerpt&) = delete;
    virtual ~Excerpt();

    Ownership ownership() const { return _ownership; }
    void setOwnership(Ownership o) { _ownership = o; }

    Score* partScore();
    QString title() { return e->title(); }
};

extern Excerpt* wrap(Ms::Excerpt* e, Ownership own = Ownership::SCORE);

} // namespace PluginAPI
} // namespace Ms
#endif
