/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a80ec. */
int __cdecl -[IODeviceDescription setMemoryRangeList:num:](
        IODeviceDescription *self,
        SEL a2,
        $85CD2974BE96D4886BB301820D1C36C2 *a3,
        unsigned int a4)
{
  int v4; // esi
  unsigned int i; // eax
  id v6; // eax
  _DWORD *v7; // ebx
  int v8; // eax
  int v10; // [esp+Ch] [ebp-4h]

  v10 = -702; /*0x1a80fb*/
  v4 = IOMalloc(8 * a4); /*0x1a810f*/
  for ( i = 0; i < a4; ++i ) /*0x1a8118*/
    *($85CD2974BE96D4886BB301820D1C36C2 *)(v4 + 8 * i) = a3[i]; /*0x1a811f*/
  v6 = -[IODeviceDescription _delegate](self, sel__delegate); /*0x1a8148*/
  if ( objc_msgSend(v6, sel_allocateRanges_numRanges_forKey_) ) /*0x1a8151*/
  {
    v7 = self->_private; /*0x1a8160*/
    v8 = v7[3]; /*0x1a8163*/
    if ( v8 ) /*0x1a8168*/
      IOFree(v7[2], 8 * v8); /*0x1a8172*/
    v7[3] = 0; /*0x1a817a*/
    v10 = 0; /*0x1a8181*/
  }
  IOFree(v4, 8 * a4); /*0x1a8191*/
  return v10; /*0x1a819c*/
}
