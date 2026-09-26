/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0c34. */
int __cdecl -[PCPointer getIntValues:forParameter:count:](
        PCPointer *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  unsigned int resolution; // edx

  if ( !strcmp(a4, aResolution_1) ) /*0x1a0c52*/
  {
    resolution = self->resolution; /*0x1a0c56*/
  }
  else
  {
    if ( strcmp(a4, aInverted_0) ) /*0x1a0c6f*/
      return -711; /*0x1a0c78*/
    resolution = self->inverted; /*0x1a0c7c*/
  }
  *a3 = resolution; /*0x1a0c83*/
  return 0; /*0x1a0c8a*/
}
