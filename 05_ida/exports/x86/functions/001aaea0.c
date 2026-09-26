/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aaea0. */
_DWORD *__cdecl sub_1AAEA0(_DWORD *a1)
{
  _DWORD *result; // eax
  id v2; // eax
  _DWORD v3[6]; // [esp+8h] [ebp-18h] BYREF

  result = a1; /*0x1aaea8*/
  qmemcpy(v3, &unk_1D5D78, sizeof(v3)); /*0x1aaeb9*/
  if ( a1[86] || a1[87] ) /*0x1aaec4*/
  {
    a1[86] = 0; /*0x1aaecd*/
    a1[87] = 0; /*0x1aaed7*/
    v3[1] = 24; /*0x1aaee1*/
    v2 = objc_msgSend(a1, sel_interruptPort); /*0x1aaef0*/
    v3[4] = IOGetKernPort((int)v2); /*0x1aaefb*/
    v3[5] = 2302755; /*0x1aaefe*/
    return (_DWORD *)msg_send_from_kernel(v3, 0, 0); /*0x1aaf0d*/
  }
  return result; /*0x1aaf15*/
}
