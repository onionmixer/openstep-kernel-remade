/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1470. */
$85CD2974BE96D4886BB301820D1C36C2 *__cdecl -[IOEISADeviceDescription portRangeList](
        IOEISADeviceDescription *self,
        SEL a2)
{
  void *eisa_private; // ebx
  id v3; // eax
  id v4; // eax

  eisa_private = self->_eisa_private; /*0x1c1478*/
  if ( !*((_DWORD *)eisa_private + 3) ) /*0x1c147b*/
  {
    v3 = -[IOEISADeviceDescription _delegate](self, sel__delegate); /*0x1c1499*/
    v4 = objc_msgSend(v3, sel_resourcesForKey_); /*0x1c14a2*/
    *((_DWORD *)eisa_private + 2) = -[IOEISADeviceDescription _fetchRangeList:returnedNum:]( /*0x1c14b8*/
                                      self,
                                      sel__fetchRangeList_returnedNum_,
                                      v4);
  }
  return *(($85CD2974BE96D4886BB301820D1C36C2 **)eisa_private + 2); /*0x1c14c1*/
}
