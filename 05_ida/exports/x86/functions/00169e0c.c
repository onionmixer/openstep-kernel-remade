/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169e0c. */
int sub_169E0C()
{
  thread_act_t v0; // ebx

  v0 = active_threads; /*0x169e10*/
  splsched(); /*0x169e16*/
  do /*0x169e35*/
  {
    while ( dword_1E7244 ) /*0x169e23*/
      ; /*0x169e21*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169e35*/
  if ( dword_1E7268 < dword_1E7260 + dword_1E7264 ) /*0x169e4a*/
  {
    ++dword_1E7268; /*0x169e4d*/
    _InterlockedExchange(&dword_1E7244, 0); /*0x169e55*/
    kernel_thread(*(_DWORD *)(v0 + 12), (int)sub_16A140, 0); /*0x169e66*/
    thread_block_with_continuation((int)sub_169E0C); /*0x169e70*/
  }
  assert_wait((int)&dword_1E7268, 0); /*0x169e7f*/
  _InterlockedExchange(&dword_1E7244, 0); /*0x169e89*/
  return thread_block_with_continuation((int)sub_169E0C); /*0x169e99*/
}
