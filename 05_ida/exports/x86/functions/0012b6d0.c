/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b6d0. */
int __cdecl udp_output(int a1, int a2)
{
  int v2; // edi
  int i; // esi
  int *v4; // esi
  char *v6; // ebx
  __int16 v7; // ax
  int v8; // [esp+Ch] [ebp-4h]

  v2 = 0; /*0x12b6dc*/
  for ( i = a2; i; i = *(_DWORD *)i ) /*0x12b6e2*/
    v2 += *(__int16 *)(i + 8); /*0x12b6e8*/
  v8 = splimp(); /*0x12b6f5*/
  v4 = (int *)mfree; /*0x12b6f8*/
  if ( mfree ) /*0x12b700*/
  {
    if ( *(_WORD *)(mfree + 10) ) /*0x12b702*/
      panic(aMget_12); /*0x12b70e*/
    *(_WORD *)(mfree + 10) = 2; /*0x12b716*/
    --word_1E917C[0]; /*0x12b71c*/
    ++word_1E9180; /*0x12b723*/
    mfree = *v4; /*0x12b72c*/
    *v4 = 0; /*0x12b732*/
    v4[1] = 12; /*0x12b738*/
  }
  else
  {
    v4 = m_more(0, 2); /*0x12b74d*/
  }
  splx(v8); /*0x12b756*/
  if ( v4 ) /*0x12b760*/
  {
    v4[1] = 96; /*0x12b774*/
    *((_WORD *)v4 + 4) = 28; /*0x12b77b*/
    *v4 = a2; /*0x12b781*/
    v6 = (char *)v4 + v4[1]; /*0x12b785*/
    *((_DWORD *)v6 + 1) = 0; /*0x12b788*/
    *(_DWORD *)v6 = 0; /*0x12b78f*/
    v6[8] = 0; /*0x12b795*/
    v6[9] = 17; /*0x12b799*/
    *((_WORD *)v6 + 5) = __ROR2__(v2 + 8, 8); /*0x12b7a7*/
    *((_DWORD *)v6 + 3) = *(_DWORD *)(a1 + 20); /*0x12b7b1*/
    *((_DWORD *)v6 + 4) = *(_DWORD *)(a1 + 12); /*0x12b7ba*/
    *((_WORD *)v6 + 10) = *(_WORD *)(a1 + 24); /*0x12b7c4*/
    *((_WORD *)v6 + 11) = *(_WORD *)(a1 + 16); /*0x12b7cf*/
    *((_WORD *)v6 + 12) = *((_WORD *)v6 + 5); /*0x12b7d7*/
    *((_WORD *)v6 + 13) = 0; /*0x12b7db*/
    if ( udpcksum ) /*0x12b7e8*/
    {
      v7 = in_cksum(v4, v2 + 28); /*0x12b7ef*/
      *((_WORD *)v6 + 13) = v7; /*0x12b7f4*/
      if ( !v7 ) /*0x12b7fe*/
        *((_WORD *)v6 + 13) = -1; /*0x12b800*/
    }
    *((_WORD *)v6 + 1) = v2 + 28; /*0x12b80a*/
    v6[8] = udp_ttl; /*0x12b814*/
    return ip_output( /*0x12b83a*/
             (int)v4,
             *(_DWORD *)(a1 + 56),
             (int *)(a1 + 36),
             *(_WORD *)(*(_DWORD *)(a1 + 28) + 2) & 0x30 | 2,
             *(_DWORD *)(a1 + 60));
  }
  else
  {
    m_freem(a2); /*0x12b763*/
    return 55; /*0x12b768*/
  }
}
