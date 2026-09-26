/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf35c. */
char __cdecl sub_1BF35C(int a1, int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  int v5; // eax

  v2 = *(_DWORD *)(a1 + 4); /*0x1bf368*/
  LOBYTE(v3) = v2 - 112; /*0x1bf36f*/
  if ( (unsigned int)(v2 - 112) <= 0x1000 && *(_BYTE *)(a1 + 3) == 1 ) /*0x1bf37c*/
  {
    LOBYTE(v3) = 2; /*0x1bf388*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 /*0x1bf3bb*/
      && (LOBYTE(v3) = 8, *(_DWORD *)(a1 + 32) == 272631816)
      && (LOBYTE(v3) = *(_BYTE *)(a1 + 103) & 0x30, (_BYTE)v3 == 48)
      && *(_DWORD *)(a1 + 104) == 524296
      && (v4 = *(_DWORD *)(a1 + 108), v5 = v4 + 3, LOBYTE(v5) = (v4 + 3) & 0xFC, v3 = v5 + 112, v2 == v3) )
    {
      v3 = EvSetParameterChar( /*0x1bf3d9*/
             *(id *)(a1 + 12),
             *(_DWORD *)(a1 + 28),
             (char *)(a1 + 36),
             a1 + 112,
             *(_DWORD *)(a1 + 108));
      *(_DWORD *)(a2 + 28) = v3; /*0x1bf3de*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf3bd*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf3e1*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf3e7*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf3eb*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf37e*/
  }
  return v3; /*0x1bf3f5*/
}
