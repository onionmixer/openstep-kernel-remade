/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165434. */
boolean_t __cdecl swtch_pri(int pri)
{
  thread_act_t v1; // ebx
  boolean_t v2; // edx

  v1 = active_threads; /*0x165438*/
  thread_depress_priority(active_threads, min_quantum); /*0x165446*/
  thread_block_with_continuation((int)swtch_pri_continue); /*0x165450*/
  if ( *(int *)(v1 + 100) >= 0 ) /*0x16545c*/
    thread_depress_abort(v1); /*0x16545f*/
  v2 = 0; /*0x165469*/
  if ( *(int *)(processor_ptr[0] + 264) > 0 || *(int *)(*(_DWORD *)(processor_ptr[0] + 300) + 264) > 0 ) /*0x165481*/
    return 1; /*0x165483*/
  return v2; /*0x16548a*/
}
