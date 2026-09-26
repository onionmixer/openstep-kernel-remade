/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19157c. */
int __cdecl sub_19157C(int a1, char a2)
{
  int i; // edi
  volatile __int32 *v3; // edx
  char *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  _DWORD *v7; // eax
  _BYTE *v8; // edx
  int v9; // ecx
  int v10; // eax
  _DWORD *v11; // ebx
  unsigned int v13; // [esp+Ch] [ebp-1Ch]
  int v14; // [esp+1Ch] [ebp-Ch]
  unsigned int v15; // [esp+20h] [ebp-8h]
  _DWORD *v16; // [esp+24h] [ebp-4h]

  v13 = pg_desc_tbl + 20 * ((unsigned int)(a1 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)); /*0x1915a8*/
  v14 = splvm(); /*0x1915b0*/
  *(_BYTE *)(v13 + 16) &= ~a2; /*0x1915bb*/
  v16 = (_DWORD *)v13; /*0x1915be*/
  for ( i = *(_DWORD *)(v13 + 4); i; i = v11[1] ) /*0x1915c6*/
  {
    v15 = v16[2]; /*0x1915e6*/
    v3 = (volatile __int32 *)(i + 12); /*0x1915e9*/
    do /*0x1915fe*/
    {
      while ( *v3 ) /*0x1915ec*/
        ; /*0x1915ee*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x1915fe*/
    v4 = (char *)v15; /*0x191600*/
    v5 = page_size + v15; /*0x19160e*/
    if ( i == kernel_pmap || *(_DWORD *)(i + 24) ) /*0x19161d*/
    {
      ++tlb_stat; /*0x191623*/
      if ( v15 < v5 ) /*0x19163f*/
      {
        v6 = kernel_pmap; /*0x191641*/
        do /*0x19165c*/
        {
          if ( i == v6 ) /*0x191646*/
            __invlpg(v4); /*0x191648*/
          else
            __invlpg(MK_FP(__FS__, v4)); /*0x191650*/
          v4 += 4096; /*0x191654*/
        }
        while ( (unsigned int)v4 < v5 ); /*0x19165c*/
      }
      ++dword_1F7AF4; /*0x19165e*/
    }
    v7 = (_DWORD *)(*(_DWORD *)i + 4 * (v15 >> 22)); /*0x19166d*/
    if ( (*(_BYTE *)v7 & 1) != 0 ) /*0x191672*/
    {
      v8 = (_BYTE *)(((v15 >> 10) & 0xFFC) + (*v7 & 0xFFFFF000)); /*0x191687*/
      if ( v8 ) /*0x191689*/
      {
        v9 = ptes_per_vm_page; /*0x19168b*/
        while ( 1 ) /*0x1916a9*/
        {
          v10 = v9--; /*0x1916a9*/
          if ( v10 <= 0 ) /*0x1916ae*/
            break; /*0x1916ae*/
          if ( (a2 & 1) != 0 ) /*0x191698*/
            *v8 &= ~0x40u; /*0x19169a*/
          if ( (a2 & 2) != 0 ) /*0x1916a1*/
            *v8 &= ~0x20u; /*0x1916a3*/
          v8 += 4; /*0x1916a6*/
        }
      }
    }
    _InterlockedExchange((volatile __int32 *)(i + 12), 0); /*0x1916b2*/
    v11 = (_DWORD *)*v16; /*0x1916b8*/
    v16 = v11; /*0x1916ba*/
    if ( !v11 ) /*0x1916bf*/
      break; /*0x1916bf*/
  }
  return splx(v14); /*0x1916d8*/
}
