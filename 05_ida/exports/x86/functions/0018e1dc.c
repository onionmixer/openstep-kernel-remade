/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e1dc. */
int __cdecl thread_setstatus(int a1, int a2, int a3, int a4)
{
  if ( a2 == -2 ) /*0x18e1ef*/
    return set_thread_fpstate(a1, a3, a4); /*0x18e203*/
  if ( a2 == -1 ) /*0x18e1f4*/
    return set_thread_state(a1, a3, a4); /*0x18e1f9*/
  return 4; /*0x18e211*/
}
