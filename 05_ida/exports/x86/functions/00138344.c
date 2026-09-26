/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138344. */
int __cdecl xdrmbuf_getbytes(int a1, char *a2, size_t a3)
{
  signed __int32 v5; // eax
  int v6; // eax
  int *v7; // eax
  int v9; // eax
  int v10; // eax

  while ( 1 ) /*0x13839f*/
  {
    v10 = *(_DWORD *)(a1 + 20) - a3; /*0x13839f*/
    *(_DWORD *)(a1 + 20) = v10; /*0x1383a1*/
    if ( v10 >= 0 ) /*0x1383a4*/
    {
      bcopy(*(const void **)(a1 + 12), a2, a3); /*0x1383ac*/
      *(_DWORD *)(a1 + 12) += a3; /*0x1383b1*/
      return 1; /*0x1383b9*/
    }
    v5 = a3 + *(_DWORD *)(a1 + 20); /*0x13835b*/
    *(_DWORD *)(a1 + 20) = v5; /*0x13835d*/
    if ( v5 > 0 ) /*0x138362*/
    {
      bcopy(*(const void **)(a1 + 12), a2, v5); /*0x13836a*/
      v6 = *(_DWORD *)(a1 + 20); /*0x13836f*/
      a2 += v6; /*0x138372*/
      a3 -= v6; /*0x138374*/
    }
    v7 = *(int **)(a1 + 16); /*0x138379*/
    if ( !v7 ) /*0x13837e*/
      return 0; /*0x138382*/
    v9 = *v7; /*0x138384*/
    *(_DWORD *)(a1 + 16) = v9; /*0x138386*/
    if ( !v9 ) /*0x13838b*/
      break; /*0x13838b*/
    *(_DWORD *)(a1 + 12) = v9 + *(_DWORD *)(v9 + 4); /*0x138392*/
    *(_DWORD *)(a1 + 20) = *(__int16 *)(v9 + 8); /*0x138399*/
  }
  return 0; /*0x1383c1*/
}
