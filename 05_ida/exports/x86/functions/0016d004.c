/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d004. */
int __cdecl sub_16D004(int *a1, int a2)
{
  unsigned int v2; // ebx
  int v3; // eax

  v2 = (~page_mask & (unsigned int)(page_mask + 32 * a2)) >> 5; /*0x16d01f*/
  v3 = kalloc(~page_mask & (page_mask + 32 * a2)); /*0x16d023*/
  *a1 = v3; /*0x16d028*/
  a1[2] = 32 * v2 + v3; /*0x16d02f*/
  a1[1] = *a1; /*0x16d034*/
  return printf("kern_serv_log_init: log 0x%x log.last 0x%x, log.base 0x%x\n", a1, a1[2], *a1);
}
