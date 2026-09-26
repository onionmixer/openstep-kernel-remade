/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3524. */
int __cdecl EvGetParameterChar(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  id v6; // edx
  int result; // eax
  int v8; // [esp+4h] [ebp-4h] BYREF

  v8 = a4; /*0x1b3531*/
  *a6 = a4; /*0x1b3534*/
  v6 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b3549*/
  if ( !v6 ) /*0x1b3550*/
    return -729; /*0x1b3552*/
  result = (int)objc_msgSend(v6, sel_getCharValues_forParameter_count_, a5, a3, &v8); /*0x1b3570*/
  if ( !result ) /*0x1b3577*/
    *a6 = v8; /*0x1b357c*/
  return result; /*0x1b357e*/
}
