/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f66c. */
int __cdecl sub_13F66C(int a1, unsigned int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // edi
  _DWORD *v5; // ebx
  int v6; // edi
  int v7; // ebx
  int *v8; // eax
  int v9; // ebx
  __int16 v10; // ax
  __int16 v11; // ax
  int v13; // [esp+0h] [ebp-1Ch]
  _DWORD *v14; // [esp+4h] [ebp-18h]
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int *v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]

  v17 = 0; /*0x13f675*/
  while ( (byte_1DDF38 & 1) != 0 ) /*0x13f69f*/
  {
    byte_1DDF38 |= 2u; /*0x13f682*/
    sleep((unsigned int)&byte_1DDF38); /*0x13f68f*/
  }
  byte_1DDF38 = 1; /*0x13f6a1*/
  v2 = a2; /*0x13f6a8*/
  v3 = *(_DWORD *)(a2 + 72); /*0x13f6ab*/
  if ( *(_DWORD *)(a1 + 72) == v3 )
  {
    v17 = 22; /*0x13f6b6*/
  }
  else if ( v3 != 2 )
  {
    v4 = 0; /*0x13f6d9*/
    while ( 1 )
    {
      if ( (*(_WORD *)(v2 + 100) & 0xF000) != 0x4000
        || !*(_WORD *)(v2 + 102)
        || (v15 = *(_DWORD *)(v2 + 108), v15 <= 0x17) )
      {
        printf(
          "%s: bad dir ino %d at offset %d: %s\n",
          (const char *)(*(_DWORD *)(v2 + 80) + 212),
          *(_DWORD *)(v2 + 72),
          0,
          aBadSizeUnlinke);
LABEL_27:
        v17 = 20; /*0x13f7ee*/
        goto LABEL_36; /*0x13f7f8*/
      }
      v5 = *(_DWORD **)(v2 + 80); /*0x13f70c*/
      if ( v15 < 1 << v5[20] ) /*0x13f71c*/
        v6 = v5[19] & (v5[13] + (v15 & ~v5[18]) - 1); /*0x13f732*/
      else
        v6 = v5[12]; /*0x13f71e*/
      v7 = bmap(v2, 0, 1, v13, v14) << v5[25]; /*0x13f744*/
      if ( v7 < 0 ) /*0x13f74b*/
      {
        sub_13F5AC(v2, aNonexixtentDir, 0); /*0x13f755*/
        *(_BYTE *)(dword_1E875C + 104) = 2; /*0x13f75f*/
      }
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x13f76b*/
        break; /*0x13f76b*/
      v8 = bread(*(_DWORD *)(v2 + 64), v7, v6); /*0x13f77e*/
      if ( (*(_BYTE *)v8 & 4) != 0 ) /*0x13f789*/
      {
        brelse((int)v8); /*0x13f78c*/
        v4 = 0; /*0x13f791*/
      }
      else
      {
        v16 = v8; /*0x13f7a0*/
        byte_swap_dir_block_in(v8[8], v8[5]); /*0x13f7a3*/
        v18 = v16[8]; /*0x13f7b1*/
        v4 = (int)v16; /*0x13f7b4*/
      }
      if ( !v4 ) /*0x13f7b8*/
        goto LABEL_35; /*0x13f7b8*/
      if ( *(_WORD *)(v18 + 18) != 2 || *(_WORD *)(v18 + 20) != 11822 )
      {
        printf(
          "%s: bad dir ino %d at offset %d: %s\n",
          (const char *)(*(_DWORD *)(v2 + 80) + 212),
          *(_DWORD *)(v2 + 72),
          0,
          aMangledEntry_1);
        goto LABEL_27; /*0x13f7e9*/
      }
      v9 = *(_DWORD *)(v18 + 12); /*0x13f800*/
      if ( *(_DWORD *)(a1 + 72) == v9 ) /*0x13f809*/
      {
        v17 = 22; /*0x13f6c4*/
        goto LABEL_36; /*0x13f6cb*/
      }
      if ( v9 == 2 ) /*0x13f812*/
        goto LABEL_36; /*0x13f812*/
      byte_swap_dir_block_out(v4); /*0x13f815*/
      brelse(v4); /*0x13f81b*/
      v4 = 0; /*0x13f820*/
      if ( a2 == v2 ) /*0x13f828*/
      {
        v10 = *(_WORD *)(a2 + 68); /*0x13f837*/
        *(_WORD *)(a2 + 68) = v10 & 0xFFFE; /*0x13f840*/
        if ( (v10 & 0x10) != 0 ) /*0x13f846*/
        {
          LOBYTE(v10) = v10 & 0xEE; /*0x13f848*/
          *(_WORD *)(a2 + 68) = v10; /*0x13f84a*/
          wakeup(a2); /*0x13f84f*/
        }
      }
      else
      {
        iput(v2); /*0x13f82b*/
      }
      v2 = iget(*(_WORD *)(v2 + 70), *(_DWORD *)(v2 + 80), v9); /*0x13f866*/
      if ( !v2 ) /*0x13f86d*/
        goto LABEL_35; /*0x13f86d*/
    }
    v4 = 0; /*0x13f771*/
LABEL_35:
    v17 = *(char *)(dword_1E875C + 104); /*0x13f873*/
LABEL_36:
    if ( v4 ) /*0x13f881*/
    {
      byte_swap_dir_block_out(v4); /*0x13f884*/
      brelse(v4); /*0x13f88a*/
    }
  }
  if ( (byte_1DDF38 & 2) != 0 ) /*0x13f899*/
    wakeup((int)&byte_1DDF38); /*0x13f8a0*/
  byte_1DDF38 = 0; /*0x13f8a8*/
  if ( v2 ) /*0x13f8b1*/
  {
    if ( a2 != v2 ) /*0x13f8b6*/
    {
      iput(v2); /*0x13f8b9*/
      while ( 1 ) /*0x13f8db*/
      {
        v11 = *(_WORD *)(a2 + 68); /*0x13f8db*/
        if ( (v11 & 1) == 0 ) /*0x13f8e1*/
          break; /*0x13f8e1*/
        LOBYTE(v11) = v11 | 0x10; /*0x13f8c4*/
        *(_WORD *)(a2 + 68) = v11; /*0x13f8c9*/
        sleep(a2); /*0x13f8d0*/
      }
      *(_BYTE *)(a2 + 68) |= 1u; /*0x13f8e6*/
      if ( !v17 && !*(_WORD *)(a2 + 102) ) /*0x13f8f0*/
        return 2; /*0x13f8f7*/
    }
  }
  return v17; /*0x13f904*/
}
