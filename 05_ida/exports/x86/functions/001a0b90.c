/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0b90. */
char __cdecl +[PCPointer probe:](id a1, SEL a2, id a3)
{
  id v3; // eax
  _DWORD *v4; // esi
  int v6; // [esp-4h] [ebp-Ch]

  v3 = objc_msgSend(a1, sel_alloc); /*0x1a0bab*/
  v4 = objc_msgSend(v3, sel_initFromDeviceDescription_); /*0x1a0bb9*/
  v4[74] = 0; /*0x1a0bbb*/
  if ( (unsigned __int8)objc_msgSend(v4, sel_mouseInit_, a3) ) /*0x1a0bce*/
  {
    v6 = dword_1E8660++; /*0x1a0bfe*/
    objc_msgSend(v4, sel_setUnit_, v6); /*0x1a0c0d*/
    objc_msgSend(v4, sel_registerDevice); /*0x1a0c1a*/
    dword_1E8664 = (int)v4; /*0x1a0c1f*/
    return 1; /*0x1a0c25*/
  }
  else
  {
    IOLog(aPcpointerProbe); /*0x1a0bdf*/
    objc_msgSend(v4, sel_free); /*0x1a0bec*/
    return 0; /*0x1a0bf1*/
  }
}
