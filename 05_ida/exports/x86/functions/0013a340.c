/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a340. */
int __cdecl spec_link(int a1, int a2, int a3, int a4)
{
  int v4; // edx

  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 48) + 56); /*0x13a34d*/
  if ( v4 ) /*0x13a352*/
    return (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)(a2 + 28) + 44))(v4, a2, a3, a4); /*0x13a364*/
  else
    return 2; /*0x13a368*/
}
