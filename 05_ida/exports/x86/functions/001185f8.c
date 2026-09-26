/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1185f8. */
int __cdecl unp_attach(int a1)
{
  int result; // eax
  int *v2; // ebx

  if ( *(_WORD *)a1 == 1 ) /*0x118607*/
  {
    result = soreserve(a1, unpst_sendspace, unpst_recvspace); /*0x118621*/
  }
  else
  {
    if ( *(_WORD *)a1 != 2 ) /*0x11860d*/
      panic(aUnpAttackBadSo); /*0x118647*/
    result = soreserve(a1, unpdg_sendspace, unpdg_recvspace); /*0x118633*/
  }
  if ( !result ) /*0x118651*/
  {
    v2 = (int *)kalloc(0x24u); /*0x11865a*/
    bzero(v2, 0x24u); /*0x11865f*/
    *(_DWORD *)(a1 + 8) = v2; /*0x118664*/
    *v2 = a1; /*0x118667*/
    return 0; /*0x118669*/
  }
  return result; /*0x118675*/
}
