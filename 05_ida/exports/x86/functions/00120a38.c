/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120a38. */
int *__cdecl nb_alloc_wrapper(int a1, __int16 a2, int a3, int a4)
{
  int *result; // eax

  result = mclgetx(a3, a4, a1, a2, 0); /*0x120a4d*/
  if ( !result ) /*0x120a54*/
    return nullptr; /*0x120a56*/
  return result; /*0x120a5a*/
}
