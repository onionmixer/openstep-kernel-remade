/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106cfc. */
int uzone_init()
{
  int result; // eax

  u_task_zone = zinit(664, 339968, 42496, 0, aUtasks); /*0x106d1a*/
  result = zinit(344, 176128, 22016, 0, aUthreads); /*0x106d35*/
  u_thread_zone = result; /*0x106d3a*/
  return result; /*0x106d41*/
}
