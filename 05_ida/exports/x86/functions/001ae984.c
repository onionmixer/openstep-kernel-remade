/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae984. */
int __cdecl -[SCSIGeneric acquire:](SCSIGeneric *self, SEL a2, id a3)
{
  int v3; // ebx

  objc_msgSend(self->_openLock, sel_lock); /*0x1ae99a*/
  if ( self->_owner ) /*0x1ae9a2*/
  {
    v3 = 1; /*0x1ae9ab*/
  }
  else
  {
    *((_BYTE *)self + 284) &= ~1u; /*0x1ae9b4*/
    self->_owner = a3; /*0x1ae9be*/
    v3 = 0; /*0x1ae9c4*/
  }
  objc_msgSend(self->_openLock, sel_unlock); /*0x1ae9d4*/
  return v3; /*0x1ae9de*/
}
