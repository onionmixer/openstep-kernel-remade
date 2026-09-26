/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e5fc. */
void __cdecl sub_16E5FC(int *a1, _DWORD *a2)
{
  processor_t v2; // eax
  kern_return_t assignment; // eax
  processor_set_name_t assigned_set; // [esp+4h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e612*/
  {
    v2 = convert_port_to_processor(a1[2]); /*0x16e628*/
    assignment = processor_get_assignment(v2, &assigned_set); /*0x16e631*/
    a2[7] = assignment; /*0x16e636*/
    if ( !assignment ) /*0x16e63e*/
    {
      *a2 |= 0x80000000; /*0x16e640*/
      a2[1] = 40; /*0x16e646*/
      a2[8] = dword_1E0148; /*0x16e653*/
      a2[9] = convert_pset_name_to_port(assigned_set); /*0x16e65f*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e614*/
  }
}
