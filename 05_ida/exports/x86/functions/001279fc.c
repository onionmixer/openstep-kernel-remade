/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1279fc. */
_BYTE *__cdecl ip_optcopy(_BYTE *a1, int a2)
{
  unsigned __int8 *v2; // edi
  _BYTE *v3; // edx
  int i; // esi
  int v5; // eax
  signed __int32 v6; // ebx
  _BYTE *j; // ebx
  _BYTE *v9; // [esp+Ch] [ebp-4h]

  v2 = a1 + 20; /*0x127a08*/
  v3 = (_BYTE *)(a2 + 20); /*0x127a0e*/
  for ( i = 4 * (*a1 & 0xF) - 20; i > 0; v2 += v6 ) /*0x127a1f*/
  {
    v5 = *v2; /*0x127a24*/
    if ( !*v2 ) /*0x127a24*/
      break; /*0x127a29*/
    if ( v5 == 1 ) /*0x127a2e*/
      v6 = 1; /*0x127a30*/
    else
      v6 = v2[1]; /*0x127a38*/
    if ( v6 > i ) /*0x127a3e*/
      v6 = i; /*0x127a40*/
    if ( (v5 & 0x80u) != 0 ) /*0x127a44*/
    {
      v9 = v3; /*0x127a49*/
      bcopy(v2, v3, v6); /*0x127a4c*/
      v3 = &v9[v6]; /*0x127a54*/
    }
    i -= v6; /*0x127a59*/
  }
  for ( j = &v3[-a2 - 20]; ((unsigned __int8)j & 3) != 0; ++j ) /*0x127a6c*/
    *v3++ = 0; /*0x127a70*/
  return j; /*0x127a7f*/
}
