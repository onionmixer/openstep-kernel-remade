/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc184. */
int __cdecl NXCompareMapTables(int a1, int a2)
{
  _BYTE v3[4]; // [esp+8h] [ebp-Ch] BYREF
  int v4; // [esp+Ch] [ebp-8h] BYREF
  int v5; // [esp+10h] [ebp-4h] BYREF

  if ( a1 == a2 ) /*0x1cc194*/
    return 1; /*0x1cc1ca*/
  if ( *(_DWORD *)(a2 + 4) == *(_DWORD *)(a1 + 4) ) /*0x1cc19c*/
  {
    v5 = NXInitMapState(a1); /*0x1cc1a4*/
    while ( NXNextMapState(a1, &v5, &v4, v3) ) /*0x1cc1c3*/
    {
      if ( NXMapMember(a2, v4, v3) == -1 ) /*0x1cc1e0*/
        return 0; /*0x1cc1e0*/
    }
    return 1; /*0x1cc1c3*/
  }
  return 0; /*0x1cc1e7*/
}
