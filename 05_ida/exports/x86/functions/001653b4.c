/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1653b4. */
boolean_t swtch(void)
{
  boolean_t v0; // edx

  thread_block_with_continuation((int)swtch_continue); /*0x1653bc*/
  v0 = 0; /*0x1653c6*/
  if ( *(int *)(processor_ptr[0] + 264) > 0 || *(int *)(*(_DWORD *)(processor_ptr[0] + 300) + 264) > 0 ) /*0x1653de*/
    return 1; /*0x1653e0*/
  return v0; /*0x1653e9*/
}
