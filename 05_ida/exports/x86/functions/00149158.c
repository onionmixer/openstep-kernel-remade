/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x149158. */
int __cdecl ipc_kmsg_copyout(unsigned int *a1, int a2, vm_map_t target_task, unsigned int a4)
{
  int v4; // esi
  int result; // eax

  v4 = a1[5]; /*0x149164*/
  result = ipc_kmsg_copyout_header(a1 + 5, a2, a4); /*0x149170*/
  if ( !result && v4 < 0 ) /*0x14917e*/
  {
    result = ipc_kmsg_copyout_body(a1 + 11, (unsigned int)a1 + a1[6] + 20, a2, target_task); /*0x149192*/
    if ( result ) /*0x149199*/
      return result | 0x1000400C; /*0x14919b*/
  }
  return result; /*0x1491a3*/
}
