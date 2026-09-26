/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aca48. */
void __cdecl -[SCSIDisk setLastReadyState:](SCSIDisk *self, SEL a2, int a3)
{
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  if ( self->_ejectPending && a3 != 3 ) /*0x1aca60*/
    self->_ejectPending = 0; /*0x1aca62*/
  v3.receiver = self; /*0x1aca71*/
  v3.super_class = (Class)stru_1FA384.super_class; /*0x1aca7a*/
  -[IODisk setLastReadyState:](&v3, sel_setLastReadyState_, a3); /*0x1aca81*/
}
