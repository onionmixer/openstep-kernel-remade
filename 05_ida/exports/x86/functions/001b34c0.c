/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b34c0. */
int __cdecl EvGetParameterInt(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  id v6; // edx
  int result; // eax
  int v8; // [esp+4h] [ebp-4h] BYREF

  v8 = a4; /*0x1b34cd*/
  *a6 = a4; /*0x1b34d0*/
  v6 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b34e5*/
  if ( !v6 ) /*0x1b34ec*/
    return -729; /*0x1b34ee*/
  result = (int)objc_msgSend(v6, sel_getIntValues_forParameter_count_, a5, a3, &v8); /*0x1b350c*/
  if ( !result ) /*0x1b3513*/
    *a6 = v8; /*0x1b3518*/
  return result; /*0x1b351a*/
}
