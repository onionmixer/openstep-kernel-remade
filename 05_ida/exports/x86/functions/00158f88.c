/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x158f88. */
mach_port_t mig_get_reply_port(void)
{
  thread_act_t v0; // ebx

  v0 = active_threads; /*0x158f8c*/
  if ( !*(_DWORD *)(active_threads + 188) ) /*0x158f92*/
    *(_DWORD *)(v0 + 188) = mach_reply_port(); /*0x158fa0*/
  return *(_DWORD *)(v0 + 188); /*0x158fac*/
}
