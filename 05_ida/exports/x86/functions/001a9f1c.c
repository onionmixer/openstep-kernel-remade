/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9f1c. */
_DWORD *__cdecl sub_1A9F1C(_DWORD *a1)
{
  _DWORD *result; // eax
  id v2; // eax
  _DWORD v3[6]; // [esp+8h] [ebp-18h] BYREF

  result = a1; /*0x1a9f24*/
  qmemcpy(v3, &unk_1D5CB4, sizeof(v3)); /*0x1a9f35*/
  if ( a1[76] || a1[77] ) /*0x1a9f40*/
  {
    a1[76] = 0; /*0x1a9f49*/
    a1[77] = 0; /*0x1a9f53*/
    v3[1] = 24; /*0x1a9f5d*/
    v2 = objc_msgSend(a1, sel_interruptPort); /*0x1a9f6c*/
    v3[4] = IOGetKernPort((int)v2); /*0x1a9f77*/
    v3[5] = 2302755; /*0x1a9f7a*/
    return (_DWORD *)msg_send_from_kernel(v3, 0, 0); /*0x1a9f89*/
  }
  return result; /*0x1a9f91*/
}
