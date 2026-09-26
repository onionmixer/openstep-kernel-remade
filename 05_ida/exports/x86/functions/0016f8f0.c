/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f8f0. */
void __cdecl sub_16F8F0(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E032C && a1[8] == dword_1E0330 ) /*0x16f919*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f92d*/
    *(_DWORD *)(a2 + 28) = mach_port_set_seqno(v2, a1[7], a1[9]); /*0x16f93d*/
    space_deallocate(v2); /*0x16f941*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f91b*/
  }
}
