/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b470. */
int __cdecl stack_free(int a1)
{
  int result; // eax

  result = stack_detach(a1); /*0x15b478*/
  if ( *(_DWORD *)(a1 + 48) != result ) /*0x15b483*/
    return freeStack(result); /*0x15b486*/
  return result; /*0x15b48b*/
}
