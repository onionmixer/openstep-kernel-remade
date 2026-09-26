/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f2b8. */
void __cdecl sub_16F2B8(int *a1, int a2)
{
  int v2; // ebx

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E02B4 ) /*0x16f2d7*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f2ed*/
    *(_DWORD *)(a2 + 28) = mach_port_destroy(v2, a1[7]); /*0x16f2f9*/
    space_deallocate(v2); /*0x16f2fd*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f2d9*/
  }
}
