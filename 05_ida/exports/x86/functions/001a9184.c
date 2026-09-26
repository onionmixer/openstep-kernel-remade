/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9184. */
int __cdecl IOSetThreadPriority(int a1, unsigned int a2)
{
  int v2; // eax

  v2 = thread_priority(a1, a2, 0); /*0x1a9191*/
  if ( v2 == 4 ) /*0x1a9199*/
    return -706; /*0x1a919b*/
  if ( v2 == 5 ) /*0x1a91a7*/
    return -705; /*0x1a91b0*/
  return 0; /*0x1a91a2*/
}
