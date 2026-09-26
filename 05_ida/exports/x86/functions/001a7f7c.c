/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7f7c. */
unsigned int __cdecl -[IODeviceDescription numInterrupts](IODeviceDescription *self, SEL a2)
{
  _DWORD *v2; // ebx
  id v3; // eax
  id v4; // eax

  v2 = self->_private; /*0x1a7f84*/
  if ( !v2[1] ) /*0x1a7f87*/
  {
    v3 = -[IODeviceDescription _delegate](self, sel__delegate); /*0x1a7fa5*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1a7fae*/
    *v2 = -[IODeviceDescription _fetchItemList:returnedNum:](self, sel__fetchItemList_returnedNum_, v4); /*0x1a7fc4*/
  }
  return v2[1]; /*0x1a7fcc*/
}
