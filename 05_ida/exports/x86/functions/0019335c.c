/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19335c. */
int __cdecl allocbuf(_DWORD *a1, int a2)
{
  vm_size_t v2; // ebx
  signed int v3; // edi
  signed int v4; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  unsigned int v8; // eax
  int v9; // ebx
  int v10; // ecx
  int v11; // ecx

  v2 = (page_size + a2 - 1) / page_size; /*0x19337c*/
  v3 = v2 * page_size; /*0x193384*/
  v4 = a1[6]; /*0x19338a*/
  if ( v2 * page_size != v4 ) /*0x19338f*/
  {
    if ( (int)(v2 * page_size) >= v4 ) /*0x193395*/
    {
      if ( v4 < v3 ) /*0x193412*/
      {
        do /*0x1934b8*/
        {
          v7 = v3 - a1[6]; /*0x19341d*/
          v8 = getnewbuf(); /*0x193420*/
          v9 = v8; /*0x193425*/
          v10 = *(_DWORD *)(v8 + 24); /*0x193427*/
          if ( v7 >= v10 ) /*0x19342c*/
            v7 = *(_DWORD *)(v8 + 24); /*0x19342e*/
          pagemove(*(_DWORD *)(v8 + 32) + v10 - v7, a1[6] + a1[8], v7); /*0x193443*/
          a1[6] += v7; /*0x19344b*/
          v11 = *(_DWORD *)(v9 + 24) - v7; /*0x193451*/
          *(_DWORD *)(v9 + 24) = v11; /*0x193453*/
          if ( *(_DWORD *)(v9 + 20) > v11 ) /*0x19345c*/
            *(_DWORD *)(v9 + 20) = v11; /*0x19345e*/
          if ( *(int *)(v9 + 24) <= 0 ) /*0x193465*/
          {
            *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4) = *(_DWORD *)(v9 + 4); /*0x19346d*/
            *(_DWORD *)(*(_DWORD *)(v9 + 4) + 8) = *(_DWORD *)(v9 + 8); /*0x193476*/
            *(_DWORD *)(v9 + 4) = dword_1E8830; /*0x19347f*/
            *(_DWORD *)(v9 + 8) = &dword_1E882C; /*0x193482*/
            *(_DWORD *)(dword_1E8830 + 8) = v9; /*0x19348e*/
            dword_1E8830 = v9; /*0x193491*/
            *(_WORD *)(v9 + 30) = -1; /*0x193497*/
            *(_WORD *)(v9 + 28) = 0; /*0x19349d*/
            *(_DWORD *)v9 |= 0x10000u; /*0x1934a3*/
          }
          brelse(v9); /*0x1934aa*/
        }
        while ( a1[6] < v3 ); /*0x1934b8*/
      }
    }
    else
    {
      v5 = dword_1E8838; /*0x193397*/
      if ( (int *)dword_1E8838 != &dword_1E882C ) /*0x1933a3*/
      {
        v6 = splbio(); /*0x1933a9*/
        *(_DWORD *)(*(_DWORD *)(v5 + 16) + 12) = *(_DWORD *)(v5 + 12); /*0x1933b6*/
        *(_DWORD *)(*(_DWORD *)(v5 + 12) + 16) = *(_DWORD *)(v5 + 16); /*0x1933bf*/
        *(_BYTE *)v5 |= 8u; /*0x1933c2*/
        splx(v6); /*0x1933c6*/
        pagemove(v3 + a1[8], *(_DWORD *)(v5 + 32), a1[6] - v3); /*0x1933e1*/
        *(_DWORD *)(v5 + 24) = a1[6] - v3; /*0x1933ee*/
        a1[6] = v3; /*0x1933f4*/
        *(_DWORD *)v5 |= 0x10000u; /*0x1933f7*/
        *(_DWORD *)(v5 + 20) = 0; /*0x1933fd*/
        brelse(v5); /*0x193405*/
      }
    }
  }
  a1[5] = a2; /*0x1934c4*/
  return 1; /*0x1934cf*/
}
