/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101e7c. */
int __cdecl strcmp(const char *__s1, const char *__s2)
{
  const char *i; // edx

  for ( i = __s1; *i; ++__s2 ) /*0x101e85*/
  {
    if ( *i != *__s2 ) /*0x101e90*/
      break; /*0x101e90*/
    ++i; /*0x101e92*/
    ++__s2; /*0x101e93*/
    if ( !*i ) /*0x101e94*/
      break; /*0x101e98*/
    if ( *__s2 != *i ) /*0x101e9c*/
      break; /*0x101e9c*/
    ++i; /*0x101e9e*/
    ++__s2; /*0x101e9f*/
    if ( !*i ) /*0x101ea0*/
      break; /*0x101ea4*/
    if ( *__s2 != *i ) /*0x101ea8*/
      break; /*0x101ea8*/
    ++i; /*0x101eaa*/
    ++__s2; /*0x101eab*/
    if ( !*i ) /*0x101eac*/
      break; /*0x101eb0*/
    if ( *__s2 != *i ) /*0x101eb4*/
      break; /*0x101eb4*/
    ++i; /*0x101eb6*/
    ++__s2; /*0x101eb7*/
    if ( !*i ) /*0x101eb8*/
      break; /*0x101ebc*/
    if ( *__s2 != *i ) /*0x101ec0*/
      break; /*0x101ec0*/
    ++i; /*0x101ec2*/
    ++__s2; /*0x101ec3*/
    if ( !*i ) /*0x101ec4*/
      break; /*0x101ec8*/
    if ( *__s2 != *i ) /*0x101ecc*/
      break; /*0x101ecc*/
    ++i; /*0x101ece*/
    ++__s2; /*0x101ecf*/
    if ( !*i ) /*0x101ed0*/
      break; /*0x101ed4*/
    if ( *__s2 != *i ) /*0x101ed8*/
      break; /*0x101ed8*/
    ++i; /*0x101eda*/
    ++__s2; /*0x101edb*/
    if ( !*i ) /*0x101edc*/
      break; /*0x101ee0*/
    if ( *__s2 != *i ) /*0x101ee4*/
      break; /*0x101ee4*/
    ++i; /*0x101ee6*/
  }
  return *i - *__s2; /*0x101ef9*/
}
