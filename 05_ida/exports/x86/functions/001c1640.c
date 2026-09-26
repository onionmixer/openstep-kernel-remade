/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1640. */
int __cdecl -[IOEISADeviceDescription getEISASlotNumber:](IOEISADeviceDescription *self, SEL a2, unsigned int *a3)
{
  void *eisa_private; // eax

  eisa_private = self->_eisa_private; /*0x1c1649*/
  if ( !*((_BYTE *)eisa_private + 16) ) /*0x1c164c*/
    return -704; /*0x1c1664*/
  if ( a3 ) /*0x1c1654*/
    *a3 = *((_DWORD *)eisa_private + 5); /*0x1c1659*/
  return 0; /*0x1c165f*/
}
