/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168e80. */
int thread_stats()
{
  int v0; // edx
  int v1; // ebx
  int *i; // eax

  v0 = 0; /*0x168e84*/
  v1 = 0; /*0x168e86*/
  for ( i = (int *)dword_1E9748; i != &dword_1E9748; i = (int *)i[6] ) /*0x168e92*/
  {
    ++v0; /*0x168e94*/
    if ( i[48] ) /*0x168e95*/
      ++v1; /*0x168e9e*/
  }
  printf("%d total threads.\n", v0); /*0x168eaf*/
  return printf("%d using rpc_reply.\n", v1); /*0x168ebf*/
}
