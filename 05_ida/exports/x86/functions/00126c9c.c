/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126c9c. */
int __cdecl ip_rtaddr(int a1)
{
  __int16 v1; // dx
  int result; // eax

  if ( ipforward_rt ) /*0x126cb0*/
  {
    if ( dword_1EACF8 == a1 ) /*0x126cb8*/
      goto LABEL_8; /*0x126cb8*/
    v1 = *(_WORD *)(ipforward_rt + 38); /*0x126cba*/
    if ( v1 == 1 ) /*0x126cc2*/
      rtfree(ipforward_rt); /*0x126cc5*/
    else
      *(_WORD *)(ipforward_rt + 38) = v1 - 1; /*0x126cd2*/
    ipforward_rt = 0; /*0x126cd6*/
  }
  word_1EACF4 = 2; /*0x126ce0*/
  dword_1EACF8 = a1; /*0x126ce5*/
  rtalloc(&ipforward_rt); /*0x126ced*/
LABEL_8:
  if ( !ipforward_rt ) /*0x126cfa*/
    return 0; /*0x126cfc*/
  for ( result = in_ifaddr; result; result = *(_DWORD *)(result + 64) ) /*0x126d07*/
  {
    if ( *(_DWORD *)(result + 32) == *(_DWORD *)(ipforward_rt + 44) ) /*0x126d0f*/
      break; /*0x126d0f*/
  }
  return result; /*0x126d1b*/
}
