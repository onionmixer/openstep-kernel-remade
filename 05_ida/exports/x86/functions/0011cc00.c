/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cc00. */
int __cdecl chroot(const char *a1)
{
  _DWORD *v1; // ebx
  int result; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  v1 = *(_DWORD **)(dword_1E875C + 36); /*0x11cc0c*/
  result = suser(); /*0x11cc0f*/
  if ( result ) /*0x11cc16*/
  {
    *(_BYTE *)(dword_1E875C + 104) = chdirec(*v1, &v3); /*0x11cc2b*/
    result = dword_1E875C; /*0x11cc2e*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11cc36*/
    {
      if ( *(_DWORD *)(active_u + 356) ) /*0x11cc41*/
        vn_rele(*(_DWORD *)(active_u + 356)); /*0x11cc4c*/
      result = active_u; /*0x11cc51*/
      *(_DWORD *)(active_u + 356) = v3; /*0x11cc59*/
    }
  }
  return result; /*0x11cc5f*/
}
