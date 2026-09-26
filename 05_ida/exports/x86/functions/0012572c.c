/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12572c. */
void __cdecl icmp_input(int *a1, int a2)
{
  int v2; // ebx
  int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // esi
  int v6; // edx
  int v7; // edx
  void (__cdecl *v8)(int, sockaddr *, unsigned __int8 *); // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // ebx
  __int16 v14; // ax
  int v15; // eax
  int *v16; // eax
  int *v17; // ebx
  int v18; // edx
  unsigned __int32 v19; // eax
  char *v20; // eax
  int v21; // [esp-8h] [ebp-1Ch]
  int v22; // [esp+Ch] [ebp-8h]
  char *v23; // [esp+10h] [ebp-4h]
  char *v24; // [esp+10h] [ebp-4h]

  v23 = (char *)a1 + a1[1]; /*0x12573b*/
  v2 = *((__int16 *)v23 + 1); /*0x12573e*/
  v22 = 4 * (*v23 & 0xF); /*0x12574a*/
  if ( v2 <= 7 ) /*0x125750*/
  {
    ++dword_1EAB8C; /*0x125752*/
LABEL_61:
    m_freem((int)a1); /*0x125bbc*/
    return; /*0x125bc0*/
  }
  if ( (unsigned int)v2 > 0x23 ) /*0x125763*/
    v3 = v22 + 36; /*0x12576f*/
  else
    v3 = v2 + v22; /*0x125768*/
  if ( (unsigned int)a1[1] > 0x7C || *((__int16 *)a1 + 4) < v3 ) /*0x125781*/
  {
    a1 = m_pullup((int)a1, v3); /*0x12578d*/
    if ( !a1 ) /*0x125795*/
    {
      ++dword_1EAB8C; /*0x125797*/
      return; /*0x12579d*/
    }
  }
  v24 = (char *)a1 + a1[1]; /*0x1257aa*/
  *((_WORD *)a1 + 4) -= v22; /*0x1257b4*/
  v4 = a1[1] + v22; /*0x1257bb*/
  a1[1] = v4; /*0x1257be*/
  v5 = (unsigned __int8 *)a1 + v4; /*0x1257c4*/
  if ( in_cksum(a1, v2) ) /*0x1257c8*/
  {
    ++dword_1EAB90; /*0x1257d4*/
    goto LABEL_61; /*0x1257da*/
  }
  *((_WORD *)a1 + 4) += v22; /*0x1257e7*/
  a1[1] -= v22; /*0x1257ee*/
  if ( *v5 > 0x12u )
  {
LABEL_60:
    *(_DWORD *)&stru_1DBCF8.sa_data[2] = *((_DWORD *)v24 + 3); /*0x125b8a*/
    dword_1DBD0C = *((_DWORD *)v24 + 4); /*0x125b9c*/
    raw_input((int)a1, &dword_1DBCF4, &stru_1DBCF8, &dword_1DBD08); /*0x125bb5*/
  }
  else
  {
    ++dword_1EAB9C[*v5]; /*0x125800*/
    v6 = v5[1]; /*0x125807*/
    switch ( *v5 )
    {
      case 3u:
        if ( v5[1] > 5u ) /*0x12586f*/
          goto LABEL_27; /*0x12586f*/
        v7 = v6 + 8; /*0x125875*/
        goto LABEL_22; /*0x125878*/
      case 4u:
        if ( v5[1] ) /*0x125807*/
          goto LABEL_27; /*0x12589a*/
        v7 = 4; /*0x12589c*/
        goto LABEL_22; /*0x12589c*/
      case 5u:
        if ( (unsigned int)v2 <= 0x23 || v2 < 4 * (v5[8] & 0xF) + 16 ) /*0x125a30*/
          goto LABEL_46; /*0x125a30*/
        dword_1DBD1C = *((_DWORD *)v24 + 3); /*0x125a46*/
        dword_1DBD0C = *((_DWORD *)v5 + 1); /*0x125a4f*/
        if ( v6 && v6 != 2 ) /*0x125a5c*/
        {
          *(_DWORD *)&stru_1DBCF8.sa_data[2] = *((_DWORD *)v5 + 6); /*0x125aaf*/
          rtredirect((int *)&stru_1DBCF8, (int)&dword_1DBD08, 6, &unk_1DBD18); /*0x125ac6*/
          pfctlinput(15, &stru_1DBCF8); /*0x125ad2*/
        }
        else
        {
          v15 = in_netof(*((_DWORD *)v5 + 6)); /*0x125a64*/
          *(_DWORD *)&stru_1DBCF8.sa_data[2] = in_makeaddr(v15, 0); /*0x125a72*/
          rtredirect((int *)&stru_1DBCF8, (int)&dword_1DBD08, 2, &unk_1DBD18); /*0x125a88*/
          *(_DWORD *)&stru_1DBCF8.sa_data[2] = *((_DWORD *)v5 + 6); /*0x125a90*/
          pfctlinput(14, &stru_1DBCF8); /*0x125a9d*/
        }
        goto LABEL_60; /*0x125aa5*/
      case 8u:
        *v5 = 0; /*0x125918*/
        goto LABEL_43; /*0x12591b*/
      case 0xBu:
        if ( v5[1] > 1u ) /*0x12587f*/
          goto LABEL_27; /*0x12587f*/
        v7 = v6 + 18; /*0x125885*/
        goto LABEL_22; /*0x125888*/
      case 0xCu:
        if ( v5[1] ) /*0x125807*/
        {
LABEL_27:
          ++dword_1EAB88; /*0x12590c*/
        }
        else
        {
          v7 = 20; /*0x125890*/
LABEL_22:
          *((_WORD *)v5 + 5) = __ROR2__(*((_WORD *)v5 + 5), 8); /*0x1258a1*/
          if ( (unsigned int)v2 <= 0x23 || v2 < 4 * (v5[8] & 0xF) + 16 ) /*0x1258c1*/
          {
            ++dword_1EAB94; /*0x1258c3*/
            goto LABEL_61; /*0x1258c9*/
          }
          *(_DWORD *)&stru_1DBCF8.sa_data[2] = *((_DWORD *)v5 + 6); /*0x1258d3*/
          v8 = (void (__cdecl *)(int, sockaddr *, unsigned __int8 *))dword_1DBB78[12 /*0x1258ea*/
                                                                                * (unsigned __int8)ip_protox[v5[17]]];
          if ( v8 ) /*0x1258f2*/
            v8(v7, &stru_1DBCF8, v5 + 8); /*0x125902*/
        }
        goto LABEL_60; /*0x125907*/
      case 0xDu:
        if ( (unsigned int)v2 <= 0x13 ) /*0x125923*/
        {
LABEL_46:
          ++dword_1EAB94; /*0x125a32*/
          goto LABEL_60; /*0x125a38*/
        }
        *v5 = 14; /*0x125929*/
        v9 = iptime(); /*0x12592c*/
        *((_DWORD *)v5 + 3) = v9; /*0x125931*/
        *((_DWORD *)v5 + 4) = v9; /*0x125934*/
LABEL_43:
        *((_WORD *)v24 + 1) += v22; /*0x1259ed*/
        ++dword_1EAB98; /*0x1259f8*/
        ++dword_1EAB3C[*v5]; /*0x125a01*/
        icmp_reflect(v24, a2); /*0x125a10*/
        break; /*0x125a15*/
      case 0xFu:
        if ( !in_netof(*((_DWORD *)v24 + 3)) ) /*0x125943*/
        {
          v10 = ifptoia(a2); /*0x125958*/
          if ( v10 ) /*0x12595f*/
          {
            v21 = in_lnaof(*((_DWORD *)v24 + 3)); /*0x12596d*/
            v11 = in_netof(*(_DWORD *)(v10 + 4)); /*0x125972*/
            *((_DWORD *)v24 + 3) = in_makeaddr(v11, v21); /*0x125983*/
          }
        }
        *v5 = 16; /*0x125989*/
        goto LABEL_43; /*0x12598c*/
      case 0x11u:
        if ( v2 <= 11 ) /*0x125993*/
          goto LABEL_60; /*0x125993*/
        v12 = ifptoia(a2); /*0x12599d*/
        v13 = v12; /*0x1259a2*/
        if ( !v12 || (*(_BYTE *)(v12 + 60) & 2) == 0 ) /*0x1259b3*/
          goto LABEL_60; /*0x1259b3*/
        *v5 = 18; /*0x1259b9*/
        *((_DWORD *)v5 + 2) = _byteswap_ulong(*(_DWORD *)(v12 + 52)); /*0x1259c1*/
        if ( !*((_DWORD *)v24 + 3) ) /*0x1259c7*/
        {
          v14 = *(_WORD *)(*(_DWORD *)(v12 + 32) + 12); /*0x1259d0*/
          if ( (v14 & 2) != 0 ) /*0x1259d6*/
          {
            *((_DWORD *)v24 + 3) = *(_DWORD *)(v13 + 20); /*0x1259db*/
          }
          else if ( (v14 & 0x10) != 0 ) /*0x1259e2*/
          {
            *((_DWORD *)v24 + 3) = *(_DWORD *)(v13 + 20); /*0x1259ea*/
          }
        }
        goto LABEL_43; /*0x1259de*/
      case 0x12u:
        v16 = (int *)ifptoia(a2); /*0x125ae4*/
        v17 = v16; /*0x125ae9*/
        if ( v16 )
        {
          v18 = v16[15]; /*0x125af6*/
          if ( (v18 & 4) != 0 )
          {
            v19 = _byteswap_ulong(*((_DWORD *)v5 + 2)); /*0x125b05*/
            if ( v19 != -1 && (v19 & 0xFF000000) == 0xFF000000 )
            {
              LOBYTE(v18) = v18 & 0xFB; /*0x125b18*/
              v17[15] = v18; /*0x125b1b*/
              if ( (*(_BYTE *)(a2 + 12) & 8) == 0 && v17[13] != (v17[13] | _byteswap_ulong(*((_DWORD *)v5 + 2))) )
              {
                v17[13] = _byteswap_ulong(*((_DWORD *)v5 + 2)); /*0x125b37*/
                if ( in_ifinit(a2, v17, v17) )
                {
                  printf("icmp_input: can't set new netmask\n");
                }
                else
                {
                  v20 = inet_ntoa((in_addr)(v24 + 12)); /*0x125b5f*/
                  printf(
                    "%s%d: setting netmask to %x, received from %s\n",
                    *(const char **)a2,
                    *(__int16 *)(a2 + 8),
                    v17[13],
                    v20);
                  wakeup((int)(v17 + 13)); /*0x125b82*/
                }
              }
            }
          }
        }
        goto LABEL_60; /*0x125b56*/
      default:
        goto LABEL_60;
    }
  }
}
