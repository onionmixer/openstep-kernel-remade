/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d5c4. */
int __cdecl pcb_common_init(int a1)
{
  _DWORD *v1; // esi
  int result; // eax

  v1 = (_DWORD *)kalloc(0x1Cu); /*0x18d5d3*/
  LOBYTE(result) = lock_init(v1 + 4, 1); /*0x18d5db*/
  *v1 = (char *)ldt - 0x40000000; /*0x18d5ec*/
  v1[1] = 24; /*0x18d5ee*/
  v1[2] = 0; /*0x18d5f5*/
  v1[3] = 0; /*0x18d5fc*/
  *(_DWORD *)(a1 + 64) = v1; /*0x18d603*/
  return result; /*0x18d609*/
}
