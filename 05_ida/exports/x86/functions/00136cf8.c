/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136cf8. */
int __cdecl ku_sendto_mbuf(int a1, int a2, _DWORD *a3)
{
  int v3; // edi
  int *v4; // eax
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 8); /*0x136d07*/
  ++Sendtries; /*0x136d0a*/
  v4 = m_get(1, 8); /*0x136d14*/
  v5 = (int)v4; /*0x136d19*/
  if ( v4 ) /*0x136d20*/
  {
    *((_WORD *)v4 + 4) = 16; /*0x136d38*/
    v7 = v4[1]; /*0x136d3e*/
    *(_DWORD *)(v7 + v5) = *a3; /*0x136d43*/
    *(_DWORD *)(v7 + v5 + 4) = a3[1]; /*0x136d49*/
    *(_DWORD *)(v7 + v5 + 8) = a3[2]; /*0x136d50*/
    *(_DWORD *)(v7 + v5 + 12) = a3[3]; /*0x136d57*/
    v11 = splnet(); /*0x136d60*/
    v10 = *(_DWORD *)(v3 + 20); /*0x136d66*/
    v8 = in_pcbconnect(v3, v5); /*0x136d6b*/
    v9 = v8; /*0x136d70*/
    if ( v8 ) /*0x136d77*/
    {
      printf("pcbsetaddr failed %d\n", v8); /*0x136d7f*/
      splx(v11); /*0x136d88*/
      m_freem(a2); /*0x136d91*/
      m_free(v5); /*0x136d97*/
    }
    else
    {
      v9 = udp_output(v3, a2); /*0x136daa*/
      in_pcbdisconnect(v3); /*0x136dad*/
      *(_DWORD *)(v3 + 20) = v10; /*0x136db5*/
      splx(v11); /*0x136dbc*/
      m_free(v5); /*0x136dc2*/
      ++Sendok; /*0x136dc7*/
    }
    return v9; /*0x136dcd*/
  }
  else
  {
    m_freem(a2); /*0x136d26*/
    return 55; /*0x136d2b*/
  }
}
