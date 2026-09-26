/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146b54. */
int __cdecl ipc_hash_local_lookup(int a1, unsigned int a2, int *a3, _DWORD *a4)
{
  int v4; // esi
  unsigned int v5; // edi
  int v6; // ebx
  int v7; // ecx
  int v9; // [esp+Ch] [ebp-4h]

  v4 = *(_DWORD *)(a1 + 20); /*0x146b60*/
  v5 = *(_DWORD *)(a1 + 24); /*0x146b63*/
  v6 = (a2 >> 6) % v5; /*0x146b70*/
  while ( 1 ) /*0x146bb4*/
  {
    v9 = *(_DWORD *)(v4 + 16 * v6 + 12); /*0x146bb4*/
    if ( !v9 ) /*0x146bb9*/
      break; /*0x146bb9*/
    v7 = 16 * v9 + v4; /*0x146b7a*/
    if ( *(_DWORD *)(v7 + 4) == a2 ) /*0x146b83*/
    {
      *a3 = (v9 << 8) | *(unsigned __int8 *)(v7 + 3); /*0x146b94*/
      *a4 = v7; /*0x146b99*/
      return 1; /*0x146ba0*/
    }
    if ( ++v6 == v5 ) /*0x146ba7*/
      v6 = 0; /*0x146ba9*/
  }
  return 0; /*0x146bc0*/
}
