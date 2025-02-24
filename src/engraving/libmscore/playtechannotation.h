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

#ifndef MU_ENGRAVING_PLAYINGTECHNIQUEANNOTATION_H
#define MU_ENGRAVING_PLAYINGTECHNIQUEANNOTATION_H

#include "stafftextbase.h"
#include "types/types.h"

namespace Ms {
class PlayTechAnnotation final : public StaffTextBase
{
public:
    PlayTechAnnotation(Segment* parent = nullptr, PlayingTechniqueType techniqueType = PlayingTechniqueType::Natural,
                       TextStyleType tid = TextStyleType::STAFF);

    PlayingTechniqueType techniqueType() const;
    void setTechniqueType(const PlayingTechniqueType techniqueType);

    PlayTechAnnotation* clone() const override;
    void layout() override;

private:
    void write(XmlWriter& writer) const override;
    void read(XmlReader& reader) override;

    mu::engraving::PropertyValue getProperty(Pid id) const override;
    bool setProperty(Pid propertyId, const mu::engraving::PropertyValue& val) override;
    mu::engraving::PropertyValue propertyDefault(Pid id) const override;

    PlayingTechniqueType m_techniqueType = PlayingTechniqueType::Undefined;
};
}

#endif // MU_ENGRAVING_PLAYINGTECHNIQUEANNOTATION_H
