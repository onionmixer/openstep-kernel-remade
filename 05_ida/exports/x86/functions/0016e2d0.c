/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e2d0. */
kern_return_t __cdecl sub_16E2D0(int *a1, int a2)
{
  kern_return_t result; // eax
  processor_t v3; // eax

  result = (kern_return_t)a1; /*0x16e2d4*/
  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e2e3*/
  {
    v3 = convert_port_to_processor(a1[2]); /*0x16e2f4*/
    result = processor_exit(v3); /*0x16e2fa*/
    *(_DWORD *)(a2 + 28) = result; /*0x16e2ff*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e2e5*/
  }
  return result; /*0x16e302*/
}
