/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdbd0. */
unsigned int __cdecl method_getArgumentInfo(objc_method *m, int arg, const char **type, int *offset)
{
  unsigned int v4; // edi
  int v5; // esi
  char *i; // ecx
  char *v7; // eax
  int v8; // ebx
  _BYTE *v9; // eax
  _BYTE *v10; // ecx
  char v12; // [esp+Ch] [ebp-4h]
  char v13; // [esp+Ch] [ebp-4h]

  v4 = 0; /*0x1cdbdc*/
  v5 = 0; /*0x1cdbde*/
  for ( i = (char *)sub_1CD9A4(m->method_types); (unsigned __int8)(*i - 48) <= 9u; ++i ) /*0x1cdbe9*/
    ; /*0x1cdbf0*/
  if ( !*i ) /*0x1cdbfc*/
    goto LABEL_30; /*0x1cdbfc*/
  do /*0x1cdc5e*/
  {
    if ( arg == v4 ) /*0x1cdc07*/
      break; /*0x1cdc07*/
    v7 = (char *)sub_1CD9A4(i); /*0x1cdc0a*/
    i = v7; /*0x1cdc0f*/
    if ( v4 ) /*0x1cdc16*/
    {
      if ( *v7 != 45 ) /*0x1cdc4f*/
        goto LABEL_17; /*0x1cdc4f*/
      while ( 1 ) /*0x1cdc54*/
      {
        ++i; /*0x1cdc54*/
LABEL_17:
        if ( (unsigned __int8)(*i - 48) > 9u ) /*0x1cdc5b*/
          goto LABEL_18; /*0x1cdc5b*/
      }
    }
    if ( *v7 == 45 ) /*0x1cdc1b*/
    {
      v12 = 1; /*0x1cdc1d*/
      goto LABEL_11; /*0x1cdc21*/
    }
    v12 = 0; /*0x1cdc24*/
    while ( (unsigned __int8)(*i - 48) <= 9u ) /*0x1cdc40*/
    {
      v5 = *i + 10 * v5 - 48; /*0x1cdc36*/
LABEL_11:
      ++i; /*0x1cdc39*/
    }
    if ( v12 ) /*0x1cdc46*/
      v5 = -v5; /*0x1cdc48*/
LABEL_18:
    ++v4; /*0x1cdc5d*/
  }
  while ( *i ); /*0x1cdc5e*/
  if ( !*i ) /*0x1cdc66*/
  {
LABEL_30:
    *type = nullptr; /*0x1cdcb8*/
    goto LABEL_31; /*0x1cdcbb*/
  }
  v8 = 0; /*0x1cdc68*/
  *type = i; /*0x1cdc6d*/
  v9 = (_BYTE *)sub_1CD9A4(i); /*0x1cdc70*/
  v10 = v9; /*0x1cdc75*/
  if ( !arg ) /*0x1cdc7b*/
  {
LABEL_31:
    *offset = 0; /*0x1cdcc1*/
    return v4; /*0x1cdcc4*/
  }
  if ( *v9 != 45 ) /*0x1cdc80*/
  {
    v13 = 0; /*0x1cdc88*/
    goto LABEL_26; /*0x1cdc8c*/
  }
  v13 = 1; /*0x1cdc82*/
  while ( 1 ) /*0x1cdc9d*/
  {
    ++v10; /*0x1cdc9d*/
LABEL_26:
    if ( (unsigned __int8)(*v10 - 48) > 9u ) /*0x1cdca4*/
      break; /*0x1cdca4*/
    v8 = (char)*v10 + 10 * v8 - 48; /*0x1cdc9a*/
  }
  if ( v13 ) /*0x1cdcaa*/
    v8 = -v8; /*0x1cdcac*/
  *offset = v8 - v5; /*0x1cdcb3*/
  return v4; /*0x1cdccf*/
}
