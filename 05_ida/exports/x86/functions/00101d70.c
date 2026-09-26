/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101d70. */
char *__cdecl strncat(char *__s1, const char *__s2, size_t __n)
{
  char *v3; // edx
  char *v12; // edx
  char v13; // al
  char *v14; // edx
  const char *i; // ebx
  char v17; // al
  char v18; // al
  char v19; // al
  char v20; // al
  char v21; // al
  char v22; // al
  char v23; // al
  char v24; // al

  v3 = __s1 + 1; /*0x101d7f*/
  if ( *__s1 ) /*0x101d82*/
  {
    do /*0x101dbe*/
    {
      if ( !*v3++ ) /*0x101d88*/
        break; /*0x101d8d*/
      if ( !*v3++ ) /*0x101d8f*/
        break; /*0x101d94*/
      if ( !*v3++ ) /*0x101d96*/
        break; /*0x101d9b*/
      if ( !*v3++ ) /*0x101d9d*/
        break; /*0x101da2*/
      if ( !*v3++ ) /*0x101da4*/
        break; /*0x101da9*/
      if ( !*v3++ ) /*0x101dab*/
        break; /*0x101db0*/
      if ( !*v3++ ) /*0x101db2*/
        break; /*0x101db7*/
    }
    while ( *v3++ ); /*0x101dbe*/
  }
  v12 = v3 - 1; /*0x101dc0*/
  v13 = *__s2; /*0x101dc1*/
  *v12 = *__s2; /*0x101dc3*/
  v14 = v12 + 1; /*0x101dc6*/
  if ( v13 ) /*0x101dc9*/
  {
    for ( i = __s2 + 1; (int)(__n - 1) >= 0; i += 8 ) /*0x101dcf*/
    {
      v17 = *i; /*0x101ddb*/
      *v14++ = *i; /*0x101ddd*/
      if ( !v17 ) /*0x101de2*/
        return __s1; /*0x101de2*/
      if ( (int)(__n - 2) < 0 ) /*0x101ded*/
        break; /*0x101ded*/
      v18 = i[1]; /*0x101def*/
      *v14++ = v18; /*0x101df2*/
      if ( !v18 ) /*0x101df7*/
        return __s1; /*0x101df7*/
      if ( (int)(__n - 3) < 0 ) /*0x101dfe*/
        break; /*0x101dfe*/
      v19 = i[2]; /*0x101e00*/
      *v14++ = v19; /*0x101e03*/
      if ( !v19 ) /*0x101e08*/
        return __s1; /*0x101e08*/
      if ( (int)(__n - 4) < 0 ) /*0x101e0f*/
        break; /*0x101e0f*/
      v20 = i[3]; /*0x101e11*/
      *v14++ = v20; /*0x101e14*/
      if ( !v20 ) /*0x101e19*/
        return __s1; /*0x101e19*/
      if ( (int)(__n - 5) < 0 ) /*0x101e20*/
        break; /*0x101e20*/
      v21 = i[4]; /*0x101e22*/
      *v14++ = v21; /*0x101e25*/
      if ( !v21 ) /*0x101e2a*/
        return __s1; /*0x101e2a*/
      if ( (int)(__n - 6) < 0 ) /*0x101e31*/
        break; /*0x101e31*/
      v22 = i[5]; /*0x101e33*/
      *v14++ = v22; /*0x101e36*/
      if ( !v22 ) /*0x101e3b*/
        return __s1; /*0x101e3b*/
      if ( (int)(__n - 7) < 0 ) /*0x101e42*/
        break; /*0x101e42*/
      v23 = i[6]; /*0x101e44*/
      *v14++ = v23; /*0x101e47*/
      if ( !v23 ) /*0x101e4c*/
        return __s1; /*0x101e4c*/
      __n -= 8; /*0x101e4e*/
      if ( (__n & 0x80000000) != 0 ) /*0x101e51*/
        break; /*0x101e51*/
      v24 = i[7]; /*0x101e5c*/
      *v14++ = v24; /*0x101e5f*/
      if ( !v24 ) /*0x101e67*/
        return __s1; /*0x101e67*/
    }
    *(v14 - 1) = 0; /*0x101e53*/
  }
  return __s1; /*0x101e72*/
}
