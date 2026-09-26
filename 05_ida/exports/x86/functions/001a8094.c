/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8094. */
unsigned int __cdecl -[IODeviceDescription numMemoryRanges](IODeviceDescription *self, SEL a2)
{
  _DWORD *v2; // ebx
  id v3; // eax
  id v4; // eax

  v2 = self->_private; /*0x1a809c*/
  if ( !v2[3] ) /*0x1a809f*/
  {
    v3 = -[IODeviceDescription _delegate](self, sel__delegate); /*0x1a80bd*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1a80c6*/
    v2[2] = -[IODeviceDescription _fetchRangeList:returnedNum:](self, sel__fetchRangeList_returnedNum_, v4); /*0x1a80dc*/
  }
  return v2[3]; /*0x1a80e5*/
}
