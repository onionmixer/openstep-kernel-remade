/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11aad4. */
int __cdecl biodone(int a1)
{
  int v1; // eax
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int *v7; // edx

  if ( (*(_BYTE *)a1 & 2) != 0 ) /*0x11aadf*/
    panic(aDupBiodone); /*0x11aae6*/
  v1 = *(_DWORD *)a1; /*0x11aaee*/
  LOBYTE(v1) = *(_DWORD *)a1 | 2; /*0x11aaf0*/
  *(_DWORD *)a1 = v1; /*0x11aaf2*/
  if ( (v1 & 0x200000) != 0 ) /*0x11aaf9*/
  {
    *(_DWORD *)a1 = v1 & 0xFFDFFFFF; /*0x11ab00*/
    return (*(int (__cdecl **)(int))(a1 + 48))(a1); /*0x11ab06*/
  }
  else if ( (v1 & 0x100) != 0 ) /*0x11ab13*/
  {
    if ( (v1 & 0x40) != 0 ) /*0x11ab1b*/
      wakeup(a1); /*0x11ab1e*/
    v3 = bfreelist; /*0x11ab26*/
    if ( (bfreelist & 0x40) != 0 ) /*0x11ab2d*/
    {
      LOBYTE(v3) = bfreelist & 0xBF; /*0x11ab2f*/
      bfreelist = v3; /*0x11ab31*/
      wakeup(&bfreelist); /*0x11ab3b*/
    }
    if ( (*(_DWORD *)a1 & 0x400200) == 0x400000 ) /*0x11ab51*/
      *(_DWORD *)a1 |= 0x10000u; /*0x11ab59*/
    v4 = *(_DWORD *)a1; /*0x11ab5b*/
    if ( (*(_DWORD *)a1 & 4) != 0 ) /*0x11ab5f*/
    {
      if ( (v4 & 0x20000) != 0 ) /*0x11ab66*/
      {
        LOBYTE(v4) = v4 & 0xFB; /*0x11ab68*/
        *(_DWORD *)a1 = v4; /*0x11ab6a*/
      }
      else
      {
        sub_11B26C(a1); /*0x11ab71*/
      }
    }
    v5 = splhigh(); /*0x11ab7e*/
    if ( *(int *)(a1 + 24) > 0 ) /*0x11ab84*/
    {
      v6 = *(_DWORD *)a1; /*0x11aba8*/
      if ( (*(_DWORD *)a1 & 0x10004) != 0 ) /*0x11abaf*/
      {
        *(_DWORD *)(dword_1E87F4 + 16) = a1; /*0x11abb6*/
        *(_DWORD *)(a1 + 12) = dword_1E87F4; /*0x11abbf*/
        dword_1E87F4 = a1; /*0x11abc2*/
        *(_DWORD *)(a1 + 16) = &unk_1E87E8; /*0x11abc8*/
      }
      else
      {
        if ( (v6 & 0x20000) != 0 ) /*0x11abd9*/
        {
          v7 = &bfreelist; /*0x11abdb*/
        }
        else
        {
          v7 = (int *)&unk_1E87A4; /*0x11abe4*/
          if ( (v6 & 0x80u) != 0 ) /*0x11abeb*/
            v7 = (int *)&unk_1E87E8; /*0x11abed*/
        }
        *(_DWORD *)(v7[4] + 12) = a1; /*0x11abf5*/
        *(_DWORD *)(a1 + 16) = v7[4]; /*0x11abfb*/
        v7[4] = a1; /*0x11abfe*/
        *(_DWORD *)(a1 + 12) = v7; /*0x11ac01*/
      }
    }
    else
    {
      *(_DWORD *)(dword_1E8838 + 16) = a1; /*0x11ab8b*/
      *(_DWORD *)(a1 + 12) = dword_1E8838; /*0x11ab94*/
      dword_1E8838 = a1; /*0x11ab97*/
      *(_DWORD *)(a1 + 16) = &unk_1E882C; /*0x11ab9d*/
    }
    *(_DWORD *)a1 &= 0xFFBFFE37; /*0x11ac04*/
    return splx(v5); /*0x11ac0b*/
  }
  else
  {
    LOBYTE(v1) = v1 & 0xBF; /*0x11ac14*/
    *(_DWORD *)a1 = v1; /*0x11ac16*/
    return wakeup(a1); /*0x11ac19*/
  }
}
