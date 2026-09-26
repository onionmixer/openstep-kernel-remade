/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c80bc. */
id __cdecl -[IOVPCodeDisplay setBrightness:token:](IOVPCodeDisplay *self, SEL a2, int a3, int a4)
{
  if ( (unsigned int)a3 <= 0x40 )
  {
    self->brightnessLevel = a3; /*0x1c80dc*/
    -[IOVPCodeDisplay setGammaTable](self, sel_setGammaTable); /*0x1c80ea*/
    return self; /*0x1c80ef*/
  }
  else
  {
    IOLog((int)"QVision: Invalid brightness level `%d'.\n", a3);
    return nullptr; /*0x1c80d6*/
  }
}
