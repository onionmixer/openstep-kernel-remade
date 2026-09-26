/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a504. */
int *__cdecl tcp_respond(int a1, char *a2, int a3, unsigned int a4, unsigned int a5, char a6)
{
  char *v6; // esi
  int v7; // ebx
  int v8; // edi
  unsigned __int16 *v9; // eax
  int *result; // eax
  int v11; // eax
  int *v12; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

  v6 = a2; /*0x12a510*/
  v7 = a3; /*0x12a513*/
  LOWORD(v13) = 0; /*0x12a516*/
  v12 = nullptr; /*0x12a51d*/
  if ( a1 ) /*0x12a526*/
  {
    v8 = *(_DWORD *)(a1 + 32); /*0x12a528*/
    v9 = *(unsigned __int16 **)(v8 + 28); /*0x12a52b*/
    v13 = v9[19] - v9[18]; /*0x12a545*/
    if ( v13 > v9[21] - v9[20] ) /*0x12a54a*/
      LOWORD(v13) = v9[21] - v9[20]; /*0x12a54c*/
    v12 = (int *)(v8 + 36); /*0x12a552*/
  }
  if ( a3 ) /*0x12a557*/
  {
    m_freem(*(_DWORD *)a3); /*0x12a597*/
    *(_DWORD *)a3 = 0; /*0x12a59c*/
    *(_DWORD *)(a3 + 4) = &a2[-a3]; /*0x12a5a6*/
    *(_WORD *)(a3 + 8) = 40; /*0x12a5ab*/
    v11 = *((_DWORD *)a2 + 4); /*0x12a5b1*/
    *((_DWORD *)a2 + 4) = *((_DWORD *)a2 + 3); /*0x12a5b7*/
    *((_DWORD *)a2 + 3) = v11; /*0x12a5ba*/
    LOWORD(v11) = *((_WORD *)a2 + 11); /*0x12a5bd*/
    *((_WORD *)a2 + 11) = *((_WORD *)a2 + 10); /*0x12a5c5*/
    *((_WORD *)a2 + 10) = v11; /*0x12a5c9*/
  }
  else
  {
    result = m_get(0, 2); /*0x12a55d*/
    v7 = (int)result; /*0x12a562*/
    if ( !result ) /*0x12a569*/
      return result; /*0x12a569*/
    *((_WORD *)result + 4) = 40; /*0x12a571*/
    qmemcpy((char *)result + result[1], a2, 0x28u); /*0x12a582*/
    v6 = (char *)result + result[1]; /*0x12a586*/
    a6 = 16; /*0x12a589*/
  }
  *((_DWORD *)v6 + 1) = 0; /*0x12a5d0*/
  *(_DWORD *)v6 = 0; /*0x12a5d7*/
  v6[8] = 0; /*0x12a5dd*/
  *((_WORD *)v6 + 5) = __ROR2__(20, 8); /*0x12a5eb*/
  *((_DWORD *)v6 + 6) = _byteswap_ulong(a5); /*0x12a5f4*/
  *((_DWORD *)v6 + 7) = _byteswap_ulong(a4); /*0x12a5fc*/
  v6[32] = 80; /*0x12a5ff*/
  v6[33] = a6; /*0x12a606*/
  *((_WORD *)v6 + 17) = __ROR2__(v13, 8); /*0x12a611*/
  *((_WORD *)v6 + 19) = 0; /*0x12a615*/
  *((_WORD *)v6 + 18) = in_cksum(v7, 40); /*0x12a628*/
  *((_WORD *)v6 + 1) = 40; /*0x12a633*/
  v6[8] = tcp_ttl; /*0x12a63d*/
  return (int *)ip_output(v7, 0, v12, 0, 0); /*0x12a653*/
}
