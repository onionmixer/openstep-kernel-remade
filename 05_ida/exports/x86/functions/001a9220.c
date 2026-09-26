/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9220. */
int IOExitThread()
{
  thread_act_t v0; // eax

  v0 = current_thread_EXTERNAL(); /*0x1a9223*/
  thread_terminate(v0); /*0x1a9229*/
  return thread_halt_self(); /*0x1a9235*/
}
