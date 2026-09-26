/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146f68. */
_DWORD *__cdecl ipc_kmsg_dequeue(_DWORD **a1)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // edx
  _DWORD *v3; // eax

  v1 = *a1; /*0x146f6f*/
  if ( *a1 ) /*0x146f6f*/
  {
    v2 = (_DWORD *)*v1; /*0x146f75*/
    if ( (_DWORD *)*v1 == v1 ) /*0x146f79*/
    {
      *a1 = nullptr; /*0x146f7b*/
    }
    else
    {
      v3 = (_DWORD *)v1[1]; /*0x146f84*/
      *a1 = v2; /*0x146f87*/
      v2[1] = v3; /*0x146f89*/
      *v3 = v2; /*0x146f8c*/
    }
  }
  return v1; /*0x146f90*/
}
