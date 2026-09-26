/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1420e4. */
int __cdecl sub_1420E4(int a1)
{
  int *v1; // ebx
  int *v2; // edx
  _DWORD *v3; // eax

  v1 = &lf_svnode_hash[a1 & 0x3F]; /*0x1420f4*/
  v2 = v1; /*0x1420fa*/
  if ( !*v1 ) /*0x142103*/
  {
LABEL_6:
    v3 = (_DWORD *)kalloc(0x10u); /*0x142125*/
    *v3 = a1; /*0x14212c*/
    v3[1] = 0; /*0x14212e*/
    v3[2] = 0; /*0x142135*/
    ++*(_WORD *)(a1 + 6); /*0x14213c*/
    goto LABEL_7; /*0x14213c*/
  }
  while ( 1 ) /*0x142108*/
  {
    v3 = (_DWORD *)*v2; /*0x142108*/
    if ( *(_DWORD *)*v2 == a1 ) /*0x14210c*/
      break; /*0x14210c*/
    v2 = v3 + 3; /*0x14211c*/
    if ( !v3[3] ) /*0x14211f*/
      goto LABEL_6; /*0x142123*/
  }
  if ( v2 != v1 ) /*0x142110*/
  {
    *v2 = v3[3]; /*0x142115*/
LABEL_7:
    v3[3] = *v1; /*0x142140*/
    *v1 = (int)v3; /*0x142145*/
  }
  return *v1; /*0x14214c*/
}
