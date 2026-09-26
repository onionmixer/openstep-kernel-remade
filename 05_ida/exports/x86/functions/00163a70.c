/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163a70. */
int __cdecl thread_run(int a1, thread_act_t a2)
{
  int v3; // edi
  int *v4; // esi
  int v6; // [esp+Ch] [ebp-4h]

  v3 = active_threads; /*0x163a7c*/
  v4 = (int *)processor_ptr[0]; /*0x163a82*/
  v6 = splsched(); /*0x163a8d*/
  while ( !thread_invoke(v3, a1, a2) ) /*0x163aa0*/
    a2 = thread_select(v4); /*0x163aa8*/
  return splx(v6); /*0x163abc*/
}
