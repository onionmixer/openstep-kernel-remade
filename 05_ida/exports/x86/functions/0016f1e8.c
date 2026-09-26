/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f1e8. */
void __cdecl sub_16F1E8(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E02A4 && a1[8] == dword_1E02A8 ) /*0x16f211*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f225*/
    *(_DWORD *)(a2 + 28) = mach_port_allocate_name(v2, a1[7], a1[9]); /*0x16f235*/
    space_deallocate(v2); /*0x16f239*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f213*/
  }
}
