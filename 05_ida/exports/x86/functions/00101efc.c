/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101efc. */
int __cdecl strncmp(const char *__s1, const char *__s2, size_t __n)
{
  signed __int32 v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx

  while ( 1 ) /*0x101f98*/
  {
    if ( (int)__n <= 0 ) /*0x101f9a*/
      return 0; /*0x101fab*/
    if ( !*__s1 || *__s1 != *__s2 ) /*0x101f14*/
      break; /*0x101f14*/
    ++__s1; /*0x101f1a*/
    ++__s2; /*0x101f1b*/
    v6 = __n - 1; /*0x101f1c*/
    if ( v6 <= 0 ) /*0x101f1f*/
      return 0; /*0x101f1f*/
    if ( !*__s1 || *__s2 != *__s1 ) /*0x101f2d*/
      break; /*0x101f2d*/
    ++__s1; /*0x101f2f*/
    ++__s2; /*0x101f30*/
    v7 = v6 - 1; /*0x101f31*/
    if ( v7 <= 0 ) /*0x101f34*/
      return 0; /*0x101f34*/
    if ( !*__s1 || *__s2 != *__s1 ) /*0x101f3e*/
      break; /*0x101f3e*/
    ++__s1; /*0x101f40*/
    ++__s2; /*0x101f41*/
    v8 = v7 - 1; /*0x101f42*/
    if ( v8 <= 0 ) /*0x101f45*/
      return 0; /*0x101f45*/
    if ( !*__s1 || *__s2 != *__s1 ) /*0x101f4f*/
      break; /*0x101f4f*/
    ++__s1; /*0x101f51*/
    ++__s2; /*0x101f52*/
    v9 = v8 - 1; /*0x101f53*/
    if ( v9 <= 0 ) /*0x101f56*/
      return 0; /*0x101f56*/
    if ( !*__s1 || *__s2 != *__s1 ) /*0x101f60*/
      break; /*0x101f60*/
    ++__s1; /*0x101f62*/
    ++__s2; /*0x101f63*/
    v10 = v9 - 1; /*0x101f64*/
    if ( v10 <= 0 ) /*0x101f67*/
      return 0; /*0x101f67*/
    if ( !*__s1 || *__s2 != *__s1 ) /*0x101f71*/
      break; /*0x101f71*/
    ++__s1; /*0x101f73*/
    ++__s2; /*0x101f74*/
    v11 = v10 - 1; /*0x101f75*/
    if ( v11 <= 0 ) /*0x101f78*/
      return 0; /*0x101f78*/
    if ( !*__s1 || *__s2 != *__s1 ) /*0x101f82*/
      break; /*0x101f82*/
    ++__s1; /*0x101f84*/
    ++__s2; /*0x101f85*/
    v12 = v11 - 1; /*0x101f86*/
    if ( v12 <= 0 ) /*0x101f89*/
      return 0; /*0x101f89*/
    if ( !*__s1 || *__s2 != *__s1 ) /*0x101f93*/
      break; /*0x101f93*/
    ++__s1; /*0x101f95*/
    ++__s2; /*0x101f96*/
    __n = v12 - 1; /*0x101f97*/
  }
  return *__s1 - *__s2; /*0x101fba*/
}
