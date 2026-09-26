/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d208. */
_DWORD *__cdecl stack_attach(int a1, int a2, int a3)
{
  _DWORD *result; // eax

  *(_DWORD *)(a1 + 44) = a2; /*0x18d214*/
  result = **(_DWORD ***)(a1 + 40); /*0x18d21a*/
  result[15] = a2 + 4084; /*0x18d222*/
  result[14] = a2 + 4084; /*0x18d225*/
  result[8] = _stack_attach; /*0x18d228*/
  result[13] = a3; /*0x18d22f*/
  return result; /*0x18d234*/
}
