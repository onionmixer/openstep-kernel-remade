/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x129a8c. */
int __cdecl tcp_dooptions(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // esi
  int i; // edi
  int v5; // eax
  int v6; // ebx
  __int16 v8; // [esp+Eh] [ebp-2h] BYREF

  v3 = (unsigned __int8 *)(*(_DWORD *)(a2 + 4) + a2); /*0x129a98*/
  for ( i = *(__int16 *)(a2 + 8); i > 0; v3 += v6 ) /*0x129aa4*/
  {
    v5 = *v3; /*0x129aa8*/
    if ( !*v3 ) /*0x129aa8*/
      break; /*0x129aad*/
    if ( v5 == 1 ) /*0x129ab2*/
    {
      v6 = 1; /*0x129ab4*/
    }
    else
    {
      v6 = v3[1]; /*0x129abc*/
      if ( !v3[1] ) /*0x129ac2*/
        return m_free(a2); /*0x129ac2*/
    }
    if ( v5 == 2 && v6 == 4 && (*(_BYTE *)(a3 + 33) & 2) != 0 ) /*0x129ad5*/
    {
      bcopy(v3 + 2, &v8, 2u); /*0x129ae1*/
      v8 = __ROR2__(v8, 8); /*0x129af4*/
      tcp_mss(a1, v8); /*0x129afd*/
    }
    i -= v6; /*0x129b05*/
  }
  return m_free(a2); /*0x129b19*/
}
