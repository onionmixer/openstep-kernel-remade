/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1975d0. */
void __cdecl -[kmDevice graphicPanelString:](kmDevice *self, SEL a2, char *__s2)
{
  unsigned int i; // ecx
  int v4; // ecx
  int v5; // ebx
  char *v6; // esi
  int m; // ecx
  __int16 *v8; // esi
  __int16 v9; // cx
  int ii; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  char *v14; // [esp+10h] [ebp-24h]
  char j; // [esp+14h] [ebp-20h]
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *v16; // [esp+18h] [ebp-1Ch]
  int n; // [esp+1Ch] [ebp-18h]
  char *v18; // [esp+20h] [ebp-14h]
  char *k; // [esp+20h] [ebp-14h]
  int v20; // [esp+24h] [ebp-10h]
  _WORD v21[4]; // [esp+28h] [ebp-Ch] BYREF
  char *v22; // [esp+30h] [ebp-4h]
  char *__s2a; // [esp+44h] [ebp+10h]

  if ( self->fbMode == 2 ) /*0x1975e3*/
  {
    __s2a = (char *)kmLocalizeString(__s2); /*0x1975f2*/
    dword_1E8640 = 0; /*0x1975f5*/
    dword_1E8628 = 288; /*0x1975ff*/
    dword_1E862C = 52; /*0x197609*/
    for ( i = 0; i <= 0xE9F; ++i ) /*0x197616*/
      byte_1E7780[i] = 85; /*0x197618*/
    v4 = 0; /*0x197628*/
    v18 = __s2a; /*0x19762d*/
    for ( j = 0; *v18; ++v18 ) /*0x197634*/
    {
      j = *v18; /*0x197641*/
      if ( *v18 == 10 ) /*0x197646*/
        ++v4; /*0x197648*/
    }
    if ( j != 10 ) /*0x197658*/
      ++v4; /*0x19765a*/
    v5 = dword_1E8630 + 3; /*0x197661*/
    LOBYTE(v5) = (dword_1E8630 + 3) & 0xFC; /*0x197664*/
    dword_1E8630 = v5; /*0x197667*/
    dword_1E8628 &= 0xFFFFFFFC; /*0x19766d*/
    v20 = *((__int16 *)off_1E3E90 + 4) + (*((__int16 *)off_1E3E90 + 4) + 9) / 10; /*0x197694*/
    dword_1E863C = (dword_1E862C - v20 * (v4 - 1)) / 2 + 2; /*0x1976b5*/
    for ( k = __s2a; *k; dword_1E863C += v20 ) /*0x1976c1*/
    {
      v6 = k; /*0x1976cc*/
      for ( m = 0; *v6; m += *((__int16 *)off_1E3E90 + 8 * (unsigned __int8)*v6++ - 244) ) /*0x1976d1*/
      {
        if ( *v6 == 10 ) /*0x1976e4*/
          break; /*0x1976e4*/
      }
      dword_1E8638 = (dword_1E8628 - m) / 2; /*0x197711*/
      if ( *k ) /*0x197719*/
      {
        while ( *k != 10 ) /*0x19772c*/
        {
          v8 = (__int16 *)((char *)off_1E3E90 + 16 * (unsigned __int8)*k - 496); /*0x197744*/
          for ( n = 0; n < v8[1]; ++n ) /*0x197757*/
          {
            v9 = *v8; /*0x197760*/
            for ( ii = 0; ii < *v8; v9 = *v8 ) /*0x197768*/
            {
              v11 = ii + *((_DWORD *)v8 + 3) + v9 * (v8[1] - n - 1); /*0x197784*/
              v12 = *(unsigned __int8 *)((v11 >> 3) + *((_DWORD *)off_1E3E90 + 388)); /*0x197797*/
              if ( _bittest(&v12, 7 - (v11 & 7)) ) /*0x1977a8*/
              {
                v13 = 2 * (ii + dword_1E8638 + v8[2] + dword_1E8628 * (dword_1E863C - v8[3] - n)); /*0x1977e1*/
                v14 = &off_1E3E8C[v13 >> 3]; /*0x1977ee*/
                if ( v14 != (char *)dword_1E8640 ) /*0x1977fc*/
                {
                  if ( dword_1E8640 ) /*0x197800*/
                    *(_BYTE *)dword_1E8640 = byte_1E8644; /*0x197808*/
                  byte_1E8644 = *v14; /*0x19780f*/
                  dword_1E8640 = (int)v14; /*0x197818*/
                }
                byte_1E8644 = (3 << (6 - (v13 & 7))) | ~(unsigned __int8)(3 << (6 - (v13 & 7))) & byte_1E8644; /*0x197847*/
              }
              ++ii; /*0x19784d*/
            }
          }
          if ( dword_1E8640 ) /*0x197874*/
            *(_BYTE *)dword_1E8640 = byte_1E8644; /*0x19787c*/
          dword_1E8640 = 0; /*0x19787e*/
          dword_1E8638 += v8[4]; /*0x19788f*/
          if ( !*++k ) /*0x19789b*/
            goto LABEL_30; /*0x19789e*/
        }
        ++k; /*0x19772f*/
      }
LABEL_30:
      ; /*0x1978a4*/
    }
    v16 = self->fbp[0]; /*0x1978c2*/
    v21[2] = dword_1E8628; /*0x1978cc*/
    v21[3] = dword_1E862C; /*0x1978d7*/
    v21[0] = dword_1E8630 + 12; /*0x1978e5*/
    v21[1] = dword_1E8634 + 62; /*0x1978f4*/
    v22 = off_1E3E8C; /*0x1978fe*/
    (*((void (__stdcall **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, _WORD *))v16 + 3))(v16, v21); /*0x19790c*/
  }
}
