/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7c70. */
int __cdecl sub_1A7C70(id a1, __int16 a2, __int16 a3)
{
  int v3; // esi
  id v4; // eax
  int v5; // eax
  int v6; // ebx
  char *v7; // eax
  int v9; // [esp+Ch] [ebp-Ch]

  v9 = IOMalloc(7260); /*0x1a7c96*/
  v3 = (unsigned __int8)objc_msgSend(a1, sel_isRemovable) != 0; /*0x1a7caf*/
  v4 = objc_msgSend(a1, sel_nextLogicalDisk); /*0x1a7cb8*/
  if ( v4 )
  {
    v5 = (int)objc_msgSend(v4, sel_readLabel_, v9); /*0x1a7cd0*/
  }
  else
  {
    IOLog("volCheck: physDev with no logicalDisk!!\n");
    v5 = -1100; /*0x1a7ce6*/
  }
  if ( v5 ) /*0x1a7cf0*/
  {
    v6 = 2; /*0x1a7d08*/
    if ( (unsigned __int8)objc_msgSend(a1, sel_isFormatted) ) /*0x1a7d00*/
      v6 = 1; /*0x1a7d11*/
  }
  else
  {
    v6 = 0; /*0x1a7cf2*/
  }
  if ( (unsigned __int8)objc_msgSend(a1, sel_isWriteProtected) ) /*0x1a7d1e*/
    v3 |= 2u; /*0x1a7d2a*/
  v7 = (char *)objc_msgSend(a1, sel_name); /*0x1a7d36*/
  vol_notify_dev(a2, a3, "", v6, v7, v3); /*0x1a7d4f*/
  return IOFree(v9, 7260); /*0x1a7d65*/
}
