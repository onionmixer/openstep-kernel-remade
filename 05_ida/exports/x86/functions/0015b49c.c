/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b49c. */
int __cdecl stack_statistics(_DWORD *a1, unsigned int *a2)
{
  int *i; // ebx
  unsigned int v3; // eax

  lock_read(&stack_queue_lock); /*0x15b4ad*/
  if ( stack_check_usage ) /*0x15b4bc*/
  {
    for ( i = (int *)dword_1E5B98; i != &dword_1E5B98; i = (int *)*i ) /*0x15b4ca*/
    {
      v3 = stack_usage(i + 3); /*0x15b4d0*/
      if ( *a2 < v3 ) /*0x15b4da*/
        *a2 = v3; /*0x15b4dc*/
    }
  }
  *a1 = dword_1DED68; /*0x15b4ee*/
  return lock_done(&stack_queue_lock); /*0x15b4fd*/
}
