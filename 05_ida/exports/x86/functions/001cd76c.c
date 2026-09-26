/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd76c. */
_DWORD *__cdecl sub_1CD76C(int a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  int *v3; // ebx
  int v4; // ecx
  _DWORD *result; // eax
  int i; // edx
  int v7; // edx
  _DWORD *v8; // ecx
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  v2 = a2; /*0x1cd775*/
  v10 = *a2; /*0x1cd77a*/
  v3 = *(int **)(a1 + 32); /*0x1cd780*/
  v9 = *v3; /*0x1cd785*/
  v4 = v3[1] + 1; /*0x1cd78b*/
  if ( 4 * v4 <= (unsigned int)(3 * *v3 + 3) ) /*0x1cd799*/
  {
    v3[1] = v4; /*0x1cd7c4*/
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 16) & 0x20) != 0 ) /*0x1cd7a2*/
    {
      sub_1CD7EC(a1); /*0x1cd7a5*/
    }
    else
    {
      v3 = sub_1CD5B4(a1); /*0x1cd7b5*/
      v9 = *v3; /*0x1cd7b9*/
    }
    ++v3[1]; /*0x1cd7bc*/
  }
  result = v3 + 2; /*0x1cd7c7*/
  for ( i = v10; ; i = v7 + 1 ) /*0x1cd7ca*/
  {
    v7 = v9 & i; /*0x1cd7cd*/
    v8 = (_DWORD *)result[v7]; /*0x1cd7d0*/
    result[v7] = v2; /*0x1cd7d3*/
    if ( !v8 ) /*0x1cd7d8*/
      break; /*0x1cd7d8*/
    v2 = v8; /*0x1cd7da*/
  }
  return result; /*0x1cd7e3*/
}
