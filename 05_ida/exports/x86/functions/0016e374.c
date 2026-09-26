/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e374. */
void __cdecl sub_16E374(int *a1, _DWORD *a2)
{
  host_t v2; // eax
  kern_return_t v3; // eax
  processor_set_name_t default_set; // [esp+4h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e38a*/
  {
    v2 = convert_port_to_host(a1[2]); /*0x16e3a0*/
    v3 = processor_set_default(v2, &default_set); /*0x16e3a9*/
    a2[7] = v3; /*0x16e3ae*/
    if ( !v3 ) /*0x16e3b6*/
    {
      *a2 |= 0x80000000; /*0x16e3b8*/
      a2[1] = 40; /*0x16e3be*/
      a2[8] = dword_1E0124; /*0x16e3cb*/
      a2[9] = convert_pset_name_to_port(default_set); /*0x16e3d7*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e38c*/
  }
}
