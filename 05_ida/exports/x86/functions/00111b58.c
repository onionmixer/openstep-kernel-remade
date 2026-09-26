/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111b58. */
int __cdecl ttynty(int a1)
{
  int v1; // edi
  int *v2; // eax
  int v3; // ebx

  v1 = spltty(); /*0x111b66*/
  if ( !a1 ) /*0x111b6a*/
    panic(aTtynty0); /*0x111b71*/
  v2 = &dword_1E56C4; /*0x111b79*/
  v3 = dword_1E56C4; /*0x111b7e*/
  if ( !dword_1E56C4 ) /*0x111b86*/
    goto LABEL_8; /*0x111b86*/
  do /*0x111b94*/
  {
    if ( *(_DWORD *)v3 == a1 ) /*0x111b8a*/
      break; /*0x111b8a*/
    v2 = (int *)(v3 + 4); /*0x111b8c*/
    v3 = *(_DWORD *)(v3 + 4); /*0x111b8f*/
  }
  while ( v3 ); /*0x111b94*/
  if ( v3 ) /*0x111b98*/
  {
    *v2 = *(_DWORD *)(v3 + 4); /*0x111b9d*/
  }
  else
  {
LABEL_8:
    v3 = kalloc(0x18u); /*0x111bab*/
    *(_DWORD *)v3 = a1; /*0x111bad*/
    *(_DWORD *)(v3 + 16) = 472193564; /*0x111baf*/
    *(_BYTE *)(v3 + 20) = 92; /*0x111bb6*/
    *(_BYTE *)(v3 + 21) = 1; /*0x111bba*/
    *(_BYTE *)(v3 + 22) = 0; /*0x111bbe*/
    *(_DWORD *)(v3 + 8) = 0; /*0x111bc2*/
    *(_DWORD *)(v3 + 12) = 0; /*0x111bc9*/
  }
  *(_DWORD *)(v3 + 4) = dword_1E56C4; /*0x111bd9*/
  dword_1E56C4 = v3; /*0x111bdc*/
  splx(v1); /*0x111be3*/
  return v3; /*0x111bed*/
}
