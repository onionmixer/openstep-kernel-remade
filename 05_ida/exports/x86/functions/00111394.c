/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111394. */
int (__stdcall *__cdecl ttydevstart(int a1))(int)
{
  int (__stdcall *result)(int); // eax

  result = *(int (__stdcall **)(int))(a1 + 36); /*0x11139a*/
  if ( result ) /*0x11139f*/
    return (int (__stdcall *)(int))result(a1); /*0x1113a2*/
  return result; /*0x1113a6*/
}
