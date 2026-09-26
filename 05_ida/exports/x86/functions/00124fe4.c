/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124fe4. */
int __cdecl in_pcbconnect(int a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int v5; // eax
  int v6; // esi
  int v7; // esi
  int *v8; // ebx
  __int16 v9; // ax
  int v10; // eax
  __int16 v11; // bx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // [esp+Ch] [ebp-4h]

  v2 = 0; /*0x124ff0*/
  v3 = *(_DWORD *)(a2 + 4) + a2; /*0x124ff4*/
  if ( *(_WORD *)(a2 + 8) != 16 ) /*0x124ffc*/
    return 22; /*0x125003*/
  if ( *(_WORD *)v3 != 2 ) /*0x12500c*/
    return 47; /*0x125013*/
  if ( !*(_WORD *)(v3 + 2) ) /*0x12501d*/
    return 49; /*0x12501d*/
  if ( in_ifaddr ) /*0x12502b*/
  {
    v5 = *(_DWORD *)(v3 + 4); /*0x12502d*/
    if ( !v5 ) /*0x125032*/
    {
      v6 = *(_DWORD *)(in_ifaddr + 4); /*0x125034*/
LABEL_12:
      *(_DWORD *)(v3 + 4) = v6; /*0x12504d*/
      goto LABEL_13; /*0x12504d*/
    }
    if ( v5 == -1 && (*(_BYTE *)(*(_DWORD *)(in_ifaddr + 32) + 12) & 2) != 0 ) /*0x125048*/
    {
      v6 = *(_DWORD *)(in_ifaddr + 20); /*0x12504a*/
      goto LABEL_12; /*0x12504a*/
    }
  }
LABEL_13:
  if ( *(_DWORD *)(a1 + 20) ) /*0x125053*/
    goto LABEL_44; /*0x125057*/
  v7 = 0; /*0x12505d*/
  v8 = (int *)(a1 + 36); /*0x125061*/
  v18 = *(_DWORD *)(a1 + 36); /*0x125067*/
  if ( !v18 ) /*0x12506c*/
  {
LABEL_21:
    if ( (*(_BYTE *)(*(_DWORD *)(a1 + 28) + 2) & 0x10) != 0 ) /*0x1250b1*/
      goto LABEL_25; /*0x1250b1*/
    goto LABEL_22; /*0x1250b1*/
  }
  if ( *(_DWORD *)(a1 + 44) != *(_DWORD *)(v3 + 4) || (*(_BYTE *)(*(_DWORD *)(a1 + 28) + 2) & 0x10) != 0 ) /*0x12507d*/
  {
    v9 = *(_WORD *)(v18 + 38); /*0x125082*/
    if ( v9 == 1 ) /*0x12508a*/
      rtfree(v18); /*0x12508d*/
    else
      *(_WORD *)(v18 + 38) = v9 - 1; /*0x12509d*/
    *v8 = 0; /*0x1250a1*/
    goto LABEL_21; /*0x1250a1*/
  }
LABEL_22:
  if ( !*v8 || !*(_DWORD *)(*v8 + 44) ) /*0x1250b9*/
  {
    *(_WORD *)(a1 + 40) = 2; /*0x1250bf*/
    *(_DWORD *)(a1 + 44) = *(_DWORD *)(v3 + 4); /*0x1250c8*/
    rtalloc(v8); /*0x1250cc*/
  }
LABEL_25:
  if ( *v8 ) /*0x1250d4*/
  {
    v10 = *(_DWORD *)(*v8 + 44); /*0x1250da*/
    if ( v10 ) /*0x1250df*/
    {
      if ( (*(_BYTE *)(v10 + 12) & 8) == 0 ) /*0x1250e5*/
      {
        v7 = in_ifaddr; /*0x1250e7*/
        if ( !in_ifaddr ) /*0x1250ef*/
        {
LABEL_32:
          v11 = *(_WORD *)(v3 + 2); /*0x125104*/
          *(_WORD *)(v3 + 2) = 0; /*0x125108*/
          v7 = ifa_ifwithdstaddr((_WORD *)v3); /*0x125114*/
          *(_WORD *)(v3 + 2) = v11; /*0x125116*/
          if ( !v7 ) /*0x12511f*/
          {
            v12 = in_netof(*(_DWORD *)(v3 + 4)); /*0x125125*/
            v7 = in_iaonnetof(v12); /*0x125130*/
            if ( !v7 ) /*0x125137*/
            {
              v7 = in_ifaddr; /*0x125139*/
              if ( !in_ifaddr ) /*0x125141*/
                return 49; /*0x125189*/
            }
          }
          goto LABEL_35; /*0x125141*/
        }
        do /*0x1250fe*/
        {
          if ( *(_DWORD *)(v7 + 32) == v10 ) /*0x1250f7*/
            break; /*0x1250f7*/
          v7 = *(_DWORD *)(v7 + 64); /*0x1250f9*/
        }
        while ( v7 ); /*0x1250fe*/
      }
    }
  }
  if ( !v7 ) /*0x125102*/
    goto LABEL_32; /*0x125102*/
LABEL_35:
  if ( (_byteswap_ulong(*(_DWORD *)(v3 + 4)) & 0xF0000000) == 0xE0000000 ) /*0x125152*/
  {
    v13 = *(_DWORD *)(a1 + 60); /*0x125157*/
    if ( v13 ) /*0x12515c*/
    {
      v14 = *(_DWORD *)(*(_DWORD *)(v13 + 4) + v13); /*0x125161*/
      if ( v14 ) /*0x125165*/
      {
        v7 = in_ifaddr; /*0x125167*/
        if ( !in_ifaddr ) /*0x12516f*/
          return 49; /*0x12516f*/
        do /*0x12517e*/
        {
          if ( *(_DWORD *)(v7 + 32) == v14 ) /*0x125177*/
            break; /*0x125177*/
          v7 = *(_DWORD *)(v7 + 64); /*0x125179*/
        }
        while ( v7 ); /*0x12517e*/
        if ( !v7 ) /*0x125182*/
          return 49; /*0x125182*/
      }
    }
  }
  v2 = v7; /*0x125190*/
LABEL_44:
  v15 = *(_DWORD *)(a1 + 20); /*0x125192*/
  if ( !v15 ) /*0x1251a1*/
    v15 = *(_DWORD *)(v2 + 4); /*0x1251a3*/
  if ( in_pcblookup(*(_DWORD *)(a1 + 8), *(_DWORD *)(v3 + 4), *(_WORD *)(v3 + 2), v15, *(_WORD *)(a1 + 24), 0) ) /*0x1251b7*/
    return 48; /*0x1251c8*/
  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a1 + 28) + 12) + 10) & 4) == 0 || *(_WORD *)(v3 + 2) != *(_WORD *)(a1 + 24) ) /*0x1251e3*/
    goto LABEL_55; /*0x1251e3*/
  v16 = *(_DWORD *)(v3 + 4); /*0x1251e5*/
  v17 = *(_DWORD *)(a1 + 20); /*0x1251e8*/
  if ( v17 ) /*0x1251ed*/
  {
    if ( v17 != v16 ) /*0x1251f1*/
      goto LABEL_55; /*0x1251f1*/
    return 61; /*0x125202*/
  }
  if ( *(_DWORD *)(v2 + 4) == v16 ) /*0x1251fb*/
    return 61; /*0x1251fb*/
LABEL_55:
  if ( !*(_DWORD *)(a1 + 20) ) /*0x125207*/
  {
    if ( !*(_WORD *)(a1 + 24) ) /*0x12520d*/
      in_pcbbind(a1, 0); /*0x125217*/
    *(_DWORD *)(a1 + 20) = *(_DWORD *)(v2 + 4); /*0x125222*/
  }
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4); /*0x12522b*/
  *(_WORD *)(a1 + 16) = *(_WORD *)(v3 + 2); /*0x125232*/
  return 0; /*0x12523b*/
}
