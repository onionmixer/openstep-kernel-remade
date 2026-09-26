/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7f24. */
unsigned int *__cdecl -[IODeviceDescription interruptList](IODeviceDescription *self, SEL a2)
{
  unsigned int **v2; // ebx
  id v3; // eax
  id v4; // eax

  v2 = (unsigned int **)self->_private; /*0x1a7f2c*/
  if ( !v2[1] ) /*0x1a7f2f*/
  {
    v3 = -[IODeviceDescription _delegate](self, sel__delegate); /*0x1a7f4d*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1a7f56*/
    *v2 = (unsigned int *)-[IODeviceDescription _fetchItemList:returnedNum:](self, sel__fetchItemList_returnedNum_, v4); /*0x1a7f6c*/
  }
  return *v2; /*0x1a7f73*/
}
