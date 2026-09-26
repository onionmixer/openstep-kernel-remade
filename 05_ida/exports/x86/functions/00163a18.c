/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163a18. */
int __cdecl thread_block_with_continuation(int a1)
{
  int v1; // esi
  int *v2; // ebx
  int v3; // edi
  int v4; // eax
  thread_act_t v5; // eax

  v1 = active_threads; /*0x163a1e*/
  v2 = (int *)processor_ptr[0]; /*0x163a24*/
  v3 = splsched(); /*0x163a2f*/
  v4 = need_ast[0]; /*0x163a31*/
  LOBYTE(v4) = need_ast[0] & 0xFB; /*0x163a36*/
  need_ast[0] = v4; /*0x163a38*/
  do /*0x163a5d*/
    v5 = thread_select(v2); /*0x163a45*/
  while ( !thread_invoke(v1, a1, v5) ); /*0x163a5d*/
  return splx(v3); /*0x163a68*/
}
