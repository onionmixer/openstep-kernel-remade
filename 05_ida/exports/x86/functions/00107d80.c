/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107d80. */
int __cdecl setreuid(uid_t a1, uid_t a2)
{
  int *v2; // ebx
  int v3; // esi
  int v4; // eax
  int result; // eax
  int v6; // ebx
  int v7; // eax

  v2 = *(int **)(dword_1E875C + 36); /*0x107d8a*/
  if ( *v2 == -1 ) /*0x107d92*/
    LOWORD(v3) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 6); /*0x107d9c*/
  else
    v3 = *v2; /*0x107da4*/
  v4 = *(_DWORD *)(active_u + 28); /*0x107dab*/
  if ( *(_WORD *)(v4 + 6) == (_WORD)v3 || *(_WORD *)(v4 + 2) == (_WORD)v3 || (result = suser()) != 0 ) /*0x107dc1*/
  {
    if ( v2[1] == -1 ) /*0x107dcd*/
      LOWORD(v6) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x107dd7*/
    else
      v6 = v2[1]; /*0x107de0*/
    v7 = *(_DWORD *)(active_u + 28); /*0x107de7*/
    if ( *(_WORD *)(v7 + 6) == (_WORD)v6 || *(_WORD *)(v7 + 2) == (_WORD)v6 || (result = suser()) != 0 ) /*0x107dfd*/
    {
      lock_write(active_u + 32); /*0x107e08*/
      *(_DWORD *)(active_u + 28) = crcopy(*(_DWORD *)(active_u + 28)); /*0x107e22*/
      *(_WORD *)(*(_DWORD *)active_u + 44) = v6; /*0x107e2c*/
      *(_WORD *)(*(_DWORD *)(active_u + 28) + 6) = v3; /*0x107e38*/
      *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) = v6; /*0x107e44*/
      return lock_done(active_u + 32); /*0x107e51*/
    }
  }
  return result; /*0x107e59*/
}
