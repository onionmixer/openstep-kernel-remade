/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1355a8. */
int __cdecl clntkudp_callit_addr(
        _DWORD *a1,
        char a2,
        int (__cdecl *a3)(int, int),
        int a4,
        unsigned int a5,
        unsigned int a6,
        int a7,
        int a8,
        _DWORD *a9)
{
  int v9; // edi
  int v10; // edx
  int i; // edx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edx
  int v18; // edx
  _DWORD *v19; // ecx
  int v20; // edx
  _DWORD *v21; // eax
  int v22; // edx
  int v23; // edx
  int v24; // edx
  int j; // edx
  int v26; // edx
  unsigned int v28; // [esp+Ch] [ebp-78h]
  rpc_msg *v29; // [esp+10h] [ebp-74h]
  unsigned int v30; // [esp+18h] [ebp-6Ch]
  int v31; // [esp+1Ch] [ebp-68h]
  int v32; // [esp+20h] [ebp-64h]
  int v33; // [esp+24h] [ebp-60h]
  int v34; // [esp+28h] [ebp-5Ch]
  int v35; // [esp+2Ch] [ebp-58h]
  int v36; // [esp+30h] [ebp-54h]
  int v37; // [esp+34h] [ebp-50h]
  int v38; // [esp+34h] [ebp-50h]
  int v39; // [esp+34h] [ebp-50h]
  int v40; // [esp+34h] [ebp-50h]
  int v41; // [esp+38h] [ebp-4Ch]
  int v42; // [esp+3Ch] [ebp-48h]
  int v43; // [esp+40h] [ebp-44h]
  rpc_msg v44; // [esp+44h] [ebp-40h] BYREF
  _DWORD v45[4]; // [esp+74h] [ebp-10h] BYREF

  v9 = a1[2]; /*0x1355b4*/
  v43 = *(_DWORD *)(v9 + 20); /*0x1355ba*/
  v41 = *(_DWORD *)(v9 + 16); /*0x1355c0*/
  v33 = 0; /*0x1355c3*/
  v32 = 2; /*0x1355ca*/
  v31 = *(_DWORD *)active_u; /*0x1355d9*/
  ++rcstat; /*0x1355dc*/
  while ( (*(_BYTE *)v9 & 2) != 0 ) /*0x1355e5*/
  {
    ++dword_1EF1D4; /*0x1355e8*/
    *(_BYTE *)v9 |= 4u; /*0x1355ee*/
    sleep((unsigned int)a1); /*0x1355f7*/
  }
  v10 = *(_DWORD *)v9; /*0x135604*/
  LOBYTE(v10) = *(_DWORD *)v9 | 2; /*0x135606*/
  *(_DWORD *)v9 = v10; /*0x135609*/
  if ( (v10 & 0x20) != 0 ) /*0x13560e*/
    v41 = 1; /*0x135610*/
  lock_write(active_u + 32); /*0x135621*/
  v36 = *(_DWORD *)(active_u + 28); /*0x13562f*/
  *(_DWORD *)(active_u + 28) = *(_DWORD *)(v9 + 116); /*0x135635*/
  v34 = clntkudpxid++; /*0x13563e*/
  v35 = a7 * hz + a8 * hz / 1000000; /*0x135663*/
  while ( 1 ) /*0x13566e*/
  {
    v37 = splimp(); /*0x13566e*/
    for ( i = *(_DWORD *)v9; (*(_DWORD *)v9 & 8) != 0; i = *(_DWORD *)v9 ) /*0x135676*/
    {
      LOBYTE(i) = i | 0x10; /*0x13567c*/
      *(_DWORD *)v9 = i; /*0x13567f*/
      timeout((int)wakeup); /*0x13568e*/
      sleep(v9 + 104); /*0x135696*/
      sbflush((unsigned __int16 *)(v43 + 36)); /*0x1356a2*/
    }
    *(_BYTE *)v9 |= 8u; /*0x1356b1*/
    splx(v37); /*0x1356b8*/
    v29 = (rpc_msg *)mclgetx((int)sub_135D94, v9, *(_DWORD *)(v9 + 104), 8800, 1); /*0x1356d3*/
    if ( v29 ) /*0x1356db*/
    {
      **(_DWORD **)(v9 + 104) = v34; /*0x135719*/
      xdrmbuf_init(v9 + 52, v29, 0); /*0x135722*/
      if ( v33 ) /*0x13572e*/
      {
        (*(void (__cdecl **)(int, int))(*(_DWORD *)(v9 + 56) + 20))(v9 + 52, v33); /*0x13573b*/
      }
      else
      {
        (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v9 + 56) + 20))(v9 + 52, *(_DWORD *)(v9 + 100)); /*0x13574f*/
        if ( !(*(int (__cdecl **)(int, char *))(*(_DWORD *)(v9 + 56) + 4))(v9 + 52, &a2) /*0x135783*/
          || !(*(int (__cdecl **)(_DWORD, int))(*(_DWORD *)(*a1 + 32) + 4))(*a1, v9 + 52)
          || !a3(v9 + 52, a4) )
        {
          *(_DWORD *)(v9 + 40) = 1; /*0x13578c*/
          *(_DWORD *)(v9 + 44) = 5; /*0x135793*/
          v14 = (int)v29; /*0x13579a*/
LABEL_55:
          m_freem(v14); /*0x135abd*/
          goto LABEL_56; /*0x135abe*/
        }
        v33 = (*(int (__cdecl **)(int))(*(_DWORD *)(v9 + 56) + 16))(v9 + 52); /*0x1357ad*/
      }
      LOWORD(v29->ru.RM_cmb.cb_rpcvers) = v33; /*0x1357ba*/
      v15 = ku_sendto_mbuf(v43, v29, v9 + 24); /*0x1357c7*/
      *(_DWORD *)(v9 + 44) = v15; /*0x1357cc*/
      if ( !v15 ) /*0x1357d4*/
      {
        v42 = 2; /*0x13580c*/
        v30 = v43 + 36; /*0x135819*/
        while ( 2 ) /*0x13581c*/
        {
          v39 = splnet(); /*0x13581c*/
          while ( !*(_WORD *)(v43 + 36) ) /*0x1358c5*/
          {
            timeout((int)ckuwakeup); /*0x135836*/
            *(_BYTE *)(v43 + 56) |= 4u; /*0x13583e*/
            if ( v31 && (*(_BYTE *)(v9 + 1) & 8) != 0 ) /*0x13584f*/
            {
              v16 = *(_DWORD *)(v31 + 28); /*0x135854*/
              *(_DWORD *)(v31 + 28) = v16 | 0xFFFBBFFA; /*0x13585f*/
              v17 = sleep(v30); /*0x135870*/
              *(_DWORD *)(v31 + 28) = v16; /*0x135875*/
            }
            else
            {
              sleep(v30); /*0x13588b*/
              v17 = 0; /*0x135893*/
            }
            v28 = v17; /*0x13589c*/
            untimeout((int)ckuwakeup, v9); /*0x13589f*/
            if ( v28 ) /*0x1358ac*/
            {
              splx(v39); /*0x135a70*/
              *(_DWORD *)(v9 + 40) = 18; /*0x135a75*/
              *(_DWORD *)(v9 + 44) = 4; /*0x135a7c*/
              goto LABEL_56; /*0x135a83*/
            }
            v18 = *(_DWORD *)v9; /*0x1358b2*/
            if ( (*(_DWORD *)v9 & 1) != 0 ) /*0x1358b7*/
            {
              LOBYTE(v18) = v18 & 0xFE; /*0x135a88*/
              *(_DWORD *)v9 = v18; /*0x135a8b*/
              splx(v39); /*0x135a91*/
              *(_DWORD *)(v9 + 40) = 5; /*0x135a96*/
              *(_DWORD *)(v9 + 44) = 60; /*0x135a9d*/
              ++dword_1EF1D0; /*0x135aa4*/
              goto LABEL_56; /*0x135aaa*/
            }
          }
          if ( *(_WORD *)(v43 + 86) ) /*0x1358ce*/
          {
            *(_WORD *)(v43 + 86) = 0; /*0x1358d5*/
            splx(v39); /*0x1358df*/
LABEL_39:
            if ( --v42 ) /*0x135966*/
              continue; /*0x135966*/
          }
          else
          {
            *(_DWORD *)(v9 + 112) = ku_recvfrom(v43, v45); /*0x1358f5*/
            if ( a9 ) /*0x1358ff*/
            {
              v19 = a9; /*0x135904*/
              *a9 = v45[0]; /*0x135907*/
              v19[1] = v45[1]; /*0x13590c*/
              v19[2] = v45[2]; /*0x135912*/
              v19[3] = v45[3]; /*0x135918*/
            }
            splx(v39); /*0x13591f*/
            v20 = *(_DWORD *)(v9 + 112); /*0x135927*/
            if ( !v20 ) /*0x13592c*/
              goto LABEL_39; /*0x13592c*/
            v21 = (_DWORD *)(*(_DWORD *)(v20 + 4) + v20); /*0x135930*/
            *(_DWORD *)(v9 + 108) = v21; /*0x135933*/
            if ( *(_WORD *)(*(_DWORD *)(v9 + 112) + 8) <= 3u ) /*0x13593e*/
            {
              m_freem(*(_DWORD *)(v9 + 112)); /*0x135941*/
              goto LABEL_39; /*0x135941*/
            }
            if ( *v21 != **(_DWORD **)(v9 + 104) ) /*0x13594b*/
            {
              ++dword_1EF1CC; /*0x135951*/
              m_freem(*(_DWORD *)(v9 + 112)); /*0x13595b*/
              goto LABEL_39; /*0x13595b*/
            }
            v38 = splnet(); /*0x1357e9*/
            sbflush((unsigned __int16 *)(v43 + 36)); /*0x1357f3*/
            splx(v38); /*0x1357fc*/
          }
          break;
        }
        if ( !v42 ) /*0x135970*/
        {
          *(_DWORD *)(v9 + 40) = 4; /*0x135972*/
          *(_DWORD *)(v9 + 44) = 5; /*0x135979*/
          goto LABEL_56; /*0x135980*/
        }
        xdrmbuf_init(v9 + 76, *(_DWORD *)(v9 + 112), 1); /*0x135992*/
        v44.ru.RM_rmb.ru.RP_ar.ar_verf = _null_auth; /*0x13599d*/
        *((_QWORD *)&v44.ru.RM_rmb.ru.RP_dr + 2) = __PAIR64__(a5, a6); /*0x1359b5*/
        if ( xdr_replymsg((XDR *)(v9 + 76), &v44) ) /*0x1359c6*/
        {
          _seterr_reply(&v44, (rpc_err *)(v9 + 40)); /*0x1359de*/
          if ( *(_DWORD *)(v9 + 40) ) /*0x1359e6*/
          {
            if ( v32 > 0 && (*(int (__cdecl **)(_DWORD))(*(_DWORD *)(*a1 + 32) + 12))(*a1) ) /*0x135a4e*/
            {
              --v32; /*0x135a57*/
              ++dword_1EF1D8; /*0x135a5a*/
              v33 = 0; /*0x135a60*/
            }
          }
          else
          {
            if ( !(*(int (__cdecl **)(_DWORD, reply_body::$B1794D2A0DAD208A76987CA2B117700C *))(*(_DWORD *)(*a1 + 32) + 8))( /*0x1359ff*/
                    *a1,
                    &v44.ru.RM_rmb.ru) )
            {
              *(_DWORD *)(v9 + 40) = 7; /*0x135a08*/
              *(_DWORD *)(v9 + 44) = 6; /*0x135a0f*/
              ++dword_1EF1DC; /*0x135a16*/
            }
            if ( v44.ru.RM_cmb.cb_vers ) /*0x135a20*/
            {
              *(_DWORD *)(v9 + 76) = 2; /*0x135a26*/
              xdr_opaque_auth((XDR *)(v9 + 76), &v44.ru.RM_rmb.ru.RP_ar.ar_verf.oa_flavor); /*0x135a32*/
            }
          }
        }
        else
        {
          *(_DWORD *)(v9 + 40) = 2; /*0x135aac*/
          *(_DWORD *)(v9 + 44) = 5; /*0x135ab3*/
        }
        v14 = *(_DWORD *)(v9 + 112); /*0x135aba*/
        goto LABEL_55; /*0x135aba*/
      }
      *(_DWORD *)(v9 + 40) = 3; /*0x1357d6*/
    }
    else
    {
      *(_DWORD *)(v9 + 40) = 12; /*0x1356dd*/
      *(_DWORD *)(v9 + 44) = 55; /*0x1356e4*/
      v12 = *(_DWORD *)v9; /*0x1356eb*/
      v13 = *(_DWORD *)v9; /*0x1356ed*/
      LOBYTE(v13) = *(_DWORD *)v9 & 0xF7; /*0x1356ef*/
      *(_DWORD *)v9 = v13; /*0x1356f2*/
      if ( (v12 & 0x10) != 0 ) /*0x1356f7*/
      {
        LOBYTE(v12) = v12 & 0xE7; /*0x1356fd*/
        *(_DWORD *)v9 = v12; /*0x135700*/
        wakeup(v9 + 104); /*0x135706*/
      }
    }
