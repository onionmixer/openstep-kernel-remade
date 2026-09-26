/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ce058. */
char *__cdecl sub_1CE058(mach_header *mhp)
{
  char *result; // eax
  char *v2; // esi
  Class Class; // edi
  uint32_t v4; // eax
  uint32_t i; // ebx
  unsigned int v6; // [esp+10h] [ebp-8h]
  uint32_t size; // [esp+14h] [ebp-4h] BYREF

  result = getsectdatafromheader(mhp, "__OBJC", "__string_object", &size); /*0x1ce073*/
  v2 = result; /*0x1ce078*/
  if ( result && size ) /*0x1ce085*/
  {
    Class = objc_getClass("NXConstantString"); /*0x1ce091*/
    v6 = 0; /*0x1ce093*/
    v4 = size; /*0x1ce09a*/
    for ( i = size; ; v4 = i ) /*0x1ce09d*/
    {
      result = (char *)(v4 / 0xC); /*0x1ce0ba*/
      if ( v6 >= (unsigned int)result ) /*0x1ce0bf*/
        break; /*0x1ce0bf*/
      *(_DWORD *)&v2[12 * v6++] = Class; /*0x1ce0aa*/
    }
  }
  return result; /*0x1ce0c4*/
}
