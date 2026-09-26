/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124e10. */
int __cdecl in_pcballoc(int a1, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ebx

  v2 = (_DWORD *)kalloc(0x40u); /*0x124e1e*/
  v3 = v2; /*0x124e23*/
  if ( !v2 ) /*0x124e2a*/
    return 55; /*0x124e50*/
  bzero(v2, 0x40u); /*0x124e2f*/
  v3[2] = a2; /*0x124e34*/
  v3[7] = a1; /*0x124e37*/
  *v3 = *(_DWORD *)a2; /*0x124e3c*/
  v3[1] = a2; /*0x124e3e*/
  *(_DWORD *)(*(_DWORD *)a2 + 4) = v3; /*0x124e43*/
  *(_DWORD *)a2 = v3; /*0x124e46*/
  *(_DWORD *)(a1 + 8) = v3; /*0x124e48*/
  return 0; /*0x124e58*/
}
