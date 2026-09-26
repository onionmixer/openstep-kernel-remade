/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdfd8. */
int (__stdcall *__cdecl sub_1CDFD8(int *a1))(int *, char *)
{
  int (__stdcall *result)(int *, char *); // eax

  result = (int (__stdcall *)(int *, char *))sub_1CDF30(*a1); /*0x1cdfe2*/
  if ( result ) /*0x1cdfec*/
  {
    result = (int (__stdcall *)(int *, char *))class_lookupMethodInMethodList((int)result, (int)aStartunloading); /*0x1cdff6*/
    if ( result ) /*0x1ce000*/
      return (int (__stdcall *)(int *, char *))result(a1, aStartunloading); /*0x1ce00a*/
  }
  return result; /*0x1ce00c*/
}
