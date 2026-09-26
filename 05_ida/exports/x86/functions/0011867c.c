/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11867c. */
int __cdecl unp_detach(int *a1)
{
  int v1; // eax
  int result; // eax

  v1 = a1[1]; /*0x118683*/
  if ( v1 ) /*0x118688*/
  {
    *(_DWORD *)(v1 + 32) = 0; /*0x11868a*/
    vn_rele(a1[1]); /*0x118695*/
    a1[1] = 0; /*0x11869a*/
  }
  if ( a1[3] ) /*0x1186a4*/
    unp_disconnect(a1); /*0x1186ab*/
  while ( a1[4] ) /*0x1186ca*/
    unp_drop(a1[4], 54); /*0x1186be*/
  soisdisconnected(*a1); /*0x1186cf*/
  *(_DWORD *)(*a1 + 8) = 0; /*0x1186d6*/
  m_freem(a1[6]); /*0x1186e1*/
  result = kfree((int)a1, 0x24u); /*0x1186e9*/
  if ( unp_rights ) /*0x1186f8*/
    return unp_gc(); /*0x1186fa*/
  return result; /*0x1186ff*/
}
