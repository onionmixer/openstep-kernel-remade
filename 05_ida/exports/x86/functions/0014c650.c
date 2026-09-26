/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c650. */
int __cdecl ipc_port_dncancel(int a1, int a2, int a3)
{
  int *v3; // edx
  int *v4; // eax
  int v5; // ebx

  v3 = *(int **)(a1 + 44); /*0x14c65b*/
  v4 = &v3[2 * a3]; /*0x14c65e*/
  v5 = *v4; /*0x14c661*/
  v4[1] = 0; /*0x14c663*/
  *v4 = *v3; /*0x14c66c*/
  *v3 = a3; /*0x14c66e*/
  return v5; /*0x14c675*/
}
