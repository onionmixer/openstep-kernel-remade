/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf3f4. */
NXHashTable *__cdecl sub_1CF3F4(NXHashTable *table, int a2)
{
  int v2; // edx
  unsigned int j; // edi
  Class v4; // edx
  const char **data; // [esp+Ch] [ebp-14h]
  int v7; // [esp+10h] [ebp-10h]
  unsigned int i; // [esp+18h] [ebp-8h]
  int v9; // [esp+1Ch] [ebp-4h]

  v9 = *(_DWORD *)(a2 + 4); /*0x1cf403*/
  for ( i = 0; *(_DWORD *)(a2 + 8) > i; ++i ) /*0x1cf413*/
  {
    v2 = 16 * i; /*0x1cf422*/
    if ( *(_DWORD *)(v9 + 16 * i + 12) ) /*0x1cf427*/
    {
      for ( j = 0; j < *(unsigned __int16 *)(*(_DWORD *)(v9 + 16 * i + 12) + 8); v2 = 16 * i ) /*0x1cf438*/
      {
        v7 = v2; /*0x1cf44c*/
        data = (const char **)NXHashInsert(table, *(const void **)(*(_DWORD *)(v9 + v2 + 12) + 4 * j + 12)); /*0x1cf464*/
        if ( data ) /*0x1cf46c*/
        {
          sub_1CF348(table, data, *(_DWORD *)(*(_DWORD *)(v9 + v7 + 12) + 4 * j + 12)); /*0x1cf482*/
          v4 = objc_lookUpClass(data[2]); /*0x1cf490*/
        }
        else
        {
          v4 = *(Class *)(*(_DWORD *)(v9 + 16 * i + 12) + 4 * j + 12); /*0x1cf4a2*/
        }
        if ( data != (const char **)v4 ) /*0x1cf4a9*/
          v4->isa->version = *(_DWORD *)(v9 + 16 * i); /*0x1cf4b6*/
        sub_1CF0D4((int)v4); /*0x1cf4ba*/
        ++j; /*0x1cf4c2*/
      }
    }
  }
  return table; /*0x1cf4f4*/
}
