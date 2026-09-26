/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4d54. */
id __cdecl -[IOFrameBufferDisplay setBrightness:token:](IOFrameBufferDisplay *self, SEL a2, int a3, int a4)
{
  const char *v4; // eax

  if ( (unsigned int)a3 > 0x40 )
  {
    v4 = -[IODevice name](self, sel_name); /*0x1c4d6c*/
    IOLog((int)"%s: Invalid arg to setBrightness:%d\n", v4, a3);
  }
  return self; /*0x1c4d81*/
}
