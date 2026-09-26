/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121bdc. */
__int16 __cdecl rtredirect(int *a1, int a2, __int16 a3, void *a4)
{
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v9[5]; // [esp+Ch] [ebp-14h] BYREF

  v4 = ifa_ifwithnet((_WORD *)a2); /*0x121bec*/
  if ( v4 ) /*0x121bf6*/
  {
    v9[1] = *a1; /*0x121c06*/
    v9[2] = a1[1]; /*0x121c0c*/
    v9[3] = a1[2]; /*0x121c12*/
    v9[4] = a1[3]; /*0x121c18*/
    v9[0] = 0; /*0x121c1b*/
    rtalloc(v9); /*0x121c26*/
    v5 = v9[0]; /*0x121c2b*/
    if ( v9[0] && (v4 = bcmp(a4, (const void *)(v9[0] + 20), 0x10u)) != 0 || (v4 = ifa_ifwithaddr((_WORD *)a2)) != 0 ) /*0x121c56*/
    {
      ++rtstat; /*0x121c58*/
      if ( !v5 ) /*0x121c61*/
        return v4; /*0x121c61*/
    }
    else
    {
      if ( !v5 ) /*0x121c6e*/
        goto LABEL_14; /*0x121c6e*/
      if ( off_1DB794[2 * *(unsigned __int16 *)a1]() ) /*0x121c83*/
      {
        --*(_WORD *)(v5 + 38); /*0x121c8c*/
        if ( (*(_DWORD *)(v5 + 36) & 0xFFFF0001) == 0 ) /*0x121c97*/
        {
          --rttrash; /*0x121c99*/
          v6 = v5; /*0x121c9f*/
          LOBYTE(v6) = v5 & 0x80; /*0x121ca1*/
          m_free(v6); /*0x121ca4*/
        }
        v5 = 0; /*0x121cac*/
      }
      if ( !v5 ) /*0x121cb0*/
      {
LABEL_14:
        LOWORD(v4) = rtinit(a1, a2, -2144308726, a3 & 4 | 0x12); /*0x121cc2*/
        ++word_1E98B2; /*0x121cc7*/
        return v4; /*0x121cce*/
      }
      LOWORD(v4) = *(_WORD *)(v5 + 36); /*0x121cd4*/
      if ( (v4 & 2) != 0 ) /*0x121cda*/
      {
        if ( (v4 & 4) != 0 || (a3 & 4) == 0 ) /*0x121ce6*/
        {
          *(_DWORD *)(v5 + 20) = *(_DWORD *)a2; /*0x121d0a*/
          *(_DWORD *)(v5 + 24) = *(_DWORD *)(a2 + 4); /*0x121d10*/
          *(_DWORD *)(v5 + 28) = *(_DWORD *)(a2 + 8); /*0x121d16*/
          *(_DWORD *)(v5 + 32) = *(_DWORD *)(a2 + 12); /*0x121d1c*/
          *(_BYTE *)(v5 + 36) |= 0x20u; /*0x121d1f*/
          ++word_1E98B4; /*0x121d23*/
        }
        else
        {
          LOWORD(v4) = rtinit(a1, a2, -2144308726, a3 | 0x10); /*0x121cf4*/
          ++word_1E98B2; /*0x121cf9*/
        }
      }
      else
      {
        ++rtstat; /*0x121d2c*/
      }
    }
    --*(_WORD *)(v5 + 38); /*0x121d44*/
    if ( (*(_DWORD *)(v5 + 36) & 0xFFFF0001) == 0 ) /*0x121d4f*/
    {
      --rttrash; /*0x121d51*/
      v7 = v5; /*0x121d57*/
      LOBYTE(v7) = v5 & 0x80; /*0x121d59*/
      LOWORD(v4) = m_free(v7); /*0x121d5c*/
    }
  }
  else
  {
    ++rtstat; /*0x121bf8*/
  }
  return v4; /*0x121d64*/
}
