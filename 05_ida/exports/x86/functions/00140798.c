/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140798. */
unsigned int __cdecl iget(__int16 a1, _DWORD *a2, unsigned int a3)
{
  int *v3; // edi
  unsigned int v4; // ebx
  __int16 v5; // si
  int v6; // esi
  __int16 v7; // ax
  int v9; // ebx
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  int v12; // esi
  int *v13; // eax
  int v14; // esi
  __int16 v15; // si
  _DWORD *v16; // [esp+1Ch] [ebp-8h]

  while ( 1 ) /*0x140800*/
  {
    while ( 1 ) /*0x1407b3*/
    {
      v16 = (_DWORD *)getmp(a1); /*0x1407b3*/
      if ( !v16 ) /*0x1407bb*/
        panic(aIgetBadDev); /*0x1407c2*/
      if ( *(_DWORD **)(v16[3] + 32) != a2 ) /*0x1407d6*/
        panic(aIgetBadFs); /*0x1407dd*/
      v3 = &ihead[2 * ((a1 + (_WORD)a3) & 0x1FF)]; /*0x1407f2*/
      v4 = *v3; /*0x1407f8*/
      if ( (int *)*v3 == v3 ) /*0x140800*/
        break; /*0x140800*/
      while ( *(_DWORD *)(v4 + 72) != a3 || *(_WORD *)(v4 + 70) != a1 ) /*0x14081c*/
      {
        v4 = *(_DWORD *)v4; /*0x1408a4*/
        if ( (int *)v4 == v3 ) /*0x1408a8*/
          goto LABEL_18; /*0x1408a8*/
      }
      v5 = *(_WORD *)(v4 + 68); /*0x140822*/
      if ( (v5 & 1) == 0 ) /*0x14082c*/
      {
        if ( (*(_WORD *)(v4 + 68) & 0x100) == 0 ) /*0x140838*/
        {
          v6 = *(_DWORD *)(v4 + 92); /*0x14083a*/
          if ( v6 ) /*0x14083f*/
            *(_DWORD *)(v6 + 96) = *(_DWORD *)(v4 + 96); /*0x140844*/
          else
            ifreet = *(_DWORD *)(v4 + 96); /*0x14084f*/
          **(_DWORD **)(v4 + 96) = v6; /*0x140857*/
          *(_DWORD *)(v4 + 92) = 0; /*0x140859*/
          *(_DWORD *)(v4 + 96) = 0; /*0x140860*/
          **(_DWORD **)(v4 + 12) = 0; /*0x14086a*/
        }
        v7 = *(_WORD *)(v4 + 68); /*0x140870*/
        HIBYTE(v7) |= 1u; /*0x140874*/
        *(_WORD *)(v4 + 68) = v7; /*0x140877*/
        if ( (v7 & 1) != 0 ) /*0x14087d*/
        {
          do /*0x140893*/
          {
            *(_BYTE *)(v4 + 68) |= 0x10u; /*0x140880*/
            sleep(v4); /*0x140887*/
          }
          while ( (*(_BYTE *)(v4 + 68) & 1) != 0 ); /*0x140893*/
        }
        *(_BYTE *)(v4 + 68) |= 1u; /*0x140895*/
        ++*(_WORD *)(v4 + 18); /*0x140899*/
        return v4; /*0x14089f*/
      }
      *(_WORD *)(v4 + 68) = v5 | 0x10; /*0x14095c*/
      sleep(v4); /*0x140963*/
    }
LABEL_18:
    v9 = ifreeh; /*0x1408ae*/
    if ( ifreeh ) /*0x1408b6*/
      break; /*0x1408b6*/
    v10 = (_DWORD *)zalloc(inode_zone); /*0x1408c3*/
    v11 = v10; /*0x1408c8*/
    if ( v10 ) /*0x1408cf*/
    {
      bzero(v10, 0xE8u); /*0x1408d7*/
      *v11 = v11; /*0x1408dc*/
      v11[1] = v11; /*0x1408de*/
      v11[23] = 0; /*0x1408e1*/
      v11[24] = 0; /*0x1408e8*/
      v11[15] = v11; /*0x1408ef*/
      v11[10] = &ufs_vnodeops; /*0x1408f2*/
      v11[3] = 0; /*0x1408f9*/
      vm_info_init(v11 + 3); /*0x140904*/
      *(_BYTE *)(v11[3] + 56) &= ~4u; /*0x14090c*/
      v11[2] = inode_list; /*0x140916*/
      inode_list = (int)v11; /*0x140919*/
      v9 = (int)v11; /*0x14091f*/
    }
    if ( v9 ) /*0x140926*/
    {
      *(_DWORD *)(v9 + 92) = ifreeh; /*0x140976*/
      break; /*0x140976*/
    }
    while ( !ifreeh && dnlc_purge1() == 1 ) /*0x140939*/
      ; /*0x140928*/
    if ( !ifreeh ) /*0x140943*/
      panic(aIgetOutOfInode); /*0x14094e*/
  }
  v12 = *(_DWORD *)(v9 + 92); /*0x140979*/
  if ( v12 ) /*0x14097e*/
    *(_DWORD *)(v12 + 96) = &ifreeh; /*0x140980*/
  ifreeh = v12; /*0x140987*/
  *(_DWORD *)(v9 + 92) = 0; /*0x14098d*/
  *(_DWORD *)(v9 + 96) = 0; /*0x140994*/
  mfs_uncache((int *)(v9 + 12)); /*0x14099f*/
  *(_WORD *)(v9 + 68) = 256; /*0x1409a4*/
  *(_BYTE *)(v9 + 68) |= 1u; /*0x1409ad*/
  if ( *(_WORD *)(v9 + 18) ) /*0x1409b1*/
    panic(aFreeInodeIsnT_0); /*0x1409bd*/
  *(_DWORD *)(*(_DWORD *)v9 + 4) = *(_DWORD *)(v9 + 4); /*0x1409ca*/
  **(_DWORD **)(v9 + 4) = *(_DWORD *)v9; /*0x1409d2*/
  *(_DWORD *)v9 = *v3; /*0x1409d6*/
  *(_DWORD *)(v9 + 4) = v3; /*0x1409d8*/
  *(_DWORD *)(*v3 + 4) = v9; /*0x1409dd*/
  *v3 = v9; /*0x1409e0*/
  *(_WORD *)(v9 + 70) = a1; /*0x1409e6*/
  *(_DWORD *)(v9 + 64) = v16[2]; /*0x1409f0*/
  *(_DWORD *)(v9 + 72) = a3; /*0x1409f6*/
  *(_DWORD *)(v9 + 76) = 0; /*0x1409f9*/
  *(_DWORD *)(v9 + 80) = a2; /*0x140a03*/
  *(_DWORD *)(v9 + 88) = 0; /*0x140a06*/
  v13 = bread( /*0x140a6e*/
          *(_DWORD *)(v9 + 64),
          (((a3 % a2[46] / a2[30]) << a2[24]) + a2[4] + a2[6] * (~a2[7] & (a3 / a2[46])) + a3 / a2[46] * a2[47]) << a2[25],
          a2[12]);
  v14 = (int)v13; /*0x140a73*/
  if ( (*(_BYTE *)v13 & 4) != 0 ) /*0x140a7b*/
  {
    brelse((int)v13); /*0x140a82*/
    *(_DWORD *)(*(_DWORD *)v9 + 4) = *(_DWORD *)(v9 + 4); /*0x140a8f*/
    **(_DWORD **)(v9 + 4) = *(_DWORD *)v9; /*0x140a97*/
    *(_DWORD *)v9 = v9; /*0x140a99*/
    *(_DWORD *)(v9 + 4) = v9; /*0x140a9b*/
    *(_DWORD *)(v9 + 72) = 0; /*0x140a9e*/
    *(_WORD *)(v9 + 18) = 0; /*0x140aa5*/
    v15 = *(_WORD *)(v9 + 68); /*0x140aab*/
    *(_WORD *)(v9 + 68) = v15 & 0xFFFE; /*0x140ab4*/
    if ( (v15 & 0x10) != 0 ) /*0x140abe*/
    {
      *(_WORD *)(v9 + 68) = v15 & 0xFFEE; /*0x140ac5*/
      wakeup(v9); /*0x140aca*/
    }
    *(_WORD *)(v9 + 68) = 0; /*0x140acf*/
    if ( ifreeh ) /*0x140adc*/
    {
      *(_DWORD *)ifreet = v9; /*0x140ae3*/
      *(_DWORD *)(v9 + 96) = ifreet; /*0x140aeb*/
    }
    else
    {
      ifreeh = v9; /*0x140af0*/
      *(_DWORD *)(v9 + 96) = &ifreeh; /*0x140af6*/
    }
    *(_DWORD *)(v9 + 92) = 0; /*0x140afd*/
    ifreet = v9 + 92; /*0x140b07*/
    return 0; /*0x140b0d*/
  }
  else
  {
    byte_swap_inode_in(v13[8] + ((a3 % a2[30]) << 7), v9); /*0x140b29*/
    *(_WORD *)(v9 + 16) = 0; /*0x140b2e*/
    *(_WORD *)(v9 + 18) = 1; /*0x140b34*/
    *(_WORD *)(v9 + 22) = 0; /*0x140b3a*/
    *(_WORD *)(v9 + 20) = 0; /*0x140b40*/
    *(_DWORD *)(v9 + 48) = *v16; /*0x140b4b*/
    *(_DWORD *)(v9 + 52) = iftovt_tab[*(_WORD *)(v9 + 100) >> 13]; /*0x140b60*/
    *(_WORD *)(v9 + 56) = *(_WORD *)(v9 + 140); /*0x140b6a*/
    *(_DWORD *)(v9 + 44) = 0; /*0x140b6e*/
    *(_DWORD *)(v9 + 36) = 0; /*0x140b75*/
    *(_DWORD *)(v9 + 32) = 0; /*0x140b7c*/
    if ( a3 == 2 ) /*0x140b8a*/
      *(_BYTE *)(v9 + 16) |= 1u; /*0x140b8c*/
    if ( *(_WORD *)(*(_DWORD *)(v9 + 48) + 292) ) /*0x140b93*/
    {
      *(_WORD *)(v9 + 228) = *(_WORD *)(v9 + 104); /*0x140ba1*/
      *(_WORD *)(v9 + 230) = *(_WORD *)(v9 + 106); /*0x140bac*/
      *(_WORD *)(v9 + 104) = *(_WORD *)(*(_DWORD *)(v9 + 48) + 292); /*0x140bbd*/
      *(_WORD *)(v9 + 106) = nogroup; /*0x140bc8*/
    }
    brelse(v14); /*0x140bcd*/
    **(_DWORD **)(v9 + 12) = 0; /*0x140bd5*/
    *(_DWORD *)(*(_DWORD *)(v9 + 12) + 20) = *(_DWORD *)(v9 + 108); /*0x140be1*/
    return v9; /*0x140be4*/
  }
}
