/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c490. */
int __cdecl ipc_port_dnrequest(int a1, int a2, int a3, _DWORD *a4)
{
  int *v4; // edx
  int v5; // ecx
  int *v6; // eax

  v4 = *(int **)(a1 + 44); /*0x14c49b*/
  if ( !v4 ) /*0x14c4a0*/
    return 3; /*0x14c4a0*/
  v5 = *v4; /*0x14c4a2*/
  if ( !*v4 ) /*0x14c4a2*/
    return 3; /*0x14c4c0*/
  v6 = &v4[2 * v5]; /*0x14c4a8*/
  *v4 = *v6; /*0x14c4ad*/
  v6[1] = a2; /*0x14c4b2*/
  *v6 = a3; /*0x14c4b8*/
  *a4 = v5; /*0x14c4ba*/
  return 0; /*0x14c4c8*/
}
