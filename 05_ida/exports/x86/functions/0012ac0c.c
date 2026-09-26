/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12ac0c. */
int __usercall tcp_usrreq@<eax>(int a1@<ebx>, int a2, int a3, signed int a4, int a5, int a6)
{
  int v6; // edi
  int result; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  char v15; // al
  int v16; // eax
  __int16 v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+14h] [ebp-4h]

  v6 = 0; /*0x12ac18*/
  if ( a3 == 11 ) /*0x12ac1e*/
    return in_control(a2, a4, (_DWORD *)a5, a6); /*0x12ac32*/
  if ( a6 && *(_WORD *)(a6 + 8) ) /*0x12ac3c*/
    return 22; /*0x12ac48*/
  v8 = splnet(); /*0x12ac50*/
  v18 = v8; /*0x12ac55*/
  v9 = *(_DWORD *)(a2 + 8); /*0x12ac5b*/
  if ( v9 ) /*0x12ac60*/
  {
    a1 = *(_DWORD *)(v9 + 32); /*0x12ac78*/
    v17 = *(_WORD *)(a1 + 8); /*0x12ac7f*/
  }
  else
  {
    if ( a3 ) /*0x12ac66*/
    {
      splx(v8); /*0x12ac69*/
      return 22; /*0x12ac73*/
    }
    v17 = 0; /*0x12ac84*/
  }
  switch ( a3 ) /*0x12ac98*/
  {
    case 0: /*0x12ac98*/
      if ( v9 ) /*0x12acf2*/
      {
        v6 = 56; /*0x12acf4*/
      }
      else
      {
        v6 = tcp_attach(a2); /*0x12ad09*/
        if ( !v6 ) /*0x12ad10*/
        {
          if ( *(char *)(a2 + 2) < 0 && !*(_WORD *)(a2 + 4) ) /*0x12ad1f*/
            *(_WORD *)(a2 + 4) = 120; /*0x12ad26*/
          a1 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 32); /*0x12ad32*/
        }
      }
      goto LABEL_59; /*0x12acf9*/
    case 1: /*0x12ac98*/
      if ( *(__int16 *)(a1 + 8) > 1 ) /*0x12ad41*/
        goto LABEL_20; /*0x12ad41*/
      a1 = tcp_close((_DWORD *)a1); /*0x12ad56*/
      goto LABEL_59; /*0x12ad58*/
    case 2: /*0x12ac98*/
      v10 = in_pcbbind(v9, a5); /*0x12ad65*/
      goto LABEL_33; /*0x12ad6a*/
    case 3: /*0x12ac98*/
      if ( !*(_WORD *)(v9 + 24) ) /*0x12ad70*/
        v6 = in_pcbbind(v9, 0); /*0x12ad7f*/
      if ( !v6 ) /*0x12ad86*/
        *(_WORD *)(a1 + 8) = 1; /*0x12ad8c*/
      goto LABEL_59; /*0x12ad92*/
    case 4: /*0x12ac98*/
      if ( !*(_WORD *)(v9 + 24) ) /*0x12ad98*/
      {
        v6 = in_pcbbind(v9, 0); /*0x12ada7*/
        if ( v6 ) /*0x12adae*/
          goto LABEL_59; /*0x12adae*/
      }
      v6 = in_pcbconnect(v9, a5); /*0x12adbe*/
      if ( v6 ) /*0x12adc5*/
        goto LABEL_59; /*0x12adc5*/
      v11 = tcp_template(a1); /*0x12adcc*/
      *(_DWORD *)(a1 + 28) = v11; /*0x12add1*/
      if ( v11 ) /*0x12add9*/
      {
        soisconnecting(a2); /*0x12adf0*/
        ++tcpstat; /*0x12adf5*/
        *(_WORD *)(a1 + 8) = 2; /*0x12adfb*/
        *(_WORD *)(a1 + 14) = 150; /*0x12ae01*/
        *(_DWORD *)(a1 + 56) = tcp_iss; /*0x12ae0d*/
        tcp_iss += 64000; /*0x12ae10*/
        v12 = *(_DWORD *)(a1 + 56); /*0x12ae1a*/
        *(_DWORD *)(a1 + 44) = v12; /*0x12ae1d*/
        *(_DWORD *)(a1 + 80) = v12; /*0x12ae20*/
        *(_DWORD *)(a1 + 40) = v12; /*0x12ae23*/
        *(_DWORD *)(a1 + 36) = v12; /*0x12ae26*/
        v10 = tcp_output(a1); /*0x12ae2a*/
LABEL_33:
        v6 = v10; /*0x12ae2f*/
      }
      else
      {
        in_pcbdisconnect(v9); /*0x12addc*/
        v6 = 55; /*0x12ade1*/
      }
      goto LABEL_59; /*0x12ade6*/
    case 5: /*0x12ac98*/
      v13 = *(_DWORD *)(a5 + 4) + a5; /*0x12ae5b*/
      *(_WORD *)(a5 + 8) = 16; /*0x12ae61*/
      *(_WORD *)v13 = 2; /*0x12ae67*/
      *(_WORD *)(v13 + 2) = *(_WORD *)(v9 + 16); /*0x12ae70*/
      *(_DWORD *)(v13 + 4) = *(_DWORD *)(v9 + 12); /*0x12ae77*/
      goto LABEL_59; /*0x12ae7a*/
    case 6: /*0x12ac98*/
