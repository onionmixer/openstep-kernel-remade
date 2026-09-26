/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146c0c. */
int __cdecl ipc_hash_local_delete(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  int result; // eax
  unsigned int v6; // ecx
  int v7; // esi
  unsigned int v8; // edx
  int v9; // [esp+10h] [ebp-4h]

  v9 = *(_DWORD *)(a1 + 20); /*0x146c1e*/
  v3 = *(_DWORD *)(a1 + 24); /*0x146c21*/
  v4 = (a2 >> 6) % v3; /*0x146c2e*/
  while ( 1 ) /*0x146c3d*/
  {
    result = 16 * v4; /*0x146c3d*/
    if ( *(_DWORD *)(v9 + 16 * v4 + 12) == a3 ) /*0x146c47*/
      break; /*0x146c47*/
    if ( ++v4 == v3 ) /*0x146c37*/
      v4 = 0; /*0x146c39*/
  }
  v6 = v4; /*0x146c49*/
  if ( a3 ) /*0x146c4d*/
  {
    while ( 1 ) /*0x146c7c*/
    {
      while ( 1 ) /*0x146c50*/
      {
        if ( ++v6 == v3 ) /*0x146c53*/
          v6 = 0; /*0x146c55*/
        v7 = *(_DWORD *)(v9 + 16 * v6 + 12); /*0x146c5f*/
        if ( !v7 ) /*0x146c65*/
          goto LABEL_15; /*0x146c65*/
        v8 = (*(_DWORD *)(v9 + 16 * v7 + 4) >> 6) % v3; /*0x146c75*/
        if ( v6 < v4 ) /*0x146c7c*/
          break; /*0x146c7c*/
        if ( v8 > v6 || v8 <= v4 ) /*0x146c90*/
          goto LABEL_15; /*0x146c90*/
      }
      if ( v6 < v8 && v8 <= v4 ) /*0x146c84*/
      {
LABEL_15:
        result = 16 * v4; /*0x146c92*/
        *(_DWORD *)(v9 + 16 * v4 + 12) = v7; /*0x146c9a*/
        v4 = v6; /*0x146c9e*/
        if ( !v7 ) /*0x146ca2*/
          return result; /*0x146ca2*/
      }
    }
  }
  return result; /*0x146ca7*/
}
