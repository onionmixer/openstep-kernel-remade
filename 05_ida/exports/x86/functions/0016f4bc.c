/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f4bc. */
void __cdecl sub_16F4BC(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E02DC && a1[8] == dword_1E02E0 ) /*0x16f4e5*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f4f9*/
    *(_DWORD *)(a2 + 28) = mach_port_set_qlimit(v2, a1[7], a1[9]); /*0x16f509*/
    space_deallocate(v2); /*0x16f50d*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f4e7*/
  }
}
