/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1796ec. */
__int32 __cdecl vm_object_enter(int a1, __int32 a2)
{
  __int32 result; // eax
  int *v3; // ebx
  int **v4; // edx
  int *v5; // eax

  result = a2; /*0x1796f4*/
  if ( a1 && a2 ) /*0x1796fd*/
  {
    v3 = &vm_object_hashtable[2 * (a2 & 0x7F)]; /*0x179702*/
    v4 = (int **)zalloc(object_hash_zone); /*0x179715*/
    v4[2] = (int *)a1; /*0x179717*/
    *(_BYTE *)(a1 + 70) |= 8u; /*0x17971a*/
    do /*0x179739*/
    {
      while ( vm_cache_lock ) /*0x179727*/
        ; /*0x179725*/
    }
    while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x179739*/
    v5 = (int *)v3[1]; /*0x17973b*/
    if ( v3 == v5 ) /*0x179740*/
      *v3 = (int)v4; /*0x179742*/
    else
      *v5 = (int)v4; /*0x179748*/
    v4[1] = v5; /*0x17974a*/
    *v4 = v3; /*0x17974d*/
    v3[1] = (int)v4; /*0x17974f*/
    return _InterlockedExchange(&vm_cache_lock, 0); /*0x179754*/
  }
  return result; /*0x17975d*/
}
