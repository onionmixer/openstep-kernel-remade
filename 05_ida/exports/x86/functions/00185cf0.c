/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185cf0. */
int __cdecl kdp_machine_write_regs(int a1, int a2, int a3)
{
  int v3; // eax

  if ( a2 == -2 ) /*0x185cfc*/
    return 0; /*0x185cfc*/
  if ( a2 == -1 ) /*0x185d01*/
  {
    v3 = dword_1F66AC; /*0x185d03*/
    *(_DWORD *)(dword_1F66AC + 44) = *(_DWORD *)a3; /*0x185d0a*/
    *(_DWORD *)(v3 + 32) = *(_DWORD *)(a3 + 4); /*0x185d10*/
    *(_DWORD *)(v3 + 40) = *(_DWORD *)(a3 + 8); /*0x185d16*/
    *(_DWORD *)(v3 + 36) = *(_DWORD *)(a3 + 12); /*0x185d1c*/
    *(_DWORD *)(v3 + 16) = *(_DWORD *)(a3 + 16); /*0x185d22*/
    *(_DWORD *)(v3 + 20) = *(_DWORD *)(a3 + 20); /*0x185d28*/
    *(_DWORD *)(v3 + 24) = *(_DWORD *)(a3 + 24); /*0x185d2e*/
    *(_DWORD *)(v3 + 64) = *(_DWORD *)(a3 + 36); /*0x185d34*/
    *(_DWORD *)(v3 + 56) = *(_DWORD *)(a3 + 40); /*0x185d3a*/
    *(_WORD *)(v3 + 4) = *(_WORD *)(a3 + 56); /*0x185d41*/
    *(_WORD *)v3 = *(_WORD *)(a3 + 60); /*0x185d49*/
    return 0; /*0x185d51*/
  }
  return 3; /*0x185d50*/
}
