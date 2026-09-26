/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142544. */
int __cdecl sub_142544(int a1, int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax

  v2 = sub_1425A4(a1); /*0x14254f*/
  v3 = v2; /*0x142554*/
  if ( v2 ) /*0x142558*/
  {
    *(_WORD *)a2 = *(_WORD *)(v2 + 2); /*0x14255e*/
    *(_WORD *)(a2 + 2) = 0; /*0x142561*/
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(v2 + 4); /*0x14256a*/
    v4 = *(_DWORD *)(v2 + 8); /*0x14256d*/
    if ( v4 == -1 ) /*0x142573*/
      *(_DWORD *)(a2 + 8) = 0; /*0x142575*/
    else
      *(_DWORD *)(a2 + 8) = v4 - *(_DWORD *)(v3 + 4) + 1; /*0x142584*/
    *(_DWORD *)(a2 + 12) = **(_DWORD **)(v3 + 12); /*0x14258c*/
  }
  else
  {
    *(_WORD *)a2 = 3; /*0x142594*/
  }
  return 0; /*0x14259b*/
}
