/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162ed8. */
_DWORD *__cdecl thread_timeout_setup(_DWORD *a1)
{
  a1[78] = thread_timeout; /*0x162edf*/
  a1[79] = a1; /*0x162ee9*/
  init_timeout_element(a1 + 70); /*0x162ef6*/
  a1[90] = thread_depress_timeout; /*0x162efb*/
  a1[91] = a1; /*0x162f05*/
  return init_timeout_element(a1 + 82); /*0x162f17*/
}
