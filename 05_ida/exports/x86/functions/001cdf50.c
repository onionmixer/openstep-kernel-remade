/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdf50. */
int (__stdcall *__cdecl sub_1CDF50(int *a1, int a2))(int *, char *, int)
{
  int (__stdcall *result)(int *, char *, int); // eax

  result = (int (__stdcall *)(int *, char *, int))sub_1CDF30(*a1); /*0x1cdf5a*/
  if ( result ) /*0x1cdf64*/
  {
    result = (int (__stdcall *)(int *, char *, int))class_lookupMethodInMethodList((int)result, (int)aFinishloading); /*0x1cdf6e*/
    if ( result ) /*0x1cdf78*/
      return (int (__stdcall *)(int *, char *, int))result(a1, aFinishloading, a2); /*0x1cdf86*/
  }
  return result; /*0x1cdf88*/
}
