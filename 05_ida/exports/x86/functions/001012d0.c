/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1012d0. */
void *__cdecl memchr(const void *__s, int __c, size_t __n)
{
  bool v3; // zf
  char *v4; // ecx

  v3 = __n == 0; /*0x1012d7*/
  if ( !__n ) /*0x1012d9*/
    return nullptr; /*0x1012f0*/
  v4 = (char *)__n; /*0x1012db*/
  do /*0x1012e3*/
  {
    if ( !v4 ) /*0x1012e3*/
      break; /*0x1012e3*/
    v3 = *(_BYTE *)__s == (unsigned __int8)__c; /*0x1012e3*/
    __s = (char *)__s + 1; /*0x1012e3*/
    --v4; /*0x1012e3*/
  }
  while ( !v3 ); /*0x1012e3*/
  if ( v3 ) /*0x1012e5*/
    return (char *)__s - 1; /*0x1012e7*/
  return v4; /*0x1012f2*/
}
