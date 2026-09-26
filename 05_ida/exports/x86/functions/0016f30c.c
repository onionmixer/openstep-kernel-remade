/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f30c. */
void __cdecl sub_16F30C(int *a1, int a2)
{
  int v2; // ebx

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E02B8 ) /*0x16f32b*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f341*/
    *(_DWORD *)(a2 + 28) = mach_port_deallocate(v2, a1[7]); /*0x16f34d*/
    space_deallocate(v2); /*0x16f351*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f32d*/
  }
}
