/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108024. */
int __cdecl setregid(gid_t a1, gid_t a2)
{
  int *v2; // esi
  int v3; // ebx
  int v4; // eax
  int result; // eax
  int v6; // esi
  int v7; // eax
  __int16 v8; // ax

  v2 = *(int **)(dword_1E875C + 36); /*0x10802e*/
  if ( *v2 == -1 ) /*0x108036*/
    LOWORD(v3) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 8); /*0x108040*/
  else
    v3 = *v2; /*0x108048*/
  v4 = *(_DWORD *)(active_u + 28); /*0x10804f*/
  if ( *(_WORD *)(v4 + 8) == (_WORD)v3 || *(_WORD *)(v4 + 4) == (_WORD)v3 || (result = suser()) != 0 ) /*0x108065*/
  {
    if ( v2[1] == -1 ) /*0x108071*/
      LOWORD(v6) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 4); /*0x10807b*/
    else
      v6 = v2[1]; /*0x108084*/
    v7 = *(_DWORD *)(active_u + 28); /*0x10808b*/
    if ( *(_WORD *)(v7 + 8) == (_WORD)v6 || *(_WORD *)(v7 + 4) == (_WORD)v6 || (result = suser()) != 0 ) /*0x1080a1*/
    {
      lock_write(active_u + 32); /*0x1080ac*/
      *(_DWORD *)(active_u + 28) = crcopy(*(_DWORD *)(active_u + 28)); /*0x1080c6*/
      v8 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 8); /*0x1080d1*/
      if ( v8 != (_WORD)v3 ) /*0x1080db*/
      {
        leavegroup(v8); /*0x1080df*/
        entergroup(v3); /*0x1080e8*/
        *(_WORD *)(*(_DWORD *)(active_u + 28) + 8) = v3; /*0x1080f5*/
      }
      *(_WORD *)(*(_DWORD *)(active_u + 28) + 4) = v6; /*0x108104*/
      return lock_done(active_u + 32); /*0x108111*/
    }
  }
  return result; /*0x108119*/
}
