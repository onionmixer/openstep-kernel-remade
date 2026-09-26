/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e294. */
kern_return_t __cdecl sub_16E294(int *a1, int a2)
{
  kern_return_t result; // eax
  processor_t v3; // eax

  result = (kern_return_t)a1; /*0x16e298*/
  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e2a7*/
  {
    v3 = convert_port_to_processor(a1[2]); /*0x16e2b8*/
    result = processor_start(v3); /*0x16e2be*/
    *(_DWORD *)(a2 + 28) = result; /*0x16e2c3*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e2a9*/
  }
  return result; /*0x16e2c6*/
}
