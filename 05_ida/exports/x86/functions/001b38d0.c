/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b38d0. */
int __cdecl -[IOEventSource becomeOwner:](IOEventSource *self, SEL a2, id a3)
{
  id owner; // eax
  int v4; // ebx
  const char *v5; // eax

  -[NXLock lock](self->_ownerLock, sel_lock); /*0x1b38ea*/
  owner = self->_owner; /*0x1b38f2*/
  if ( owner )
  {
    if ( (unsigned __int8)objc_msgSend(owner, sel_respondsTo_, sel_relinquishOwnership_) )
    {
      v4 = (int)objc_msgSend(self->_owner, sel_relinquishOwnership_, self); /*0x1b392b*/
    }
    else
    {
      v5 = -[IODevice name](self, sel_name); /*0x1b393c*/
      IOLog((int)"%s: owner does not respond to relinquishOwnership:\n", v5);
      v4 = -725; /*0x1b394c*/
    }
    if ( !v4 ) /*0x1b3956*/
      self->_owner = a3; /*0x1b3958*/
  }
  else
  {
    self->_owner = a3; /*0x1b3960*/
    v4 = 0; /*0x1b3966*/
  }
  -[NXLock unlock](self->_ownerLock, sel_unlock); /*0x1b3976*/
  return v4; /*0x1b3980*/
}
