/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a730. */
int __cdecl tcp_close(_DWORD *a1)
{
  int *v1; // edi
  _DWORD *v2; // ebx
  _DWORD *v3; // edx
  int v4; // eax
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v1 = (int *)a1[8]; /*0x12a73c*/
  v7 = v1[7]; /*0x12a742*/
  v2 = (_DWORD *)*a1; /*0x12a745*/
  while ( v2 != a1 ) /*0x12a749*/
  {
    v2 = (_DWORD *)*v2; /*0x12a74c*/
    v3 = (_DWORD *)v2[1]; /*0x12a74e*/
    v6 = v3[5]; /*0x12a754*/
    *(_DWORD *)(*v3 + 4) = v3[1]; /*0x12a75c*/
    *(_DWORD *)v3[1] = *v3; /*0x12a764*/
    m_freem(v6); /*0x12a76a*/
  }
  v4 = a1[7]; /*0x12a776*/
  if ( v4 ) /*0x12a77b*/
  {
    LOBYTE(v4) = v4 & 0x80; /*0x12a77d*/
    m_free(v4); /*0x12a780*/
  }
  kfree((int)a1, 0x6Cu); /*0x12a78b*/
  v1[8] = 0; /*0x12a790*/
  soisdisconnected(v7); /*0x12a79b*/
  if ( tcp_last_inpcb == v1 ) /*0x12a7a9*/
    tcp_last_inpcb = &tcb; /*0x12a7ab*/
  in_pcbdetach(v1); /*0x12a7b6*/
  ++dword_1EED84; /*0x12a7bb*/
  return 0; /*0x12a7c6*/
}
