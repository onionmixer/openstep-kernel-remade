/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cf34. */
int __cdecl loadaddrs(int *a1)
{
  int v1; // eax
  unsigned int v3; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // esi

  v1 = *a1; /*0x12cf3d*/
  if ( (unsigned int)*a1 > 0x400 ) /*0x12cf44*/
    return 22; /*0x12cf46*/
  v3 = 16 * v1; /*0x12cf52*/
  v4 = a1[1]; /*0x12cf55*/
  if ( 16 * v1 ) /*0x12cf52*/
  {
    v5 = kalloc(16 * v1); /*0x12cf69*/
    a1[1] = v5; /*0x12cf6e*/
    v6 = copyin(v4, v5, v3); /*0x12cf79*/
    if ( v6 ) /*0x12cf80*/
      kfree(a1[1], v3); /*0x12cf87*/
    return v6; /*0x12cf8c*/
  }
  else
  {
    a1[1] = 0; /*0x12cf5a*/
    return 0; /*0x12cf61*/
  }
}
