/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b37ec. */
IOEventSource *__cdecl -[IOEventSource init](IOEventSource *self, SEL a2)
{
  NXLock *ownerLock; // eax
  objc_super v4; // [esp+4h] [ebp-8h] BYREF

  v4.receiver = self; /*0x1b37fd*/
  v4.super_class = (Class)stru_1FA424.super_class; /*0x1b3806*/
  -[IODevice init](&v4, sel_init); /*0x1b380d*/
  self->_owner = nullptr; /*0x1b3812*/
  self->_desiredOwner = nullptr; /*0x1b381c*/
  ownerLock = self->_ownerLock; /*0x1b3829*/
  if ( ownerLock ) /*0x1b3831*/
    -[NXLock free](ownerLock, sel_free); /*0x1b383b*/
  self->_ownerLock = +[Object new](aNxlock, sel_new); /*0x1b3856*/
  return self; /*0x1b385e*/
}
