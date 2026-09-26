/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e218. */
int __cdecl set_thread_state(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int v4; // eax
  _BOOL4 v5; // ecx
  int v6; // eax
  _BOOL4 v7; // ecx
  int v8; // eax
  _BOOL4 v9; // ecx
  int v10; // eax
  _BOOL4 v11; // ecx
  int v12; // eax
  _DWORD *v13; // eax
  int v15; // eax
  int v16; // edx
  int v17; // edx
  int v18; // edi

  if ( a3 <= 0xF ) /*0x18e225*/
    return 4; /*0x18e225*/
  if ( (*(_BYTE *)(a2 + 38) & 2) == 0 ) /*0x18e232*/
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 12) + 76) ) /*0x18e243*/
    {
      v13 = **(_DWORD ***)(a1 + 40); /*0x18e3c3*/
      if ( *(int (**)())(a1 + 52) == thread_bootstrap_return ) /*0x18e3cc*/
      {
        v13[10] = *(_DWORD *)a2; /*0x18e3da*/
        v13[13] = *(_DWORD *)(a2 + 4); /*0x18e3e0*/
        v13[11] = *(_DWORD *)(a2 + 8); /*0x18e3e6*/
        v13[12] = *(_DWORD *)(a2 + 12); /*0x18e3ec*/
        v13[17] = *(_DWORD *)(a2 + 16); /*0x18e3f2*/
        v13[16] = *(_DWORD *)(a2 + 20); /*0x18e3f8*/
        thread_start(a1, *(_DWORD *)(a2 + 40)); /*0x18e400*/
        return 0; /*0x18e405*/
      }
    }
    else
    {
      v3 = *(_DWORD *)(a2 + 44); /*0x18e24d*/
      if ( v3 ) /*0x18e254*/
      {
        if ( (v3 & 4) != 0 ) /*0x18e25d*/
        {
          if ( (v3 & 3) != 3 ) /*0x18e265*/
            return 4; /*0x18e265*/
        }
        else if ( (unsigned __int16)((unsigned __int16)v3 >> 3) > 0x1Fu /*0x18e29b*/
               || (v3 & 3) != 3
               || (*((_BYTE *)gdt + 8 * ((unsigned __int16)v3 >> 3) + 5) & 0x60) != 0x60 )
        {
          return 4; /*0x18e29b*/
        }
        v4 = *(_DWORD *)(a2 + 48); /*0x18e2a1*/
        if ( !v4 || (v4 & 4) != 0 ) /*0x18e2af*/
          goto LABEL_50; /*0x18e2af*/
        v5 = 0; /*0x18e2ba*/
        if ( (unsigned __int16)((unsigned __int16)v4 >> 3) <= 0x1Fu ) /*0x18e2bf*/
          v5 = (*((_BYTE *)gdt + 8 * ((unsigned __int16)v4 >> 3) + 5) & 0x60) == 96; /*0x18e2d0*/
        if ( v5 ) /*0x18e2d3*/
        {
LABEL_50:
          v6 = *(_DWORD *)(a2 + 52); /*0x18e2d9*/
          if ( !v6 || (v6 & 4) != 0 ) /*0x18e2e7*/
            goto LABEL_51; /*0x18e2e7*/
          v7 = 0; /*0x18e2f2*/
          if ( (unsigned __int16)((unsigned __int16)v6 >> 3) <= 0x1Fu ) /*0x18e2f7*/
            v7 = (*((_BYTE *)gdt + 8 * ((unsigned __int16)v6 >> 3) + 5) & 0x60) == 96; /*0x18e308*/
          if ( v7 ) /*0x18e30b*/
          {
LABEL_51:
            v8 = *(_DWORD *)(a2 + 56); /*0x18e311*/
            if ( !v8 || (v8 & 4) != 0 ) /*0x18e31f*/
              goto LABEL_52; /*0x18e31f*/
            v9 = 0; /*0x18e32a*/
            if ( (unsigned __int16)((unsigned __int16)v8 >> 3) <= 0x1Fu ) /*0x18e32f*/
              v9 = (*((_BYTE *)gdt + 8 * ((unsigned __int16)v8 >> 3) + 5) & 0x60) == 96; /*0x18e340*/
            if ( v9 ) /*0x18e343*/
            {
LABEL_52:
              v10 = *(_DWORD *)(a2 + 60); /*0x18e349*/
              if ( !v10 || (v10 & 4) != 0 ) /*0x18e357*/
                goto LABEL_53; /*0x18e357*/
              v11 = 0; /*0x18e362*/
              if ( (unsigned __int16)((unsigned __int16)v10 >> 3) <= 0x1Fu ) /*0x18e367*/
                v11 = (*((_BYTE *)gdt + 8 * ((unsigned __int16)v10 >> 3) + 5) & 0x60) == 96; /*0x18e378*/
              if ( v11 ) /*0x18e37b*/
              {
LABEL_53:
                v12 = *(_DWORD *)(a2 + 32); /*0x18e37d*/
                if ( v12 ) /*0x18e386*/
                {
                  if ( (v12 & 4) != 0 ) /*0x18e38b*/
                  {
                    if ( (v12 & 3) == 3 ) /*0x18e393*/
                      goto LABEL_43; /*0x18e393*/
                  }
                  else if ( (unsigned __int16)((unsigned __int16)v12 >> 3) <= 0x1Fu /*0x18e3bb*/
                         && (v12 & 3) == 3
                         && (*((_BYTE *)gdt + 8 * ((unsigned __int16)v12 >> 3) + 5) & 0x60) == 0x60 )
                  {
LABEL_43:
                    v15 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112); /*0x18e40c*/
                    if ( v15 ) /*0x18e414*/
                    {
                      v16 = v15 + 132; /*0x18e416*/
                    }
                    else
                    {
                      v17 = kalloc(0xE0u); /*0x18e42a*/
                      *(_DWORD *)(*(_DWORD *)(a1 + 40) + 112) = v17; /*0x18e42f*/
                      qmemcpy((void *)(v17 + 132), &unk_1D15E0, 0x5Cu); /*0x18e445*/
                      *(_DWORD *)(v17 + 196) = 512; /*0x18e447*/
                      *(_WORD *)(v17 + 192) = 99; /*0x18e451*/
                      *(_WORD *)(v17 + 204) = 107; /*0x18e45a*/
                      *(_WORD *)(v17 + 144) = 107; /*0x18e463*/
                      *(_WORD *)(v17 + 140) = 107; /*0x18e46c*/
                      *(_WORD *)(v17 + 136) = 0; /*0x18e475*/
                      *(_WORD *)(v17 + 132) = 0; /*0x18e47e*/
                      v16 = v17 + 132; /*0x18e487*/
                    }
                    *(_DWORD *)(v16 + 44) = *(_DWORD *)a2; /*0x18e48b*/
                    *(_DWORD *)(v16 + 32) = *(_DWORD *)(a2 + 4); /*0x18e491*/
                    *(_DWORD *)(v16 + 40) = *(_DWORD *)(a2 + 8); /*0x18e497*/
                    *(_DWORD *)(v16 + 36) = *(_DWORD *)(a2 + 12); /*0x18e49d*/
                    *(_DWORD *)(v16 + 16) = *(_DWORD *)(a2 + 16); /*0x18e4a3*/
                    *(_DWORD *)(v16 + 20) = *(_DWORD *)(a2 + 20); /*0x18e4a9*/
                    *(_DWORD *)(v16 + 24) = *(_DWORD *)(a2 + 24); /*0x18e4af*/
                    *(_DWORD *)(v16 + 68) = *(_DWORD *)(a2 + 28); /*0x18e4b5*/
                    *(_WORD *)(v16 + 72) = *(_WORD *)(a2 + 32); /*0x18e4bc*/
                    v18 = *(_DWORD *)(a2 + 36); /*0x18e4c0*/
                    *(_DWORD *)(v16 + 64) = v18; /*0x18e4c3*/
                    *(_DWORD *)(v16 + 64) = v18 & 0x50DD5 | 0x202; /*0x18e4d2*/
                    *(_DWORD *)(v16 + 56) = *(_DWORD *)(a2 + 40); /*0x18e4d8*/
                    *(_WORD *)(v16 + 60) = *(_WORD *)(a2 + 44); /*0x18e4df*/
                    *(_WORD *)(v16 + 12) = *(_WORD *)(a2 + 48); /*0x18e4e7*/
                    *(_WORD *)(v16 + 8) = *(_WORD *)(a2 + 52); /*0x18e4ef*/
                    *(_WORD *)(v16 + 4) = *(_WORD *)(a2 + 56); /*0x18e4f7*/
                    *(_WORD *)v16 = *(_WORD *)(a2 + 60); /*0x18e4ff*/
                    return 0; /*0x18e4ff*/
                  }
                }
              }
            }
          }
        }
      }
    }
    return 4; /*0x18e3d3*/
  }
  sub_18E510(a1, a2); /*0x18e236*/
  return 0; /*0x18e507*/
}
