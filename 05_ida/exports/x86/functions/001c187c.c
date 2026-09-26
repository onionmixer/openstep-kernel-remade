/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c187c. */
int __cdecl -[IODirectDevice getPCIConfigSpace:](IODirectDevice *self, SEL a2, $753F089B692BDCBCFC42C16D2A86E59C *a3)
{
  id v3; // eax

  -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c188f*/
  v3 = -[Object class](self, sel_class); /*0x1c18a5*/
  return (int)objc_msgSend(v3, sel_getPCIConfigSpace_withDeviceDescription_); /*0x1c18b6*/
}