LABEL_56:
    v22 = *(_DWORD *)(v9 + 40); /*0x135ac6*/
    if ( !v22 ) /*0x135acb*/
      break; /*0x135acb*/
    if ( v22 == 18 ) /*0x135ad0*/
      break; /*0x135ad0*/
    if ( v22 == 1 ) /*0x135ad5*/
      break; /*0x135ad5*/
    if ( --v41 <= 0 ) /*0x135ade*/
      break; /*0x135ade*/
    ++dword_1EF1C8; /*0x135ae0*/
    v23 = 60 * hz; /*0x135af9*/
    if ( 2 * v35 <= 60 * hz ) /*0x135afe*/
      v23 = 2 * v35; /*0x135b00*/
    v35 = v23; /*0x135b02*/
    v24 = *(_DWORD *)(v9 + 40); /*0x135b05*/
    if ( v24 == 12 || v24 == 3 ) /*0x135b10*/
      sleep((unsigned int)&lbolt); /*0x135b1d*/
  }
  *(_DWORD *)(active_u + 28) = v36; /*0x135b35*/
  lock_done(active_u + 32); /*0x135b42*/
  v40 = splimp(); /*0x135b4c*/
  for ( j = *(_DWORD *)v9; (*(_DWORD *)v9 & 8) != 0; j = *(_DWORD *)v9 ) /*0x135b57*/
  {
    LOBYTE(j) = j | 0x10; /*0x135b5c*/
    *(_DWORD *)v9 = j; /*0x135b5f*/
    timeout((int)wakeup); /*0x135b6e*/
    sleep(v9 + 104); /*0x135b76*/
    sbflush((unsigned __int16 *)(v43 + 36)); /*0x135b82*/
  }
  splx(v40); /*0x135b95*/
  v26 = *(_DWORD *)v9; /*0x135b9a*/
  *(_DWORD *)v9 &= ~2u; /*0x135ba1*/
  if ( (v26 & 4) != 0 ) /*0x135ba9*/
  {
    LOBYTE(v26) = v26 & 0xF9; /*0x135bab*/
    *(_DWORD *)v9 = v26; /*0x135bae*/
    wakeup((int)a1); /*0x135bb4*/
  }
  if ( *(_DWORD *)(v9 + 40) ) /*0x135bb9*/
    ++dword_1EF1C4; /*0x135bbf*/
  return *(_DWORD *)(v9 + 40); /*0x135bce*/
}
