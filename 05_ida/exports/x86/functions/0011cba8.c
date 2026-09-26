/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cba8. */
int __cdecl chdir(const char *a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-4h] BYREF

  *(_BYTE *)(dword_1E875C + 104) = chdirec(**(_DWORD **)(dword_1E875C + 36), &v2); /*0x11cbc9*/
  result = dword_1E875C; /*0x11cbcc*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11cbd4*/
  {
    vn_rele(*(_DWORD *)(active_u + 352)); /*0x11cbe6*/
    result = active_u; /*0x11cbeb*/
    *(_DWORD *)(active_u + 352) = v2; /*0x11cbf3*/
  }
  return result; /*0x11cbf9*/
}
