/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1122cc. */
int __cdecl ptcread(unsigned __int8 a1, _DWORD *a2)
{
  int v2; // eax
  int v3; // ebx
  char *v4; // esi
  int v5; // edi
  char v6; // al
  int result; // eax
  int v8; // eax
  char v9; // al
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  _BYTE v14[4]; // [esp+10h] [ebp-80h] BYREF
  __int16 v15; // [esp+14h] [ebp-7Ch]
  _BYTE v16[6]; // [esp+16h] [ebp-7Ah] BYREF
  _BYTE v17[8]; // [esp+1Ch] [ebp-74h] BYREF
  int v18; // [esp+24h] [ebp-6Ch]
  int v19; // [esp+28h] [ebp-68h]
  _BYTE v20[100]; // [esp+2Ch] [ebp-64h] BYREF

  v2 = 8 * a1; /*0x1122dc*/
  v3 = *(_DWORD *)&word_1E56C8[v2 + 4]; /*0x1122e4*/
  v4 = *(char **)&word_1E56C8[v2 + 6]; /*0x1122e8*/
  v5 = 0; /*0x1122ec*/
  while ( 1 ) /*0x1122f8*/
  {
    if ( (*(_BYTE *)(v3 + 64) & 4) != 0 ) /*0x1122fc*/
    {
      if ( (*v4 & 8) != 0 ) /*0x112305*/
      {
        v6 = v4[12]; /*0x11230b*/
        if ( v6 ) /*0x112310*/
        {
          result = ureadc(v6, a2); /*0x112320*/
          if ( !result ) /*0x11232c*/
          {
            if ( (v4[12] & 0x40) != 0 ) /*0x112336*/
            {
              v14[0] = *(_BYTE *)(v3 + 73); /*0x11233b*/
              v14[1] = *(_BYTE *)(v3 + 74); /*0x112341*/
              v14[2] = *(_BYTE *)(v3 + 77); /*0x112347*/
              v14[3] = *(_BYTE *)(v3 + 78); /*0x11234d*/
              v15 = *(_WORD *)(v3 + 60); /*0x112354*/
              bcopy((const void *)(v3 + 79), v16, 6u); /*0x112362*/
              bcopy((const void *)(v3 + 85), v17, 6u); /*0x112371*/
              v18 = *(_DWORD *)(v3 + 64); /*0x112379*/
              v19 = *(unsigned __int16 *)(v3 + 62); /*0x112380*/
              v8 = 28; /*0x11238c*/
              if ( a2[5] <= 0x1Bu ) /*0x112394*/
                v8 = a2[5]; /*0x112396*/
              uiomove((int)v14, v8, 0, a2); /*0x1123a6*/
            }
            v4[12] = 0; /*0x1123ab*/
            return 0; /*0x1123af*/
          }
          return result; /*0x1123b1*/
        }
      }
      if ( *v4 < 0 ) /*0x1123bb*/
      {
        v9 = v4[13]; /*0x1123bd*/
        if ( v9 ) /*0x1123c2*/
        {
          result = ureadc(v9, a2); /*0x1123ce*/
          if ( !result ) /*0x1123d7*/
          {
            v4[13] = 0; /*0x1123dd*/
            return 0; /*0x1123e1*/
          }
          return result; /*0x1123e3*/
        }
      }
      if ( *(_DWORD *)(v3 + 24) && (*(_BYTE *)(v3 + 65) & 1) == 0 ) /*0x1123f2*/
        break; /*0x1123f2*/
    }
    if ( (*(_BYTE *)(v3 + 64) & 0x10) == 0 ) /*0x1123f8*/
      return 5; /*0x1123ff*/
    if ( (*v4 & 4) != 0 ) /*0x112407*/
    {
      if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x112414*/
        return 11; /*0x112416*/
      else
        return 35; /*0x112420*/
    }
    sleep(v3 + 28); /*0x112432*/
  }
  if ( (*v4 & 0x88) != 0 ) /*0x112443*/
    v5 = ureadc(0, a2); /*0x112450*/
  v10 = a2[5]; /*0x112458*/
  if ( v10 > 0 && !v5 ) /*0x112461*/
  {
    do /*0x1124a2*/
    {
      if ( v10 > 100 ) /*0x11246b*/
        v10 = 100; /*0x11246d*/
      v11 = q_to_b(v3 + 24, v20, v10); /*0x112478*/
      if ( v11 <= 0 ) /*0x112482*/
        break; /*0x112482*/
      v5 = uiomove((int)v20, v11, 0, a2); /*0x112491*/
      v10 = a2[5]; /*0x112499*/
      if ( v10 <= 0 ) /*0x11249e*/
        break; /*0x11249e*/
    }
    while ( !v5 ); /*0x1124a2*/
  }
  if ( *(_DWORD *)(v3 + 24) <= ttlowat[*(_BYTE *)(v3 + 74) & 0x1F] ) /*0x1124b5*/
  {
    v12 = *(_DWORD *)(v3 + 64); /*0x1124b7*/
    if ( (v12 & 0x40) != 0 ) /*0x1124bc*/
    {
      LOBYTE(v12) = v12 & 0xBF; /*0x1124be*/
      *(_DWORD *)(v3 + 64) = v12; /*0x1124c0*/
      wakeup(v3 + 24); /*0x1124c7*/
    }
    v13 = *(_DWORD *)(v3 + 44); /*0x1124cf*/
    if ( v13 ) /*0x1124d4*/
    {
      selwakeup(v13, *(_DWORD *)(v3 + 64) & 0x1000); /*0x1124e0*/
      thread_deallocate(*(_DWORD *)(v3 + 44)); /*0x1124e9*/
      *(_DWORD *)(v3 + 44) = 0; /*0x1124ee*/
      *(_DWORD *)(v3 + 64) &= ~0x1000u; /*0x1124f5*/
    }
  }
  return v5; /*0x112504*/
}
