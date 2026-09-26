/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155540. */
unsigned int __cdecl mach_port_gst_helper(int a1, int a2, unsigned int a3, int a4, unsigned int *a5)
{
  int v5; // ebx
  unsigned int result; // eax
  unsigned int v7; // eax

  do /*0x155562*/
  {
    while ( *(_DWORD *)a2 ) /*0x155550*/
      ; /*0x155552*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x155562*/
  v5 = *(_DWORD *)(a2 + 16); /*0x155564*/
  result = *(_DWORD *)(a2 + 48); /*0x155567*/
  _InterlockedExchange((volatile __int32 *)a2, 0); /*0x15556c*/
  if ( a1 == result ) /*0x155571*/
  {
    v7 = *a5; /*0x155573*/
    if ( a3 > *a5 ) /*0x155578*/
      *(_DWORD *)(a4 + 4 * v7) = v5; /*0x15557a*/
    result = v7 + 1; /*0x15557d*/
    *a5 = result; /*0x15557e*/
  }
  return result; /*0x155583*/
}
