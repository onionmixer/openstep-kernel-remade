/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x127b90. */
int __cdecl ip_pcbopts(int *a1, int a2)
{
  __int16 v2; // si
  size_t v3; // edx
  int v4; // edi
  unsigned __int8 *v5; // esi
  unsigned int v6; // edx
  int v7; // eax
  unsigned int v8; // edx
  unsigned int v10; // [esp+10h] [ebp-4h]

  if ( *a1 ) /*0x127b9c*/
    m_free(*a1); /*0x127ba3*/
  *a1 = 0; /*0x127bae*/
  if ( !a2 ) /*0x127bb8*/
    return 0; /*0x127bb8*/
  v2 = *(_WORD *)(a2 + 8); /*0x127bc1*/
  if ( !v2 ) /*0x127bc8*/
  {
    m_free(a2); /*0x127bcb*/
    return 0; /*0x127cad*/
  }
  v3 = v2; /*0x127bd8*/
  if ( (v2 & 3) == 0 && (unsigned int)(v2 + *(_DWORD *)(a2 + 4) + 4) <= 0x7C ) /*0x127bf2*/
  {
    v4 = v2; /*0x127bf8*/
    *(_WORD *)(a2 + 8) = v2 + 4; /*0x127bfe*/
    v5 = (unsigned __int8 *)(*(_DWORD *)(a2 + 4) + a2 + 4); /*0x127c08*/
    ovbcopy((void *)(*(_DWORD *)(a2 + 4) + a2), v5, v3); /*0x127c0e*/
    bzero((void *)(*(_DWORD *)(a2 + 4) + a2), 4u); /*0x127c1c*/
    for ( ; v4 > 0; v5 += v6 ) /*0x127c26*/
    {
      if ( !*v5 ) /*0x127c28*/
        break; /*0x127c2c*/
      if ( *v5 == 1 ) /*0x127c30*/
      {
        v6 = 1; /*0x127c32*/
      }
      else
      {
        v6 = v5[1]; /*0x127c3c*/
        if ( v6 <= 1 || (int)v6 > v4 ) /*0x127c47*/
          goto LABEL_21; /*0x127c47*/
      }
      v7 = *v5; /*0x127c49*/
      if ( v7 == 131 || v7 == 137 ) /*0x127c5a*/
      {
        if ( v6 <= 6 ) /*0x127c5f*/
          goto LABEL_21; /*0x127c5f*/
        *(_WORD *)(a2 + 8) -= 4; /*0x127c64*/
        v4 -= 4; /*0x127c69*/
        v8 = v6 - 4; /*0x127c6c*/
        v5[1] = v8; /*0x127c6f*/
        v10 = v8; /*0x127c7f*/
        bcopy(v5 + 3, (void *)(*(_DWORD *)(a2 + 4) + a2), 4u); /*0x127c82*/
        ovbcopy(v5 + 7, v5 + 3, v4 + 4); /*0x127c90*/
        v6 = v10; /*0x127c98*/
      }
      v4 -= v6; /*0x127c9b*/
    }
    *a1 = a2; /*0x127ca9*/
    return 0; /*0x127ca9*/
  }
LABEL_21:
  m_free(a2); /*0x127cb0*/
  return 22; /*0x127cc1*/
}
