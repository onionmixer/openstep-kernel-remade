/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18355c. */
int __cdecl sdclose(unsigned __int16 a1)
{
  void *v1; // esi

  v1 = (void *)sub_1840EC(a1); /*0x18356e*/
  if ( !v1 ) /*0x183575*/
    return 6; /*0x183575*/
  if ( (a1 & 7) != 7 ) /*0x183581*/
  {
    if ( !(unsigned __int8)objc_msgSend(v1, sel_isInstanceOpen) ) /*0x18358b*/
      return 6; /*0x18359c*/
    if ( dword_1E7564 == HIBYTE(a1) ) /*0x1835ad*/
      objc_msgSend(v1, sel_setBlockDeviceOpen_, 0); /*0x1835b7*/
    else
      objc_msgSend(v1, sel_setRawDeviceOpen_, 0); /*0x1835c6*/
  }
  return 0; /*0x1835d0*/
}
