/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c13c0. */
unsigned int *__cdecl -[IOEISADeviceDescription channelList](IOEISADeviceDescription *self, SEL a2)
{
  unsigned int **eisa_private; // ebx
  id v3; // eax
  id v4; // eax

  eisa_private = (unsigned int **)self->_eisa_private; /*0x1c13c8*/
  if ( !eisa_private[1] ) /*0x1c13cb*/
  {
    v3 = -[IOEISADeviceDescription _delegate](self, sel__delegate); /*0x1c13e9*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1c13f2*/
    *eisa_private = (unsigned int *)-[IOEISADeviceDescription _fetchItemList:returnedNum:]( /*0x1c1408*/
                                      self,
                                      sel__fetchItemList_returnedNum_,
                                      v4);
  }
  return *eisa_private; /*0x1c140f*/
}
