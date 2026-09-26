/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbfb4. */
_DWORD *__cdecl NXCreateMapTableFromZone(int data, int a2, int a3, int a4, unsigned int a5, int a6)
{
  _DWORD *v6; // esi
  _DWORD *v8; // ebx
  int v9; // ebx
  int v10; // eax
  _DWORD *v11; // ecx
  int v12; // edx

  v6 = (_DWORD *)(*(int (__cdecl **)(int, int))(a6 + 4))(a6, 16); /*0x1cbfc5*/
  if ( !dword_1E557C ) /*0x1cbfd1*/
    dword_1E557C = NXCreateHashTable(prototype, 0, nullptr); /*0x1cbff8*/
  if ( data && a2 && a3 && !a4 )
  {
    v8 = NXHashGet(dword_1E557C, &data); /*0x1cc03c*/
    if ( !v8 ) /*0x1cc043*/
    {
      v8 = malloc(0x10u); /*0x1cc04c*/
      *v8 = data; /*0x1cc051*/
      v8[1] = a2; /*0x1cc056*/
      v8[2] = a3; /*0x1cc05c*/
      v8[3] = a4; /*0x1cc062*/
      NXHashInsert(dword_1E557C, v8); /*0x1cc06d*/
    }
    *v6 = v8; /*0x1cc075*/
    v6[1] = 0; /*0x1cc077*/
    v9 = 1 << (sub_1CBF14(a5) + 1); /*0x1cc092*/
    v6[2] = v9 - 1; /*0x1cc097*/
    v10 = (*(int (__stdcall **)(int))(a6 + 4))(a6); /*0x1cc0a5*/
    v11 = (_DWORD *)v10; /*0x1cc0a7*/
    v12 = v9 - 2; /*0x1cc0a9*/
    if ( v9 != 1 ) /*0x1cc0af*/
    {
      do /*0x1cc0c8*/
      {
        *v11 = -1; /*0x1cc0b4*/
        v11[1] = 0; /*0x1cc0ba*/
        v11 += 2; /*0x1cc0c1*/
        --v12; /*0x1cc0c4*/
      }
      while ( v12 != -1 ); /*0x1cc0c8*/
    }
    v6[3] = v10; /*0x1cc0ca*/
    return v6; /*0x1cc0cd*/
  }
  else
  {
    _NXLogError("*** NXCreateMapTable: invalid creation parameters\n");
    return nullptr; /*0x1cc022*/
  }
}
