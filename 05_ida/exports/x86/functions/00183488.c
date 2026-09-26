/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x183488. */
int __cdecl sdopen(unsigned __int16 a1, char a2)
{
  void *v2; // ebx
  id v4; // [esp+Ch] [ebp-4h] BYREF

  v2 = (void *)sub_1840EC(a1); /*0x1834a1*/
  if ( !v2 || objc_msgSend(v2, sel_isDiskReady_, (a2 & 4) == 0) ) /*0x1834c2*/
    return 6; /*0x1834ce*/
  if ( !dword_1E756C ) /*0x1834df*/
  {
    if ( IOGetObjectForDeviceName(aSc0, (int)&v4) ) /*0x1834ea*/
      IOPanic(aSdopenCanTFind); /*0x1834fb*/
    dword_1E756C = (int)objc_msgSend(v4, sel_maxTransfer); /*0x183513*/
  }
  if ( (a1 & 7) != 7 ) /*0x183525*/
  {
    if ( dword_1E7564 == HIBYTE(a1) ) /*0x183534*/
      objc_msgSend(v2, sel_setBlockDeviceOpen_, 1); /*0x18353e*/
    else
      objc_msgSend(v2, sel_setRawDeviceOpen_, 1); /*0x18354a*/
  }
  return 0; /*0x183554*/
}
