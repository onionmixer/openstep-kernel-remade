/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd474. */
void __cdecl get_disktab(unsigned int *a1, char *a2)
{
  unsigned int *v2; // ebx
  _DWORD *v3; // edi
  int i; // esi
  int v5; // edi
  char *v6; // esi
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  bcopy(a1, a2, 0x18u); /*0x1bd487*/
  bcopy(a1 + 6, a2 + 24, 0x18u); /*0x1bd49c*/
  *((_DWORD *)a2 + 12) = _byteswap_ulong(a1[12]); /*0x1bd4af*/
  *((_DWORD *)a2 + 13) = _byteswap_ulong(a1[13]); /*0x1bd4b7*/
  *((_DWORD *)a2 + 14) = _byteswap_ulong(a1[14]); /*0x1bd4bf*/
  *((_DWORD *)a2 + 15) = _byteswap_ulong(a1[15]); /*0x1bd4c7*/
  *((_DWORD *)a2 + 16) = _byteswap_ulong(a1[16]); /*0x1bd4cf*/
  *((_WORD *)a2 + 34) = __ROR2__(*((_WORD *)a1 + 34), 8); /*0x1bd4da*/
  *((_WORD *)a2 + 35) = __ROR2__(*((_WORD *)a1 + 35), 8); /*0x1bd4e6*/
  *((_WORD *)a2 + 36) = __ROR2__(*((_WORD *)a1 + 36), 8); /*0x1bd4f2*/
  *((_WORD *)a2 + 37) = __ROR2__(*((_WORD *)a1 + 37), 8); /*0x1bd4fe*/
  *((_WORD *)a2 + 38) = __ROR2__(*((_WORD *)a1 + 38), 8); /*0x1bd50a*/
  *((_WORD *)a2 + 39) = __ROR2__(*((_WORD *)a1 + 39), 8); /*0x1bd516*/
  v2 = a1 + 20; /*0x1bd51d*/
  v3 = a2 + 80; /*0x1bd523*/
  for ( i = 0; i <= 1; ++i ) /*0x1bd526*/
    *v3++ = _byteswap_ulong(*v2++); /*0x1bd52c*/
  bcopy(a1 + 22, a2 + 88, 0x18u); /*0x1bd54a*/
  bcopy(a1 + 28, a2 + 112, 0x20u); /*0x1bd55f*/
  a2[144] = *((_BYTE *)a1 + 144); /*0x1bd573*/
  a2[145] = *((_BYTE *)a1 + 145); /*0x1bd582*/
  v5 = 0; /*0x1bd588*/
  v8 = 0; /*0x1bd58a*/
  v7 = 0; /*0x1bd591*/
  do /*0x1bd63a*/
  {
    v6 = &a2[v8 + 148]; /*0x1bd5ad*/
    *(_DWORD *)v6 = _byteswap_ulong(*(unsigned int *)((char *)a1 + v5 + v7 + 146)); /*0x1bd5b8*/
    *((_DWORD *)v6 + 1) = _byteswap_ulong(*(unsigned int *)((char *)a1 + v5 + v7 + 150)); /*0x1bd5bf*/
    *((_WORD *)v6 + 4) = __ROR2__(*(_WORD *)((char *)a1 + v5 + v7 + 154), 8); /*0x1bd5ca*/
    *((_WORD *)v6 + 5) = __ROR2__(*(_WORD *)((char *)a1 + v5 + v7 + 156), 8); /*0x1bd5d6*/
    v6[12] = *((_BYTE *)a1 + v5 + v7 + 158); /*0x1bd5dd*/
    *((_WORD *)v6 + 7) = __ROR2__(*(_WORD *)((char *)a1 + v5 + v7 + 160), 8); /*0x1bd5e8*/
    *((_WORD *)v6 + 8) = __ROR2__(*(_WORD *)((char *)a1 + v5 + v7 + 162), 8); /*0x1bd5f4*/
    v6[18] = *((_BYTE *)a1 + v5 + v7 + 164); /*0x1bd5fb*/
    v6[19] = *((_BYTE *)a1 + v5 + v7 + 165); /*0x1bd601*/
    bcopy((char *)a1 + v5 + v7 + 166, &a2[v8 + 168], 0x10u); /*0x1bd60e*/
    v6[36] = *((_BYTE *)a1 + v5 + v7 + 182); /*0x1bd619*/
    bcopy((char *)a1 + v5 + v7 + 183, &a2[v8 + 185], 8u); /*0x1bd626*/
    v8 += 48; /*0x1bd62e*/
    v7 += 45; /*0x1bd632*/
    ++v5; /*0x1bd636*/
  }
  while ( v5 <= 7 ); /*0x1bd63a*/
}
