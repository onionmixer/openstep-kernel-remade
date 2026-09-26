/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13ed2c. */
int __cdecl sub_13ED2C(int a1, _DWORD *a2)
{
  int v2; // eax
  unsigned int v3; // esi
  char v4; // dl
  int result; // eax
  int v6; // eax
  _WORD *v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-10h]
  unsigned __int16 *v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]

  v2 = a2[1]; /*0x13ed3b*/
  v3 = a2[2] + v2; /*0x13ed40*/
  if ( *a2 ) /*0x13ed43*/
  {
    if ( *(_DWORD *)(a1 + 108) >= v3 ) /*0x13eddf*/
      goto LABEL_14; /*0x13eddf*/
    *(_DWORD *)(a1 + 108) = (v3 + 1023) & 0xFFFFFC00; /*0x13edec*/
  }
  else
  {
    if ( (v2 & 0x3FF) != 0 ) /*0x13ed51*/
      panic(aDirprepareentr); /*0x13ed58*/
    if ( *(int *)(*(_DWORD *)(a1 + 80) + 52) <= 1023 ) /*0x13ed6a*/
      panic(aDirblksizFsize); /*0x13ed71*/
    if ( bmap( /*0x13edae*/
           a1,
           a2[1] >> *(_DWORD *)(*(_DWORD *)(a1 + 80) + 80),
           0,
           (a2[1] & ~*(_DWORD *)(*(_DWORD *)(a1 + 80) + 72)) + 1024,
           nullptr) <= 0
      || *(_BYTE *)(dword_1E875C + 104) )
    {
      v4 = *(_BYTE *)(dword_1E875C + 104); /*0x13edb9*/
      result = 28; /*0x13edbc*/
      if ( v4 ) /*0x13edc3*/
        return v4; /*0x13edc9*/
      return result; /*0x13edcc*/
    }
    *(_DWORD *)(a1 + 108) = v3; /*0x13edd4*/
  }
  *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13edef*/
LABEL_14:
  v6 = blkatoff(a1, a2[1], a2 + 4); /*0x13edf3*/
  a2[3] = v6; /*0x13ee0a*/
  if ( !v6 ) /*0x13ee12*/
    return *(char *)(dword_1E875C + 104); /*0x13ee19*/
  v7 = (_WORD *)a2[4]; /*0x13ee27*/
  if ( *a2 ) /*0x13ee2a*/
  {
    if ( *a2 > 2u ) /*0x13ee4b*/
      panic(aDirprepareentr_0); /*0x13eeed*/
    v13 = a2[4]; /*0x13ee51*/
    v8 = (unsigned __int16)v7[3] + 4; /*0x13ee58*/
    LOBYTE(v8) = v8 & 0xFC; /*0x13ee5b*/
    v9 = v8 + 8; /*0x13ee5d*/
    v14 = (unsigned __int16)v7[2] - (v8 + 8); /*0x13ee68*/
    v11 = (unsigned __int16)v7[2]; /*0x13ee6b*/
    while ( a2[2] > v11 ) /*0x13ee74*/
    {
      v12 = (unsigned __int16 *)(v11 + v13); /*0x13ee7e*/
      if ( *(_DWORD *)v7 ) /*0x13ee81*/
      {
        v7[2] = v9; /*0x13ee86*/
        v7 = (_WORD *)((char *)v7 + v9); /*0x13ee8a*/
      }
      else
      {
        v14 += v9; /*0x13ee90*/
      }
      v10 = v12[3] + 4; /*0x13ee9a*/
      LOBYTE(v10) = v10 & 0xFC; /*0x13ee9d*/
      v9 = v10 + 8; /*0x13ee9f*/
      v14 += v12[2] - (v10 + 8); /*0x13eeaa*/
      v11 += v12[2]; /*0x13eead*/
      bcopy(v12, v7, v10 + 8); /*0x13eeb3*/
    }
    if ( *(_DWORD *)v7 ) /*0x13eec6*/
    {
      v7[2] = v9; /*0x13eed8*/
      v7 = (_WORD *)((char *)v7 + v9); /*0x13eedc*/
      v7[2] = v14; /*0x13eee2*/
    }
    else
    {
      v7[2] = v9 + v14; /*0x13eed2*/
    }
  }
  else
  {
    bzero(v7, 0x400u); /*0x13ee36*/
    v7[2] = 1024; /*0x13ee3b*/
  }
  a2[4] = v7; /*0x13eef5*/
  return 0; /*0x13eefd*/
}
