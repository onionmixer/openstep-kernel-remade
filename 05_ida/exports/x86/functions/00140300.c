/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140300. */
int __cdecl disksort_first(int a1)
{
  char v1; // dl
  int v3; // ecx
  volatile __int32 *v4; // edx
  int *v5; // edx
  int v6; // esi

  if ( dword_1F50EC ) /*0x14030f*/
  {
    v1 = *(_BYTE *)(a1 + 12); /*0x140311*/
    if ( (v1 & 1) != 0 ) /*0x140317*/
      return dword_1F50DC(a1); /*0x140362*/
    if ( *(_DWORD *)(a1 + 16) == a1 + 16 ) /*0x14031f*/
    {
      *(_BYTE *)(a1 + 12) = v1 | 1; /*0x140324*/
      ((void (__cdecl *)(int))dword_1F50E4)(a1); /*0x14032d*/
    }
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 12) & 1) == 0 ) /*0x140334*/
      goto LABEL_10; /*0x140334*/
    if ( !dword_1F50DC(a1) ) /*0x14033c*/
    {
      *(_BYTE *)(a1 + 12) &= ~1u; /*0x140345*/
      ((void (__cdecl *)(int))dword_1F50E8)(a1); /*0x14034f*/
    }
  }
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 ) /*0x140358*/
    return dword_1F50DC(a1); /*0x140358*/
LABEL_10:
  v3 = splbio(); /*0x140364*/
  v4 = (volatile __int32 *)(a1 + 36); /*0x14036b*/
  do /*0x140382*/
  {
    while ( *v4 ) /*0x140370*/
      ; /*0x140372*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x140382*/
  v5 = *(int **)(a1 + 16); /*0x140387*/
  if ( (int *)(a1 + 16) == v5 ) /*0x14038c*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 36), 0); /*0x140390*/
    splx(v3); /*0x140394*/
    return 0; /*0x140399*/
  }
  else
  {
    v6 = *v5; /*0x1403a0*/
    _InterlockedExchange((volatile __int32 *)(a1 + 36), 0); /*0x1403a4*/
    splx(v3); /*0x1403a8*/
    return v6; /*0x1403ad*/
  }
}
