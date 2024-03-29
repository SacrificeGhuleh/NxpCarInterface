//
// Created by Richard Zvonek on 08-Oct-18.
//

#ifndef NXPCUPRASPI_REGION_H
#define NXPCUPRASPI_REGION_H

#include "NxpDefines.h"

namespace nxpbc {
  struct Region {

    uint8_t left;
    uint8_t right;
    uint8_t color;

    Region(uint8_t left = minLeft, uint8_t right = maxRight, uint8_t color = COLOR_WHITE) {
      if (left < minLeft) {
        left = minLeft;
      }
      if (right > maxRight) {
        right = maxRight;
      }

      assert(left <= right);

      this->left = left;
      this->right = right;
      this->color = color;
    };

    uint8_t getSize() const {
      return right - left;
    }

    uint8_t getCenter() const {
      return static_cast<uint8_t>((right + left) / 2);
    }

    bool isBlack() {
      return color == COLOR_BLACK;
    }
    bool isWhite() {
      return color == COLOR_WHITE;
    }

    const static uint8_t minLeft = BLACK_COUNT;
    const static uint8_t maxRight = CAMERA_LINE_LENGTH - BLACK_COUNT - 1;
  };
}

#endif //NXPCUPRASPI_REGION_H
