/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a52cc. */
char *__cdecl strstr(const char *__big, const char *__little)
{
  char v3; // dl
  const char *v4; // ebx
  char v5; // al
  char v7; // dl
  const char *v8; // [esp+Ch] [ebp-8h]

  while ( 1 ) /*0x1a531c*/
  {
    v7 = *__big++; /*0x1a531c*/
    if ( !v7 ) /*0x1a5321*/
      return nullptr; /*0x1a5328*/
    if ( *__little == v7 ) /*0x1a52e7*/
    {
      v3 = __little[1]; /*0x1a52e9*/
      v4 = __little + 2; /*0x1a52ec*/
      v8 = __big + 1; /*0x1a52f2*/
      if ( *__big == v3 ) /*0x1a52f7*/
      {
        while ( v3 ) /*0x1a52fe*/
        {
          v3 = *v4; /*0x1a5300*/
          v5 = *v8; /*0x1a5305*/
          ++v4; /*0x1a5307*/
          ++v8; /*0x1a5309*/
          if ( v5 != v3 ) /*0x1a530e*/
            goto LABEL_6; /*0x1a530e*/
        }
        return (char *)(__big - 1); /*0x1a5317*/
      }
LABEL_6:
      if ( !v3 ) /*0x1a5312*/
        return (char *)(__big - 1); /*0x1a5312*/
    }
  }
}
