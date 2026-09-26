/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101a3c. */
char *__cdecl strrchr(const char *__s, int __c)
{
  char *v3; // ebx
  char v4; // cl
  char v5; // cl
  char v6; // cl
  char v7; // cl
  char v8; // cl
  char v9; // cl
  char v10; // cl

  v3 = nullptr; /*0x101a48*/
  do /*0x101ae5*/
  {
    if ( *__s == __c ) /*0x101a53*/
      v3 = (char *)__s; /*0x101a55*/
    if ( !*__s ) /*0x101a4c*/
      break; /*0x101a5c*/
    v4 = __s[1]; /*0x101a62*/
    if ( v4 == __c ) /*0x101a6a*/
      v3 = (char *)(__s + 1); /*0x101a6c*/
    if ( !v4 ) /*0x101a73*/
      break; /*0x101a73*/
    v5 = __s[2]; /*0x101a75*/
    if ( v5 == __c ) /*0x101a7d*/
      v3 = (char *)(__s + 2); /*0x101a7f*/
    if ( !v5 ) /*0x101a86*/
      break; /*0x101a86*/
    v6 = __s[3]; /*0x101a88*/
    if ( v6 == __c ) /*0x101a90*/
      v3 = (char *)(__s + 3); /*0x101a92*/
    if ( !v6 ) /*0x101a99*/
      break; /*0x101a99*/
    v7 = __s[4]; /*0x101a9b*/
    if ( v7 == __c ) /*0x101aa3*/
      v3 = (char *)(__s + 4); /*0x101aa5*/
    if ( !v7 ) /*0x101aac*/
      break; /*0x101aac*/
    v8 = __s[5]; /*0x101aae*/
    if ( v8 == __c ) /*0x101ab6*/
      v3 = (char *)(__s + 5); /*0x101ab8*/
    if ( !v8 ) /*0x101abf*/
      break; /*0x101abf*/
    v9 = __s[6]; /*0x101ac1*/
    if ( v9 == __c ) /*0x101ac9*/
      v3 = (char *)(__s + 6); /*0x101acb*/
    if ( !v9 ) /*0x101ad2*/
      break; /*0x101ad2*/
    v10 = __s[7]; /*0x101ad4*/
    if ( v10 == __c ) /*0x101adc*/
      v3 = (char *)(__s + 7); /*0x101ade*/
    __s += 8; /*0x101ae0*/
  }
  while ( v10 ); /*0x101ae5*/
  return v3; /*0x101af0*/
}
