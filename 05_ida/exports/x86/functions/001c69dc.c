/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c69dc. */
id __cdecl -[IOSVGADisplay setBrightness:token:](IOSVGADisplay *self, SEL a2, int a3, int a4)
{
  const char *v4; // eax

  if ( (unsigned int)a3 > 0x40 )
  {
    v4 = -[IODevice name](self, sel_name); /*0x1c69f4*/
    IOLog((int)"%s: Invalid arg to setBrightness:%d\n", v4, a3);
  }
  return self; /*0x1c6a09*/
}
