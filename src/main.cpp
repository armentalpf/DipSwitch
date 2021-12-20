/**
 * @file main.cpp
 * @author Francisco Armenta L. (sistron@sistron.com)
 * @brief DipSwitch class template example
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
#include <Arduino.h>
#include <DipSwitch.h>

uint8_t dipSwitchPins[] = {23, 24, 25, 26, 27, 28};
DipSwitch<sizeof(dipSwitchPins)> idSwitch;

void setup()
{
  Serial.begin(9600);
  delay(1000);

  idSwitch.setup(dipSwitchPins);

  Serial.print("id Address: ");
  Serial.println(idSwitch.getBcd());
}

void loop()
{
  // put your main code here, to run repeatedly:
}