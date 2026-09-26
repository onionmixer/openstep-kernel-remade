/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f90c. */
void __cdecl disksort(int a1, int a2)
{
  int v2; // edx
  int v3; // ecx
  int v4; // eax
  int v5; // eax

  v2 = *(_DWORD *)(a1 + 12); /*0x13f918*/
  if ( v2 ) /*0x13f91d*/
  {
    if ( *(_DWORD *)(a2 + 56) >= *(_DWORD *)(v2 + 56) ) /*0x13f936*/
    {
      while ( *(_DWORD *)(v2 + 12) ) /*0x13f982*/
      {
        v5 = *(_DWORD *)(*(_DWORD *)(v2 + 12) + 56); /*0x13f973*/
        if ( *(_DWORD *)(v2 + 56) > v5 || *(_DWORD *)(a2 + 56) < v5 ) /*0x13f97e*/
          break; /*0x13f97e*/
        v2 = *(_DWORD *)(v2 + 12); /*0x13f980*/
      }
    }
    else if ( *(_DWORD *)(v2 + 12) ) /*0x13f938*/
    {
      while ( 1 ) /*0x13f940*/
      {
        v3 = *(_DWORD *)(v2 + 12); /*0x13f940*/
        if ( *(_DWORD *)(v3 + 56) < *(_DWORD *)(v2 + 56) ) /*0x13f949*/
          break; /*0x13f949*/
        v2 = *(_DWORD *)(v2 + 12); /*0x13f964*/
        if ( !*(_DWORD *)(v3 + 12) ) /*0x13f966*/
          goto LABEL_15; /*0x13f96a*/
      }
      do /*0x13f95a*/
      {
        v4 = *(_DWORD *)(v2 + 12); /*0x13f950*/
        if ( *(_DWORD *)(v4 + 56) > *(_DWORD *)(a2 + 56) ) /*0x13f956*/
          break; /*0x13f956*/
        v2 = *(_DWORD *)(v2 + 12); /*0x13f958*/
      }
      while ( *(_DWORD *)(v4 + 12) ); /*0x13f95a*/
    }
LABEL_15:
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(v2 + 12); /*0x13f988*/
    *(_DWORD *)(v2 + 12) = a2; /*0x13f98e*/
    if ( *(_DWORD *)(a1 + 16) == v2 ) /*0x13f994*/
      *(_DWORD *)(a1 + 16) = a2; /*0x13f996*/
  }
  else
  {
    *(_DWORD *)(a1 + 12) = a2; /*0x13f91f*/
    *(_DWORD *)(a1 + 16) = a2; /*0x13f922*/
    *(_DWORD *)(a2 + 12) = 0; /*0x13f925*/
  }
}
