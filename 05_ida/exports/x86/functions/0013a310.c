/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a310. */
int __cdecl spec_access(int a1, int a2, int a3)
{
  int v3; // edx

  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 48) + 56); /*0x13a319*/
  if ( v3 ) /*0x13a31e*/
    return (*(int (__stdcall **)(int, int, int))(*(_DWORD *)(v3 + 28) + 28))(v3, a2, a3); /*0x13a32f*/
  else
    return 0; /*0x13a338*/
}
