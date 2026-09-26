/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ef74. */
void __cdecl sub_16EF74(int *a1, _DWORD *a2)
{
  int v2; // eax
  int time; // eax

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16ef87*/
  {
    v2 = convert_port_to_host(a1[2]); /*0x16ef9c*/
    time = host_get_time(v2, a2 + 9); /*0x16efa5*/
    a2[7] = time; /*0x16efaa*/
    if ( !time ) /*0x16efaf*/
    {
      a2[1] = 44; /*0x16efb1*/
      a2[8] = dword_1E01CC; /*0x16efbe*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16ef89*/
  }
}
