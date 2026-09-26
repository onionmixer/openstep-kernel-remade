/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f44c. */
void __cdecl sub_16F44C(int *a1, _DWORD *a2)
{
  int v2; // esi

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E02D4 ) /*0x16f46b*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f481*/
    a2[7] = old_mach_port_get_receive_status(v2, a1[7], a2 + 9); /*0x16f491*/
    space_deallocate(v2); /*0x16f495*/
    if ( !a2[7] ) /*0x16f49a*/
    {
      a2[1] = 68; /*0x16f4a0*/
      a2[8] = dword_1E02D8; /*0x16f4ad*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16f46d*/
  }
}
