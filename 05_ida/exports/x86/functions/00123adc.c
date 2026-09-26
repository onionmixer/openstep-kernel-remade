/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123adc. */
int __cdecl in_ifinit(int a1, int *a2, int *a3)
{
  int v3; // ebx
  __int16 v5; // ax
  unsigned int v6; // ecx
  _DWORD *v7; // edx
  int v8; // eax
  int v9; // ebx
  int v10; // ecx
  _DWORD *v11; // edx
  __int16 v12; // ax
  int *v13; // eax
  unsigned int v14; // ecx
  _DWORD *v15; // edx
  int *v16; // [esp-Ch] [ebp-44h]
  __int16 v17; // [esp-4h] [ebp-3Ch]
  int v18; // [esp+Ch] [ebp-2Ch]
  int v19; // [esp+10h] [ebp-28h]
  int v20; // [esp+18h] [ebp-20h] BYREF
  unsigned __int32 v21; // [esp+1Ch] [ebp-1Ch]
  int v22; // [esp+28h] [ebp-10h] BYREF
  int v23; // [esp+2Ch] [ebp-Ch]
  int v24; // [esp+30h] [ebp-8h]
  int v25; // [esp+34h] [ebp-4h]

  v18 = _byteswap_ulong(a3[1]); /*0x123af0*/
  v19 = splimp(); /*0x123af8*/
  v22 = *a2; /*0x123afd*/
  v23 = a2[1]; /*0x123b03*/
  v24 = a2[2]; /*0x123b09*/
  v25 = a2[3]; /*0x123b0f*/
  *a2 = *a3; /*0x123b14*/
  a2[1] = a3[1]; /*0x123b19*/
  a2[2] = a3[2]; /*0x123b1f*/
  a2[3] = a3[3]; /*0x123b25*/
  if ( *(_DWORD *)(a1 + 56) && (v3 = if_ioctl(a1, 0x8020690C, (int)a2)) != 0 ) /*0x123b44*/
  {
    splx(v19); /*0x123b4a*/
    *a2 = v22; /*0x123b52*/
    a2[1] = v23; /*0x123b57*/
    a2[2] = v24; /*0x123b5d*/
    a2[3] = v25; /*0x123b63*/
    return v3; /*0x123b66*/
  }
  else
  {
    bzero(&v20, 0x10u); /*0x123b76*/
    LOWORD(v20) = 2; /*0x123b7b*/
    if ( (a2[15] & 1) != 0 ) /*0x123b88*/
    {
      v5 = *(_WORD *)(a1 + 12); /*0x123b8d*/
      if ( (v5 & 8) != 0 ) /*0x123b93*/
      {
        rtinit(&v22, &v22, -2144308725, 4); /*0x123ba0*/
      }
      else if ( (v5 & 0x10) != 0 ) /*0x123ba6*/
      {
        rtinit(a2 + 4, &v22, -2144308725, 4); /*0x123bb6*/
      }
      else
      {
        v6 = a2[12]; /*0x123bb8*/
        v7 = (_DWORD *)in_ifaddr; /*0x123bbb*/
        if ( in_ifaddr ) /*0x123bc3*/
        {
          do /*0x123bd7*/
          {
            if ( v7[10] == (v6 & v7[11]) ) /*0x123bd0*/
              break; /*0x123bd0*/
            v7 = (_DWORD *)v7[16]; /*0x123bd2*/
          }
          while ( v7 ); /*0x123bd7*/
        }
        v21 = _byteswap_ulong(v6); /*0x123be0*/
        rtinit(&v20, &v22, -2144308725, 0); /*0x123bf2*/
      }
      a2[15] &= ~1u; /*0x123bfa*/
    }
    if ( v18 < 0 ) /*0x123c02*/
    {
      if ( (v18 & 0xC0000000) == 0x80000000 ) /*0x123c18*/
        a2[11] = -65536; /*0x123c1f*/
      else
        a2[11] = -256; /*0x123c28*/
    }
    else
    {
      a2[11] = -16777216; /*0x123c04*/
    }
    a2[10] = a2[11] & v18; /*0x123c35*/
    v8 = a2[11] | a2[13]; /*0x123c3b*/
    a2[13] = v8; /*0x123c3e*/
    a2[12] = v18 & v8; /*0x123c44*/
    if ( (*(_BYTE *)(a1 + 12) & 2) != 0 ) /*0x123c4e*/
    {
      *((_WORD *)a2 + 8) = 2; /*0x123c50*/
      v9 = a2[12]; /*0x123c56*/
      if ( v9 < 0 ) /*0x123c5b*/
      {
        v10 = 255; /*0x123c73*/
        if ( (v9 & 0xC0000000) == 0x80000000 ) /*0x123c78*/
          v10 = 0xFFFF; /*0x123c7f*/
      }
      else
      {
        v10 = 0xFFFFFF; /*0x123c5d*/
      }
      v11 = (_DWORD *)in_ifaddr; /*0x123c84*/
      if ( in_ifaddr ) /*0x123c8c*/
      {
        while ( v11[10] != (v9 & v11[11]) ) /*0x123c98*/
        {
          v11 = (_DWORD *)v11[16]; /*0x123c9a*/
          if ( !v11 ) /*0x123c9f*/
            goto LABEL_28; /*0x123c9f*/
        }
        v10 = ~v11[13]; /*0x123c67*/
      }
LABEL_28:
      a2[5] = _byteswap_ulong(v10 | v9); /*0x123ca1*/
      a2[14] = _byteswap_ulong(a2[10] | ~a2[11]); /*0x123cb7*/
    }
    v12 = *(_WORD *)(a1 + 12); /*0x123cbd*/
    if ( (v12 & 8) != 0 ) /*0x123cc3*/
    {
      rtinit(a2, a2, -2144308726, 5); /*0x123cce*/
    }
    else
    {
      if ( (v12 & 0x10) != 0 ) /*0x123cd2*/
      {
        v17 = 5; /*0x123cd4*/
        v16 = a2; /*0x123cdb*/
        v13 = a2 + 4; /*0x123cdc*/
      }
      else
      {
        v14 = a2[12]; /*0x123ce4*/
        v15 = (_DWORD *)in_ifaddr; /*0x123ce7*/
        if ( in_ifaddr ) /*0x123cef*/
        {
          do /*0x123d03*/
          {
            if ( v15[10] == (v14 & v15[11]) ) /*0x123cfc*/
              break; /*0x123cfc*/
            v15 = (_DWORD *)v15[16]; /*0x123cfe*/
          }
          while ( v15 ); /*0x123d03*/
        }
        v21 = _byteswap_ulong(v14); /*0x123d0c*/
        v17 = 1; /*0x123d0f*/
        v16 = a2; /*0x123d16*/
        v13 = &v20; /*0x123d17*/
      }
      rtinit(v13, v16, -2144308726, v17); /*0x123d1b*/
    }
    *((_BYTE *)a2 + 60) |= 1u; /*0x123d23*/
    in_addmulti(_byteswap_ulong(0xE0000001), a1); /*0x123d33*/
    splx(v19); /*0x123d3c*/
    return 0; /*0x123d41*/
  }
}
