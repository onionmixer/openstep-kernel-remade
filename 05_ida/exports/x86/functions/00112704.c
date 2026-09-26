/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x112704. */
int __cdecl ptcwrite(unsigned __int8 a1, _DWORD *a2)
{
  int v2; // eax
  int v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // ebx
  int v6; // eax
  int result; // eax
  int v8; // edx
  _DWORD *v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // [esp-8h] [ebp-88h]
  int v14; // [esp+Ch] [ebp-74h]
  _BYTE *v15; // [esp+10h] [ebp-70h]
  int v16; // [esp+14h] [ebp-6Ch]
  _DWORD *v17; // [esp+18h] [ebp-68h]
  _BYTE v18[100]; // [esp+1Ch] [ebp-64h] BYREF

  v2 = 8 * a1; /*0x112711*/
  v3 = *(_DWORD *)&word_1E56C8[v2 + 4]; /*0x112719*/
  v17 = (_DWORD *)*a2; /*0x112722*/
  v4 = nullptr; /*0x112725*/
  v5 = 0; /*0x112727*/
  v16 = 0; /*0x112729*/
  v15 = *(_BYTE **)&word_1E56C8[v2 + 6]; /*0x112734*/
  while ( 1 ) /*0x112737*/
  {
    if ( (*(_BYTE *)(v3 + 64) & 4) != 0 ) /*0x11273b*/
    {
      if ( (*v15 & 0x20) == 0 ) /*0x112747*/
      {
        while ( 1 ) /*0x1128b4*/
        {
          v12 = a2[1]; /*0x1128b4*/
          if ( v12 <= 0 ) /*0x1128b9*/
            return 0; /*0x1128b9*/
          v9 = (_DWORD *)*a2; /*0x112813*/
          v17 = (_DWORD *)*a2; /*0x112815*/
          if ( v5 ) /*0x11281a*/
            goto LABEL_34; /*0x11281a*/
          v10 = v9[1]; /*0x112820*/
          if ( v10 ) /*0x112825*/
          {
            v5 = v9[1]; /*0x112834*/
            if ( v10 > 100 ) /*0x112839*/
              v5 = 100; /*0x11283b*/
            v4 = v18; /*0x112840*/
            result = uiomove((int)v18, v5, 1, a2); /*0x11284b*/
            if ( result ) /*0x112855*/
              return result; /*0x112855*/
            if ( (*(_BYTE *)(v3 + 64) & 4) == 0 ) /*0x11285f*/
              return 5; /*0x112924*/
LABEL_34:
            while ( v5 > 0 ) /*0x1128ad*/
            {
              v11 = *(_DWORD *)(v3 + 12); /*0x112868*/
              if ( v11 + *(_DWORD *)v3 > 1021 && (v11 > 0 || (*(_BYTE *)(v3 + 60) & 0x22) != 0) ) /*0x11287e*/
              {
                wakeup(v3); /*0x112881*/
                goto LABEL_38; /*0x112889*/
              }
              v13 = *v4++; /*0x11289a*/
              (*(&off_1DAFFC + 12 * *(char *)(v3 + 71)))(v13, (FILE *)v3); /*0x1128a2*/
              ++v16; /*0x1128a4*/
              --v5; /*0x1128a7*/
            }
            v5 = 0; /*0x1128af*/
          }
          else
          {
            a2[1] = v12 - 1; /*0x11282b*/
            *a2 += 8; /*0x11282e*/
          }
        }
      }
      if ( !*(_DWORD *)(v3 + 12) ) /*0x11274d*/
        break; /*0x11274d*/
    }
LABEL_38:
    if ( (*(_BYTE *)(v3 + 64) & 0x10) == 0 ) /*0x1128c8*/
      return 5; /*0x1128cf*/
    if ( (*v15 & 4) != 0 ) /*0x1128da*/
    {
      *v17 -= v5; /*0x1128df*/
      v17[1] += v5; /*0x1128e1*/
      a2[5] += v5; /*0x1128e7*/
      a2[2] -= v5; /*0x1128ea*/
      if ( !v16 ) /*0x1128f1*/
      {
        if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x1128fe*/
          return 11; /*0x112900*/
        else
          return 35; /*0x112908*/
      }
      return 0; /*0x1128c1*/
    }
    sleep(v3 + 4); /*0x112916*/
  }
  while ( 1 ) /*0x1127e6*/
  {
    v8 = a2[1]; /*0x1127e6*/
    if ( v8 <= 0 ) /*0x1127eb*/
      break; /*0x1127eb*/
    v14 = *(_DWORD *)(v3 + 12); /*0x11275f*/
    if ( v14 > 1022 ) /*0x112768*/
      break; /*0x112768*/
    v6 = *(_DWORD *)(*a2 + 4); /*0x112776*/
    if ( v6 ) /*0x11277b*/
    {
      if ( v5 ) /*0x11278e*/
        goto LABEL_17; /*0x11278e*/
      v5 = *(_DWORD *)(*a2 + 4); /*0x112790*/
      if ( v6 > 100 ) /*0x112795*/
        v5 = 100; /*0x112797*/
      if ( v5 > 1023 - v14 ) /*0x1127a6*/
        v5 = 1023 - v14; /*0x1127a8*/
      v4 = v18; /*0x1127aa*/
      result = uiomove((int)v18, v5, 1, a2); /*0x1127b5*/
      if ( result ) /*0x1127bf*/
        return result; /*0x1127bf*/
      if ( (*(_BYTE *)(v3 + 64) & 4) == 0 ) /*0x1127c9*/
        return 5; /*0x1127c9*/
      if ( v5 ) /*0x1127d1*/
LABEL_17:
        b_to_q(v4, v5, v3 + 12); /*0x1127d9*/
      v5 = 0; /*0x1127e1*/
    }
    else
    {
      a2[1] = v8 - 1; /*0x112781*/
      *a2 += 8; /*0x112784*/
    }
  }
  putc(0, (FILE *)(v3 + 12)); /*0x1127f7*/
  ttwakeup(v3); /*0x1127fd*/
  wakeup(v3 + 12); /*0x112803*/
  return 0; /*0x11292c*/
}
