/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101cb8. */
char *__cdecl strcat(char *__s1, const char *__s2)
{
  char *v2; // edx
  char *v11; // edx
  char v12; // al
  const char *v13; // ecx
  char *v14; // edx
  char v15; // al
  char v16; // al
  char v17; // al
  char v18; // al
  char v19; // al
  char v20; // al
  char v21; // al
  char v22; // al

  v2 = __s1 + 1; /*0x101cc2*/
  if ( *__s1 ) /*0x101cc5*/
  {
    do /*0x101d02*/
    {
      if ( !*v2++ ) /*0x101ccc*/
        break; /*0x101cd1*/
      if ( !*v2++ ) /*0x101cd3*/
        break; /*0x101cd8*/
      if ( !*v2++ ) /*0x101cda*/
        break; /*0x101cdf*/
      if ( !*v2++ ) /*0x101ce1*/
        break; /*0x101ce6*/
      if ( !*v2++ ) /*0x101ce8*/
        break; /*0x101ced*/
      if ( !*v2++ ) /*0x101cef*/
        break; /*0x101cf4*/
      if ( !*v2++ ) /*0x101cf6*/
        break; /*0x101cfb*/
    }
    while ( *v2++ ); /*0x101d02*/
  }
  v11 = v2 - 1; /*0x101d04*/
  v12 = *__s2; /*0x101d05*/
  *v11 = *__s2; /*0x101d07*/
  v13 = __s2 + 1; /*0x101d09*/
  v14 = v11 + 1; /*0x101d0a*/
  if ( v12 ) /*0x101d0d*/
  {
    do /*0x101d62*/
    {
      v15 = *v13; /*0x101d10*/
      *v14 = *v13; /*0x101d12*/
      if ( !v15 ) /*0x101d16*/
        break; /*0x101d16*/
      v16 = v13[1]; /*0x101d18*/
      v14[1] = v16; /*0x101d1b*/
      if ( !v16 ) /*0x101d20*/
        break; /*0x101d20*/
      v17 = v13[2]; /*0x101d22*/
      v14[2] = v17; /*0x101d25*/
      if ( !v17 ) /*0x101d2a*/
        break; /*0x101d2a*/
      v18 = v13[3]; /*0x101d2c*/
      v14[3] = v18; /*0x101d2f*/
      if ( !v18 ) /*0x101d34*/
        break; /*0x101d34*/
      v19 = v13[4]; /*0x101d36*/
      v14[4] = v19; /*0x101d39*/
      if ( !v19 ) /*0x101d3e*/
        break; /*0x101d3e*/
      v20 = v13[5]; /*0x101d40*/
      v14[5] = v20; /*0x101d43*/
      if ( !v20 ) /*0x101d48*/
        break; /*0x101d48*/
      v21 = v13[6]; /*0x101d4a*/
      v14[6] = v21; /*0x101d4d*/
      if ( !v21 ) /*0x101d52*/
        break; /*0x101d52*/
      v22 = v13[7]; /*0x101d54*/
      v14[7] = v22; /*0x101d57*/
      v13 += 8; /*0x101d5a*/
      v14 += 8; /*0x101d5d*/
    }
    while ( v22 ); /*0x101d62*/
  }
  return __s1; /*0x101d66*/
}
