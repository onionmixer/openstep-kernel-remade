/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151910. */
_DWORD *__cdecl ipc_splay_traverse_finish(_DWORD *a1)
{
  _DWORD *result; // eax
  int v2; // edx

  result = a1; /*0x151913*/
  v2 = a1[1]; /*0x151916*/
  if ( v2 ) /*0x15191b*/
  {
    *a1 = *(_DWORD *)(v2 + 16); /*0x151920*/
    a1[3] = a1 + 2; /*0x151925*/
    a1[5] = a1 + 4; /*0x15192b*/
  }
  return result; /*0x151930*/
}
