/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1418. */
unsigned int __cdecl -[IOEISADeviceDescription numChannels](IOEISADeviceDescription *self, SEL a2)
{
  _DWORD *eisa_private; // ebx
  id v3; // eax
  id v4; // eax

  eisa_private = self->_eisa_private; /*0x1c1420*/
  if ( !eisa_private[1] ) /*0x1c1423*/
  {
    v3 = -[IOEISADeviceDescription _delegate](self, sel__delegate); /*0x1c1441*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1c144a*/
    *eisa_private = -[IOEISADeviceDescription _fetchItemList:returnedNum:](self, sel__fetchItemList_returnedNum_, v4); /*0x1c1460*/
  }
  return eisa_private[1]; /*0x1c1468*/
}
