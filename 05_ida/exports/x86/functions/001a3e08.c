/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3e08. */
int *__cdecl sub_1A3E08(int a1)
{
  int *result; // eax

  result = (int *)dword_1E866C; /*0x1a3e0e*/
  if ( (int *)dword_1E866C == &dword_1E866C ) /*0x1a3e18*/
    return nullptr; /*0x1a3e2a*/
  while ( *result != a1 ) /*0x1a3e1e*/
  {
    result = (int *)result[2]; /*0x1a3e20*/
    if ( result == &dword_1E866C ) /*0x1a3e28*/
      return nullptr; /*0x1a3e28*/
  }
  return result; /*0x1a3e2e*/
}
