/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10daf0. */
int __cdecl ttysetspec(_DWORD *a1)
{
  int result; // eax
  int v2; // ebx
  int v3; // esi
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // cl
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // cl
  unsigned __int8 v14; // cl
  int v15; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]
  int j; // [esp+10h] [ebp-4h]

  result = (int)a1; /*0x10daf9*/
  v2 = *a1; /*0x10dafc*/
  v15 = *(_DWORD *)(*a1 + 60); /*0x10db01*/
  v3 = a1[4]; /*0x10db04*/
  for ( i = 0; i <= 7; ++i ) /*0x10db07*/
    *(_DWORD *)(v2 + 4 * i + 100) = 0; /*0x10db13*/
  if ( (v15 & 0x20) == 0 ) /*0x10db2a*/
  {
    if ( (v3 & 0x10) != 0 ) /*0x10db36*/
    {
      v4 = *(_BYTE *)(v2 + 90); /*0x10db38*/
      if ( v4 != 0xFF ) /*0x10db41*/
        *(_DWORD *)(v2 + 4 * (v4 >> 5) + 100) |= 1 << (v4 & 0x1F); /*0x10db58*/
      v5 = *(_BYTE *)(v2 + 88); /*0x10db5c*/
      if ( v5 != 0xFF ) /*0x10db65*/
        *(_DWORD *)(v2 + 4 * (v5 >> 5) + 100) |= 1 << (v5 & 0x1F); /*0x10db7c*/
    }
    if ( (v3 & 8) != 0 ) /*0x10db86*/
    {
      v6 = *(_BYTE *)(v2 + 79); /*0x10db88*/
      if ( v6 != 0xFF ) /*0x10db91*/
        *(_DWORD *)(v2 + 4 * (v6 >> 5) + 100) |= 1 << (v6 & 0x1F); /*0x10dba8*/
      v7 = *(_BYTE *)(v2 + 80); /*0x10dbac*/
      if ( v7 != 0xFF ) /*0x10dbb5*/
        *(_DWORD *)(v2 + 4 * (v7 >> 5) + 100) |= 1 << (v7 & 0x1F); /*0x10dbcc*/
      v8 = *(_BYTE *)(v2 + 85); /*0x10dbd0*/
      if ( v8 != 0xFF ) /*0x10dbd9*/
        *(_DWORD *)(v2 + 4 * (v8 >> 5) + 100) |= 1 << (v8 & 0x1F); /*0x10dbf0*/
    }
    if ( (v3 & 0x4000000) != 0 ) /*0x10dbfa*/
    {
      v9 = *(_BYTE *)(v2 + 82); /*0x10dbfc*/
      if ( v9 != 0xFF ) /*0x10dc05*/
        *(_DWORD *)(v2 + 4 * (v9 >> 5) + 100) |= 1 << (v9 & 0x1F); /*0x10dc1c*/
      v10 = *(_BYTE *)(v2 + 81); /*0x10dc20*/
      if ( v10 != 0xFF ) /*0x10dc29*/
        *(_DWORD *)(v2 + 4 * (v10 >> 5) + 100) |= 1 << (v10 & 0x1F); /*0x10dc40*/
    }
    if ( (v15 & 0x10) != 0 || (v3 & 0x3000000) != 0 ) /*0x10dc55*/
      *(_DWORD *)(v2 + 100) |= 0x2000u; /*0x10dc57*/
    if ( (v3 & 0x800000) != 0 ) /*0x10dc64*/
      *(_DWORD *)(v2 + 100) |= 0x400u; /*0x10dc66*/
    if ( (v15 & 2) == 0 ) /*0x10dc73*/
    {
      v11 = *(_BYTE *)(v2 + 77); /*0x10dc79*/
      if ( v11 != 0xFF ) /*0x10dc82*/
        *(_DWORD *)(v2 + 4 * (v11 >> 5) + 100) |= 1 << (v11 & 0x1F); /*0x10dc99*/
      v12 = *(_BYTE *)(v2 + 78); /*0x10dc9d*/
      if ( v12 != 0xFF ) /*0x10dca6*/
        *(_DWORD *)(v2 + 4 * (v12 >> 5) + 100) |= 1 << (v12 & 0x1F); /*0x10dcbd*/
      v13 = *(_BYTE *)(v2 + 89); /*0x10dcc1*/
      if ( v13 != 0xFF ) /*0x10dcca*/
        *(_DWORD *)(v2 + 4 * (v13 >> 5) + 100) |= 1 << (v13 & 0x1F); /*0x10dce1*/
      v14 = *(_BYTE *)(v2 + 87); /*0x10dce5*/
      if ( v14 != 0xFF ) /*0x10dcee*/
        *(_DWORD *)(v2 + 4 * (v14 >> 5) + 100) |= 1 << (v14 & 0x1F); /*0x10dd05*/
    }
    if ( (v15 & 4) != 0 ) /*0x10dd12*/
    {
      for ( j = 0; j <= 127; ++j ) /*0x10dd14*/
        *(_DWORD *)(v2 + 4 * ((unsigned __int8)j >> 5) + 100) |= 1 << (j & 0x1F); /*0x10dd36*/
    }
    result = v3 & 0x181000; /*0x10dd45*/
    if ( (_UNKNOWN *)(v3 & 0x181000) == &unk_101000 ) /*0x10dd4f*/
      *(_DWORD *)(v2 + 128) |= 0x80000000; /*0x10dd51*/
  }
  return result; /*0x10dd5e*/
}
