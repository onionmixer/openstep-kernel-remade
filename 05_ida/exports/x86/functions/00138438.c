/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138438. */
int __cdecl xdrmbuf_putbytes(int a1, char *a2, size_t a3)
{
  signed __int32 v5; // eax
  int v6; // eax
  int *v7; // eax
  int v9; // eax
  int v10; // eax

  while ( 1 ) /*0x138493*/
  {
    v10 = *(_DWORD *)(a1 + 20) - a3; /*0x138493*/
    *(_DWORD *)(a1 + 20) = v10; /*0x138495*/
    if ( v10 >= 0 ) /*0x138498*/
    {
      bcopy(a2, *(void **)(a1 + 12), a3); /*0x1384a0*/
      *(_DWORD *)(a1 + 12) += a3; /*0x1384a5*/
      return 1; /*0x1384ad*/
    }
    v5 = a3 + *(_DWORD *)(a1 + 20); /*0x13844f*/
    *(_DWORD *)(a1 + 20) = v5; /*0x138451*/
    if ( v5 > 0 ) /*0x138456*/
    {
      bcopy(a2, *(void **)(a1 + 12), v5); /*0x13845e*/
      v6 = *(_DWORD *)(a1 + 20); /*0x138463*/
      a2 += v6; /*0x138466*/
      a3 -= v6; /*0x138468*/
    }
    v7 = *(int **)(a1 + 16); /*0x13846d*/
    if ( !v7 ) /*0x138472*/
      return 0; /*0x138476*/
    v9 = *v7; /*0x138478*/
    *(_DWORD *)(a1 + 16) = v9; /*0x13847a*/
    if ( !v9 ) /*0x13847f*/
      break; /*0x13847f*/
    *(_DWORD *)(a1 + 12) = v9 + *(_DWORD *)(v9 + 4); /*0x138486*/
    *(_DWORD *)(a1 + 20) = *(__int16 *)(v9 + 8); /*0x13848d*/
  }
  return 0; /*0x1384b5*/
}
