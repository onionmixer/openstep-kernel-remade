/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126e90. */
void __usercall ip_forward(int a1@<esi>, _DWORD *a2, int a3)
{
  int v3; // eax
  unsigned __int8 v4; // al
  int *v5; // eax
  __int16 v6; // ax
  int v7; // eax
  _DWORD *v8; // edx
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // eax
  unsigned int *v12; // ebx
  int v13; // [esp-Ch] [ebp-2Ch]
  unsigned __int32 v14; // [esp+Ch] [ebp-14h]
  unsigned __int32 v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h] BYREF

  v17 = 0; /*0x126e9c*/
  v18 = 0; /*0x126ea3*/
  if ( ipprintfs )
    printf("forward: src %x dst %x ttl %x\n", a2[3], a2[4], *((unsigned __int8 *)a2 + 8));
  *((_WORD *)a2 + 2) = __ROR2__(*((_WORD *)a2 + 2), 8); /*0x126ed5*/
  if ( !ipforwarding || in_interfaces <= 1 ) /*0x126ee9*/
  {
    ++dword_1EAAD8; /*0x126eeb*/
LABEL_7:
    v3 = (int)a2; /*0x126f04*/
    LOBYTE(v3) = (unsigned __int8)a2 & 0x80; /*0x126f06*/
    m_freem(v3); /*0x126f09*/
    return; /*0x126f0e*/
  }
  if ( !in_canforward(a2[4]) ) /*0x126ef8*/
    goto LABEL_7; /*0x126f02*/
  v4 = *((_BYTE *)a2 + 8); /*0x126f14*/
  if ( v4 <= 1u ) /*0x126f19*/
  {
    icmp_error(a2, 0xBu, 0, a3, &v18); /*0x126f24*/
    return; /*0x126f24*/
  }
  *((_BYTE *)a2 + 8) = v4 - 1; /*0x126f2e*/
  v13 = imin(*((__int16 *)a2 + 1), 64); /*0x126f3d*/
  v5 = a2; /*0x126f40*/
  LOBYTE(v5) = (unsigned __int8)a2 & 0x80; /*0x126f42*/
  v16 = m_copy(v5, 0, v13); /*0x126f4a*/
  if ( !ipforward_rt ) /*0x126f58*/
    goto LABEL_17; /*0x126f58*/
  if ( a2[4] != dword_1EACF8 ) /*0x126f62*/
  {
    if ( ipforward_rt ) /*0x126f66*/
    {
      v6 = *(_WORD *)(ipforward_rt + 38); /*0x126f68*/
      if ( v6 == 1 ) /*0x126f70*/
        rtfree(ipforward_rt); /*0x126f73*/
      else
        *(_WORD *)(ipforward_rt + 38) = v6 - 1; /*0x126f82*/
      ipforward_rt = 0; /*0x126f86*/
    }
LABEL_17:
    word_1EACF4 = 2; /*0x126f90*/
    dword_1EACF8 = a2[4]; /*0x126f9c*/
    rtalloc(&ipforward_rt); /*0x126fa7*/
  }
  if ( ipforward_rt ) /*0x126fb6*/
  {
    if ( *(_DWORD *)(ipforward_rt + 44) == a3 && (*(_BYTE *)(ipforward_rt + 36) & 0x30) == 0 ) /*0x126fcc*/
    {
      if ( *(_DWORD *)(ipforward_rt + 8) ) /*0x126fd2*/
      {
        if ( ipsendredirects ) /*0x126fe3*/
        {
          if ( (*(_BYTE *)a2 & 0xF) == 5 ) /*0x126ff1*/
          {
            v14 = _byteswap_ulong(a2[3]); /*0x126ffc*/
            v15 = _byteswap_ulong(a2[4]); /*0x127004*/
            v7 = ifptoia(a3); /*0x127008*/
            if ( v7 ) /*0x127014*/
            {
              if ( *(_DWORD *)(v7 + 48) == (*(_DWORD *)(v7 + 52) & v14) ) /*0x127023*/
              {
                if ( (*(_BYTE *)(ipforward_rt + 36) & 2) != 0 ) /*0x12702e*/
                  v18 = *(_DWORD *)(ipforward_rt + 24); /*0x127033*/
                else
                  v18 = a2[4]; /*0x12703b*/
                v17 = 5; /*0x12703e*/
                a1 = 0; /*0x127045*/
                if ( (*(_WORD *)(ipforward_rt + 36) & 6) == 2 ) /*0x127058*/
                {
                  v8 = (_DWORD *)in_ifaddr; /*0x12705a*/
                  while ( 1 ) /*0x127080*/
                  {
                    v8 = (_DWORD *)v8[16]; /*0x127080*/
                    if ( !v8 ) /*0x127085*/
                      break; /*0x127085*/
                    v9 = v8[11]; /*0x127064*/
                    if ( v8[10] == (v9 & v15) ) /*0x12706f*/
                    {
                      if ( v8[13] == v9 ) /*0x127074*/
                        break; /*0x127074*/
                      goto LABEL_33; /*0x127074*/
                    }
                  }
                }
                else
                {
LABEL_33:
                  a1 = 1; /*0x127076*/
                }
                if ( ipprintfs ) /*0x12708e*/
                  printf("redirect (%d) to %x\n", a1, v18); /*0x12709a*/
              }
            }
          }
        }
      }
    }
  }
  v10 = a2; /*0x1270ab*/
  LOBYTE(v10) = (unsigned __int8)a2 & 0x80; /*0x1270ad*/
  v11 = ip_output(v10, 0, &ipforward_rt, 1); /*0x1270b0*/
  if ( v11 ) /*0x1270ba*/
  {
    ++dword_1EAAD8; /*0x1270bc*/
    goto LABEL_44; /*0x1270c2*/
  }
  if ( v17 ) /*0x1270c8*/
  {
    ++dword_1EAADC; /*0x1270ca*/
LABEL_44:
    if ( v16 ) /*0x1270f4*/
    {
      v12 = (unsigned int *)(*(_DWORD *)(v16 + 4) + v16); /*0x1270fd*/
      switch ( v11 ) /*0x127110*/
      {
        case 0: /*0x127110*/
          icmp_error(v12, 5u, a1, a3, &v18); /*0x127227*/
          return; /*0x127227*/
        case 1: /*0x127110*/
          LOBYTE(a1) = 3; /*0x127248*/
          break; /*0x12724d*/
        case 40: /*0x127110*/
          LOBYTE(a1) = 4; /*0x127240*/
          break; /*0x127245*/
        case 50: /*0x127110*/
        case 51: /*0x127110*/
          LOBYTE(a1) = 0; /*0x127238*/
          if ( in_localaddr(v12[4]) ) /*0x127230*/
            goto LABEL_52; /*0x12723c*/
          break; /*0x12723c*/
        case 55: /*0x127110*/
          icmp_error(v12, 4u, a1, a3, &v18); /*0x127257*/
          return; /*0x127257*/
        case 64: /*0x127110*/
        case 65: /*0x127110*/
LABEL_52:
          LOBYTE(a1) = 1; /*0x12725c*/
          break; /*0x12725c*/
        default:
          break;
      }
      icmp_error(v12, 3u, a1, a3, &v18); /*0x127261*/
    }
    return; /*0x12726f*/
  }
  if ( v16 ) /*0x1270d8*/
    m_freem(v16); /*0x1270de*/
  ++dword_1EAAD4; /*0x1270e3*/
}
