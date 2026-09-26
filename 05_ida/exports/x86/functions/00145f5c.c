/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x145f5c. */
int __cdecl ipc_entry_alloc(int a1, _DWORD *a2, int **a3)
{
  volatile __int32 *v3; // edx
  int result; // eax
  int v5; // edx
  unsigned int v6; // ecx
  int *v7; // eax
  int v8; // edx

  v3 = (volatile __int32 *)(a1 + 8); /*0x145f68*/
  do /*0x145f7e*/
  {
    while ( *v3 ) /*0x145f6c*/
      ; /*0x145f6e*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x145f7e*/
  while ( 1 ) /*0x145f80*/
  {
    if ( !*(_DWORD *)(a1 + 12) ) /*0x145f80*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x145f88*/
      return 16; /*0x145f90*/
    }
    v5 = *(_DWORD *)(a1 + 20); /*0x145f94*/
    v6 = *(_DWORD *)(v5 + 8); /*0x145f97*/
    if ( v6 ) /*0x145f9c*/
      break; /*0x145f9c*/
    result = ipc_entry_grow_table(a1); /*0x145fd1*/
    if ( result ) /*0x145fdb*/
      return result; /*0x145fdb*/
  }
  v7 = (int *)(v5 + 16 * v6); /*0x145fa3*/
  *(_DWORD *)(v5 + 8) = v7[2]; /*0x145fa8*/
  v8 = *v7 + 0x1000000; /*0x145fad*/
  *v7 = v8; /*0x145fb3*/
  v7[2] = 0; /*0x145fb5*/
  *a2 = __SPAIR64__(v6, v8) >> 24; /*0x145fc7*/
  *a3 = v7; /*0x145fc9*/
  return 0; /*0x145fe0*/
}
