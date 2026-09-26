/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x147688. */
int __cdecl ipc_kmsg_get_from_kernel(void *a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // eax
  _DWORD *v5; // ebx

  v4 = (_DWORD *)kalloc(a2 + 20); /*0x147695*/
  v5 = v4; /*0x14769a*/
  if ( !v4 ) /*0x1476a1*/
    return 268435469; /*0x1476dc*/
  v4[2] = a2 + 20; /*0x1476a3*/
  v4[3] = 0; /*0x1476a6*/
  v4[4] = 0; /*0x1476ad*/
  bcopy(a1, v4 + 5, a2 + a3); /*0x1476c2*/
  v5[4] = a3; /*0x1476ca*/
  v5[6] = a2; /*0x1476cd*/
  *a4 = v5; /*0x1476d3*/
  return 0; /*0x1476e4*/
}
