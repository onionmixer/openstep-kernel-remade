/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e690. */
int __cdecl thread_set_cthread_self(int a1)
{
  *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 232) = a1; /*0x18e69e*/
  return 0; /*0x18e6a8*/
}
