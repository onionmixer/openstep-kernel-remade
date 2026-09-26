/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ebe8. */
void __cdecl sub_16EBE8(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E0190 && a1[8] == dword_1E0194 ) /*0x16ec11*/
  {
    v2 = convert_port_to_pset(a1[2]); /*0x16ec25*/
    *(_DWORD *)(a2 + 28) = processor_set_policy_disable(v2, a1[7], a1[9]); /*0x16ec35*/
    pset_deallocate(v2); /*0x16ec39*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ec13*/
  }
}
