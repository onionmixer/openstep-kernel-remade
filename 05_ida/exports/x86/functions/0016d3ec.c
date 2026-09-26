/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d3ec. */
_DWORD *__cdecl sub_16D3EC(_DWORD *a1)
{
  _DWORD *result; // eax
  int v2; // edx

  if ( a1[5] != 484675 )
    return (_DWORD *)printf("notify server: bogus msg_id on pn_register_port (%d)\n", a1[5]);
  result = (_DWORD *)kalloc(0x14u); /*0x16d3ff*/
  result[2] = a1[7]; /*0x16d407*/
  result[3] = a1[8]; /*0x16d40d*/
  result[4] = a1[10]; /*0x16d413*/
  v2 = dword_1E727C; /*0x16d416*/
  if ( (int *)dword_1E727C == &dword_1E7278 ) /*0x16d422*/
    dword_1E7278 = (int)result; /*0x16d424*/
  else
    *(_DWORD *)dword_1E727C = result; /*0x16d42c*/
  result[1] = v2; /*0x16d42e*/
  *result = &dword_1E7278; /*0x16d431*/
  dword_1E727C = (int)result; /*0x16d437*/
  return result; /*0x16d44b*/
}
