/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12075c. */
int __cdecl sub_12075C(int a1)
{
  int v1; // esi
  unsigned int v2; // edi
  int v3; // eax
  int v4; // ebx
  __int16 v6; // ax

  v1 = *(_DWORD *)(if_private(a1) + 20); /*0x12076e*/
  v2 = if_mtu(a1); /*0x120777*/
  v3 = if_getbuf(v1); /*0x12077a*/
  v4 = v3; /*0x12077f*/
  if ( !v3 ) /*0x120786*/
    return 0; /*0x120788*/
  nb_shrink_top(v3, 8); /*0x12078f*/
  if ( nb_size(v4) > v2 ) /*0x12079f*/
  {
    v6 = nb_size(v4); /*0x1207a2*/
    nb_shrink_bot(v4, v6 - v2); /*0x1207ab*/
  }
  return v4; /*0x1207b5*/
}
