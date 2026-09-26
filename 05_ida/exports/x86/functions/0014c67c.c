/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c67c. */
int __cdecl ipc_port_pdrequest(int a1, int a2, _DWORD *a3)
{
  int v4; // edx

  v4 = *(_DWORD *)(a1 + 40); /*0x14c687*/
  *(_DWORD *)(a1 + 40) = a2; /*0x14c68d*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14c692*/
  *a3 = v4; /*0x14c694*/
  return a1; /*0x14c699*/
}
