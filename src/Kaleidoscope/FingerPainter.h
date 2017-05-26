/* -*- mode: c++ -*-
 * Kaleidoscope-FingerPainter -- On-the-fly keyboard painting.
 * Copyright (C) 2017  Gergely Nagy
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
 */

#pragma once

#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-EEPROM-Settings.h>

namespace KaleidoscopePlugins {
class FingerPainter : public LEDMode {
  public:
    FingerPainter (void);

    virtual void begin (void) final;
    virtual void update (void) final;

    static void configure (void);
    static void toggleEdit (void);
    static bool focusHook (const char *command);

    static const cRGB *defaultPalette;

  private:
    static uint16_t paletteBase;
    static uint16_t colorBase;
    static bool editMode;

    static Key eventHandlerHook (Key mappedKey, byte row, byte col, uint8_t keyState);
    static cRGB lookupColor (uint8_t row, uint8_t column);
};
};

extern KaleidoscopePlugins::FingerPainter FingerPainter;

#define FOCUS_HOOK_FINGERPAINTER FOCUS_HOOK(FingerPainter.focusHook,  \
                                            "fingerpainter.palette\n" \
                                            "fingerpainter.toggle\n"  \
                                            "fingerpainter.clear")

#define FINGERPAINTER_PALETTE_EGA (const cRGB[]) { \
      CRGB (0x00, 0x00, 0x00),                     \
      CRGB (0x00, 0x00, 0xaa),                     \
      CRGB (0x00, 0xaa, 0x00),                     \
      CRGB (0x00, 0xaa, 0xaa),                     \
      CRGB (0xaa, 0x00, 0x00),                     \
      CRGB (0xaa, 0x00, 0xaa),                     \
      CRGB (0xaa, 0x55, 0x00),                     \
      CRGB (0xaa, 0xaa, 0xaa),                     \
                                                   \
      CRGB (0x55, 0x55, 0x55),                     \
      CRGB (0x55, 0x55, 0xff),                     \
      CRGB (0x55, 0xff, 0x55),                     \
      CRGB (0x55, 0xff, 0xff),                     \
      CRGB (0xff, 0x55, 0x55),                     \
      CRGB (0xff, 0x55, 0xff),                     \
      CRGB (0xff, 0xff, 0x55),                     \
      CRGB (0xff, 0xff, 0xff)                      \
  }

#define FINGERPAINTER_PALETTE_PASTEL (const cRGB[]) { \
      CRGB (0, 0, 0),                                 \
      CRGB (230, 119, 107),                           \
      CRGB (229, 154, 67),                            \
      CRGB (242, 228, 110),                           \
      CRGB (155, 243, 150),                           \
      CRGB (150, 221, 243),                           \
      CRGB (255, 255, 255),                           \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
      CRGB (0, 0, 0),                                 \
  }

#define FINGERPAINTER_PALETTE_SOLARIZED (const cRGB[]) { \
      CRGB (0, 0, 0),                                    \
      CRGB (181, 137, 0),                                \
      CRGB (203, 75, 22),                                \
      CRGB (220, 50, 47),                                \
      CRGB (211, 54, 130),                               \
      CRGB (108, 113, 196),                              \
      CRGB (38, 139, 210),                               \
      CRGB (42, 161, 152),                               \
      CRGB (133, 153, 0),                                \
      CRGB (238, 232, 213),                              \
      CRGB (0, 0, 0),                                    \
      CRGB (0, 0, 0),                                    \
      CRGB (0, 0, 0),                                    \
      CRGB (0, 0, 0),                                    \
      CRGB (0, 0, 0),                                    \
      CRGB (0, 0, 0),                                    \
  }
