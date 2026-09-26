/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c14c8. */
unsigned int __cdecl -[IOEISADeviceDescription numPortRanges](IOEISADeviceDescription *self, SEL a2)
{
  _DWORD *eisa_private; // ebx
  id v3; // eax
  id v4; // eax

  eisa_private = self->_eisa_private; /*0x1c14d0*/
  if ( !eisa_private[3] ) /*0x1c14d3*/
  {
    v3 = -[IOEISADeviceDescription _delegate](self, sel__delegate); /*0x1c14f1*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1c14fa*/
    eisa_private[2] = -[IOEISADeviceDescription _fetchRangeList:returnedNum:]( /*0x1c1510*/
                        self,
                        sel__fetchRangeList_returnedNum_,
                        v4);
  }
  return eisa_private[3]; /*0x1c1519*/
}
