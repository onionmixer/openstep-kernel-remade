/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf5c0. */
char *__cdecl sub_1CF5C0(int a1)
{
  char *result; // eax
  unsigned int *v2; // edi
  unsigned int j; // esi
  char **v4; // ebx
  int v5; // eax
  unsigned int *v6; // edi
  unsigned int k; // esi
  char **v8; // ebx
  int v9; // eax
  uint32_t i; // [esp+Ch] [ebp-Ch]
  char *v11; // [esp+10h] [ebp-8h]
  uint32_t size; // [esp+14h] [ebp-4h] BYREF

  result = getsectdatafromheaderinfo(a1, "__OBJC", "__protocol", &size); /*0x1cf5db*/
  v11 = result; /*0x1cf5e0*/
  if ( result ) /*0x1cf5e8*/
  {
    for ( i = 0; i < size / 0x14; ++i ) /*0x1cf5ee*/
    {
      if ( *(_DWORD *)&v11[20 * i + 12] ) /*0x1cf604*/
      {
        v2 = *(unsigned int **)&v11[20 * i + 12]; /*0x1cf60b*/
        for ( j = 0; *v2 > j; ++j ) /*0x1cf611*/
        {
          v4 = (char **)&v2[2 * j + 1]; /*0x1cf618*/
          v5 = _sel_registerName(*v4); /*0x1cf61f*/
          if ( *v4 != (char *)v5 ) /*0x1cf629*/
            *v4 = (char *)v5; /*0x1cf62b*/
        }
      }
      if ( *(_DWORD *)&v11[20 * i + 16] ) /*0x1cf63e*/
      {
        v6 = *(unsigned int **)&v11[20 * i + 16]; /*0x1cf645*/
        for ( k = 0; *v6 > k; ++k ) /*0x1cf64b*/
        {
          v8 = (char **)&v6[2 * k + 1]; /*0x1cf650*/
          v9 = _sel_registerName(*v8); /*0x1cf657*/
          if ( *v8 != (char *)v9 ) /*0x1cf661*/
            *v8 = (char *)v9; /*0x1cf663*/
        }
      }
    }
    return (char *)+[Protocol _fixup:numElements:](aProtocol_0, sel__fixup_numElements_, v11, size / 0x14); /*0x1cf6a1*/
  }
  return result; /*0x1cf6a9*/
}
