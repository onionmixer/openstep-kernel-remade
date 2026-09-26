/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c954. */
_DWORD *__cdecl ipc_port_init(_DWORD *a1, int a2, int a3)
{
  _DWORD *result; // eax

  a1[3] = a2; /*0x14c961*/
  a1[4] = a3; /*0x14c964*/
  a1[6] = 0; /*0x14c967*/
  a1[7] = 0; /*0x14c96e*/
  a1[8] = 0; /*0x14c975*/
  a1[9] = 0; /*0x14c97c*/
  a1[10] = 0; /*0x14c983*/
  a1[11] = 0; /*0x14c98a*/
  a1[12] = 0; /*0x14c991*/
  a1[13] = 0; /*0x14c998*/
  a1[14] = 0; /*0x14c99f*/
  a1[15] = 5; /*0x14c9a6*/
  result = ipc_mqueue_init(a1 + 16); /*0x14c9b1*/
  a1[19] = 0; /*0x14c9b6*/
  return result; /*0x14c9bd*/
}
