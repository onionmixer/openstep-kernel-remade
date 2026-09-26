/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a288. */
int __cdecl brelse(int a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int *v5; // edx

  if ( (*(_BYTE *)a1 & 0x40) != 0 ) /*0x11a293*/
    wakeup(a1); /*0x11a296*/
  v1 = bfreelist; /*0x11a29e*/
  if ( (bfreelist & 0x40) != 0 ) /*0x11a2a5*/
  {
    LOBYTE(v1) = bfreelist & 0xBF; /*0x11a2a7*/
    bfreelist = v1; /*0x11a2a9*/
    wakeup(&bfreelist); /*0x11a2b3*/
  }
  if ( (*(_DWORD *)a1 & 0x400200) == 0x400000 ) /*0x11a2c9*/
    *(_DWORD *)a1 |= 0x10000u; /*0x11a2d1*/
  v2 = *(_DWORD *)a1; /*0x11a2d3*/
  if ( (*(_DWORD *)a1 & 4) != 0 ) /*0x11a2d7*/
  {
    if ( (v2 & 0x20000) != 0 ) /*0x11a2de*/
    {
      LOBYTE(v2) = v2 & 0xFB; /*0x11a2e0*/
      *(_DWORD *)a1 = v2; /*0x11a2e2*/
    }
    else
    {
      sub_11B26C(a1); /*0x11a2e9*/
    }
  }
  v3 = splhigh(); /*0x11a2f6*/
  if ( *(int *)(a1 + 24) > 0 ) /*0x11a2fc*/
  {
    v4 = *(_DWORD *)a1; /*0x11a320*/
    if ( (*(_DWORD *)a1 & 0x10004) != 0 ) /*0x11a327*/
    {
      *(_DWORD *)(dword_1E87F4 + 16) = a1; /*0x11a32e*/
      *(_DWORD *)(a1 + 12) = dword_1E87F4; /*0x11a337*/
      dword_1E87F4 = a1; /*0x11a33a*/
      *(_DWORD *)(a1 + 16) = &unk_1E87E8; /*0x11a340*/
    }
    else
    {
      if ( (v4 & 0x20000) != 0 ) /*0x11a351*/
      {
        v5 = &bfreelist; /*0x11a353*/
      }
      else
      {
        v5 = (int *)&unk_1E87A4; /*0x11a35c*/
        if ( (v4 & 0x80u) != 0 ) /*0x11a363*/
          v5 = (int *)&unk_1E87E8; /*0x11a365*/
      }
      *(_DWORD *)(v5[4] + 12) = a1; /*0x11a36d*/
      *(_DWORD *)(a1 + 16) = v5[4]; /*0x11a373*/
      v5[4] = a1; /*0x11a376*/
      *(_DWORD *)(a1 + 12) = v5; /*0x11a379*/
    }
  }
  else
  {
    *(_DWORD *)(dword_1E8838 + 16) = a1; /*0x11a303*/
    *(_DWORD *)(a1 + 12) = dword_1E8838; /*0x11a30c*/
    dword_1E8838 = a1; /*0x11a30f*/
    *(_DWORD *)(a1 + 16) = &unk_1E882C; /*0x11a315*/
  }
  *(_DWORD *)a1 &= 0xFFBFFE37; /*0x11a37c*/
  return splx(v3); /*0x11a38b*/
}
