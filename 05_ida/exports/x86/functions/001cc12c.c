/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc12c. */
int __cdecl NXResetMapTable(_DWORD *a1)
{
  _DWORD *v1; // ebx
  int result; // eax
  int v3; // esi
  int (__cdecl *v4)(_DWORD *, _DWORD, _DWORD); // [esp+Ch] [ebp-4h]

  v1 = (_DWORD *)a1[3]; /*0x1cc138*/
  result = *(_DWORD *)(*a1 + 8); /*0x1cc13d*/
  v4 = (int (__cdecl *)(_DWORD *, _DWORD, _DWORD))result; /*0x1cc140*/
  v3 = a1[2]; /*0x1cc143*/
  while ( --v3 != -1 ) /*0x1cc16d*/
  {
    if ( *v1 != -1 ) /*0x1cc14b*/
    {
      result = v4(a1, *v1, v1[1]); /*0x1cc158*/
      *v1 = -1; /*0x1cc15a*/
      v1[1] = 0; /*0x1cc160*/
    }
    v1 += 2; /*0x1cc16a*/
  }
  a1[1] = 0; /*0x1cc173*/
  return result; /*0x1cc17d*/
}
