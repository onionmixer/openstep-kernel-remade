/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a803c. */
$85CD2974BE96D4886BB301820D1C36C2 *__cdecl -[IODeviceDescription memoryRangeList](IODeviceDescription *self, SEL a2)
{
  void *v2; // ebx
  id v3; // eax
  id v4; // eax

  v2 = self->_private; /*0x1a8044*/
  if ( !*((_DWORD *)v2 + 3) ) /*0x1a8047*/
  {
    v3 = -[IODeviceDescription _delegate](self, sel__delegate); /*0x1a8065*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1a806e*/
    *((_DWORD *)v2 + 2) = -[IODeviceDescription _fetchRangeList:returnedNum:]( /*0x1a8084*/
                            self,
                            sel__fetchRangeList_returnedNum_,
                            v4);
  }
  return *(($85CD2974BE96D4886BB301820D1C36C2 **)v2 + 2); /*0x1a808d*/
}
