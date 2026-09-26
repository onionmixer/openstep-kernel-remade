/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f3dc. */
void __cdecl sub_16F3DC(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 48 && *a1 >= 0 && a1[6] == dword_1E02C8 && a1[8] == dword_1E02CC && a1[10] == dword_1E02D0 ) /*0x16f40f*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f425*/
    *(_DWORD *)(a2 + 28) = mach_port_mod_refs(v2, a1[7], a1[9], a1[11]); /*0x16f439*/
    space_deallocate(v2); /*0x16f43d*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f411*/
  }
}
