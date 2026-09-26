/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3868. */
id __cdecl -[IOEventSource free](IOEventSource *self, SEL a2)
{
  NXLock *ownerLock; // eax
  objc_super v4; // [esp+4h] [ebp-8h] BYREF

  ownerLock = self->_ownerLock; /*0x1b3872*/
  if ( ownerLock ) /*0x1b387a*/
    -[NXLock free](ownerLock, sel_free); /*0x1b3884*/
  v4.receiver = self; /*0x1b3893*/
  v4.super_class = (Class)stru_1FA424.super_class; /*0x1b389c*/
  return -[IODevice free](&v4, sel_free); /*0x1b38a8*/
}
