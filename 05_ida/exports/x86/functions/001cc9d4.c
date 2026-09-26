/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc9d4. */
int __cdecl NXNextMapState(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // ecx
  _DWORD *v5; // eax

  v4 = *(_DWORD *)(a1 + 12); /*0x1cc9e6*/
  while ( --*a2 != -1 ) /*0x1cca0c*/
  {
    v5 = (_DWORD *)(v4 + 8 * *a2); /*0x1cc9f5*/
    if ( *v5 != -1 ) /*0x1cc9fa*/
    {
      *a3 = *v5; /*0x1cc9fe*/
      *a4 = v5[1]; /*0x1cca03*/
      return 1; /*0x1cca0a*/
    }
  }
  return 0; /*0x1cca18*/
}
