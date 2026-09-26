/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1670. */
int __cdecl -[IOEISADeviceDescription getEISASlotID:](IOEISADeviceDescription *self, SEL a2, unsigned int *a3)
{
  void *eisa_private; // eax

  eisa_private = self->_eisa_private; /*0x1c1679*/
  if ( !*((_BYTE *)eisa_private + 16) ) /*0x1c167c*/
    return -704; /*0x1c1694*/
  if ( a3 ) /*0x1c1684*/
    *a3 = *((_DWORD *)eisa_private + 6); /*0x1c1689*/
  return 0; /*0x1c168f*/
}
