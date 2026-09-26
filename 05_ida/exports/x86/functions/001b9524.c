/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9524. */
void __cdecl -[AudioStream setDataEncoding:](AudioStream *self, SEL a2, int a3)
{
  switch ( a3 )
  {
    case 600:
      self->dataFormat = 0; /*0x1b9554*/
      break; /*0x1b955e*/
    case 601:
      self->dataFormat = 3; /*0x1b9560*/
      break; /*0x1b956a*/
    case 602:
      self->dataFormat = 1; /*0x1b956c*/
      break; /*0x1b9576*/
    case 603:
      self->dataFormat = 2; /*0x1b9578*/
      break; /*0x1b9582*/
    case 604:
      self->dataFormat = 4; /*0x1b9584*/
      break; /*0x1b958e*/
    default:
      IOLog((int)"Audio: supported encoding: %d\n", a3);
      break; /*0x1b9596*/
  }
}
