/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b270c. */
int __cdecl -[EventDriver currentBrightness](EventDriver *self, SEL a2)
{
  int result; // eax

  if ( self->autoDimmed != 1 ) /*0x1b2719*/
    return self->curBright; /*0x1b2719*/
  result = self->dimmedBrightness; /*0x1b271b*/
  if ( self->curBright <= result ) /*0x1b2727*/
    return self->curBright; /*0x1b2729*/
  return result; /*0x1b2731*/
}
