/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f248. */
void __cdecl sub_16F248(int *a1, _DWORD *a2)
{
  int v2; // esi

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E02AC ) /*0x16f267*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f27d*/
    a2[7] = mach_port_allocate(v2, a1[7], a2 + 9); /*0x16f28d*/
    space_deallocate(v2); /*0x16f291*/
    if ( !a2[7] ) /*0x16f296*/
    {
      a2[1] = 40; /*0x16f29c*/
      a2[8] = dword_1E02B0; /*0x16f2a9*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16f269*/
  }
}
