/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118a20. */
int __cdecl unp_externalize(int a1)
{
  int *v1; // esi
  signed int j; // ebx
  signed int i; // ebx
  int v5; // edi
  int v6; // edx
  signed int v7; // [esp+Ch] [ebp-4h]

  v7 = (unsigned int)*(__int16 *)(a1 + 8) >> 2; /*0x118a33*/
  v1 = (int *)(*(_DWORD *)(a1 + 4) + a1); /*0x118a38*/
  if ( v7 <= ufavail() ) /*0x118a43*/
  {
    for ( i = 0; v7 > i; ++i ) /*0x118a75*/
    {
      v5 = ufalloc(0); /*0x118a7f*/
      if ( v5 < 0 ) /*0x118a86*/
        panic(aUnpExternalize); /*0x118a8d*/
      v6 = *v1; /*0x118a95*/
      *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v5) = *v1; /*0x118aa2*/
      --*(_WORD *)(v6 + 16); /*0x118aa5*/
      --unp_rights; /*0x118aa9*/
      *v1++ = v5; /*0x118aaf*/
    }
    return 0; /*0x118aba*/
  }
  else
  {
    for ( j = 0; v7 > j; ++j ) /*0x118a4a*/
    {
      unp_discard(*v1); /*0x118a4f*/
      *v1++ = 0; /*0x118a54*/
    }
    return 40; /*0x118a66*/
  }
}
