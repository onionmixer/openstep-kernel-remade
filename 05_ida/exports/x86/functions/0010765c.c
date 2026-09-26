/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10765c. */
int __cdecl leavepgrp(int a1)
{
  int posix_proc; // ebx
  int v2; // edx
  int result; // eax

  posix_proc = get_posix_proc(*(__int16 *)(a1 + 48)); /*0x10766e*/
  v2 = *(_DWORD *)(posix_proc + 16) + 4; /*0x107673*/
  if ( !*(_DWORD *)v2 ) /*0x10767d*/
LABEL_5:
    panic(aLeavepgrpCanTF); /*0x1076a6*/
  while ( *(_DWORD *)v2 != a1 ) /*0x107684*/
  {
    v2 = get_posix_proc(*(__int16 *)(*(_DWORD *)v2 + 48)) + 12; /*0x10769a*/
    if ( !*(_DWORD *)v2 ) /*0x1076a0*/
      goto LABEL_5; /*0x1076a4*/
  }
  *(_DWORD *)v2 = *(_DWORD *)(posix_proc + 12); /*0x107689*/
  result = *(_DWORD *)(posix_proc + 16); /*0x1076b3*/
  if ( !*(_DWORD *)(result + 4) ) /*0x1076b6*/
    result = pgdelete(*(_DWORD *)(posix_proc + 16)); /*0x1076bd*/
  *(_DWORD *)(posix_proc + 16) = 0; /*0x1076c2*/
  *(_WORD *)(a1 + 46) = 0; /*0x1076c9*/
  return result; /*0x1076d2*/
}
