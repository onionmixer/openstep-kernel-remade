/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17b9e0. */
int __cdecl vm_synchronize(int a1, int a2, int a3)
{
  int v3; // edx
  int v4; // eax

  v3 = a2; /*0x17b9e6*/
  v4 = a3; /*0x17b9e9*/
  if ( !a1 ) /*0x17b9ee*/
    return 5; /*0x17b9f0*/
  if ( !a3 ) /*0x17b9fe*/
    v4 = *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 20); /*0x17ba03*/
  if ( !a2 ) /*0x17ba08*/
    v3 = *(_DWORD *)(a1 + 20); /*0x17ba0a*/
  return sub_17BA1C(a1, v3, v3 + v4); /*0x17b9f7*/
}
