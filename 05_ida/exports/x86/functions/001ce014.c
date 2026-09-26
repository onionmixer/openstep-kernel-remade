/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ce014. */
Class __cdecl sub_1CE014(int a1)
{
  Class result; // eax
  int (__stdcall *v2)(Class, char *); // ebx

  result = *(Class *)(a1 + 12); /*0x1ce01c*/
  if ( result ) /*0x1ce021*/
  {
    v2 = (int (__stdcall *)(Class, char *))class_lookupMethodInMethodList((int)result, (int)aStartunloading); /*0x1ce030*/
    result = objc_getClass(*(const char **)(a1 + 4)); /*0x1ce036*/
    if ( v2 ) /*0x1ce040*/
      return (Class)v2(result, aStartunloading); /*0x1ce04a*/
  }
  return result; /*0x1ce04f*/
}
