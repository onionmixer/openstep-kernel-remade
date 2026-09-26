/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137814. */
int __cdecl svckudp_dupsave(_DWORD *a1)
{
  _DWORD *v1; // ebx
  int v2; // eax
  _DWORD *v3; // eax
  int result; // eax

  if ( ndupreqs > 399 ) /*0x137826*/
  {
    v1 = *(_DWORD **)(drmru + 32); /*0x137859*/
    sub_137944(v1); /*0x13785d*/
  }
  else
  {
    v1 = (_DWORD *)kalloc(0x28u); /*0x13782f*/
    v2 = drmru; /*0x137831*/
    if ( drmru ) /*0x137838*/
    {
      v1[8] = *(_DWORD *)(drmru + 32); /*0x13783d*/
      *(_DWORD *)(v2 + 32) = v1; /*0x137840*/
    }
    else
    {
      v1[8] = v1; /*0x137848*/
    }
    ++ndupreqs; /*0x13784b*/
  }
  drmru = (int)v1; /*0x137862*/
  *v1 = *(_DWORD *)(*(_DWORD *)(a1[7] + 48) + 4); /*0x137871*/
  v1[7] = *a1; /*0x137875*/
  v1[6] = a1[1]; /*0x13787b*/
  v1[5] = a1[2]; /*0x137881*/
  v3 = (_DWORD *)a1[7]; /*0x137884*/
  v1[1] = v3[4]; /*0x13788a*/
  v1[2] = v3[5]; /*0x137890*/
  v1[3] = v3[6]; /*0x137896*/
  v1[4] = v3[7]; /*0x13789c*/
  v1[9] = drhashtbl[*v1 & 0x1F]; /*0x1378ab*/
  result = *v1 & 0x1F; /*0x1378b0*/
  drhashtbl[result] = (int)v1; /*0x1378b3*/
  return result; /*0x1378bd*/
}
