/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ead4. */
void __cdecl sub_16EAD4(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E017C && a1[8] == dword_1E0180 ) /*0x16eafd*/
  {
    v2 = convert_port_to_pset(a1[2]); /*0x16eb11*/
    *(_DWORD *)(a2 + 28) = processor_set_max_priority(v2, a1[7], a1[9]); /*0x16eb21*/
    pset_deallocate(v2); /*0x16eb25*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16eaff*/
  }
}
