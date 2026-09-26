/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf4fc. */
char *__cdecl sub_1CF4FC(int a1)
{
  char *result; // eax
  char *v2; // esi
  Class Class; // edi
  uint32_t v4; // eax
  uint32_t i; // ebx
  unsigned int v6; // [esp+10h] [ebp-8h]
  uint32_t size; // [esp+14h] [ebp-4h] BYREF

  result = getsectdatafromheaderinfo(a1, "__OBJC", "__string_object", &size); /*0x1cf517*/
  v2 = result; /*0x1cf51c*/
  if ( result && size ) /*0x1cf529*/
  {
    Class = objc_getClass("NXConstantString"); /*0x1cf535*/
    v6 = 0; /*0x1cf537*/
    v4 = size; /*0x1cf53e*/
    for ( i = size; ; v4 = i ) /*0x1cf541*/
    {
      result = (char *)(v4 / 0xC); /*0x1cf55e*/
      if ( v6 >= (unsigned int)result ) /*0x1cf563*/
        break; /*0x1cf563*/
      *(_DWORD *)&v2[12 * v6++] = Class; /*0x1cf54e*/
    }
  }
  return result; /*0x1cf568*/
}
