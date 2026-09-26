/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14282c. */
int __cdecl sub_14282C(int a1)
{
  int result; // eax
  int v2; // ebx
  int v3; // eax

  result = a1; /*0x142830*/
  v2 = *(_DWORD *)(a1 + 24); /*0x142833*/
  for ( *(_DWORD *)(a1 + 24) = 0; v2; result = wakeup(v3) ) /*0x14283f*/
  {
    v3 = v2; /*0x142844*/
    v2 = *(_DWORD *)(v2 + 24); /*0x142846*/
    *(_DWORD *)(v3 + 24) = 0; /*0x142849*/
    *(_DWORD *)(v3 + 20) = 0; /*0x142850*/
  }
  return result; /*0x142864*/
}
