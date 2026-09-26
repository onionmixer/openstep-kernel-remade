/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f880. */
void __cdecl sub_16F880(int *a1, _DWORD *a2)
{
  int v2; // esi

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E0324 ) /*0x16f89f*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f8b5*/
    a2[7] = mach_port_get_receive_status(v2, a1[7], a2 + 9); /*0x16f8c5*/
    space_deallocate(v2); /*0x16f8c9*/
    if ( !a2[7] ) /*0x16f8ce*/
    {
      a2[1] = 72; /*0x16f8d4*/
      a2[8] = dword_1E0328; /*0x16f8e1*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16f8a1*/
  }
}
