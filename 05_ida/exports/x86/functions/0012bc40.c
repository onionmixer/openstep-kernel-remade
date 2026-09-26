/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12bc40. */
void __cdecl igmp_input(int *a1, int a2)
{
  unsigned int v2; // ecx
  int v3; // eax
  unsigned int *v4; // esi
  int v5; // ebx
  unsigned int *v6; // ecx
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch]
  char *v14; // [esp+18h] [ebp-8h]
  unsigned __int8 *v15; // [esp+1Ch] [ebp-4h]

  ++igmpstat; /*0x12bc49*/
  v2 = a1[1]; /*0x12bc52*/
  v12 = 4 * (*((_BYTE *)a1 + v2) & 0xF); /*0x12bc62*/
  v13 = *(__int16 *)((char *)a1 + v2 + 2); /*0x12bc69*/
  if ( v13 <= 7 ) /*0x12bc6f*/
  {
    ++dword_1EEE74; /*0x12bc71*/
    m_freem((int)a1); /*0x12bc7b*/
    return; /*0x12bc80*/
  }
  if ( v2 > 0x7C || *((__int16 *)a1 + 4) < v12 + 8 ) /*0x12bc9f*/
  {
    a1 = m_pullup((int)a1, v12 + 8); /*0x12bcae*/
    if ( !a1 ) /*0x12bcb6*/
    {
      ++dword_1EEE74; /*0x12bcb8*/
      return; /*0x12bcbe*/
    }
  }
  a1[1] += v12; /*0x12bcca*/
  *((_WORD *)a1 + 4) -= v12; /*0x12bcd1*/
  v15 = (unsigned __int8 *)a1 + a1[1]; /*0x12bcd8*/
  if ( in_cksum(a1, v13) ) /*0x12bce3*/
  {
    ++dword_1EEE78; /*0x12bcef*/
LABEL_35:
    m_freem((int)a1); /*0x12be3d*/
    return; /*0x12be46*/
  }
  a1[1] -= v12; /*0x12bd02*/
  *((_WORD *)a1 + 4) += v12; /*0x12bd09*/
  v14 = (char *)a1 + a1[1]; /*0x12bd10*/
  v3 = *v15; /*0x12bd16*/
  if ( v3 != 17 ) /*0x12bd1c*/
  {
    if ( v3 == 18 ) /*0x12bd21*/
    {
      ++dword_1EEE84; /*0x12be04*/
      if ( loifp != a2 ) /*0x12be13*/
      {
        if ( (_byteswap_ulong(*((_DWORD *)v15 + 1)) & 0xF0000000) != 0xE0000000 /*0x12be35*/
          || *((_DWORD *)v14 + 4) != *((_DWORD *)v15 + 1) )
        {
          ++dword_1EEE88; /*0x12be37*/
          goto LABEL_35; /*0x12be37*/
        }
        if ( (_byteswap_ulong(*((_DWORD *)v14 + 3)) & 0xFF000000) == 0 ) /*0x12be59*/
        {
          v9 = (_DWORD *)in_ifaddr; /*0x12be5b*/
          if ( in_ifaddr ) /*0x12be62*/
          {
            do /*0x12be71*/
            {
              if ( v9[8] == a2 ) /*0x12be6a*/
                break; /*0x12be6a*/
              v9 = (_DWORD *)v9[16]; /*0x12be6c*/
            }
            while ( v9 ); /*0x12be71*/
            if ( v9 ) /*0x12be75*/
              *((_DWORD *)v14 + 3) = _byteswap_ulong(v9[12]); /*0x12be7f*/
          }
        }
        v10 = (_DWORD *)in_ifaddr; /*0x12be82*/
        if ( in_ifaddr ) /*0x12be89*/
        {
          do /*0x12be99*/
          {
            if ( v10[8] == a2 ) /*0x12be92*/
              break; /*0x12be92*/
            v10 = (_DWORD *)v10[16]; /*0x12be94*/
          }
          while ( v10 ); /*0x12be99*/
          if ( v10 ) /*0x12be9d*/
          {
            v11 = (_DWORD *)v10[17]; /*0x12be9f*/
            if ( v11 ) /*0x12bea4*/
            {
              do /*0x12beb5*/
              {
                if ( *v11 == *((_DWORD *)v15 + 1) ) /*0x12beae*/
                  break; /*0x12beae*/
                v11 = (_DWORD *)v11[5]; /*0x12beb0*/
              }
              while ( v11 ); /*0x12beb5*/
              if ( v11 ) /*0x12beb9*/
              {
                v11[4] = 0; /*0x12bebb*/
                ++dword_1EEE8C; /*0x12bec2*/
              }
            }
          }
        }
      }
    }
    goto LABEL_51; /*0x12bec2*/
  }
  ++dword_1EEE7C; /*0x12bd2c*/
  if ( loifp != a2 ) /*0x12bd3b*/
  {
    if ( *((_DWORD *)v14 + 4) != dword_1E59AC ) /*0x12bd4c*/
    {
      ++dword_1EEE80; /*0x12bd4e*/
      goto LABEL_35; /*0x12bd54*/
    }
    v5 = in_ifaddr; /*0x12bd64*/
    v4 = nullptr; /*0x12bd6a*/
    v6 = nullptr; /*0x12bd6c*/
    if ( in_ifaddr ) /*0x12bd70*/
    {
      while ( 1 ) /*0x12bd76*/
      {
        v6 = *(unsigned int **)(v5 + 68); /*0x12bd76*/
        v7 = *(_DWORD *)(v5 + 64); /*0x12bd79*/
        v5 = v7; /*0x12bd7c*/
        if ( v6 ) /*0x12bd80*/
          break; /*0x12bd80*/
        if ( !v7 ) /*0x12bd84*/
          goto LABEL_19; /*0x12bd84*/
      }
      v4 = (unsigned int *)v6[5]; /*0x12bd5c*/
    }
LABEL_19:
    while ( v6 ) /*0x12bd88*/
    {
      if ( v6[1] == a2 && !v6[4] && dword_1E59AC != *v6 ) /*0x12bda9*/
      {
        v6[4] = (_byteswap_ulong(*v6) + ipstat + _byteswap_ulong(*(_DWORD *)(in_ifaddr + 4))) % 0x32 + 1; /*0x12bdc9*/
        dword_1DBF44 = 1; /*0x12bdcc*/
      }
      v6 = v4; /*0x12bdd6*/
      if ( !v4 ) /*0x12bdda*/
      {
        if ( !v5 ) /*0x12bde6*/
          continue; /*0x12bde6*/
        while ( 1 ) /*0x12bdea*/
        {
          v6 = *(unsigned int **)(v5 + 68); /*0x12bdea*/
          v8 = *(_DWORD *)(v5 + 64); /*0x12bded*/
          v5 = v8; /*0x12bdf0*/
          if ( v6 ) /*0x12bdf4*/
            break; /*0x12bdf4*/
          if ( !v8 ) /*0x12bdf8*/
            goto LABEL_29; /*0x12bdf8*/
        }
      }
      v4 = (unsigned int *)v6[5]; /*0x12bddc*/
LABEL_29:
      ; /*0x12bdfc*/
    }
  }
LABEL_51:
  dword_1DBF28 = *((_DWORD *)v14 + 3); /*0x12bec8*/
  dword_1DBF38 = *((_DWORD *)v14 + 4); /*0x12beda*/
  raw_input((int)a1, &dword_1DBF20, &dword_1DBF24, &dword_1DBF34); /*0x12bef3*/
}
