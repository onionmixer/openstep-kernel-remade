/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cb18. */
int __cdecl unexport(void *a1, _WORD *a2)
{
  int *v2; // ebx
  unsigned __int16 *v3; // edx
  int v4; // eax

  v2 = &exported; /*0x12cb24*/
  if ( !exported ) /*0x12cb30*/
    return 22; /*0x12cb8f*/
  while ( 1 ) /*0x12cb3d*/
  {
    if ( !bcmp((const void *)(*v2 + 32), a1, 8u) ) /*0x12cb3d*/
    {
      v3 = *(unsigned __int16 **)(*v2 + 40); /*0x12cb4b*/
      if ( *a2 == *v3 && !bcmp(v3 + 1, a2 + 1, *v3) ) /*0x12cb64*/
        break; /*0x12cb64*/
    }
    v2 = (int *)(*v2 + 44); /*0x12cb86*/
    if ( !*v2 ) /*0x12cb89*/
      return 22; /*0x12cb8d*/
  }
  v4 = *v2; /*0x12cb70*/
  *v2 = *(_DWORD *)(*v2 + 44); /*0x12cb75*/
  exportfree(v4); /*0x12cb78*/
  return 0; /*0x12cb97*/
}
