/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18e9a4. */
int thread_get_cthread_self()
{
  return *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 232); /*0x18e9b7*/
}
