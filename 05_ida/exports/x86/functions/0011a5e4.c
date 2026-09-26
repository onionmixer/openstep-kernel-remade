/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a5e4. */
int __cdecl brealloc(unsigned int *a1, signed int a2)
{
  signed int v2; // eax
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int *v17; // esi
  int v18; // [esp+Ch] [ebp-10h]
  char *v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+18h] [ebp-4h]

  v2 = a1[5]; /*0x11a5f0*/
  if ( a2 == v2 ) /*0x11a5f6*/
    return 1; /*0x11a5f8*/
  v4 = *a1; /*0x11a604*/
  if ( (*a1 & 0x200) != 0 ) /*0x11a609*/
  {
    *a1 = v4 & 0xFFFFFDF8; /*0x11a613*/
    if ( (int)a1[5] > (int)a1[6] ) /*0x11a61b*/
      panic(aBwrite); /*0x11a622*/
    (*(void (__cdecl **)(unsigned int *))(*(_DWORD *)(a1[16] + 28) + 84))(a1); /*0x11a634*/
    if ( (v4 & 0x100) != 0 ) /*0x11a63c*/
    {
      *(_BYTE *)a1 |= 0x80u; /*0x11a64c*/
    }
    else
    {
      biowait((unsigned int)a1); /*0x11a63f*/
      brelse((int)a1); /*0x11a645*/
    }
    return 0; /*0x11a64f*/
  }
  else
  {
    if ( a2 >= v2 ) /*0x11a65b*/
    {
      LOBYTE(v4) = v4 & 0xFD; /*0x11a684*/
      *a1 = v4; /*0x11a687*/
      v5 = a1[16]; /*0x11a689*/
      if ( v5 ) /*0x11a68e*/
      {
        v18 = (*(int (__cdecl **)(unsigned int))(*(_DWORD *)(v5 + 28) + 128))(a1[16]); /*0x11a6d8*/
        if ( v18 < 0 ) /*0x11a6e0*/
          panic(aCouldnTDetermi); /*0x11a6e7*/
        v20 = a1[9]; /*0x11a6f2*/
        v19 = (char *)&bufhash + 12 * ((a1[16] + v20 / 8) & 0xF); /*0x11a723*/
LABEL_21:
        v6 = *((_DWORD *)v19 + 1); /*0x11a729*/
        if ( (char *)v6 != v19 ) /*0x11a72e*/
        {
          do /*0x11a734*/
          {
            if ( (unsigned int *)v6 != a1 && *(_DWORD *)(v6 + 64) == a1[16] && (*(_BYTE *)(v6 + 2) & 1) == 0 ) /*0x11a74c*/
            {
              v7 = *(_DWORD *)(v6 + 20); /*0x11a752*/
              if ( v7 ) /*0x11a757*/
              {
                v8 = *(_DWORD *)(v6 + 36); /*0x11a75d*/
                if ( a2 / v18 + v20 - 1 >= v8 && v20 < v8 + v7 / v18 ) /*0x11a772*/
                {
                  v9 = splhigh(); /*0x11a77d*/
                  v10 = *(_DWORD *)v6; /*0x11a77f*/
                  if ( (*(_DWORD *)v6 & 8) != 0 ) /*0x11a783*/
                  {
                    LOBYTE(v10) = v10 | 0x40; /*0x11a6a0*/
                    *(_DWORD *)v6 = v10; /*0x11a6a2*/
                    sleep(v6); /*0x11a6a7*/
                    splx(v9); /*0x11a6ad*/
                    goto LABEL_21; /*0x11a6b5*/
                  }
                  splx(v9); /*0x11a78a*/
                  v11 = splbio(); /*0x11a78f*/
                  *(_DWORD *)(*(_DWORD *)(v6 + 16) + 12) = *(_DWORD *)(v6 + 12); /*0x11a79c*/
                  *(_DWORD *)(*(_DWORD *)(v6 + 12) + 16) = *(_DWORD *)(v6 + 16); /*0x11a7a5*/
                  *(_BYTE *)v6 |= 8u; /*0x11a7a8*/
                  splx(v11); /*0x11a7ac*/
                  v12 = *(_DWORD *)v6; /*0x11a7b1*/
                  if ( (*(_DWORD *)v6 & 0x200) != 0 ) /*0x11a7bc*/
                  {
                    *(_DWORD *)v6 = v12 & 0xFFFFFDF8; /*0x11a7c6*/
                    if ( *(_DWORD *)(v6 + 20) > *(_DWORD *)(v6 + 24) ) /*0x11a7ce*/
                      panic(aBwrite); /*0x11a7d5*/
                    (*(void (__cdecl **)(int))(*(_DWORD *)(*(_DWORD *)(v6 + 64) + 28) + 84))(v6); /*0x11a7e7*/
                    if ( (v12 & 0x100) != 0 ) /*0x11a7f2*/
                    {
                      *(_BYTE *)v6 |= 0x80u; /*0x11a7f8*/
                    }
                    else
                    {
                      biowait(v6); /*0x11a6b9*/
                      brelse(v6); /*0x11a6bf*/
                    }
                    goto LABEL_21; /*0x11a7fb*/
                  }
                  *(_DWORD *)v6 = v12 | 0x10000; /*0x11a807*/
                  if ( (v12 & 0x40) != 0 ) /*0x11a80b*/
                    wakeup(v6); /*0x11a80e*/
                  v13 = bfreelist; /*0x11a816*/
                  if ( (bfreelist & 0x40) != 0 ) /*0x11a81d*/
                  {
                    LOBYTE(v13) = bfreelist & 0xBF; /*0x11a81f*/
                    bfreelist = v13; /*0x11a821*/
                    wakeup(&bfreelist); /*0x11a82b*/
                  }
                  if ( (*(_DWORD *)v6 & 0x400200) == 0x400000 ) /*0x11a841*/
                    *(_DWORD *)v6 |= 0x10000u; /*0x11a849*/
                  v14 = *(_DWORD *)v6; /*0x11a84b*/
                  if ( (*(_DWORD *)v6 & 4) != 0 ) /*0x11a84f*/
                  {
                    if ( (v14 & 0x20000) != 0 ) /*0x11a856*/
                    {
                      LOBYTE(v14) = v14 & 0xFB; /*0x11a858*/
                      *(_DWORD *)v6 = v14; /*0x11a85a*/
                    }
                    else
                    {
                      sub_11B26C(v6); /*0x11a861*/
                    }
                  }
                  v15 = splhigh(); /*0x11a86e*/
                  if ( *(int *)(v6 + 24) > 0 ) /*0x11a874*/
                  {
                    v16 = *(_DWORD *)v6; /*0x11a898*/
                    if ( (*(_DWORD *)v6 & 0x10004) != 0 ) /*0x11a89f*/
                    {
                      *(_DWORD *)(dword_1E87F4 + 16) = v6; /*0x11a8a6*/
                      *(_DWORD *)(v6 + 12) = dword_1E87F4; /*0x11a8af*/
                      dword_1E87F4 = v6; /*0x11a8b2*/
                      *(_DWORD *)(v6 + 16) = &unk_1E87E8; /*0x11a8b8*/
                    }
                    else
                    {
                      if ( (v16 & 0x20000) != 0 ) /*0x11a8c9*/
                      {
                        v17 = &bfreelist; /*0x11a8cb*/
                      }
                      else
                      {
                        v17 = (int *)&unk_1E87A4; /*0x11a8d4*/
                        if ( (v16 & 0x80u) != 0 ) /*0x11a8db*/
                          v17 = (int *)&unk_1E87E8; /*0x11a8dd*/
                      }
                      *(_DWORD *)(v17[4] + 12) = v6; /*0x11a8e5*/
                      *(_DWORD *)(v6 + 16) = v17[4]; /*0x11a8eb*/
                      v17[4] = v6; /*0x11a8ee*/
                      *(_DWORD *)(v6 + 12) = v17; /*0x11a8f1*/
                    }
                  }
                  else
                  {
                    *(_DWORD *)(dword_1E8838 + 16) = v6; /*0x11a87b*/
                    *(_DWORD *)(v6 + 12) = dword_1E8838; /*0x11a884*/
                    dword_1E8838 = v6; /*0x11a887*/
                    *(_DWORD *)(v6 + 16) = &unk_1E882C; /*0x11a88d*/
                  }
                  *(_DWORD *)v6 &= 0xFFBFFE37; /*0x11a8f4*/
                  splx(v15); /*0x11a8fb*/
                }
              }
            }
            v6 = *(_DWORD *)(v6 + 4); /*0x11a903*/
          }
          while ( v19 != (char *)v6 ); /*0x11a734*/
        }
      }
    }
    else if ( (v4 & 0x20000) != 0 ) /*0x11a663*/
    {
      panic(aBrealloc); /*0x11a66a*/
    }
    return allocbuf(a1, a2); /*0x11a90f*/
  }
}
