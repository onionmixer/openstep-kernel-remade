/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd7a4. */
void __cdecl put_disktab(unsigned int *a1, char *a2)
{
  _DWORD *v2; // ebx
  unsigned int *v3; // edi
  int i; // esi
  int v5; // edi
  char *v6; // ebx
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  bcopy(a1, a2, 0x18u); /*0x1bd7b7*/
  bcopy(a1 + 6, a2 + 24, 0x18u); /*0x1bd7cc*/
  *((_DWORD *)a2 + 12) = _byteswap_ulong(a1[12]); /*0x1bd7df*/
  *((_DWORD *)a2 + 13) = _byteswap_ulong(a1[13]); /*0x1bd7e7*/
  *((_DWORD *)a2 + 14) = _byteswap_ulong(a1[14]); /*0x1bd7ef*/
  *((_DWORD *)a2 + 15) = _byteswap_ulong(a1[15]); /*0x1bd7f7*/
  *((_DWORD *)a2 + 16) = _byteswap_ulong(a1[16]); /*0x1bd7ff*/
  *((_WORD *)a2 + 34) = __ROR2__(*((_WORD *)a1 + 34), 8); /*0x1bd80a*/
  *((_WORD *)a2 + 35) = __ROR2__(*((_WORD *)a1 + 35), 8); /*0x1bd816*/
  *((_WORD *)a2 + 36) = __ROR2__(*((_WORD *)a1 + 36), 8); /*0x1bd822*/
  *((_WORD *)a2 + 37) = __ROR2__(*((_WORD *)a1 + 37), 8); /*0x1bd82e*/
  *((_WORD *)a2 + 38) = __ROR2__(*((_WORD *)a1 + 38), 8); /*0x1bd83a*/
  *((_WORD *)a2 + 39) = __ROR2__(*((_WORD *)a1 + 39), 8); /*0x1bd846*/
  v2 = a2 + 80; /*0x1bd84d*/
  v3 = a1 + 20; /*0x1bd853*/
  for ( i = 0; i <= 1; ++i ) /*0x1bd856*/
    *v2++ = _byteswap_ulong(*v3++); /*0x1bd85c*/
  bcopy(a1 + 22, a2 + 88, 0x18u); /*0x1bd87a*/
  bcopy(a1 + 28, a2 + 112, 0x20u); /*0x1bd88f*/
  a2[144] = *((_BYTE *)a1 + 144); /*0x1bd8a3*/
  a2[145] = *((_BYTE *)a1 + 145); /*0x1bd8b2*/
  v5 = 0; /*0x1bd8b8*/
  v8 = 0; /*0x1bd8ba*/
  v7 = 0; /*0x1bd8c1*/
  do /*0x1bd96a*/
  {
    v6 = &a2[v5 + 146 + v8]; /*0x1bd8dd*/
    *(_DWORD *)v6 = _byteswap_ulong(a1[v7 + 37]); /*0x1bd8e8*/
    *((_DWORD *)v6 + 1) = _byteswap_ulong(a1[v7 + 38]); /*0x1bd8ef*/
    *((_WORD *)v6 + 4) = __ROR2__(a1[v7 + 39], 8); /*0x1bd8fa*/
    *((_WORD *)v6 + 5) = __ROR2__(HIWORD(a1[v7 + 39]), 8); /*0x1bd906*/
    v6[12] = a1[v7 + 40]; /*0x1bd90d*/
    *((_WORD *)v6 + 7) = __ROR2__(HIWORD(a1[v7 + 40]), 8); /*0x1bd918*/
    *((_WORD *)v6 + 8) = __ROR2__(a1[v7 + 41], 8); /*0x1bd924*/
    v6[18] = BYTE2(a1[v7 + 41]); /*0x1bd92b*/
    v6[19] = HIBYTE(a1[v7 + 41]); /*0x1bd931*/
    bcopy(&a1[v7 + 42], &a2[v5 + 166 + v8], 0x10u); /*0x1bd93e*/
    v6[36] = a1[v7 + 46]; /*0x1bd949*/
    bcopy((char *)&a1[v7 + 46] + 1, &a2[v5 + 183 + v8], 8u); /*0x1bd956*/
    v8 += 45; /*0x1bd95e*/
    v7 += 12; /*0x1bd962*/
    ++v5; /*0x1bd966*/
  }
  while ( v5 <= 7 ); /*0x1bd96a*/
}
