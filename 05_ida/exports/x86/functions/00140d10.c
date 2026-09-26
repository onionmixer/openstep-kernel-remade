/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140d10. */
__int16 __cdecl idrop(int a1)
{
  __int16 v1; // ax
  __int16 result; // ax

  if ( (*(_BYTE *)(a1 + 68) & 1) == 0 ) /*0x140d1b*/
    panic(aIdrop); /*0x140d22*/
  v1 = *(_WORD *)(a1 + 68); /*0x140d2a*/
  *(_WORD *)(a1 + 68) = v1 & 0xFFFE; /*0x140d33*/
  if ( (v1 & 0x10) != 0 ) /*0x140d39*/
  {
    LOBYTE(v1) = v1 & 0xEE; /*0x140d3b*/
    *(_WORD *)(a1 + 68) = v1; /*0x140d3d*/
    wakeup(a1); /*0x140d42*/
  }
  result = *(_WORD *)(a1 + 18); /*0x140d47*/
  *(_WORD *)(a1 + 18) = result - 1; /*0x140d4f*/
  if ( result == 1 ) /*0x140d57*/
  {
    *(_WORD *)(a1 + 68) = 0; /*0x140d59*/
    if ( ifreeh ) /*0x140d66*/
    {
      result = ifreet; /*0x140d68*/
      *(_DWORD *)ifreet = a1; /*0x140d6d*/
      *(_DWORD *)(a1 + 96) = ifreet; /*0x140d75*/
    }
    else
    {
      ifreeh = a1; /*0x140d7c*/
      *(_DWORD *)(a1 + 96) = &ifreeh; /*0x140d82*/
    }
    *(_DWORD *)(a1 + 92) = 0; /*0x140d89*/
    ifreet = a1 + 92; /*0x140d93*/
  }
  return result; /*0x140d99*/
}
