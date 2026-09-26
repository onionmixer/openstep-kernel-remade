/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b84c. */
int __cdecl udp_usrreq(int a1, int a2, signed int a3, _DWORD *a4, int a5)
{
  int v5; // edi
  int v6; // ebx
  int result; // eax
  signed int i; // esi
  int v9; // ebx
  int *v10; // esi
  char *v11; // ebx
  __int16 v12; // ax
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v5 = *(_DWORD *)(a1 + 8); /*0x12b85e*/
  v6 = 0; /*0x12b861*/
  if ( a2 == 11 ) /*0x12b866*/
    return in_control(a1, a3, a4, a5); /*0x12b87a*/
  v15 = splnet(); /*0x12b888*/
  if ( a5 && *(_WORD *)(a5 + 8) || !v5 && a2 ) /*0x12b89f*/
  {
LABEL_9:
    v6 = 22; /*0x12b910*/
  }
  else
  {
    switch ( a2 ) /*0x12b8aa*/
    {
      case 0: /*0x12b8aa*/
        if ( v5 ) /*0x12b90e*/
          goto LABEL_9; /*0x12b90e*/
        v6 = in_pcballoc(a1, (int)&udb); /*0x12b92a*/
        if ( !v6 ) /*0x12b931*/
          v6 = soreserve(a1, udp_sendspace, udp_recvspace); /*0x12b94e*/
        break; /*0x12b953*/
      case 1: /*0x12b8aa*/
        in_pcbdetach((_DWORD *)v5); /*0x12b959*/
        break; /*0x12b95e*/
      case 2: /*0x12b8aa*/
        v6 = in_pcbbind(v5, (int)a4); /*0x12b96e*/
        break; /*0x12b973*/
      case 3: /*0x12b8aa*/
      case 5: /*0x12b8aa*/
      case 14: /*0x12b8aa*/
      case 17: /*0x12b8aa*/
      case 18: /*0x12b8aa*/
      case 19: /*0x12b8aa*/
      case 20: /*0x12b8aa*/
      case 21: /*0x12b8aa*/
        v6 = 45; /*0x12bbe0*/
        break; /*0x12bbe5*/
      case 4: /*0x12b8aa*/
        if ( *(_DWORD *)(v5 + 12) ) /*0x12b978*/
          goto LABEL_22; /*0x12b97c*/
        v6 = in_pcbconnect(v5, (int)a4); /*0x12b988*/
        if ( !v6 ) /*0x12b98f*/
          soisconnected(a1); /*0x12b999*/
        break; /*0x12b99e*/
      case 6: /*0x12b8aa*/
        if ( !*(_DWORD *)(v5 + 12) ) /*0x12b9a8*/
          goto LABEL_26; /*0x12b9a8*/
        in_pcbdisconnect(v5); /*0x12b9ab*/
        *(_BYTE *)(a1 + 6) &= ~2u; /*0x12b9b3*/
        break; /*0x12b9b7*/
      case 7: /*0x12b8aa*/
        socantsendmore(a1); /*0x12b9c0*/
        break; /*0x12b9c5*/
      case 8: /*0x12b8aa*/
      case 13: /*0x12b8aa*/
        splx(v15); /*0x12bbec*/
        return 45; /*0x12bbf6*/
      case 9: /*0x12b8aa*/
        if ( !a4 ) /*0x12b9d0*/
        {
          if ( !*(_DWORD *)(v5 + 12) ) /*0x12ba04*/
          {
LABEL_26:
            v6 = 57; /*0x12ba0a*/
            break; /*0x12ba0f*/
          }
          goto LABEL_27; /*0x12ba08*/
        }
        v14 = *(_DWORD *)(v5 + 20); /*0x12b9d5*/
        if ( *(_DWORD *)(v5 + 12) ) /*0x12b9d8*/
        {
LABEL_22:
          v6 = 56; /*0x12b9de*/
          break; /*0x12b9e3*/
        }
        v6 = in_pcbconnect(v5, (int)a4); /*0x12b9f2*/
        if ( !v6 ) /*0x12b9f9*/
        {
LABEL_27:
          v13 = 0; /*0x12ba14*/
          for ( i = a3; i; i = *(_DWORD *)i ) /*0x12ba20*/
            v13 += *(__int16 *)(i + 8); /*0x12ba28*/
          v9 = splimp(); /*0x12ba36*/
          v10 = (int *)mfree; /*0x12ba38*/
          if ( mfree ) /*0x12ba40*/
          {
            if ( *(_WORD *)(mfree + 10) ) /*0x12ba42*/
              panic(aMget_12); /*0x12ba4e*/
            *(_WORD *)(mfree + 10) = 2; /*0x12ba56*/
            --word_1E917C[0]; /*0x12ba5c*/
            ++word_1E9180; /*0x12ba63*/
            mfree = *v10; /*0x12ba6c*/
            *v10 = 0; /*0x12ba72*/
            v10[1] = 12; /*0x12ba78*/
          }
          else
          {
            v10 = m_more(0, 2); /*0x12ba8d*/
          }
          splx(v9); /*0x12ba93*/
          if ( v10 ) /*0x12ba9d*/
          {
            v10[1] = 96; /*0x12bab8*/
            *((_WORD *)v10 + 4) = 28; /*0x12babf*/
            *v10 = a3; /*0x12bac8*/
            v11 = (char *)v10 + v10[1]; /*0x12bacc*/
            *((_DWORD *)v11 + 1) = 0; /*0x12bacf*/
            *(_DWORD *)v11 = 0; /*0x12bad6*/
            v11[8] = 0; /*0x12badc*/
            v11[9] = 17; /*0x12bae0*/
            *((_WORD *)v11 + 5) = __ROR2__(v13 + 8, 8); /*0x12baf0*/
            *((_DWORD *)v11 + 3) = *(_DWORD *)(v5 + 20); /*0x12baf7*/
            *((_DWORD *)v11 + 4) = *(_DWORD *)(v5 + 12); /*0x12bafd*/
            *((_WORD *)v11 + 10) = *(_WORD *)(v5 + 24); /*0x12bb04*/
            *((_WORD *)v11 + 11) = *(_WORD *)(v5 + 16); /*0x12bb0c*/
            *((_WORD *)v11 + 12) = *((_WORD *)v11 + 5); /*0x12bb14*/
            *((_WORD *)v11 + 13) = 0; /*0x12bb18*/
            if ( udpcksum ) /*0x12bb25*/
            {
              v12 = in_cksum(v10, v13 + 28); /*0x12bb2f*/
              *((_WORD *)v11 + 13) = v12; /*0x12bb34*/
              if ( !v12 ) /*0x12bb3e*/
                *((_WORD *)v11 + 13) = -1; /*0x12bb40*/
            }
            *((_WORD *)v11 + 1) = v13 + 28; /*0x12bb4e*/
            v11[8] = udp_ttl; /*0x12bb58*/
            v6 = ip_output( /*0x12bb7a*/
                   (int)v10,
                   *(_DWORD *)(v5 + 56),
                   (int *)(v5 + 36),
                   *(_WORD *)(*(_DWORD *)(v5 + 28) + 2) & 0x30 | 2,
                   *(_DWORD *)(v5 + 60));
          }
          else
          {
            m_freem(a3); /*0x12baa3*/
            v6 = 55; /*0x12baa8*/
          }
          a3 = 0; /*0x12bb7f*/
          if ( a4 ) /*0x12bb8a*/
          {
            in_pcbdisconnect(v5); /*0x12bb8d*/
            *(_DWORD *)(v5 + 20) = v14; /*0x12bb95*/
          }
          break; /*0x12bb98*/
        }
        break; /*0x12bb98*/
      case 10: /*0x12b8aa*/
        soisdisconnected(a1); /*0x12bba0*/
        in_pcbdetach((_DWORD *)v5); /*0x12bba6*/
        break; /*0x12bbae*/
      case 12: /*0x12b8aa*/
        splx(v15); /*0x12bbd4*/
        return 0; /*0x12bbdb*/
      case 15: /*0x12b8aa*/
        in_setsockaddr(v5, (int)a4); /*0x12bbb5*/
        break; /*0x12bbbd*/
      case 16: /*0x12b8aa*/
        in_setpeeraddr(v5, (int)a4); /*0x12bbc5*/
        break; /*0x12bbcd*/
      default:
        panic(aUdpUsrreq); /*0x12bbfd*/
        return result; /*0x12bbfd*/
    }
  }
  splx(v15); /*0x12bc05*/
  if ( a3 ) /*0x12bc15*/
    m_freem(a3); /*0x12bc1b*/
  return v6; /*0x12bc25*/
}
