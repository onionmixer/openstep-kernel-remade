/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf570. */
char *__cdecl sub_1CF570(int a1)
{
  char *result; // eax
  char *v2; // esi
  uint32_t i; // ebx
  uint32_t size; // [esp+8h] [ebp-4h] BYREF

  result = getsectdatafromheaderinfo(a1, "__OBJC", "__cls_refs", &size); /*0x1cf58a*/
  v2 = result; /*0x1cf58f*/
  if ( result ) /*0x1cf596*/
  {
    for ( i = 0; ; ++i ) /*0x1cf598*/
    {
      result = (char *)(size >> 2); /*0x1cf5af*/
      if ( i >= size >> 2 ) /*0x1cf5b4*/
        break; /*0x1cf5b4*/
      *(_DWORD *)&v2[4 * i] = objc_lookUpClass(*(const char **)&v2[4 * i]); /*0x1cf5a5*/
    }
  }
  return result; /*0x1cf5b9*/
}
