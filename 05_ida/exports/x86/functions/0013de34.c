/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13de34. */
int __cdecl dirlook(unsigned int a1, char *a2, unsigned int *a3)
{
  unsigned int v3; // kr04_4
  int result; // eax
  int v5; // eax
  unsigned int *v6; // ecx
  __int16 v7; // ax
  int v8; // eax
  unsigned int v9; // edi
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  __int16 v13; // ax
  unsigned int v14; // ebx
  __int16 v15; // ax
  int v16; // ebx
  __int16 v17; // ax
  size_t v18; // [esp+Ch] [ebp-14h]
  unsigned int v19; // [esp+10h] [ebp-10h]
  int v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]

  v22 = 0; /*0x13de40*/
  v21 = 0; /*0x13de47*/
  v3 = strlen(a2) + 1; /*0x13de59*/
  v18 = v3 - 1; /*0x13de60*/
  if ( (*(_WORD *)(a1 + 100) & 0xF000) != 0x4000 ) /*0x13de6f*/
    return 20; /*0x13de76*/
  result = iaccess(a1, 64); /*0x13de7f*/
  if ( !result ) /*0x13de8b*/
  {
    v5 = dnlc_lookup(a1 + 12, a2, 0); /*0x13de9b*/
    if ( v5 ) /*0x13dea5*/
    {
      ++*(_WORD *)(v5 + 6); /*0x13dea7*/
      v6 = a3; /*0x13deae*/
      *a3 = *(_DWORD *)(v5 + 48); /*0x13deb1*/
      while ( (*(_BYTE *)(*v6 + 68) & 1) != 0 ) /*0x13ded5*/
      {
        *(_BYTE *)(*v6 + 68) |= 0x10u; /*0x13deb8*/
        sleep(*a3); /*0x13dec4*/
        v6 = a3; /*0x13decc*/
      }
      *(_BYTE *)(*a3 + 68) |= 1u; /*0x13dedc*/
      return 0; /*0x13dee2*/
    }
    while ( 1 ) /*0x13def9*/
    {
      v7 = *(_WORD *)(a1 + 68); /*0x13def9*/
      if ( (v7 & 1) == 0 ) /*0x13deff*/
        break; /*0x13deff*/
      LOBYTE(v7) = v7 | 0x10; /*0x13dee8*/
      *(_WORD *)(a1 + 68) = v7; /*0x13deea*/
      sleep(a1); /*0x13def1*/
    }
    *(_BYTE *)(a1 + 68) |= 1u; /*0x13df01*/
    if ( *(_DWORD *)(a1 + 76) > *(_DWORD *)(a1 + 108) ) /*0x13df0b*/
      *(_DWORD *)(a1 + 76) = 0; /*0x13df0d*/
    v8 = *(_DWORD *)(a1 + 76); /*0x13df14*/
    if ( !v8 ) /*0x13df19*/
    {
      v9 = 0; /*0x13df1b*/
      v20 = 1; /*0x13df1d*/
LABEL_18:
      v19 = (*(_DWORD *)(a1 + 108) + 1023) & 0xFFFFFC00; /*0x13df57*/
      while ( 1 ) /*0x13e118*/
      {
        while ( v19 <= v9 ) /*0x13e118*/
        {
          if ( v20 != 2 ) /*0x13e122*/
          {
            v16 = 2; /*0x13e150*/
            goto LABEL_53; /*0x13e150*/
          }
          v20 = 1; /*0x13e124*/
          v9 = 0; /*0x13e12b*/
          v19 = *(_DWORD *)(a1 + 76); /*0x13e130*/
        }
        if ( (v9 & ~*(_DWORD *)(*(_DWORD *)(a1 + 80) + 72)) == 0 ) /*0x13df76*/
        {
          if ( v22 ) /*0x13df7c*/
          {
            byte_swap_dir_block_out(v22); /*0x13df82*/
            brelse(v22); /*0x13df8b*/
          }
          v22 = blkatoff(a1, v9, 0); /*0x13df9c*/
          if ( !v22 ) /*0x13dfa4*/
            goto LABEL_50; /*0x13dfa4*/
          v21 = 0; /*0x13dfaa*/
        }
        v10 = *(_DWORD *)(v22 + 32) + v21; /*0x13dfb7*/
        if ( !*(_WORD *)(v10 + 4) || dirchk && sub_13F52C(a1, v10, v21, v9) ) /*0x13dfd1*/
        {
          v11 = 1024 - (v21 & 0x3FF); /*0x13dfec*/
        }
        else
        {
          if ( *(_DWORD *)v10 /*0x13e021*/
            && v18 == *(unsigned __int16 *)(v10 + 6)
            && *a2 == *(_BYTE *)(v10 + 8)
            && !bcmp(a2, (const void *)(v10 + 8), v18) )
          {
            v12 = *(_DWORD *)v10; /*0x13e031*/
            byte_swap_dir_block_out(v22); /*0x13e037*/
            brelse(v22); /*0x13e040*/
            v22 = 0; /*0x13e045*/
            *(_DWORD *)(a1 + 76) = v9; /*0x13e04c*/
            if ( v3 == 3 && *a2 == 46 && a2[1] == 46 ) /*0x13e064*/
            {
              v13 = *(_WORD *)(a1 + 68); /*0x13e066*/
              *(_WORD *)(a1 + 68) = v13 & 0xFFFE; /*0x13e06f*/
              if ( (v13 & 0x10) != 0 ) /*0x13e075*/
              {
                LOBYTE(v13) = v13 & 0xEE; /*0x13e077*/
                *(_WORD *)(a1 + 68) = v13; /*0x13e079*/
                wakeup(a1); /*0x13e07e*/
              }
              v14 = iget(*(_WORD *)(a1 + 70), *(_DWORD *)(a1 + 80), v12); /*0x13e095*/
              if ( !v14 ) /*0x13e09c*/
                goto LABEL_51; /*0x13e09c*/
LABEL_44:
              *a3 = v14; /*0x13e0ec*/
              dnlc_enter(a1 + 12, a2, v14 + 12, nullptr); /*0x13e0ff*/
              return 0; /*0x13e106*/
            }
            if ( *(_DWORD *)(a1 + 72) == v12 ) /*0x13e0a7*/
            {
              ++*(_WORD *)(a1 + 18); /*0x13e0a9*/
              v14 = a1; /*0x13e0ad*/
              goto LABEL_44; /*0x13e0af*/
            }
            v14 = iget(*(_WORD *)(a1 + 70), *(_DWORD *)(a1 + 80), v12); /*0x13e0c3*/
            v15 = *(_WORD *)(a1 + 68); /*0x13e0c5*/
            *(_WORD *)(a1 + 68) = v15 & 0xFFFE; /*0x13e0ce*/
            if ( (v15 & 0x10) != 0 ) /*0x13e0d7*/
            {
              LOBYTE(v15) = v15 & 0xEE; /*0x13e0d9*/
              *(_WORD *)(a1 + 68) = v15; /*0x13e0db*/
              wakeup(a1); /*0x13e0e0*/
            }
            if ( v14 ) /*0x13e0ea*/
              goto LABEL_44; /*0x13e0ea*/
LABEL_51:
            v16 = *(char *)(dword_1E875C + 104); /*0x13e144*/
            goto LABEL_55; /*0x13e14d*/
          }
          v11 = *(unsigned __int16 *)(v10 + 4); /*0x13e10c*/
        }
        v9 += v11; /*0x13e110*/
        v21 += v11; /*0x13e112*/
      }
    }
    v9 = *(_DWORD *)(a1 + 76); /*0x13df28*/
    v21 = v8 & ~*(_DWORD *)(*(_DWORD *)(a1 + 80) + 72); /*0x13df34*/
    if ( !v21 || (v22 = blkatoff(a1, v9, 0)) != 0 ) /*0x13df4a*/
    {
      v20 = 2; /*0x13df50*/
      goto LABEL_18; /*0x13df50*/
    }
LABEL_50:
    v16 = *(char *)(dword_1E875C + 104); /*0x13e138*/
LABEL_53:
    v17 = *(_WORD *)(a1 + 68); /*0x13e155*/
    *(_WORD *)(a1 + 68) = v17 & 0xFFFE; /*0x13e15e*/
    if ( (v17 & 0x10) != 0 ) /*0x13e164*/
    {
      LOBYTE(v17) = v17 & 0xEE; /*0x13e166*/
      *(_WORD *)(a1 + 68) = v17; /*0x13e168*/
      wakeup(a1); /*0x13e16d*/
    }
LABEL_55:
    if ( v22 ) /*0x13e179*/
    {
      byte_swap_dir_block_out(v22); /*0x13e17f*/
      brelse(v22); /*0x13e188*/
    }
    return v16; /*0x13e18d*/
  }
  return result; /*0x13e192*/
}
