/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bed00. */
unsigned __int32 __cdecl strtoul(const char *__str, char **__endptr, int __base)
{
  const char *v3; // edi
  int v4; // ecx
  int v5; // ebx
  unsigned __int32 v6; // esi
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  char *v10; // eax
  int v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-8h]
  unsigned int v14; // [esp+1Ch] [ebp-4h]

  v3 = __str; /*0x1bed09*/
  v13 = 0; /*0x1bed0c*/
  do /*0x1bed36*/
  {
    v4 = *v3++; /*0x1bed14*/
    v5 = 0; /*0x1bed1b*/
    if ( (_BYTE)v4 == 32 || (unsigned __int8)(v4 - 9) <= 1u ) /*0x1bed28*/
      v5 = 1; /*0x1bed2f*/
  }
  while ( v5 ); /*0x1bed36*/
  if ( v4 == 45 ) /*0x1bed3b*/
  {
    v13 = 1; /*0x1bed3d*/
LABEL_9:
    v4 = *v3++; /*0x1bed4d*/
    goto LABEL_10; /*0x1bed50*/
  }
  if ( v4 == 43 ) /*0x1bed4b*/
    goto LABEL_9; /*0x1bed4b*/
LABEL_10:
  if ( (!__base || __base == 16) && v4 == 48 && (*v3 == 120 || *v3 == 88) ) /*0x1bed6a*/
  {
    v4 = v3[1]; /*0x1bed6c*/
    v3 += 2; /*0x1bed70*/
    __base = 16; /*0x1bed73*/
  }
  else
  {
    if ( (!__base || __base == 2) && v4 == 48 && (*v3 == 98 || *v3 == 66) ) /*0x1bed95*/
    {
      v4 = v3[1]; /*0x1bed97*/
      v3 += 2; /*0x1bed9b*/
      __base = 2; /*0x1bed9e*/
    }
    if ( !__base ) /*0x1beda9*/
    {
      __base = 10; /*0x1bedab*/
      if ( v4 == 48 ) /*0x1bedb5*/
        __base = 8; /*0x1bedb7*/
    }
  }
  v14 = 0xFFFFFFFF / __base; /*0x1bedcb*/
  v6 = 0; /*0x1bedce*/
  v12 = 0; /*0x1bedd0*/
  while ( 1 ) /*0x1bedd8*/
  {
    if ( (unsigned __int8)(v4 - 48) <= 9u ) /*0x1bede1*/
    {
      v7 = v4 - 48; /*0x1bede3*/
      goto LABEL_36; /*0x1bede6*/
    }
    v8 = 0; /*0x1bede8*/
    if ( (unsigned __int8)(v4 - 65) <= 0x19u || (unsigned __int8)(v4 - 97) <= 0x19u ) /*0x1bedfa*/
      v8 = 1; /*0x1bedfc*/
    if ( !v8 ) /*0x1bee03*/
      break; /*0x1bee03*/
    if ( (unsigned __int8)(v4 - 65) > 0x19u ) /*0x1bee0b*/
      v9 = v4 - 87; /*0x1bee14*/
    else
      v9 = v4 - 55; /*0x1bee0d*/
    v7 = v9; /*0x1bee17*/
LABEL_36:
    if ( __base <= v7 ) /*0x1bee1c*/
      break; /*0x1bee1c*/
    if ( v12 < 0 || v14 < v6 || v14 == v6 && (int)(0xFFFFFFFF % __base) < v7 ) /*0x1bee2e*/
    {
      v12 = -1; /*0x1bee30*/
    }
    else
    {
      v12 = 1; /*0x1bee3c*/
      v6 = v7 + __base * v6; /*0x1bee47*/
    }
    v4 = *v3++; /*0x1bee49*/
  }
  if ( v12 >= 0 ) /*0x1bee54*/
  {
    if ( v13 ) /*0x1bee64*/
      v6 = -v6; /*0x1bee66*/
  }
  else
  {
    v6 = -1; /*0x1bee56*/
  }
  if ( __endptr ) /*0x1bee6c*/
  {
    v10 = (char *)__str; /*0x1bee6e*/
    if ( v12 ) /*0x1bee75*/
      v10 = (char *)(v3 - 1); /*0x1bee77*/
    *__endptr = v10; /*0x1bee7d*/
  }
  return v6; /*0x1bee84*/
}
