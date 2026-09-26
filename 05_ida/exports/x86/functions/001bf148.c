/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf148. */
int __cdecl sub_1BF148(int a1, int a2)
{
  int result; // eax
  int v3; // ecx
  int v4; // [esp+8h] [ebp-4h] BYREF

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf156*/
  if ( *(_DWORD *)(a1 + 4) == 108 && result == 1 ) /*0x1bf163*/
  {
    result = 268509186; /*0x1bf174*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 /*0x1bf190*/
      && (result = 272631816, *(_DWORD *)(a1 + 32) == 272631816)
      && (result = 268509186, *(_DWORD *)(a1 + 100) == 268509186) )
    {
      v4 = 64; /*0x1bf19c*/
      result = EvGetParameterInt( /*0x1bf1bb*/
                 *(_DWORD *)(a1 + 12),
                 *(_DWORD *)(a1 + 28),
                 a1 + 36,
                 *(_DWORD *)(a1 + 104),
                 a2 + 36,
                 &v4);
      *(_DWORD *)(a2 + 28) = result; /*0x1bf1c0*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf192*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf1c3*/
    {
      *(_DWORD *)(a2 + 32) = 272637954; /*0x1bf1cf*/
      v3 = v4; /*0x1bf1d2*/
      *(_WORD *)(a2 + 34) = v4 & 0xFFF | *(_WORD *)(a2 + 34) & 0xF000; /*0x1bf1e5*/
      result = 4 * v3 + 36; /*0x1bf1e9*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf1f0*/
      *(_DWORD *)(a2 + 4) = result; /*0x1bf1f4*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf165*/
  }
  return result; /*0x1bf1fa*/
}