LABEL_20:
      a1 = tcp_disconnect(a1); /*0x12ad43*/
      goto LABEL_59; /*0x12ad4b*/
    case 7: /*0x12ac98*/
      socantsendmore(a2); /*0x12ae84*/
      v14 = tcp_usrclosed(a1); /*0x12ae8a*/
      a1 = v14; /*0x12ae8f*/
      if ( !v14 ) /*0x12ae96*/
        goto LABEL_62; /*0x12ae96*/
      v6 = tcp_output(v14); /*0x12aea2*/
LABEL_59:
      if ( a1 ) /*0x12b02b*/
      {
        if ( (*(_BYTE *)(a2 + 2) & 1) != 0 ) /*0x12b034*/
          tcp_trace(2, v17, (const void *)a1, nullptr, a3); /*0x12b043*/
      }
LABEL_62:
      splx(v18); /*0x12b04b*/
      result = v6; /*0x12b054*/
      break; /*0x12b05f*/
    case 8: /*0x12ac98*/
      tcp_output(a1); /*0x12aead*/
      goto LABEL_59; /*0x12aeb2*/
    case 9: /*0x12ac98*/
      sbappend(a2 + 60, a4); /*0x12aec3*/
      v6 = tcp_output(a1); /*0x12aece*/
      goto LABEL_59; /*0x12aed3*/
    case 10: /*0x12ac98*/
      a1 = tcp_drop(a1, 53); /*0x12aee0*/
      goto LABEL_59; /*0x12aee5*/
    case 12: /*0x12ac98*/
      *(_DWORD *)(a4 + 48) = *(unsigned __int16 *)(a2 + 62); /*0x12aef6*/
      splx(v8); /*0x12aefd*/
      return 0; /*0x12af04*/
    case 13: /*0x12ac98*/
      if ( (*(_WORD *)(a2 + 88) || (*(_BYTE *)(a2 + 6) & 0x40) != 0) /*0x12af2a*/
        && (*(_BYTE *)(a2 + 3) & 1) == 0
        && (v15 = *(_BYTE *)(a1 + 104), (v15 & 2) == 0) )
      {
        if ( (v15 & 1) != 0 ) /*0x12af3a*/
        {
          *(_WORD *)(a4 + 8) = 1; /*0x12af4b*/
          *(_BYTE *)(*(_DWORD *)(a4 + 4) + a4) = *(_BYTE *)(a1 + 105); /*0x12af57*/
          if ( (a5 & 2) == 0 ) /*0x12af60*/
            *(_BYTE *)(a1 + 104) ^= 3u; /*0x12af66*/
        }
        else
        {
          v6 = 35; /*0x12af3c*/
        }
      }
      else
      {
        v6 = 22; /*0x12af2c*/
      }
      goto LABEL_59; /*0x12af31*/
    case 14: /*0x12ac98*/
      v16 = *(unsigned __int16 *)(a2 + 62) - *(unsigned __int16 *)(a2 + 60); /*0x12af8c*/
      if ( v16 > *(unsigned __int16 *)(a2 + 66) - *(unsigned __int16 *)(a2 + 64) ) /*0x12af90*/
        v16 = *(unsigned __int16 *)(a2 + 66) - *(unsigned __int16 *)(a2 + 64); /*0x12af92*/
      if ( v16 >= -512 ) /*0x12af99*/
      {
        sbappend(a2 + 60, a4); /*0x12afb7*/
        *(_DWORD *)(a1 + 44) = *(_DWORD *)(a1 + 36) + *(unsigned __int16 *)(a2 + 60); /*0x12afc6*/
        *(_BYTE *)(a1 + 26) = 1; /*0x12afc9*/
        v6 = tcp_output(a1); /*0x12afd3*/
        *(_BYTE *)(a1 + 26) = 0; /*0x12afd5*/
      }
      else
      {
        m_freem(a4); /*0x12af9f*/
        v6 = 55; /*0x12afa4*/
      }
      goto LABEL_59; /*0x12afa9*/
    case 15: /*0x12ac98*/
      in_setsockaddr(v9, a5); /*0x12afe5*/
      goto LABEL_59; /*0x12afed*/
    case 16: /*0x12ac98*/
      in_setpeeraddr(v9, a5); /*0x12aff5*/
      goto LABEL_59; /*0x12affd*/
    case 17: /*0x12ac98*/
      v6 = 45; /*0x12ae3c*/
      goto LABEL_59; /*0x12ae41*/
    case 19: /*0x12ac98*/
      a1 = tcp_timers(a1, a5); /*0x12b00a*/
      LOWORD(a3) = ((_WORD)a5 << 8) | a3; /*0x12b012*/
      goto LABEL_59; /*0x12b012*/
    default:
      panic(aTcpUsrreq); /*0x12b021*/
      return result; /*0x12b021*/
  }
  return result; /*0x12b059*/
}
