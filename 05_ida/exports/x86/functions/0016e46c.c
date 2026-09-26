/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e46c. */
void __cdecl sub_16E46C(int *a1, int a2)
{
  int v2; // ebx

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e480*/
  {
    v2 = convert_port_to_pset(a1[2]); /*0x16e495*/
    *(_DWORD *)(a2 + 28) = processor_set_destroy(v2); /*0x16e49d*/
    pset_deallocate(v2); /*0x16e4a1*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e482*/
  }
}
