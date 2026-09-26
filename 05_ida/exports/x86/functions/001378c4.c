/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1378c4. */
int __cdecl svckudp_dup(_DWORD *a1)
{
  int v1; // edi
  _DWORD *i; // ebx

  ++dupchecks; /*0x1378cd*/
  v1 = *(_DWORD *)(*(_DWORD *)(a1[7] + 48) + 4); /*0x1378d9*/
  for ( i = (_DWORD *)drhashtbl[v1 & 0x1F]; i; i = (_DWORD *)i[9] ) /*0x1378e1*/
  {
    if ( *i == v1 && i[7] == *a1 && i[6] == a1[1] && i[5] == a1[2] && !bcmp(i + 1, (const void *)(a1[7] + 16), 0x10u) ) /*0x13791e*/
    {
      ++dupreqs; /*0x137928*/
      return 1; /*0x137933*/
    }
  }
  return 0; /*0x13793d*/
}
