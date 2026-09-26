/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142154. */
int __cdecl sub_142154(_DWORD *a1)
{
  int *v1; // esi
  int *v2; // ebx
  int result; // eax

  if ( (int)a1[2] <= 0 ) /*0x142160*/
  {
    v1 = &lf_svnode_hash[*a1 & 0x3F]; /*0x14216a*/
    if ( !*v1 ) /*0x142177*/
LABEL_6:
      panic(aLfFreeSvnodeCa); /*0x1421a5*/
    while ( 1 ) /*0x14217c*/
    {
      v2 = (int *)*v1; /*0x14217c*/
      if ( (_DWORD *)*v1 == a1 ) /*0x142180*/
        break; /*0x142180*/
      v1 = v2 + 3; /*0x14219c*/
      if ( !v2[3] ) /*0x14219f*/
        goto LABEL_6; /*0x1421a3*/
    }
    vn_rele(*v2); /*0x142185*/
    *v1 = v2[3]; /*0x14218d*/
    return kfree((int)v2, 0x10u); /*0x142192*/
  }
  return result; /*0x1421b2*/
}
