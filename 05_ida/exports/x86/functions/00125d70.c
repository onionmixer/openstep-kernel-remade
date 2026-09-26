/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125d70. */
int __cdecl icmp_sendMaskPacket(int a1, char a2, int a3)
{
  int v3; // esi
  __int16 v4; // ax
  int v6; // eax
  int v7; // edi
  int *v8; // eax
  int v9; // eax
  int v10; // ebx
  unsigned __int32 v11; // eax
  int v12; // ebx
  __int16 v13; // ax
  int v14; // [esp+Ch] [ebp-18h]
  _WORD v15[2]; // [esp+14h] [ebp-10h] BYREF
  int v16; // [esp+18h] [ebp-Ch]

  v3 = 0; /*0x125d82*/
  v4 = *(_WORD *)(a1 + 12); /*0x125d84*/
  if ( (v4 & 1) == 0 || (v4 & 8) != 0 ) /*0x125d8e*/
    return 0; /*0x125d92*/
  v6 = in_ifaddr; /*0x125da0*/
  if ( in_ifaddr ) /*0x125da7*/
  {
    while ( *(_DWORD *)(v6 + 32) != a1 ) /*0x125daf*/
    {
      v6 = *(_DWORD *)(v6 + 64); /*0x125db1*/
      if ( !v6 ) /*0x125db6*/
        goto LABEL_8; /*0x125db6*/
    }
    v14 = v6; /*0x125d98*/
  }
  else
  {
LABEL_8:
    v14 = 0; /*0x125db8*/
  }
  if ( v14 ) /*0x125dc3*/
  {
    v8 = m_get(1, 2); /*0x125dd4*/
    v3 = (int)v8; /*0x125dd9*/
    if ( v8 ) /*0x125de0*/
    {
      *((_WORD *)v8 + 4) = 32; /*0x125dec*/
      v8[1] = 92; /*0x125df2*/
      bzero(v8 + 23, *((__int16 *)v8 + 4)); /*0x125e02*/
      *(_WORD *)(v3 + 8) -= 20; /*0x125e07*/
      v9 = *(_DWORD *)(v3 + 4) + 20; /*0x125e0f*/
      *(_DWORD *)(v3 + 4) = v9; /*0x125e12*/
      v10 = v9 + v3; /*0x125e15*/
      if ( a2 == 18 ) /*0x125e1f*/
      {
        *(_BYTE *)v10 = 18; /*0x125e21*/
        v11 = _byteswap_ulong(*(_DWORD *)(v14 + 52)); /*0x125e2a*/
        *(_DWORD *)(v10 + 8) = v11; /*0x125e2c*/
        if ( !v11 ) /*0x125e31*/
        {
          v7 = 22; /*0x125e33*/
          goto LABEL_21; /*0x125e38*/
        }
      }
      else
      {
        *(_BYTE *)v10 = 17; /*0x125e40*/
      }
      *(_BYTE *)(v10 + 1) = 0; /*0x125e43*/
      *(_WORD *)(v10 + 2) = 0; /*0x125e47*/
      *(_DWORD *)(v10 + 4) = 0; /*0x125e4d*/
      *(_WORD *)(v10 + 2) = in_cksum(v3, 12); /*0x125e5c*/
      *(_DWORD *)(v3 + 4) -= 20; /*0x125e60*/
      *(_WORD *)(v3 + 8) += 20; /*0x125e64*/
      v12 = *(_DWORD *)(v3 + 4) + v3; /*0x125e6b*/
      *(_BYTE *)v12 = 69; /*0x125e6e*/
      v13 = ip_id++; /*0x125e71*/
      *(_WORD *)(v12 + 4) = __ROR2__(v13, 8); /*0x125e85*/
      *(_BYTE *)(v12 + 8) = -1; /*0x125e89*/
      *(_BYTE *)(v12 + 9) = 1; /*0x125e8d*/
      *(_DWORD *)(v12 + 12) = *(_DWORD *)(v14 + 4); /*0x125e97*/
      *(_DWORD *)(v12 + 16) = -1; /*0x125e9a*/
      *(_WORD *)(v12 + 2) = __ROR2__(32, 8); /*0x125eaa*/
      *(_WORD *)(v12 + 10) = 0; /*0x125eae*/
      *(_WORD *)(v12 + 10) = in_cksum(v3, 20); /*0x125ebc*/
      v15[0] = 2; /*0x125ec0*/
      v15[1] = 0; /*0x125ec6*/
      v16 = -1; /*0x125ecc*/
      if ( a3 > 0 ) /*0x125eda*/
      {
        timeout((int)wakeup); /*0x125ef3*/
        sleep(v14 + 52); /*0x125efb*/
      }
      v7 = if_output_mbuf(a1, v3, (int)v15); /*0x125f0e*/
      v3 = 0; /*0x125f10*/
      if ( a2 == 17 ) /*0x125f19*/
      {
        timeout((int)wakeup); /*0x125f2e*/
        sleep(v14 + 52); /*0x125f36*/
      }
      goto LABEL_21; /*0x125f36*/
    }
    v7 = 55; /*0x125de2*/
  }
  else
  {
    v7 = 51; /*0x125dc5*/
  }
LABEL_21:
  if ( v3 ) /*0x125f40*/
    m_freem(v3); /*0x125f43*/
  return v7; /*0x125f4d*/
}
