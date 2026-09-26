/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1236e0. */
int __cdecl in_control(int a1, signed int a2, _DWORD *a3, int a4)
{
  int v4; // edx
  int i; // ebx
  int v6; // eax
  int *v7; // eax
  int result; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  unsigned __int32 v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // [esp+10h] [ebp-14h]
  int v16; // [esp+14h] [ebp-10h] BYREF
  int v17; // [esp+18h] [ebp-Ch]
  int v18; // [esp+1Ch] [ebp-8h]
  int v19; // [esp+20h] [ebp-4h]

  v4 = a4; /*0x1236ec*/
  i = 0; /*0x1236f2*/
  if ( a4 ) /*0x1236f6*/
  {
    for ( i = in_ifaddr; i; i = *(_DWORD *)(i + 64) ) /*0x123700*/
    {
      if ( *(_DWORD *)(i + 32) == a4 ) /*0x123707*/
        break; /*0x123707*/
    }
  }
  if ( a2 == -2145359597 ) /*0x123716*/
  {
    v11 = suser(); /*0x123827*/
    v4 = a4; /*0x12382c*/
    if ( v11 ) /*0x123831*/
      goto LABEL_36; /*0x123831*/
    return *(char *)(dword_1E875C + 104); /*0x12383c*/
  }
  if ( a2 <= -2145359597 ) /*0x12371c*/
  {
    if ( a2 != -2145359604 && a2 != -2145359602 ) /*0x12372c*/
      goto LABEL_36; /*0x12372c*/
    goto LABEL_16; /*0x12372c*/
  }
  if ( a2 == -2145359582 ) /*0x12373a*/
    goto LABEL_16; /*0x12373a*/
  if ( a2 > -2145359582 ) /*0x12373c*/
  {
    if ( a2 == -1071617759 ) /*0x123752*/
      goto LABEL_38; /*0x123752*/
    goto LABEL_36; /*0x123752*/
  }
  if ( a2 == -2145359594 ) /*0x123744*/
  {
LABEL_16:
    v6 = suser(); /*0x123760*/
    v4 = a4; /*0x123768*/
    if ( v6 ) /*0x12376d*/
    {
      if ( !a4 ) /*0x123775*/
        panic(aInControl); /*0x12377f*/
      if ( !i ) /*0x12378c*/
      {
        v7 = m_getclr(1, 13); /*0x123799*/
        v4 = a4; /*0x1237a1*/
        if ( !v7 ) /*0x1237a6*/
          return 55; /*0x1237ad*/
        v9 = in_ifaddr; /*0x1237b4*/
        if ( in_ifaddr ) /*0x1237bc*/
        {
          if ( *(_DWORD *)(in_ifaddr + 64) ) /*0x1237be*/
          {
            do /*0x1237c7*/
              v9 = *(_DWORD *)(v9 + 64); /*0x1237c4*/
            while ( *(_DWORD *)(v9 + 64) ); /*0x1237c7*/
          }
          *(_DWORD *)(v9 + 64) = (char *)v7 + v7[1]; /*0x1237d2*/
        }
        else
        {
          in_ifaddr = (int)v7 + v7[1]; /*0x1237dd*/
        }
        i = (int)v7 + v7[1]; /*0x1237e5*/
        v10 = *(_DWORD *)(a4 + 24); /*0x1237e8*/
        if ( v10 ) /*0x1237ed*/
        {
          for ( ; *(_DWORD *)(v10 + 36); v10 = *(_DWORD *)(v10 + 36) ) /*0x1237ef*/
            ; /*0x1237f8*/
          *(_DWORD *)(v10 + 36) = i; /*0x123801*/
        }
        else
        {
          *(_DWORD *)(a4 + 24) = i; /*0x123808*/
        }
        *(_DWORD *)(i + 32) = a4; /*0x12380b*/
        *(_WORD *)i = 2; /*0x12380e*/
        if ( (*(_BYTE *)(a4 + 12) & 8) == 0 ) /*0x123817*/
          ++in_interfaces; /*0x123819*/
      }
      goto LABEL_38; /*0x12381f*/
    }
    return *(char *)(dword_1E875C + 104); /*0x12376d*/
  }
LABEL_36:
  if ( !i ) /*0x123846*/
    return 49; /*0x12384d*/
LABEL_38:
  if ( a2 != -2145359582 ) /*0x12385a*/
  {
    if ( a2 <= -2145359582 ) /*0x123860*/
    {
      if ( a2 == -2145359602 ) /*0x123868*/
      {
        if ( (*(_BYTE *)(v4 + 12) & 0x10) != 0 ) /*0x12393c*/
        {
          v16 = *(_DWORD *)(i + 16); /*0x123945*/
          v17 = *(_DWORD *)(i + 20); /*0x12394b*/
          v18 = *(_DWORD *)(i + 24); /*0x123951*/
          v19 = *(_DWORD *)(i + 28); /*0x123957*/
          *(_DWORD *)(i + 16) = a3[4]; /*0x12395d*/
          *(_DWORD *)(i + 20) = a3[5]; /*0x123963*/
          *(_DWORD *)(i + 24) = a3[6]; /*0x123969*/
          *(_DWORD *)(i + 28) = a3[7]; /*0x12396f*/
          if ( *(_DWORD *)(v4 + 56) ) /*0x123972*/
          {
            result = if_ioctl(v4, 0x8020690E, i); /*0x12397f*/
            if ( result ) /*0x123989*/
            {
              *(_DWORD *)(i + 16) = v16; /*0x12398e*/
              *(_DWORD *)(i + 20) = v17; /*0x123994*/
              *(_DWORD *)(i + 24) = v18; /*0x12399a*/
              *(_DWORD *)(i + 28) = v19; /*0x1239a0*/
              return result; /*0x1239a3*/
            }
          }
          if ( (*(_BYTE *)(i + 60) & 1) != 0 ) /*0x1239ac*/
          {
            rtinit(&v16, (int *)i, -2144308725, 4); /*0x1239be*/
            rtinit((int *)(i + 16), (int *)i, -2144308726, 5); /*0x1239cf*/
          }
          return 0; /*0x1239d4*/
        }
      }
      else
      {
        if ( a2 <= -2145359602 ) /*0x12386e*/
        {
          if ( a2 == -2145359604 ) /*0x123876*/
          {
            *(_WORD *)(v4 + 12) &= ~0x8000u; /*0x123a0c*/
            return in_ifinit(v4, i, a3 + 4); /*0x123a1d*/
          }
          goto LABEL_78; /*0x123876*/
        }
        if ( a2 != -2145359597 ) /*0x12388a*/
        {
          if ( a2 != -2145359594 ) /*0x123896*/
          {
LABEL_78:
            if ( v4 && *(_DWORD *)(v4 + 56) ) /*0x123aac*/
              return if_ioctl(v4, a2, (int)a3); /*0x123ac2*/
            else
              return 45; /*0x123ab2*/
          }
          *(_DWORD *)(i + 60) &= 0xFFFFFFF9; /*0x123a24*/
          v12 = _byteswap_ulong(a3[5]); /*0x123a2b*/
          *(_DWORD *)(i + 52) = v12; /*0x123a2d*/
          if ( v12 ) /*0x123a32*/
          {
            *(_BYTE *)(i + 60) |= 2u; /*0x123a38*/
            icmp_sendMaskPacket(v4, 18, 0); /*0x123a41*/
          }
          return 0; /*0x123ad0*/
        }
        if ( (*(_BYTE *)(v4 + 12) & 2) != 0 ) /*0x1239e0*/
        {
          *(_DWORD *)(i + 16) = a3[4]; /*0x1239ef*/
          *(_DWORD *)(i + 20) = a3[5]; /*0x1239f5*/
          *(_DWORD *)(i + 24) = a3[6]; /*0x1239fb*/
          *(_DWORD *)(i + 28) = a3[7]; /*0x123a01*/
          return 0; /*0x123a04*/
        }
      }
      return 22; /*0x1239e0*/
    }
    if ( a2 == -1071617777 ) /*0x1238aa*/
    {
      if ( (*(_BYTE *)(v4 + 12) & 0x10) == 0 ) /*0x123900*/
        return 22; /*0x123900*/
    }
    else
    {
      if ( a2 <= -1071617777 ) /*0x1238ac*/
      {
        if ( a2 != -1071617779 ) /*0x1238b4*/
          goto LABEL_78; /*0x1238b4*/
        a3[4] = *(_DWORD *)i; /*0x1238d6*/
        a3[5] = *(_DWORD *)(i + 4); /*0x1238dc*/
        a3[6] = *(_DWORD *)(i + 8); /*0x1238e2*/
        a3[7] = *(_DWORD *)(i + 12); /*0x1238e8*/
        return 0; /*0x1238eb*/
      }
      if ( a2 != -1071617774 ) /*0x1238c2*/
      {
        if ( a2 != -1071617771 ) /*0x1238ca*/
          goto LABEL_78; /*0x1238ca*/
        *((_WORD *)a3 + 8) = 2; /*0x123924*/
        a3[5] = _byteswap_ulong(*(_DWORD *)(i + 52)); /*0x12392f*/
        return 0; /*0x123932*/
      }
      if ( (*(_BYTE *)(v4 + 12) & 2) == 0 ) /*0x1238f4*/
        return 22; /*0x1239e7*/
    }
    a3[4] = *(_DWORD *)(i + 16); /*0x123909*/
    a3[5] = *(_DWORD *)(i + 20); /*0x12390f*/
    a3[6] = *(_DWORD *)(i + 24); /*0x123915*/
    a3[7] = *(_DWORD *)(i + 28); /*0x12391b*/
    return 0; /*0x12391e*/
  }
  v13 = *(_DWORD *)(i + 60); /*0x123a4c*/
  LOBYTE(v13) = v13 & 0xFD; /*0x123a4f*/
  *(_DWORD *)(i + 60) = v13; /*0x123a51*/
  if ( (*(_BYTE *)(v4 + 12) & 1) == 0 ) /*0x123a58*/
    return 50; /*0x123a9f*/
  LOBYTE(v13) = v13 | 4; /*0x123a5a*/
  *(_DWORD *)(i + 60) = v13; /*0x123a5c*/
  v14 = 0; /*0x123a5f*/
  while ( 1 ) /*0x123a81*/
  {
    v15 = v4; /*0x123a81*/
    result = icmp_sendMaskPacket(v4, 17, 1 << v14 >> 1); /*0x123a84*/
    v4 = v15; /*0x123a8c*/
    if ( result ) /*0x123a91*/
      break; /*0x123a91*/
    if ( (*(_BYTE *)(i + 60) & 4) == 0 ) /*0x123a97*/
      return 0; /*0x123ace*/
    if ( ++v14 > 4 ) /*0x123a9d*/
      return 50; /*0x123a9d*/
  }
  return result; /*0x123ad5*/
}
