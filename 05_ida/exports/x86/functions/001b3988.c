/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3988. */
int __cdecl -[IOEventSource relinquishOwnership:](IOEventSource *self, SEL a2, id a3)
{
  int v3; // esi
  id desiredOwner; // eax
  const char *v5; // eax

  -[NXLock lock](self->_ownerLock, sel_lock); /*0x1b39a2*/
  if ( self->_owner == a3 ) /*0x1b39b0*/
  {
    v3 = 0; /*0x1b39b2*/
    self->_owner = nullptr; /*0x1b39b4*/
  }
  else
  {
    v3 = -725; /*0x1b39c0*/
  }
  -[NXLock unlock](self->_ownerLock, sel_unlock); /*0x1b39d3*/
  if ( !v3 )
  {
    desiredOwner = self->_desiredOwner; /*0x1b39df*/
    if ( desiredOwner )
    {
      if ( desiredOwner != a3 )
      {
        if ( (unsigned __int8)objc_msgSend(desiredOwner, sel_respondsTo_, sel_canBecomeOwner_) )
        {
          objc_msgSend(self->_desiredOwner, sel_canBecomeOwner_, self); /*0x1b3a17*/
        }
        else
        {
          v5 = -[IODevice name](self, sel_name); /*0x1b3a28*/
          IOLog((int)"%s: desiredOwner does not respond to canBecomeOwner:\n", v5);
        }
      }
    }
  }
  return v3; /*0x1b3a3d*/
}
