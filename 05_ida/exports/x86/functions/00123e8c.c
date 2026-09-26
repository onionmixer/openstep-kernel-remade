/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123e8c. */
int __cdecl inet_queue(int a1, int a2)
{
  int v2; // edx
  int *v3; // ebx
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  LOBYTE(netisr) = netisr | 4; /*0x123e98*/
  wakeup((int)&soft_net_wakeup); /*0x123ea4*/
  v6 = splimp(); /*0x123eb3*/
  if ( dword_1EAA78 >= dword_1EAA7C ) /*0x123ec4*/
  {
    ++dword_1EAA80; /*0x123ec6*/
LABEL_18:
    m_freem(a2); /*0x123fa3*/
    return splx(v6); /*0x123fa4*/
  }
  v2 = *(_DWORD *)(a2 + 4); /*0x123ed4*/
  if ( (unsigned int)(v2 - 16) > 0x6C ) /*0x123edd*/
  {
    v5 = splimp(); /*0x123ef9*/
    v3 = (int *)mfree; /*0x123efc*/
    if ( mfree ) /*0x123f04*/
    {
      if ( *(_WORD *)(mfree + 10) ) /*0x123f06*/
        panic(aMget_7); /*0x123f12*/
      *(_WORD *)(mfree + 10) = 2; /*0x123f1a*/
      --word_1E917C[0]; /*0x123f20*/
      ++word_1E9180; /*0x123f27*/
      mfree = *v3; /*0x123f30*/
      *v3 = 0; /*0x123f36*/
      v3[1] = 12; /*0x123f3c*/
    }
    else
    {
      v3 = m_more(0, 2); /*0x123f51*/
    }
    splx(v5); /*0x123f5a*/
    if ( !v3 ) /*0x123f64*/
      goto LABEL_17; /*0x123f64*/
    v3[1] = 12; /*0x123f66*/
    *((_WORD *)v3 + 4) = 4; /*0x123f6d*/
    *v3 = a2; /*0x123f73*/
  }
  else
  {
    v3 = (int *)a2; /*0x123edf*/
    *(_DWORD *)(a2 + 4) = v2 - 4; /*0x123ee4*/
    *(_WORD *)(a2 + 8) += 4; /*0x123ee7*/
  }
  if ( !v3 ) /*0x123f77*/
  {
LABEL_17:
    ++dword_1EAA80; /*0x123fa0*/
    goto LABEL_18; /*0x123fa0*/
  }
  *(int *)((char *)v3 + v3[1]) = a1; /*0x123f7f*/
  v3[31] = 0; /*0x123f82*/
  if ( dword_1EAA74 ) /*0x123f8e*/
    *(_DWORD *)(dword_1EAA74 + 124) = v3; /*0x123f94*/
  else
    ipintrq = (int)v3; /*0x123f90*/
  dword_1EAA74 = (int)v3; /*0x123f97*/
  ++dword_1EAA78; /*0x123f9a*/
  return splx(v6); /*0x123fb8*/
}
