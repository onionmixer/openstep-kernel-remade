/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140da0. */
__int16 __cdecl iinactive(int a1)
{
  int v1; // eax
  __int16 v2; // ax
  __int16 v3; // ax

  if ( (*(_WORD *)(a1 + 68) & 0x101) != 0x100 || *(_DWORD *)(a1 + 96) || *(_DWORD *)(a1 + 92) ) /*0x140dbb*/
    panic(aIinactive); /*0x140dc6*/
  v1 = *(_DWORD *)(a1 + 80); /*0x140dce*/
  if ( !*(_BYTE *)(v1 + 210) ) /*0x140dd1*/
  {
    while ( 1 ) /*0x140df1*/
    {
      v2 = *(_WORD *)(a1 + 68); /*0x140df1*/
      if ( (v2 & 1) == 0 ) /*0x140df7*/
        break; /*0x140df7*/
      LOBYTE(v2) = v2 | 0x10; /*0x140de0*/
      *(_WORD *)(a1 + 68) = v2; /*0x140de2*/
      sleep(a1); /*0x140de9*/
    }
    *(_BYTE *)(a1 + 68) |= 1u; /*0x140df9*/
    if ( *(__int16 *)(a1 + 102) <= 0 ) /*0x140e02*/
    {
      ++*(_DWORD *)(a1 + 208); /*0x140e04*/
      *(_WORD *)(a1 + 68) |= 0x200u; /*0x140e0a*/
      itrunc(a1, 0); /*0x140e13*/
      v3 = *(_WORD *)(a1 + 100); /*0x140e18*/
      *(_WORD *)(a1 + 100) = 0; /*0x140e1c*/
      *(_DWORD *)(a1 + 140) = 0; /*0x140e22*/
      *(_BYTE *)(a1 + 68) |= 0x42u; /*0x140e2c*/
      ifree(a1, *(_DWORD *)(a1 + 72), v3); /*0x140e36*/
    }
    if ( (*(_BYTE *)(a1 + 68) & 0x4E) != 0 ) /*0x140e42*/
      iupdat(a1, 0); /*0x140e47*/
    LOWORD(v1) = *(_WORD *)(a1 + 68); /*0x140e4f*/
    *(_WORD *)(a1 + 68) = v1 & 0xFFFE; /*0x140e58*/
    if ( (v1 & 0x10) != 0 ) /*0x140e5e*/
    {
      LOBYTE(v1) = v1 & 0xEE; /*0x140e60*/
      *(_WORD *)(a1 + 68) = v1; /*0x140e62*/
      LOWORD(v1) = wakeup(a1); /*0x140e67*/
    }
  }
  *(_WORD *)(a1 + 68) = 0; /*0x140e6c*/
  if ( ifreeh ) /*0x140e79*/
  {
    LOWORD(v1) = ifreet; /*0x140e7b*/
    *(_DWORD *)ifreet = a1; /*0x140e80*/
    *(_DWORD *)(a1 + 96) = ifreet; /*0x140e88*/
  }
  else
  {
    ifreeh = a1; /*0x140e90*/
    *(_DWORD *)(a1 + 96) = &ifreeh; /*0x140e96*/
  }
  *(_DWORD *)(a1 + 92) = 0; /*0x140e9d*/
  ifreet = a1 + 92; /*0x140ea7*/
  return v1; /*0x140ead*/
}
