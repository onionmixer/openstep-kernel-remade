/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104948. */
void __cdecl closef(int a1)
{
  __int16 v1; // ax
  int v2; // eax

  if ( a1 ) /*0x104951*/
  {
    v1 = *(_WORD *)(a1 + 14); /*0x104953*/
    if ( v1 <= 1 ) /*0x10495b*/
    {
      if ( v1 != 1 ) /*0x10496c*/
        panic(aFpNotOne); /*0x104973*/
      v2 = *(_DWORD *)(a1 + 20); /*0x10497b*/
      if ( v2 ) /*0x104980*/
        (*(void (__cdecl **)(int))(v2 + 12))(a1); /*0x104986*/
      crfree(*(_DWORD *)(a1 + 32)); /*0x10498f*/
      if ( *(_WORD *)(a1 + 14) != 1 ) /*0x10499c*/
        panic(aFpNotOne2); /*0x1049a3*/
      *(_WORD *)(a1 + 14) = 0; /*0x1049ab*/
      free_file(a1); /*0x1049b2*/
    }
    else
    {
      *(_WORD *)(a1 + 14) = v1 - 1; /*0x10495f*/
    }
  }
}
