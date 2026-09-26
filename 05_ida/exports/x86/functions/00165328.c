/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165328. */
int thread_block()
{
  int v0; // esi
  int *v1; // ebx
  int v2; // edi
  int v3; // eax
  thread_act_t v4; // eax

  v0 = active_threads; /*0x16532e*/
  v1 = (int *)processor_ptr[0]; /*0x165334*/
  v2 = splsched(); /*0x16533f*/
  v3 = need_ast[0]; /*0x165341*/
  LOBYTE(v3) = need_ast[0] & 0xFB; /*0x165346*/
  need_ast[0] = v3; /*0x165348*/
  do /*0x16536b*/
    v4 = thread_select(v1); /*0x165355*/
  while ( !thread_invoke(v0, 0, v4) ); /*0x16536b*/
  return splx(v2); /*0x165376*/
}
