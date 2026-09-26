/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1af064. */
int __cdecl -[IODisplay devicePort](IODisplay *self, SEL a2)
{
  id v2; // eax

  v2 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1af079*/
  return (int)objc_msgSend(v2, sel_devicePort); /*0x1af089*/
}
