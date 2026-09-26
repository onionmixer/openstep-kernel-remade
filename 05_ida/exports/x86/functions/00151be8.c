/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151be8. */
_DWORD *__cdecl ipc_thread_enqueue(_DWORD *a1, int a2)
{
  _DWORD *result; // eax
  int v3; // edx

  result = a1; /*0x151beb*/
  v3 = *a1; /*0x151bf1*/
  if ( *a1 ) /*0x151bf1*/
  {
    result = *(_DWORD **)(v3 + 148); /*0x151c00*/
    *(_DWORD *)(a2 + 144) = v3; /*0x151c06*/
    *(_DWORD *)(a2 + 148) = result; /*0x151c0c*/
    *(_DWORD *)(v3 + 148) = a2; /*0x151c12*/
    result[36] = a2; /*0x151c18*/
  }
  else
  {
    *a1 = a2; /*0x151bf7*/
  }
  return result; /*0x151bfb*/
}
