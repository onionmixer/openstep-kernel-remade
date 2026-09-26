/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae9e4. */
int __cdecl -[SCSIGeneric release:](SCSIGeneric *self, SEL a2, id a3)
{
  const char *v3; // eax

  objc_msgSend(self->_openLock, sel_lock); /*0x1ae9fd*/
  if ( self->_owner == a3 )
  {
    -[SCSIGeneric clearReservation](self, sel_clearReservation); /*0x1aea34*/
    self->_owner = nullptr; /*0x1aea39*/
  }
  else
  {
    v3 = -[IODevice name](self, sel_name); /*0x1aea15*/
    IOLog((int)"%s: bogus close call\n", v3);
  }
  return (int)objc_msgSend(self->_openLock, sel_unlock); /*0x1aea5c*/
}
