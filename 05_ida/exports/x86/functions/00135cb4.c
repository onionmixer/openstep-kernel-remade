/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135cb4. */
int __cdecl sub_135CB4(int a1)
{
  int *v1; // eax
  int v2; // edi
  int v4; // esi
  __int16 v5; // bx
  int v6; // [esp+Ch] [ebp-Ch]
  _WORD *v7; // [esp+10h] [ebp-8h]
  char *v8; // [esp+14h] [ebp-4h]

  v1 = m_get(1, 8); /*0x135cc1*/
  v2 = (int)v1; /*0x135cc6*/
  if ( v1 )
  {
    v8 = (char *)v1 + v1[1]; /*0x135ce9*/
    *(_WORD *)v8 = 2; /*0x135cec*/
    *((_DWORD *)v8 + 1) = 0; /*0x135cf1*/
    *((_WORD *)v1 + 4) = 16; /*0x135cf8*/
    v7 = crdup(*(const void **)(active_u + 28)); /*0x135d0c*/
    v6 = *(_DWORD *)(active_u + 28); /*0x135d17*/
    *(_DWORD *)(active_u + 28) = v7; /*0x135d1d*/
    *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) = 0; /*0x135d28*/
    v4 = 48; /*0x135d2e*/
    v5 = 1023; /*0x135d33*/
    do /*0x135d64*/
    {
      if ( (unsigned __int16)v5 <= 0x1FFu ) /*0x135d41*/
        break; /*0x135d41*/
      *((_WORD *)v8 + 1) = __ROR2__(v5, 8); /*0x135d4c*/
      v4 = sobind(a1, v2); /*0x135d5a*/
      --v5; /*0x135d5f*/
    }
    while ( v4 == 48 ); /*0x135d64*/
    m_freem(v2); /*0x135d67*/
    *(_DWORD *)(active_u + 28) = v6; /*0x135d74*/
    crfree(v7); /*0x135d7b*/
    return v4; /*0x135d80*/
  }
  else
  {
    printf("bindresvport: couldn't alloc mbuf");
    return 55; /*0x135cd9*/
  }
}
