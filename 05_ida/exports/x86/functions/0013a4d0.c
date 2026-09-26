/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a4d0. */
int __cdecl spec_fid(int a1, int a2)
{
  int v2; // edx

  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 48) + 56); /*0x13a4d9*/
  if ( v2 ) /*0x13a4de*/
    return (*(int (__stdcall **)(int, int))(*(_DWORD *)(v2 + 28) + 100))(v2, a2); /*0x13a4eb*/
  else
    return 22; /*0x13a4f4*/
}
