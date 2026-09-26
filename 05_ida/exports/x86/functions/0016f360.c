/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f360. */
void __cdecl sub_16F360(int *a1, _DWORD *a2)
{
  int v2; // edi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E02BC && a1[8] == dword_1E02C0 ) /*0x16f389*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f39d*/
    a2[7] = mach_port_get_refs(v2, a1[7], a1[9], a2 + 9); /*0x16f3b1*/
    space_deallocate(v2); /*0x16f3b5*/
    if ( !a2[7] ) /*0x16f3ba*/
    {
      a2[1] = 40; /*0x16f3c0*/
      a2[8] = dword_1E02C4; /*0x16f3cd*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16f38b*/
  }
}
