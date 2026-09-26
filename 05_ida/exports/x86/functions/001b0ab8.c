/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0ab8. */
char __cdecl +[EventDriver probe:](id a1, SEL a2, id a3)
{
  _DWORD *v3; // eax

  if ( dword_1E532C ) /*0x1b0ac2*/
    return 1; /*0x1b0b4c*/
  v3 = objc_msgSend(a1, sel_alloc); /*0x1b0ad3*/
  dword_1E532C = v3; /*0x1b0ad8*/
  v3[67] = 0; /*0x1b0add*/
  objc_msgSend(v3, sel_setUnit_, 0); /*0x1b0af1*/
  objc_msgSend(dword_1E532C, sel_setName_, "event0"); /*0x1b0b09*/
  objc_msgSend(dword_1E532C, sel_setDeviceKind_, "event"); /*0x1b0b24*/
  return objc_msgSend(dword_1E532C, sel_init) != nullptr; /*0x1b0b48*/
}
