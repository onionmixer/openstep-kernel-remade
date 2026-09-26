/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16eb94. */
void __cdecl sub_16EB94(int *a1, int a2)
{
  int v2; // ebx

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E018C ) /*0x16ebb3*/
  {
    v2 = convert_port_to_pset(a1[2]); /*0x16ebc9*/
    *(_DWORD *)(a2 + 28) = processor_set_policy_enable(v2, a1[7]); /*0x16ebd5*/
    pset_deallocate(v2); /*0x16ebd9*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ebb5*/
  }
}
