/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x145f04. */
int __cdecl ipc_entry_get(int a1, _DWORD *a2, int **a3)
{
  int v3; // edx
  unsigned int v4; // ecx
  int *v5; // eax
  int v6; // edx

  v3 = *(_DWORD *)(a1 + 20); /*0x145f13*/
  v4 = *(_DWORD *)(v3 + 8); /*0x145f16*/
  if ( !v4 ) /*0x145f1b*/
    return 3; /*0x145f4c*/
  v5 = (int *)(v3 + 16 * v4); /*0x145f22*/
  *(_DWORD *)(v3 + 8) = v5[2]; /*0x145f27*/
  v6 = *v5 + 0x1000000; /*0x145f2c*/
  *v5 = v6; /*0x145f32*/
  v5[2] = 0; /*0x145f34*/
  *a2 = __SPAIR64__(v4, v6) >> 24; /*0x145f43*/
  *a3 = v5; /*0x145f45*/
  return 0; /*0x145f54*/
}
