/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179630. */
int __cdecl vm_object_lookup(int a1)
{
  int *v1; // edx
  int *v2; // eax
  int v3; // ecx
  volatile __int32 *v4; // edx
  int *v5; // edx
  int *v6; // eax

  v1 = &vm_object_hashtable[2 * (a1 & 0x7F)]; /*0x17963c*/
  do /*0x17965d*/
  {
    while ( vm_cache_lock ) /*0x17964b*/
      ; /*0x179649*/
  }
  while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x17965d*/
  v2 = (int *)*v1; /*0x17965f*/
  if ( v1 == (int *)*v1 ) /*0x179663*/
  {
LABEL_19:
    _InterlockedExchange(&vm_cache_lock, 0); /*0x1796da*/
    return 0; /*0x1796e2*/
  }
  else
  {
    while ( 1 ) /*0x179668*/
    {
      v3 = v2[2]; /*0x179668*/
      if ( *(_DWORD *)(v3 + 40) == a1 ) /*0x17966e*/
        break; /*0x17966e*/
      v2 = (int *)*v2; /*0x1796d4*/
      if ( v1 == v2 ) /*0x1796d8*/
        goto LABEL_19; /*0x1796d8*/
    }
    v4 = (volatile __int32 *)(v3 + 16); /*0x179670*/
    do /*0x179686*/
    {
      while ( *v4 ) /*0x179674*/
        ; /*0x179676*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x179686*/
    if ( !*(_WORD *)(v3 + 24) ) /*0x179688*/
    {
      v5 = *(int **)(v3 + 76); /*0x17968f*/
      v6 = *(int **)(v3 + 80); /*0x179692*/
      if ( v5 == &vm_object_cached_list ) /*0x17969b*/
        dword_1F6F3C = *(_DWORD *)(v3 + 80); /*0x17969d*/
      else
        v5[20] = (int)v6; /*0x1796a4*/
      if ( v6 == &vm_object_cached_list ) /*0x1796ac*/
        vm_object_cached_list = (int)v5; /*0x1796cc*/
      else
        v6[19] = (int)v5; /*0x1796ae*/
      --vm_object_cached; /*0x1796b1*/
    }
    ++*(_WORD *)(v3 + 24); /*0x1796b7*/
    _InterlockedExchange((volatile __int32 *)(v3 + 16), 0); /*0x1796bd*/
    _InterlockedExchange(&vm_cache_lock, 0); /*0x1796c2*/
    return v3; /*0x1796c8*/
  }
}
