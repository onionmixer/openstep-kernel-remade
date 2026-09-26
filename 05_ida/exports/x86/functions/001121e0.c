/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1121e0. */
int __cdecl ptcclose(unsigned __int8 a1)
{
  unsigned int v1; // esi
  int v2; // edi
  __int16 *v3; // esi
  int v4; // ebx
  int v5; // ebx
  int result; // eax
  int v7; // [esp+Ch] [ebp-4h]

  v1 = 8 * a1; /*0x1121ef*/
  v2 = dword_1E56D4[v1 / 2]; /*0x1121f2*/
  v7 = *(_DWORD *)&word_1E56C8[v1 + 4]; /*0x112201*/
  (*(&off_1DB00C + 12 * *(char *)(v7 + 71)))((FILE *)v7, 0); /*0x112217*/
  if ( (word_1E56C8[v1 + 2] & 1) != 0 ) /*0x112220*/
  {
    forceclose(word_1E56C8[8 * a1]); /*0x11222a*/
    v3 = &word_1E56C8[8 * LOBYTE(word_1E56C8[8 * a1])]; /*0x11223c*/
    v4 = *((_DWORD *)v3 + 2); /*0x112242*/
    if ( (v3[2] & 1) != 0 ) /*0x112249*/
    {
      (*(&off_1DAFEC + 12 * *(char *)(v4 + 71)))((FILE *)v4); /*0x11225c*/
      ttyclose((FILE *)v4); /*0x11225f*/
      *((_DWORD *)v3 + 1) = 0; /*0x112264*/
    }
    ptcwakeup(v4, 3); /*0x112271*/
  }
  v5 = spltty(); /*0x11227e*/
  if ( *(_DWORD *)(v2 + 4) ) /*0x112280*/
    selthreadclear((_DWORD *)(v2 + 4)); /*0x11228a*/
  if ( *(_DWORD *)(v2 + 8) ) /*0x112292*/
    selthreadclear((_DWORD *)(v2 + 8)); /*0x11229c*/
  splx(v5); /*0x1122a5*/
  *(_DWORD *)(v7 + 36) = 0; /*0x1122ad*/
  result = ttynty(v7); /*0x1122b5*/
  *(_DWORD *)(result + 8) = 0; /*0x1122ba*/
  return result; /*0x1122c4*/
}
