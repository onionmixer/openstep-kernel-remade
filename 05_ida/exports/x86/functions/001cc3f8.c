/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc3f8. */
void __cdecl sub_1CC3F8(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  _DWORD *i; // edx
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  _DWORD *v8; // [esp+14h] [ebp-4h]

  v8 = (_DWORD *)a1[3]; /*0x1cc407*/
  v1 = v8; /*0x1cc40a*/
  v6 = a1[2]; /*0x1cc413*/
  v7 = a1[1]; /*0x1cc41c*/
  a1[2] = v6 + 1 + v6; /*0x1cc426*/
  a1[1] = 0; /*0x1cc429*/
  v2 = NXZoneFromPtr(a1); /*0x1cc431*/
  v3 = a1[2]; /*0x1cc438*/
  v4 = (*(int (__cdecl **)(int, int))(v2 + 4))(v2, 8 * v3); /*0x1cc44a*/
  for ( i = (_DWORD *)v4; --v3 != -1; i += 2 ) /*0x1cc44c*/
  {
    *i = -1; /*0x1cc454*/
    i[1] = 0; /*0x1cc45a*/
  }
  a1[3] = v4; /*0x1cc46d*/
  ++dword_1E558C; /*0x1cc470*/
  dword_1E5590 += a1[1]; /*0x1cc479*/
  while ( --v6 != -1 ) /*0x1cc49f*/
  {
    if ( *v1 != -1 ) /*0x1cc487*/
      NXMapInsert(a1, *v1, v1[1]); /*0x1cc494*/
    v1 += 2; /*0x1cc49c*/
  }
  if ( a1[1] != v7 )
    _NXLogError(
      "*** maptable: count differs after rehashing; probably indicates a broken invariant: there are x and y such as isEq"
      "ual(x, y) is TRUE but hash(x) != hash (y)\n");
  free(v8); /*0x1cc4c4*/
}
