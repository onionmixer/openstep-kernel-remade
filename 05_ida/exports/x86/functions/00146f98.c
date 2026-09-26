/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146f98. */
_DWORD *__cdecl ipc_kmsg_rmqueue(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ebx

  result = (_DWORD *)*a2; /*0x146fa2*/
  v3 = (_DWORD *)a2[1]; /*0x146fa4*/
  if ( (_DWORD *)*a2 == a2 ) /*0x146fa9*/
  {
    *a1 = 0; /*0x146fab*/
  }
  else
  {
    if ( (_DWORD *)*a1 == a2 ) /*0x146fb6*/
      *a1 = result; /*0x146fb8*/
    result[1] = v3; /*0x146fba*/
    *v3 = result; /*0x146fbd*/
  }
  return result; /*0x146fbf*/
}
