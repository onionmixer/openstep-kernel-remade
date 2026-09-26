/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f5e4. */
int __cdecl sub_13F5E4(int a1, int a2)
{
  unsigned int v2; // esi
  int v4; // [esp+Ch] [ebp-1Ch] BYREF
  int v5; // [esp+10h] [ebp-18h] BYREF
  unsigned __int16 v6; // [esp+14h] [ebp-14h]
  unsigned __int16 v7; // [esp+16h] [ebp-12h]
  char v8; // [esp+18h] [ebp-10h]
  char v9; // [esp+19h] [ebp-Fh]

  v2 = 0; /*0x13f5f3*/
  if ( !*(_DWORD *)(a1 + 108) ) /*0x13f5f5*/
    return 1; /*0x13f65b*/
  while ( !rdwri(0, a1, &v5, 12, v2, 1, &v4) /*0x13f647*/
       && !v4
       && v6
       && (!v5 || v7 <= 2u && v8 == 46 && (v7 == 1 || v9 == 46 && a2 == v5)) )
  {
    v2 += v6; /*0x13f654*/
    if ( *(_DWORD *)(a1 + 108) <= v2 ) /*0x13f659*/
      return 1; /*0x13f659*/
  }
  return 0; /*0x13f663*/
}
