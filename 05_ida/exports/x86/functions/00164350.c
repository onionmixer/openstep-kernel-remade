/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164350. */
int __cdecl rem_runq(_DWORD *a1)
{
  int v1; // edx
  volatile __int32 *v2; // ecx

  v1 = a1[2]; /*0x164358*/
  if ( v1 ) /*0x16435d*/
  {
    v2 = (volatile __int32 *)(v1 + 256); /*0x16435f*/
    do /*0x16437a*/
    {
      while ( *v2 ) /*0x164368*/
        ; /*0x16436a*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x16437a*/
    if ( a1[2] == v1 ) /*0x16437f*/
    {
      *(_DWORD *)(*a1 + 4) = a1[1]; /*0x164386*/
      *(_DWORD *)a1[1] = *a1; /*0x16438e*/
      --*(_DWORD *)(v1 + 264); /*0x164390*/
      a1[2] = 0; /*0x164396*/
      _InterlockedExchange((volatile __int32 *)(v1 + 256), 0); /*0x16439f*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(v1 + 256), 0); /*0x1643aa*/
      return 0; /*0x1643b0*/
    }
  }
  return v1; /*0x1643b7*/
}
