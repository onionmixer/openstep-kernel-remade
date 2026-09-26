/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16957c. */
int __cdecl calloutRemove(int a1, int a2)
{
  int v2; // ecx
  int *v3; // edx

  v2 = splsched(); /*0x16958d*/
  do /*0x1695a9*/
  {
    while ( dword_1E7244 ) /*0x169597*/
      ; /*0x169595*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x1695a9*/
  v3 = (int *)dword_1E7250; /*0x1695ad*/
  if ( (int *)dword_1E7250 == &dword_1E7250 ) /*0x1695b9*/
  {
LABEL_9:
    v3 = (int *)dword_1E7258; /*0x1695ee*/
    if ( (int *)dword_1E7258 == &dword_1E7258 ) /*0x1695fa*/
      goto LABEL_17; /*0x1695fa*/
    while ( v3[2] != a1 || v3[3] != a2 ) /*0x169604*/
    {
      v3 = (int *)*v3; /*0x169648*/
      if ( v3 == &dword_1E7258 ) /*0x169650*/
        goto LABEL_17; /*0x169650*/
    }
    *(_DWORD *)(*v3 + 4) = v3[1]; /*0x16960b*/
    *(_DWORD *)v3[1] = *v3; /*0x169613*/
  }
  else
  {
    while ( v3[2] != a1 || v3[3] != a2 ) /*0x1695c4*/
    {
      v3 = (int *)*v3; /*0x1695e0*/
      if ( v3 == &dword_1E7250 ) /*0x1695e8*/
        goto LABEL_9; /*0x1695e8*/
    }
    *(_DWORD *)(*v3 + 4) = v3[1]; /*0x1695cb*/
    *(_DWORD *)v3[1] = *v3; /*0x1695d3*/
    --dword_1E7260; /*0x1695d5*/
  }
  v3[7] = 0; /*0x169615*/
  if ( v3 >= &dword_1E6A44 && v3 < &dword_1E7244 ) /*0x16962a*/
  {
    *v3 = (int)&dword_1E7248; /*0x16962c*/
    v3[1] = dword_1E724C; /*0x169638*/
    *(_DWORD *)v3[1] = v3; /*0x16963e*/
    dword_1E724C = (int)v3; /*0x169640*/
  }
LABEL_17:
  _InterlockedExchange(&dword_1E7244, 0); /*0x169652*/
  return splx(v2); /*0x169663*/
}
