/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13b714. */
int __cdecl verify_and_swap_cg(int a1)
{
  int v1; // ebx

  v1 = *(_DWORD *)(a1 + 32); /*0x13b71c*/
  if ( (*(_BYTE *)a1 & 4) != 0 ) /*0x13b722*/
  {
    brelse(a1); /*0x13b725*/
    return 0; /*0x13b72a*/
  }
  else
  {
    byte_swap_cylgroup(*(_DWORD *)(a1 + 32)); /*0x13b731*/
    if ( *(_DWORD *)(v1 + 980) == 590421 ) /*0x13b743*/
    {
      return 1; /*0x13b758*/
    }
    else
    {
      byte_swap_cylgroup(v1); /*0x13b746*/
      brelse(a1); /*0x13b74c*/
      return 0; /*0x13b751*/
    }
  }
}
