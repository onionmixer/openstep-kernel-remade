/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1076d8. */
int __cdecl pgdelete(int *a1)
{
  int *v1; // ebx
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  int v4; // edx

  v1 = &pgrphash[a1[3] & 0x3F]; /*0x1076e6*/
  if ( *(_DWORD *)(a1[2] + 8) ) /*0x1076f0*/
  {
    v2 = (_DWORD *)ttynty(*(_DWORD *)(a1[2] + 8)); /*0x1076f8*/
    if ( (int *)v2[3] == a1 ) /*0x107703*/
    {
      v2[3] = 0; /*0x107705*/
      *(_WORD *)(*v2 + 68) = 0; /*0x10770e*/
    }
  }
  while ( 1 ) /*0x107726*/
  {
    if ( !*v1 ) /*0x107726*/
      panic(aPgdeleteCanTFi); /*0x107730*/
    if ( (int *)*v1 == a1 ) /*0x10771c*/
      break; /*0x10771c*/
    v1 = (int *)*v1; /*0x107724*/
  }
  *v1 = *a1; /*0x107720*/
  v3 = (_DWORD *)a1[2]; /*0x107738*/
  v4 = (*v3)--; /*0x10773b*/
  if ( v4 == 1 ) /*0x107745*/
  {
    if ( *(_DWORD *)(a1[2] + 8) ) /*0x10774a*/
      *(_DWORD *)(ttynty(*(_DWORD *)(a1[2] + 8)) + 8) = 0; /*0x107757*/
    kfree(a1[2], 0x10u); /*0x107767*/
  }
  return kfree((int)a1, 0x14u); /*0x10777a*/
}
