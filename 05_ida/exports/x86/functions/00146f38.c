/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146f38. */
_DWORD *__cdecl ipc_kmsg_enqueue(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // edx

  result = a1; /*0x146f3b*/
  v3 = *a1; /*0x146f41*/
  if ( *a1 ) /*0x146f41*/
  {
    result = *(_DWORD **)(v3 + 4); /*0x146f54*/
    *a2 = v3; /*0x146f57*/
    a2[1] = result; /*0x146f59*/
    *(_DWORD *)(v3 + 4) = a2; /*0x146f5c*/
    *result = a2; /*0x146f5f*/
  }
  else
  {
    *a1 = a2; /*0x146f47*/
    *a2 = a2; /*0x146f49*/
    a2[1] = a2; /*0x146f4b*/
  }
  return result; /*0x146f50*/
}
