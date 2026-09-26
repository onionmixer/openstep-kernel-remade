/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1beb58. */
__int32 __cdecl strtol(const char *__str, char **__endptr, int __base)
{
  const char *v3; // edi
  int v4; // ecx
  int v5; // ebx
  unsigned __int32 v6; // esi
  int v7; // ecx
  int v8; // ebx
  char *v9; // ecx
  signed int v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-8h]
  unsigned int v14; // [esp+1Ch] [ebp-4h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  v3 = __str; /*0x1beb61*/
  v13 = 0; /*0x1beb64*/
  do /*0x1beb8e*/
  {
    v4 = *v3++; /*0x1beb6c*/
    v5 = 0; /*0x1beb73*/
    if ( (_BYTE)v4 == 32 || (unsigned __int8)(v4 - 9) <= 1u ) /*0x1beb80*/
      v5 = 1; /*0x1beb87*/
  }
  while ( v5 ); /*0x1beb8e*/
  if ( v4 == 45 ) /*0x1beb93*/
  {
    v13 = 1; /*0x1beb95*/
LABEL_9:
    v4 = *v3++; /*0x1beba5*/
    goto LABEL_10; /*0x1beba8*/
  }
  if ( v4 == 43 ) /*0x1beba3*/
    goto LABEL_9; /*0x1beba3*/
LABEL_10:
  if ( (!__base || __base == 16) && v4 == 48 && (*v3 == 120 || *v3 == 88) ) /*0x1bebc4*/
  {
    v4 = v3[1]; /*0x1bebc6*/
    v3 += 2; /*0x1bebca*/
    __base = 16; /*0x1bebcd*/
  }
  else
  {
    if ( (!__base || __base == 2) && v4 == 48 && (*v3 == 98 || *v3 == 66) ) /*0x1bebf3*/
    {
      v4 = v3[1]; /*0x1bebf5*/
      v3 += 2; /*0x1bebf9*/
      __base = 2; /*0x1bebfc*/
    }
    if ( !__base ) /*0x1bec07*/
    {
      __base = 10; /*0x1bec09*/
      if ( v4 == 48 ) /*0x1bec13*/
        __base = 8; /*0x1bec15*/
    }
  }
  v14 = 0x7FFFFFFF; /*0x1bec1c*/
  if ( v13 ) /*0x1bec27*/
    v14 = 0x80000000; /*0x1bec29*/
  v11 = v14 % __base; /*0x1bec38*/
  v15 = v14 / __base; /*0x1bec3b*/
  v6 = 0; /*0x1bec3e*/
  v12 = 0; /*0x1bec40*/
  while ( 1 ) /*0x1bec48*/
  {
    if ( (unsigned __int8)(v4 - 48) <= 9u ) /*0x1bec51*/
    {
      v7 = v4 - 48; /*0x1bec53*/
      goto LABEL_37; /*0x1bec56*/
    }
    v8 = 0; /*0x1bec58*/
    if ( (unsigned __int8)(v4 - 65) <= 0x19u || (unsigned __int8)(v4 - 97) <= 0x19u ) /*0x1bec6a*/
      v8 = 1; /*0x1bec6c*/
    if ( !v8 ) /*0x1bec73*/
      break; /*0x1bec73*/
    if ( (unsigned __int8)(v4 - 65) > 0x19u ) /*0x1bec7b*/
      v7 = v4 - 87; /*0x1bec84*/
    else
      v7 = v4 - 55; /*0x1bec7d*/
LABEL_37:
    if ( __base <= v7 ) /*0x1bec8a*/
      break; /*0x1bec8a*/
    if ( v12 < 0 || v15 < v6 || v15 == v6 && v11 < v7 ) /*0x1bec9c*/
    {
      v12 = -1; /*0x1bec9e*/
    }
    else
    {
      v12 = 1; /*0x1beca8*/
      v6 = v7 + __base * v6; /*0x1becb3*/
    }
    v4 = *v3++; /*0x1becb5*/
  }
  if ( v12 >= 0 ) /*0x1becc0*/
  {
    if ( v13 ) /*0x1becd8*/
      v6 = -v6; /*0x1becda*/
  }
  else
  {
    v6 = 0x7FFFFFFF; /*0x1becc2*/
    if ( v13 ) /*0x1beccb*/
      v6 = 0x80000000; /*0x1beccd*/
  }
  if ( __endptr ) /*0x1bece0*/
  {
    v9 = (char *)__str; /*0x1bece2*/
    if ( v12 ) /*0x1bece9*/
      v9 = (char *)(v3 - 1); /*0x1beceb*/
    *__endptr = v9; /*0x1becf1*/
  }
  return v6; /*0x1becf8*/
}
