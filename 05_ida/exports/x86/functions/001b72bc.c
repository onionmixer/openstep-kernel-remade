/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b72bc. */
int __cdecl -[IOAudio dataEncoding](IOAudio *self, SEL a2)
{
  int result; // eax

  result = self->_dataEncoding; /*0x1b72c2*/
  switch ( result ) /*0x1b72cb*/
  {
    case 1: /*0x1b72cb*/
      return 602; /*0x1b72f8*/
    case 0: /*0x1b72cb*/
      return 600; /*0x1b72e0*/
    case 2: /*0x1b72cb*/
      return 603; /*0x1b7304*/
    case 3: /*0x1b72cb*/
      return 601; /*0x1b72ec*/
  }
  return result; /*0x1b72db*/
}
