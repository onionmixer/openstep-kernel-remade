/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120648. */
int __cdecl sub_120648(int a1, char *__s1, _DWORD *a3)
{
  int v3; // edi
  int v4; // eax
  __int16 v6; // ax
  __int16 v7; // ax
  int v8; // eax
  int v9; // [esp-8h] [ebp-14h]

  v3 = *(_DWORD *)(if_private(a1) + 20); /*0x12065d*/
  if ( !strcmp(__s1, "autoaddr") ) /*0x120666*/
  {
    if ( *(_WORD *)a3 == 2 ) /*0x120679*/
    {
      v4 = if_private(a1); /*0x12067c*/
      return in_bootp(a1, a3, v4 + 8); /*0x120692*/
    }
    return 47; /*0x120679*/
  }
  if ( strcmp(__s1, "setaddr") ) /*0x12069e*/
    return if_control(v3, __s1, a3); /*0x120746*/
  if ( *(_WORD *)a3 != 2 ) /*0x1206b5*/
    return 47; /*0x1206bc*/
  v6 = if_flags(a1); /*0x1206c5*/
  if_flags_set(a1, v6 | 0x8001); /*0x1206d1*/
  if ( !if_init(v3) ) /*0x1206d7*/
  {
    v7 = if_flags(a1); /*0x1206e4*/
    LOBYTE(v7) = v7 | 0x40; /*0x1206e9*/
    if_flags_set(a1, v7); /*0x1206ed*/
  }
  *(_DWORD *)(if_private(a1) + 16) = a3[1]; /*0x120704*/
  if ( (if_flags(a1) & 0x4000) == 0 ) /*0x120713*/
  {
    v9 = *(_DWORD *)(if_private(a1) + 16); /*0x120728*/
    v8 = if_private(a1); /*0x12072a*/
    arpwhohas(a1, (void *)(v8 + 8), v9, a3 + 1); /*0x120737*/
  }
  return 0; /*0x120755*/
}
