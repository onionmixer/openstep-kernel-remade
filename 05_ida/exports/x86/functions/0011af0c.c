/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11af0c. */
__int16 __cdecl brelvp_wakeup(int a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int *v5; // edx

  if ( (*(_BYTE *)a1 & 0x40) != 0 ) /*0x11af17*/
    wakeup(a1); /*0x11af1a*/
  v1 = bfreelist; /*0x11af22*/
  if ( (bfreelist & 0x40) != 0 ) /*0x11af29*/
  {
    LOBYTE(v1) = bfreelist & 0xBF; /*0x11af2b*/
    bfreelist = v1; /*0x11af2d*/
    wakeup((int)&bfreelist); /*0x11af37*/
  }
  if ( (*(_DWORD *)a1 & 0x400200) == 0x400000 ) /*0x11af4d*/
    *(_DWORD *)a1 |= 0x10000u; /*0x11af55*/
  v2 = *(_DWORD *)a1; /*0x11af57*/
  if ( (*(_DWORD *)a1 & 4) != 0 ) /*0x11af5b*/
  {
    if ( (v2 & 0x20000) != 0 ) /*0x11af62*/
    {
      LOBYTE(v2) = v2 & 0xFB; /*0x11af64*/
      *(_DWORD *)a1 = v2; /*0x11af66*/
    }
    else
    {
      sub_11B26C(a1); /*0x11af6d*/
    }
  }
  v3 = splhigh(); /*0x11af7a*/
  if ( *(int *)(a1 + 24) > 0 ) /*0x11af80*/
  {
    v4 = *(_DWORD *)a1; /*0x11afa4*/
    if ( (*(_DWORD *)a1 & 0x10004) != 0 ) /*0x11afab*/
    {
      *(_DWORD *)(dword_1E87F4 + 16) = a1; /*0x11afb2*/
      *(_DWORD *)(a1 + 12) = dword_1E87F4; /*0x11afbb*/
      dword_1E87F4 = a1; /*0x11afbe*/
      *(_DWORD *)(a1 + 16) = &unk_1E87E8; /*0x11afc4*/
    }
    else
    {
      if ( (v4 & 0x20000) != 0 ) /*0x11afd5*/
      {
        v5 = &bfreelist; /*0x11afd7*/
      }
      else
      {
        v5 = (int *)&unk_1E87A4; /*0x11afe0*/
        if ( (v4 & 0x80u) != 0 ) /*0x11afe7*/
          v5 = (int *)&unk_1E87E8; /*0x11afe9*/
      }
      *(_DWORD *)(v5[4] + 12) = a1; /*0x11aff1*/
      *(_DWORD *)(a1 + 16) = v5[4]; /*0x11aff7*/
      v5[4] = a1; /*0x11affa*/
      *(_DWORD *)(a1 + 12) = v5; /*0x11affd*/
    }
  }
  else
  {
    *(_DWORD *)(dword_1E8838 + 16) = a1; /*0x11af87*/
    *(_DWORD *)(a1 + 12) = dword_1E8838; /*0x11af90*/
    dword_1E8838 = a1; /*0x11af93*/
    *(_DWORD *)(a1 + 16) = &dword_1E882C; /*0x11af99*/
  }
  *(_DWORD *)a1 &= 0xFFBFFE37; /*0x11b000*/
  splx(v3); /*0x11b007*/
  return sub_11B26C(a1); /*0x11b018*/
}
