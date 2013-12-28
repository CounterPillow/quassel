/***************************************************************************
 *   Copyright (C) 2005-2013 by the Quassel Project                        *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) version 3.                                           *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#include "transfer.h"

INIT_SYNCABLE_OBJECT(Transfer)
Transfer::Transfer(const QUuid &uuid, QObject *parent)
    : SyncableObject(parent),
    _state(New),
    _direction(Receive),
    _port(0),
    _fileSize(0),
    _uuid(uuid)
{
    renameObject(QString("Transfer/%1").arg(_uuid.toString()));
}

Transfer::Transfer(Direction direction, const QString &nick, const QString &fileName, const QHostAddress &address, quint16 port, quint64 fileSize, QObject *parent)
    : SyncableObject(parent),
    _state(New),
    _direction(direction),
    _fileName(fileName),
    _address(address),
    _port(port),
    _fileSize(fileSize),
    _nick(nick),
    _uuid(QUuid::createUuid())
{
    renameObject(QString("Transfer/%1").arg(_uuid.toString()));
}


QUuid Transfer::uuid() const
{
    return _uuid;
}


Transfer::State Transfer::state() const
{
    return _state;
}


void Transfer::setState(Transfer::State state)
{
    if (_state != state) {
        _state = state;
        SYNC(ARG(state));
        emit stateChanged(state);
    }
}



Transfer::Direction Transfer::direction() const
{
    return _direction;
}


void Transfer::setDirection(Transfer::Direction direction)
{
    if (_direction != direction) {
        _direction = direction;
        SYNC(ARG(direction));
        emit directionChanged(direction);
    }
}


QHostAddress Transfer::address() const
{
    return _address;
}


void Transfer::setAddress(const QHostAddress &address)
{
    if (_address != address) {
        _address = address;
        SYNC(ARG(address));
        emit addressChanged(address);
    }
}


quint16 Transfer::port() const
{
    return _port;
}


void Transfer::setPort(quint16 port)
{
    if (_port != port) {
        _port = port;
        SYNC(ARG(port));
        emit portChanged(port);
    }
}


QString Transfer::fileName() const
{
    return _fileName;
}


void Transfer::setFileName(const QString &fileName)
{
    if (_fileName != fileName) {
        _fileName = fileName;
        SYNC(ARG(fileName));
        emit fileNameChanged(fileName);
    }
}


quint64 Transfer::fileSize() const
{
    return _fileSize;
}


void Transfer::setFileSize(quint64 fileSize)
{
    if (_fileSize != fileSize) {
        _fileSize = fileSize;
        SYNC(ARG(fileSize));
        emit fileSizeChanged(fileSize);
    }
}


QString Transfer::nick() const
{
    return _nick;
}


void Transfer::setNick(const QString &nick)
{
    if (_nick != nick) {
        _nick = nick;
        SYNC(ARG(nick));
        emit nickChanged(nick);
    }
}