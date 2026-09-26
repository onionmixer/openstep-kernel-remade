/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1588. */
int __cdecl -[IOEISADeviceDescription setPortRangeList:num:](
        IOEISADeviceDescription *self,
        SEL a2,
        $85CD2974BE96D4886BB301820D1C36C2 *a3,
        unsigned int a4)
{
  int v4; // esi
  unsigned int i; // eax
  id v6; // eax
  _DWORD *eisa_private; // ebx
  int v8; // eax
  int v10; // [esp+Ch] [ebp-4h]

  v10 = -702; /*0x1c1597*/
  v4 = IOMalloc(8 * a4); /*0x1c15ab*/
  for ( i = 0; i < a4; ++i ) /*0x1c15b4*/
    *($85CD2974BE96D4886BB301820D1C36C2 *)(v4 + 8 * i) = a3[i]; /*0x1c15bb*/
  v6 = -[IOEISADeviceDescription _delegate](self, sel__delegate); /*0x1c15e4*/
  if ( objc_msgSend(v6, sel_allocateRanges_numRanges_forKey_) ) /*0x1c15ed*/
  {
    eisa_private = self->_eisa_private; /*0x1c15fc*/
    v8 = eisa_private[3]; /*0x1c15ff*/
    if ( v8 ) /*0x1c1604*/
      IOFree(eisa_private[2], 8 * v8); /*0x1c160e*/
    eisa_private[3] = 0; /*0x1c1616*/
    v10 = 0; /*0x1c161d*/
  }
  IOFree(v4, 8 * a4); /*0x1c162d*/
  return v10; /*0x1c1638*/
}
