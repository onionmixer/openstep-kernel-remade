/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114bd4. */
int __cdecl socreate(int a1, char **a2, int a3, int a4)
{
  __int16 *v4; // esi
  int *v6; // eax
  char *v7; // ebx
  int v8; // esi

  if ( a4 ) /*0x114be4*/
    v4 = pffindproto(a1, a4, a3); /*0x114bf1*/
  else
    v4 = pffindtype(a1, a3); /*0x114bff*/
  if ( !v4 ) /*0x114c06*/
    return 43; /*0x114c08*/
  if ( *v4 != a3 ) /*0x114c15*/
    return 41; /*0x114c17*/
  v6 = m_getclr(1, 3); /*0x114c24*/
  v7 = (char *)v6 + v6[1]; /*0x114c2b*/
  *((_WORD *)v7 + 1) = 32; /*0x114c2e*/
  *((_WORD *)v7 + 3) = 0; /*0x114c34*/
  *(_WORD *)v7 = a3; /*0x114c3a*/
  if ( !*(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x114c48*/
    *((_WORD *)v7 + 3) = 128; /*0x114c4f*/
  *((_DWORD *)v7 + 3) = v4; /*0x114c55*/
  v8 = (*((int (__cdecl **)(char *, _DWORD, _DWORD, int, _DWORD))v4 + 7))(v7, 0, 0, a4, 0); /*0x114c68*/
  if ( v8 ) /*0x114c6f*/
  {
    v7[6] |= 1u; /*0x114c71*/
    sofree(v7); /*0x114c76*/
    return v8; /*0x114c7b*/
  }
  else
  {
    *a2 = v7; /*0x114c83*/
    return 0; /*0x114c85*/
  }
}
