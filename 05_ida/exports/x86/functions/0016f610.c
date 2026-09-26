/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f610. */
void __cdecl sub_16F610(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E02FC && a1[8] == dword_1E0300 ) /*0x16f639*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f64d*/
    *(_DWORD *)(a2 + 28) = mach_port_move_member(v2, a1[7], a1[9]); /*0x16f65d*/
    space_deallocate(v2); /*0x16f661*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f63b*/
  }
}
