/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162d80. */
int *wait_queue_init()
{
  int v0; // ebx
  unsigned int v1; // edx
  int *result; // eax
  int v3; // ecx

  v0 = 0; /*0x162d84*/
  v1 = 0; /*0x162d86*/
  result = wait_queue; /*0x162d88*/
  v3 = 0; /*0x162d8d*/
  do /*0x162db4*/
  {
    dword_1F6A14[v3] = (int)result; /*0x162d90*/
    wait_queue[v1 / 2] = (int)result; /*0x162d96*/
    wait_lock[v1 / 4] = 0; /*0x162d9d*/
    v1 += 4; /*0x162da7*/
    result += 2; /*0x162daa*/
    v3 += 2; /*0x162dad*/
    ++v0; /*0x162db0*/
  }
  while ( v0 <= 58 ); /*0x162db4*/
  return result; /*0x162db6*/
}
