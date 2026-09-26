/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146bc8. */
int __cdecl ipc_hash_local_insert(int a1, unsigned int a2, int a3)
{
  int v3; // ebx
  unsigned int v4; // ecx
  int v5; // edx

  v3 = *(_DWORD *)(a1 + 20); /*0x146bd0*/
  v4 = *(_DWORD *)(a1 + 24); /*0x146bd3*/
  v5 = (a2 >> 6) % v4; /*0x146bde*/
  while ( *(_DWORD *)(v3 + 16 * v5 + 12) ) /*0x146bf5*/
  {
    if ( ++v5 == v4 ) /*0x146be7*/
      v5 = 0; /*0x146be9*/
  }
  *(_DWORD *)(v3 + 16 * v5 + 12) = a3; /*0x146bff*/
  return 16 * v5; /*0x146c06*/
}
