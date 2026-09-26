/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x158420. */
int __cdecl ipc_kobject_notify(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax

  v2 = *(_DWORD *)(a1 + 8); /*0x158429*/
  *(_DWORD *)(a2 + 28) = -305; /*0x15842c*/
  v3 = *(_DWORD *)(a1 + 20); /*0x158433*/
  if ( v3 < 65 || v3 > 66 && (v3 > 72 || v3 < 69) ) /*0x158448*/
    return 0; /*0x15844a*/
  if ( *(_WORD *)(v2 + 8) == 12 ) /*0x158455*/
    return ds_notify(a1); /*0x158458*/
  return 0; /*0x15844e*/
}
