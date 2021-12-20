/**
 * @file DipSwitch.h
 * @author Francisco Armenta L. (sistron@sistron.com)
 * @brief Dip switch class using template for any array length.
 * @version 0.1.0
 * @date 2021-12-17
 *
 * @copyright Copyright (c) 2021 SITRN SISTEMAS ELECTRONICOS
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#ifndef DIPSWITCH_H_INCLUDED
#define DIPSWITCH_H_INCLUDED

#include <Arduino.h>

template <size_t nPins>
class DipSwitch
{
private:
    uint8_t pinArray[nPins];

public:
    /**
     * @brief Setup dipSwitch inputs 
     * 
     * @param pinsArray pin address array
     */
    void setup(uint8_t *pinsArray)
    {
        for (size_t i = 0; i < nPins; i++)
        {
            pinArray[i] = pinsArray[i];
            pinMode(pinArray[i], INPUT_PULLUP);
        }
    }

    /**
     * @brief Get BCD address from dip switch positions
     * 
     * @return uint16_t BCD address
     */
    uint16_t getBcd()
    {
        uint16_t bcd = 1;

        for (size_t i = 0; i < nPins; i++)
        {
            bcd += (digitalRead(pinArray[i]) << i);
        }
        return bcd;
    }
};

#endif
// End of File