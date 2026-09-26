/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x154b28. */
__int32 __cdecl mach_port_names_helper(int a1, unsigned int *a2, int a3, int a4, int a5, __int32 *a6)
{
  unsigned int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // edx
  __int32 result; // eax
  int v10; // edx
  __int32 v11; // eax
  _BOOL4 v12; // [esp+Ch] [ebp-4h]

  v6 = *a2; /*0x154b34*/
  v7 = a2[2]; /*0x154b36*/
  if ( (*a2 & 0x50000) != 0 ) /*0x154b3f*/
  {
    v8 = a2[1]; /*0x154b41*/
    do /*0x154b56*/
    {
      while ( *(_DWORD *)v8 ) /*0x154b44*/
        ; /*0x154b46*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x154b56*/
    v12 = 0; /*0x154b58*/
    if ( *(int *)(v8 + 8) >= 0 ) /*0x154b63*/
      v12 = *(_DWORD *)(v8 + 12) - a1 < 0; /*0x154b6d*/
    result = _InterlockedExchange((volatile __int32 *)v8, 0); /*0x154b72*/
    if ( v12 ) /*0x154b78*/
    {
      if ( (v6 & 0x400000) != 0 ) /*0x154b80*/
        return result; /*0x154b80*/
      v6 = v6 & 0xFFC0FFFF | 0x100000; /*0x154b88*/
      if ( v7 ) /*0x154b90*/
        ++v6; /*0x154b92*/
      v7 = 0; /*0x154b93*/
    }
  }
  v10 = v6 & 0x1F0000; /*0x154b97*/
  if ( (v6 & 0x400000) != 0 ) /*0x154ba3*/
  {
    v10 |= 0x20000000u; /*0x154ba5*/
  }
  else if ( v7 ) /*0x154bb2*/
  {
    v10 |= 0x80000000; /*0x154bb4*/
  }
  if ( (v6 & 0x200000) != 0 ) /*0x154bc0*/
    v10 |= 0x40000000u; /*0x154bc2*/
  v11 = *a6; /*0x154bcb*/
  *(_DWORD *)(a4 + 4 * v11) = a3; /*0x154bd3*/
  *(_DWORD *)(a5 + 4 * v11) = v10; /*0x154bd9*/
  result = v11 + 1; /*0x154bdc*/
  *a6 = result; /*0x154be0*/
  return result; /*0x154be5*/
}
