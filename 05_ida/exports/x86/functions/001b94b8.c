/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b94b8. */
int __cdecl -[AudioStream dataEncoding](AudioStream *self, SEL a2)
{
  int dataFormat; // eax

  dataFormat = self->dataFormat; /*0x1b94be*/
  if ( dataFormat == 1 ) /*0x1b94c4*/
    return 602; /*0x1b94fc*/
  if ( dataFormat > 1 ) /*0x1b94c6*/
  {
    if ( dataFormat == 2 ) /*0x1b94d3*/
      return 603; /*0x1b9508*/
    if ( dataFormat == 3 ) /*0x1b94d8*/
      return 601; /*0x1b94f0*/
  }
  else if ( !dataFormat ) /*0x1b94ca*/
  {
    return 600; /*0x1b94e4*/
  }
  IOLog((int)"Audio: unrecognized data format: %d\n", self->dataFormat);
  return -1; /*0x1b94e3*/
}
