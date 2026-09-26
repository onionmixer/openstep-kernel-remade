/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169ea0. */
int sub_169EA0()
{
  thread_act_t v0; // ebx

  stack_privilege(active_threads); /*0x169eab*/
  v0 = active_threads; /*0x169eb3*/
  splsched(); /*0x169eb9*/
  do /*0x169ed9*/
  {
    while ( dword_1E7244 ) /*0x169ec7*/
      ; /*0x169ec5*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169ed9*/
  if ( dword_1E7268 < dword_1E7260 + dword_1E7264 ) /*0x169eee*/
  {
    ++dword_1E7268; /*0x169ef1*/
    _InterlockedExchange(&dword_1E7244, 0); /*0x169ef9*/
    kernel_thread(*(_DWORD *)(v0 + 12), (int)sub_16A140, 0); /*0x169f0a*/
    thread_block_with_continuation((int)sub_169E0C); /*0x169f14*/
  }
  assert_wait((int)&dword_1E7268, 0); /*0x169f23*/
  _InterlockedExchange(&dword_1E7244, 0); /*0x169f2d*/
  return thread_block_with_continuation((int)sub_169E0C); /*0x169f3d*/
}
