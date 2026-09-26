/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf128. */
void __cdecl sub_1CF128(int a1, int a2)
{
  int zone; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int *v6; // eax
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-4h] [ebp-10h]
  int v9; // [esp+0h] [ebp-Ch]

  if ( objc_lookUpClass(*(const char **)(a1 + 4)) ) /*0x1cf135*/
  {
    _objc_add_category((const char **)a1, a2); /*0x1cf146*/
  }
  else
  {
    if ( !dword_1E5620 ) /*0x1cf157*/
    {
      zone = _objc_create_zone(); /*0x1cf159*/
      dword_1E5620 = (int)NXCreateMapTableFromZone( /*0x1cf185*/
                            NXStrValueMapPrototype,
                            (int)_mapStrIsEqual,
                            (int)_mapNoFree,
                            0,
                            0x80u,
                            zone);
    }
    v3 = NXMapGet((_DWORD *)dword_1E5620, *(_DWORD *)(a1 + 4)); /*0x1cf19d*/
    v4 = _objc_create_zone(); /*0x1cf1a4*/
    v5 = _objc_create_zone(); /*0x1cf1a8*/
    v6 = (int *)(*(int (__stdcall **)(int, int, int, int, int))(v4 + 4))(v5, 12, v7, v8, v9); /*0x1cf1b1*/
    *v6 = v3; /*0x1cf1b3*/
    v6[1] = a1; /*0x1cf1b5*/
    v6[2] = a2; /*0x1cf1bb*/
    NXMapInsert((_DWORD *)dword_1E5620, *(_DWORD *)(a1 + 4), (int)v6); /*0x1cf1ca*/
  }
}
