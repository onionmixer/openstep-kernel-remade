/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3a44. */
int __cdecl -[IOEventSource desireOwnership:](IOEventSource *self, SEL a2, id a3)
{
  id desiredOwner; // eax
  int v4; // ebx

  -[NXLock lock](self->_ownerLock, sel_lock); /*0x1b3a5d*/
  desiredOwner = self->_desiredOwner; /*0x1b3a65*/
  if ( !desiredOwner || desiredOwner == a3 ) /*0x1b3a71*/
  {
    self->_desiredOwner = a3; /*0x1b3a7c*/
    v4 = 0; /*0x1b3a82*/
  }
  else
  {
    v4 = -725; /*0x1b3a73*/
  }
  -[NXLock unlock](self->_ownerLock, sel_unlock); /*0x1b3a92*/
  return v4; /*0x1b3a9c*/
}
