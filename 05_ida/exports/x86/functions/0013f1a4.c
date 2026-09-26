/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f1a4. */
int __cdecl dirremove(unsigned int a1, char *a2, int a3, int a4)
{
  unsigned int v4; // eax
  size_t v5; // ebx
  __int16 v7; // ax
  int v8; // edi
  __int16 v9; // dx
  int v10; // edx
  char v11; // al
  __int16 v12; // bx
  int *v13; // ebx
  __int16 v14; // ax
  int v15; // [esp+Ch] [ebp-18h] BYREF
  int v16; // [esp+10h] [ebp-14h] BYREF
  int v17; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  int *v19; // [esp+1Ch] [ebp-8h]
  int v20; // [esp+20h] [ebp-4h]

  v4 = strlen(a2) + 1; /*0x13f1bb*/
  v5 = v4 - 1; /*0x13f1c1*/
  if ( v4 == 1 ) /*0x13f1c6*/
    panic(aDirremove); /*0x13f1cd*/
  if ( *a2 != 46 ) /*0x13f1db*/
    goto LABEL_9; /*0x13f1db*/
  if ( v4 == 2 ) /*0x13f1e0*/
    return 22; /*0x13f1e7*/
  if ( v4 == 3 && a2[1] == 46 ) /*0x13f1f8*/
    return 66; /*0x13f1fa*/
LABEL_9:
  v15 = 0; /*0x13f204*/
  v19 = nullptr; /*0x13f20b*/
  while ( 1 ) /*0x13f225*/
  {
    v7 = *(_WORD *)(a1 + 68); /*0x13f225*/
    if ( (v7 & 1) == 0 ) /*0x13f22b*/
      break; /*0x13f22b*/
    LOBYTE(v7) = v7 | 0x10; /*0x13f214*/
    *(_WORD *)(a1 + 68) = v7; /*0x13f216*/
    sleep(a1); /*0x13f21d*/
  }
  *(_BYTE *)(a1 + 68) |= 1u; /*0x13f22d*/
  if ( (*(_WORD *)(a1 + 100) & 0xF000) == 0x4000 ) /*0x13f23d*/
  {
    v8 = iaccess(a1, 192); /*0x13f257*/
    if ( !v8 ) /*0x13f25e*/
    {
      v16 = 2; /*0x13f264*/
      v8 = sub_13E5C8(a1, a2, v5, &v16, &v15); /*0x13f27e*/
      if ( !v8 ) /*0x13f285*/
      {
        if ( v15 && (!a3 || a3 == v15) ) /*0x13f29b*/
        {
          if ( (*(_BYTE *)(a1 + 101) & 2) == 0 /*0x13f2cc*/
            || (v9 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2)) == 0
            || *(_WORD *)(a1 + 104) == v9
            || *(_WORD *)(v15 + 104) == v9 )
          {
            if ( *(_DWORD *)(v15 + 24) ) /*0x13f2db*/
            {
              v8 = 16; /*0x13f2e1*/
            }
            else if ( !a4 /*0x13f30c*/
                   || (*(_WORD *)(v15 + 100) & 0xF000) != 0x4000
                   || *(_WORD *)(v15 + 102) == 2 && sub_13F5E4(v15, *(_DWORD *)(a1 + 72)) )
            {
              dnlc_remove(a1 + 12, a2); /*0x13f32c*/
              if ( (v17 & 0x3FF) != 0 ) /*0x13f33e*/
                *(_WORD *)(v20 - v18 + 4) += *(_WORD *)(v20 + 4); /*0x13f351*/
              else
                *(_DWORD *)v20 = 0; /*0x13f340*/
              byte_swap_dir_block_out(v19); /*0x13f359*/
              bwrite(v19); /*0x13f362*/
              v19 = nullptr; /*0x13f367*/
              *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13f36e*/
              v10 = v15; /*0x13f372*/
              *(_BYTE *)(v15 + 68) |= 0x40u; /*0x13f375*/
              v11 = *(_BYTE *)(dword_1E875C + 104); /*0x13f381*/
              if ( v11 ) /*0x13f386*/
              {
                v8 = v11; /*0x13f388*/
              }
              else
              {
                v12 = *(_WORD *)(v10 + 102); /*0x13f390*/
                if ( v12 > 0 ) /*0x13f397*/
                {
                  if ( a4 && (*(_WORD *)(v10 + 100) & 0xF000) == 0x4000 ) /*0x13f3ab*/
                  {
                    *(_WORD *)(v10 + 102) = v12 - 2; /*0x13f3b1*/
                    --*(_WORD *)(a1 + 102); /*0x13f3b5*/
                    dnlc_remove(v10 + 12, asc_1DDEE4); /*0x13f3c2*/
                    dnlc_remove(v15 + 12, asc_1DDEE6); /*0x13f3d3*/
                    itrunc(v15, 0); /*0x13f3de*/
                  }
                  else
                  {
                    --*(_WORD *)(v15 + 102); /*0x13f3eb*/
                  }
                }
              }
            }
            else
            {
              v8 = 66; /*0x13f318*/
            }
          }
          else
          {
            v8 = 1; /*0x13f2ce*/
          }
        }
        else
        {
          v8 = 2; /*0x13f29d*/
        }
      }
    }
  }
  else
  {
    v8 = 20; /*0x13f23f*/
  }
  if ( v15 ) /*0x13f3f4*/
  {
    iput(v15); /*0x13f3f7*/
    if ( !*(_WORD *)(v15 + 102) ) /*0x13f402*/
      vnode_uncache(v15 + 12); /*0x13f40d*/
  }
  v13 = v19; /*0x13f415*/
  if ( v19 ) /*0x13f41a*/
  {
    byte_swap_dir_block_out(v19); /*0x13f41d*/
    brelse((int)v13); /*0x13f423*/
  }
  v14 = *(_WORD *)(a1 + 68); /*0x13f42b*/
  *(_WORD *)(a1 + 68) = v14 & 0xFFFE; /*0x13f434*/
  if ( (v14 & 0x10) != 0 ) /*0x13f43a*/
  {
    LOBYTE(v14) = v14 & 0xEE; /*0x13f43c*/
    *(_WORD *)(a1 + 68) = v14; /*0x13f43e*/
    wakeup(a1); /*0x13f443*/
  }
  return v8; /*0x13f44d*/
}
