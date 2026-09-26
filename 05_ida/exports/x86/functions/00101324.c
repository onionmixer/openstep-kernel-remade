/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101324. */
int __cdecl memcmp(const void *__s1, const void *__s2, size_t __n)
{
  signed __int32 v3; // ebx
  int result; // eax
  bool v5; // zf
  size_t v6; // ecx
  int v7; // edx
  bool v8; // zf
  int v9; // ecx
  int v10; // edx
  _BYTE *v11; // edi
  _BYTE *v12; // esi
  bool v13; // zf
  int v14; // ecx
  _DWORD *v15; // edi
  _DWORD *v16; // esi
  signed __int32 v17; // eax
  _BYTE *v18; // edi
  _BYTE *v19; // esi

  v3 = __n; /*0x10132a*/
  if ( !__n ) /*0x10132f*/
    return 0; /*0x101333*/
  v5 = __n == 15; /*0x101338*/
  if ( (int)__n <= 15 ) /*0x10133b*/
  {
    v6 = __n; /*0x10133d*/
    goto LABEL_21; /*0x10133f*/
  }
  v7 = (unsigned __int8)__s2 & 3; /*0x101347*/
  if ( ((unsigned __int8)__s2 & 3) != 0 ) /*0x10134a*/
  {
    v9 = 4 - v7; /*0x101351*/
    v8 = v7 == 4; /*0x101351*/
    v10 = 4 - v7; /*0x101353*/
    v11 = __s1; /*0x101355*/
    v12 = __s2; /*0x101358*/
    do /*0x10135b*/
    {
      if ( !v9 ) /*0x10135b*/
        break; /*0x10135b*/
      v8 = *v12++ == *v11++; /*0x10135b*/
      --v9; /*0x10135b*/
    }
    while ( v8 ); /*0x10135b*/
    if ( !v8 ) /*0x10135d*/
    {
      BYTE1(v3) = *(v12 - 1); /*0x101362*/
      LOBYTE(v9) = *(v11 - 1) - BYTE1(v3); /*0x101365*/
    }
    result = (char)v9; /*0x101369*/
    if ( (_BYTE)v9 ) /*0x10136e*/
      return result; /*0x10136e*/
    v3 -= v10; /*0x101370*/
    __s1 = (char *)__s1 + v10; /*0x101372*/
    __s2 = (char *)__s2 + v10; /*0x101375*/
  }
  v13 = v3 >> 2 == 0; /*0x10137a*/
  v14 = v3 >> 2; /*0x10137d*/
  v15 = __s1; /*0x10137f*/
  v16 = __s2; /*0x101382*/
  do /*0x101385*/
  {
    if ( !v14 ) /*0x101385*/
      break; /*0x101385*/
    v13 = *v16++ == *v15++; /*0x101385*/
    --v14; /*0x101385*/
  }
  while ( v13 ); /*0x101385*/
  if ( !v13 ) /*0x101387*/
    v14 = *(v15 - 1) - *(v16 - 1); /*0x10138f*/
  result = v14; /*0x101391*/
  if ( !v14 && (v3 & 3) != 0 ) /*0x10139c*/
  {
    v17 = v3; /*0x10139e*/
    LOBYTE(v17) = v3 & 0xFC; /*0x1013a0*/
    __s2 = (char *)__s2 + v17; /*0x1013a2*/
    v5 = (char *)__s1 + v17 == nullptr; /*0x1013a5*/
    __s1 = (char *)__s1 + v17; /*0x1013a5*/
    v6 = v3 & 3; /*0x1013a8*/
LABEL_21:
    v18 = __s1; /*0x1013aa*/
    v19 = __s2; /*0x1013ad*/
    do /*0x1013b0*/
    {
      if ( !v6 ) /*0x1013b0*/
        break; /*0x1013b0*/
      v5 = *v19++ == *v18++; /*0x1013b0*/
      --v6; /*0x1013b0*/
    }
    while ( v5 ); /*0x1013b0*/
    if ( !v5 ) /*0x1013b2*/
      LOBYTE(v6) = *(v18 - 1) - *(v19 - 1); /*0x1013ba*/
    return (char)v6; /*0x1013be*/
  }
  return result; /*0x1013c4*/
}
