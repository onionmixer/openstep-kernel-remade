/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106d44. */
int __cdecl utask_free(int *a1)
{
  unsigned int v1; // ebx

  v1 = a1[87]; /*0x106d4c*/
  if ( v1 ) /*0x106d54*/
  {
    kfree(a1[84], 4 * v1); /*0x106d65*/
    kfree(a1[85], v1); /*0x106d72*/
    a1[87] = 0; /*0x106d77*/
  }
  return zfree(u_task_zone, a1); /*0x106d94*/
}
