/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_IO_PATH_H
#define MU_IO_PATH_H

#include <QString>
#include "framework/global/logstream.h"

namespace mu::io {
struct path_t;
using paths_t = std::vector<path_t>;
struct path_t {
    path_t() = default;
    path_t(const QByteArray& s);
    path_t(const QString& s);
    path_t(const std::string& s);
    path_t(const char* s);

    bool empty() const;

    path_t appendingComponent(const path_t& other) const;
    path_t appendingSuffix(const path_t& suffix) const;

    inline path_t& operator=(const QString& other) { m_path = other.toUtf8(); return *this; }

    inline bool operator==(const path_t& other) const { return m_path == other.m_path; }
    inline bool operator!=(const path_t& other) const { return !(m_path == other.m_path); }

    inline path_t operator+(const path_t& other) const { path_t p = *this; p += other; return p; }
    inline path_t operator+(const QString& other) const { path_t p = *this; p += other; return p; }
    inline path_t operator+(const char* other) const { path_t p = *this; p += other; return p; }

    inline path_t& operator+=(const path_t& other) { m_path += other.m_path; return *this; }
    inline path_t& operator+=(const QString& other) { m_path += other.toUtf8(); return *this; }
    inline path_t& operator+=(const char* other) { m_path += other; return *this; }

    inline bool operator<(const path_t& other) const { return m_path < other.m_path; }

    QString toQString() const;
    std::string toStdString() const;
    std::wstring toStdWString() const;
    const char* c_str() const;

    const QByteArray& constData() const;

private:
    QByteArray m_path;
};

inline path_t operator+(const char* one, const path_t& other) { return path_t(one) + other; }
inline path_t operator+(const QString& one, const path_t& other) { return path_t(one) + other; }

inline mu::logger::Stream& operator<<(mu::logger::Stream& s, const mu::io::path_t& p)
{
    s << p.c_str();
    return s;
}

std::string suffix(const path_t& path);
path_t filename(const path_t& path, bool includingExtension = true);
path_t basename(const path_t& path);
path_t completeBasename(const path_t& path);
path_t absolutePath(const path_t& path);
path_t dirname(const path_t& path);
path_t dirpath(const path_t& path);
path_t absoluteDirpath(const path_t& path);

bool isAbsolute(const path_t& path);

bool isAllowedFileName(const path_t& fn);
path_t escapeFileName(const path_t& fn);

paths_t pathsFromStrings(const QStringList& list);

paths_t pathsFromString(const std::string& str, const std::string& delim = ";");
std::string pathsToString(const paths_t& ps, const std::string& delim = ";");
}

#endif // MU_IO_PATH_H
