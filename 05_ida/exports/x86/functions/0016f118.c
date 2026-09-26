/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f118. */
void __cdecl sub_16F118(int *a1, _DWORD *a2)
{
  int v2; // esi

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E0294 ) /*0x16f137*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f14d*/
    a2[7] = mach_port_type(v2, a1[7], a2 + 9); /*0x16f15d*/
    space_deallocate(v2); /*0x16f161*/
    if ( !a2[7] ) /*0x16f166*/
    {
      a2[1] = 40; /*0x16f16c*/
      a2[8] = dword_1E0298; /*0x16f179*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16f139*/
  }
}
