/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7d6c. */
id __cdecl sub_1A7D6C(int a1)
{
  int v1; // esi
  int v2; // eax

  v1 = IOMalloc(0x18u); /*0x1a7d7b*/
  *(_DWORD *)v1 = 5; /*0x1a7d7d*/
  *(_DWORD *)(v1 + 4) = a1; /*0x1a7d83*/
  *(_DWORD *)(v1 + 8) = 0; /*0x1a7d86*/
  *(_WORD *)(v1 + 12) = 0; /*0x1a7d8d*/
  *(_WORD *)(v1 + 14) = 0; /*0x1a7d93*/
  objc_msgSend(dword_1E86E8, sel_lock); /*0x1a7da7*/
  if ( (int *)dword_1E86E0 == &dword_1E86E0 ) /*0x1a7db9*/
  {
    dword_1E86E0 = v1; /*0x1a7dbb*/
    dword_1E86E4 = v1; /*0x1a7dc1*/
    *(_DWORD *)(v1 + 16) = &dword_1E86E0; /*0x1a7dc7*/
    *(_DWORD *)(v1 + 20) = &dword_1E86E0; /*0x1a7dce*/
  }
  else
  {
    v2 = dword_1E86E4; /*0x1a7dd8*/
    *(_DWORD *)(v1 + 20) = dword_1E86E4; /*0x1a7ddd*/
    *(_DWORD *)(v1 + 16) = &dword_1E86E0; /*0x1a7de0*/
    dword_1E86E4 = v1; /*0x1a7de7*/
    *(_DWORD *)(v2 + 16) = v1; /*0x1a7ded*/
  }
  return objc_msgSend(dword_1E86E8, sel_unlock); /*0x1a7e06*/
}
