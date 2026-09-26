/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11dd98. */
_DWORD *vhangup()
{
  _DWORD *result; // eax
  _DWORD *v1[38]; // [esp-90h] [ebp-98h] BYREF

  result = (_DWORD *)suser(); /*0x11dd9d*/
  if ( result ) /*0x11dda4*/
  {
    result = (_DWORD *)active_u; /*0x11dda6*/
    if ( *(_DWORD *)(active_u + 360) ) /*0x11ddab*/
    {
      forceclose(*(_WORD *)(active_u + 364)); /*0x11ddbc*/
      v1[34] = (_DWORD *)1; /*0x11ddc1*/
      qmemcpy(v1, *(const void **)(active_u + 360), 0x88u); /*0x11dddc*/
      return gsignal(v1[0], (char *)v1[1]); /*0x11ddde*/
    }
  }
  return result; /*0x11dde6*/
}
