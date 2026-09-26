/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdf90. */
Class __cdecl sub_1CDF90(int a1, int a2)
{
  Class result; // eax
  int (__stdcall *v3)(Class, char *, int); // ebx

  result = *(Class *)(a1 + 12); /*0x1cdf98*/
  if ( result ) /*0x1cdf9d*/
  {
    v3 = (int (__stdcall *)(Class, char *, int))class_lookupMethodInMethodList((int)result, (int)aFinishloading); /*0x1cdfac*/
    result = objc_getClass(*(const char **)(a1 + 4)); /*0x1cdfb2*/
    if ( v3 ) /*0x1cdfbc*/
      return (Class)v3(result, aFinishloading, a2); /*0x1cdfca*/
  }
  return result; /*0x1cdfcf*/
}
