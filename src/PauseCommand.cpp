/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#include "PauseCommand.h"

#include <SFML/Audio/Music.hpp>

namespace tmplayer
{

PauseCommand::PauseCommand(const sf::MusicSPtr &musicSPtr) : m_musicSPtr(musicSPtr)
{
}

void PauseCommand::execute(const QVariant &)
{
    QWeakPointer<sf::Music> musicWPtr = m_musicSPtr.toWeakRef();
    if (!musicWPtr.isNull())
    {
        musicWPtr.lock()->pause();
    }
}

} // namespace tmplayer
