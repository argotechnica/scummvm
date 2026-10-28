/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SAGA2_GAME_H
#define SAGA2_GAME_H

#include "common/scummsys.h"

namespace Saga2 {

/**
 * Layout of a prototype's object base.
 *
 * Object prototypes always use the full base. FTA2 actor prototypes also use
 * it; Dinotopia actor prototypes store only the common fields and put the
 * actor extension immediately after them.
 */
enum ObjectProtoLayout {
	kObjectProtoFull,       // common fields followed by the object extension
	kObjectProtoCommonOnly  // common fields only (Dinotopia actor prototypes)
};

/**
 * Per-game data layout and feature flags.
 *
 * FTA2 and Dinotopia use different resource record layouts. Keeping those
 * differences here avoids scattering game checks through the resource
 * parsers. Values in the table are listed as FTA2 / Dino.
 */
struct Saga2GameSettings {
	uint8 protoIndexSize;          // 2 / 4
	uint8 objectRecordSize;        // 19 / 24
	uint8 objectReservedBytes;     // 0 / 3
	uint8 actorRecordSize;         // 91 / 96
	uint8 objectProtoRecordSize;   // 52 / 52
	uint8 actorProtoRecordSize;    // 86 / 52
	ObjectProtoLayout actorProtoLayout; // FTA2 full, Dino common-only
	bool appearanceBigEndian;      // FTA2 true, Dino false
	bool hasSpellBook;             // FTA2 true, Dino false
	bool hasFixedPlayerActors;     // FTA2 true, Dino false
};

} // End of namespace Saga2

#endif // SAGA2_GAME_H
