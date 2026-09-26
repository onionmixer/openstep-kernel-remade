/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca2b8. */
objc_method_description *__cdecl +[Object descriptionForInstanceMethod:](id a1, SEL a2, SEL a3)
{
  _DWORD *i; // ebx
  _DWORD *j; // edi
  objc_method_description *result; // eax
  _DWORD *k; // esi
  _DWORD *v7; // ecx
  int v8; // edx
  int v9; // [esp+14h] [ebp-4h]

  for ( i = a1; i; i = (_DWORD *)i[1] ) /*0x1ca2c1*/
  {
    if ( *(int *)(*i + 12) > 2 ) /*0x1ca2d1*/
    {
      for ( j = (_DWORD *)i[9]; j; j = (_DWORD *)*j ) /*0x1ca2d3*/
      {
        v9 = 0; /*0x1ca2d8*/
        if ( (int)j[1] > 0 ) /*0x1ca2e8*/
        {
          do /*0x1ca302*/
          {
            result = (objc_method_description *)objc_msgSend((id)j[v9 + 2], sel_descriptionForInstanceMethod_, a3); /*0x1ca302*/
            if ( result ) /*0x1ca30c*/
              return result; /*0x1ca30c*/
          }
          while ( j[1] > ++v9 ); /*0x1ca302*/
        }
        if ( *(int *)(*i + 12) <= 4 ) /*0x1ca329*/
          break; /*0x1ca329*/
      }
    }
  }
  for ( k = a1; ; k = (_DWORD *)k[1] ) /*0x1ca344*/
  {
    if ( !k ) /*0x1ca38f*/
      return nullptr; /*0x1ca391*/
    v7 = (_DWORD *)k[7]; /*0x1ca34f*/
    if ( v7 ) /*0x1ca354*/
      break; /*0x1ca354*/
LABEL_19:
    ; /*0x1ca384*/
  }
  while ( 1 ) /*0x1ca358*/
  {
    v8 = 0; /*0x1ca358*/
    if ( (int)v7[1] > 0 ) /*0x1ca35d*/
      break; /*0x1ca35d*/
LABEL_18:
    v7 = (_DWORD *)*v7; /*0x1ca37e*/
    if ( !v7 ) /*0x1ca382*/
      goto LABEL_19; /*0x1ca382*/
  }
  while ( (SEL)v7[3 * v8 + 2] != a3 ) /*0x1ca36d*/
  {
    if ( v7[1] <= ++v8 ) /*0x1ca37c*/
      goto LABEL_18; /*0x1ca37c*/
  }
  return (objc_method_description *)&v7[3 * v8 + 2]; /*0x1ca396*/
}
