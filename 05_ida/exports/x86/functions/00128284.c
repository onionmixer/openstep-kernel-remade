/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x128284. */
int __cdecl rip_output(int a1, int a2)
{
  __int16 v2; // bx
  int v3; // esi
  __int16 v4; // ax
  int i; // edx
  int *v6; // eax
  int v7; // edx
  int v8; // ebx
  char *v9; // edi
  int v10; // edi
  int v11; // ebx
  _DWORD *v12; // eax
  int v13; // ebx

  v2 = 0; /*0x12828d*/
  v3 = *(_DWORD *)(a2 + 8); /*0x128292*/
  v4 = *(_WORD *)(v3 + 46); /*0x128295*/
  if ( v4 == 255 || v4 == 2 ) /*0x1282a7*/
  {
    v7 = a1; /*0x128340*/
    v10 = *(_DWORD *)(a1 + 4) + a1; /*0x128342*/
    v11 = *(_DWORD *)(v10 + 12); /*0x128345*/
    if ( v11 ) /*0x12834a*/
    {
      v12 = (_DWORD *)in_ifaddr; /*0x12834c*/
      if ( in_ifaddr ) /*0x128353*/
      {
        do /*0x128362*/
        {
          if ( v12[1] == v11 ) /*0x12835b*/
            break; /*0x12835b*/
          v12 = (_DWORD *)v12[16]; /*0x12835d*/
        }
        while ( v12 ); /*0x128362*/
      }
      v13 = 0; /*0x128364*/
      if ( v12 ) /*0x128368*/
        v13 = v12[8]; /*0x12836a*/
      if ( !v13 ) /*0x12836f*/
      {
        v8 = 49; /*0x128371*/
        goto LABEL_23; /*0x128376*/
      }
    }
    *(_DWORD *)(v10 + 16) = *(_DWORD *)(v3 + 16); /*0x12837b*/
    return ip_output(v7, *(_DWORD *)(v3 + 52), (int *)(v3 + 56), *(_BYTE *)(a2 + 2) & 0x10 | 0x22, *(_DWORD *)(v3 + 80)); /*0x12837b*/
  }
  for ( i = a1; i; i = *(_DWORD *)i ) /*0x1282b1*/
    v2 += *(_WORD *)(i + 8); /*0x1282b8*/
  v6 = m_get(0, 2); /*0x1282c4*/
  v7 = (int)v6; /*0x1282c9*/
  if ( v6 ) /*0x1282d0*/
  {
    v6[1] = 104; /*0x1282e0*/
    *((_WORD *)v6 + 4) = 20; /*0x1282e7*/
    *v6 = a1; /*0x1282ed*/
    v9 = (char *)v6 + v6[1]; /*0x1282f1*/
    v9[1] = 0; /*0x1282f4*/
    *((_WORD *)v9 + 3) = 0; /*0x1282f8*/
    v9[9] = *(_BYTE *)(v3 + 46); /*0x128301*/
    *((_WORD *)v9 + 1) = v2 + 20; /*0x128308*/
    if ( (*(_BYTE *)(v3 + 76) & 1) != 0 ) /*0x128310*/
    {
      if ( *(_WORD *)(v3 + 28) != 2 ) /*0x128317*/
      {
        v8 = 47; /*0x128319*/
        goto LABEL_23; /*0x12831e*/
      }
      *((_DWORD *)v9 + 3) = *(_DWORD *)(v3 + 32); /*0x128327*/
    }
    else
    {
      *((_DWORD *)v9 + 3) = 0; /*0x12832c*/
    }
    *((_DWORD *)v9 + 4) = *(_DWORD *)(v3 + 16); /*0x128336*/
    v9[8] = -1; /*0x128339*/
    return ip_output(v7, *(_DWORD *)(v3 + 52), (int *)(v3 + 56), *(_BYTE *)(a2 + 2) & 0x10 | 0x22, *(_DWORD *)(v3 + 80)); /*0x12839f*/
  }
  v7 = a1; /*0x1282d2*/
  v8 = 55; /*0x1282d4*/
LABEL_23:
  m_freem(v7); /*0x1283a4*/
  return v8; /*0x1283af*/
}
