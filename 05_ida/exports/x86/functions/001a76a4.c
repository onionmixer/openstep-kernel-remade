/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a76a4. */
id __cdecl sub_1A76A4(int a1, int a2, int a3, __int16 a4, __int16 a5)
{
  int v5; // eax
  int v6; // eax
  int v8; // [esp+Ch] [ebp-4h]

  v5 = IOMalloc(24); /*0x1a76ba*/
  *(_DWORD *)v5 = a1; /*0x1a76c1*/
  *(_DWORD *)(v5 + 4) = a2; /*0x1a76c6*/
  *(_DWORD *)(v5 + 8) = a3; /*0x1a76cc*/
  *(_WORD *)(v5 + 12) = a4; /*0x1a76cf*/
  *(_WORD *)(v5 + 14) = a5; /*0x1a76d3*/
  v8 = v5; /*0x1a76e5*/
  objc_msgSend(dword_1E86E8, sel_lock); /*0x1a76e8*/
  if ( (int *)dword_1E86E0 == &dword_1E86E0 ) /*0x1a76fd*/
  {
    dword_1E86E0 = v8; /*0x1a76ff*/
    dword_1E86E4 = v8; /*0x1a7705*/
    *(_DWORD *)(v8 + 16) = &dword_1E86E0; /*0x1a770b*/
    *(_DWORD *)(v8 + 20) = &dword_1E86E0; /*0x1a7712*/
  }
  else
  {
    v6 = dword_1E86E4; /*0x1a771c*/
    *(_DWORD *)(v8 + 20) = dword_1E86E4; /*0x1a7721*/
    *(_DWORD *)(v8 + 16) = &dword_1E86E0; /*0x1a7724*/
    dword_1E86E4 = v8; /*0x1a772b*/
    *(_DWORD *)(v6 + 16) = v8; /*0x1a7731*/
  }
  return objc_msgSend(dword_1E86E8, sel_unlock); /*0x1a774a*/
}
