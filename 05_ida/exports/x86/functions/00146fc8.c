/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146fc8. */
int __cdecl ipc_kmsg_queue_next(_DWORD *a1, int *a2)
{
  int result; // eax

  result = *a2; /*0x146fd1*/
  if ( *a1 == *a2 ) /*0x146fd5*/
    return 0; /*0x146fd7*/
  return result; /*0x146fdb*/
}
