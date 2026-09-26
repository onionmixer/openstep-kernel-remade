/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x105ad8. */
void __cdecl __noreturn exit(int a1)
{
  do_exit(*(_DWORD *)active_u, a1); /*0x105ae7*/
  while ( 1 ) /*0x105af2*/
    thread_halt_self_with_continuation(0); /*0x105af2*/
}
