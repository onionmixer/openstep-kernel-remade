/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ef0c. */
int __cdecl sub_16EF0C(int *a1, _DWORD *a2)
{
  int result; // eax
  int v3; // eax
  int v4; // [esp-Ch] [ebp-10h]
  int v5; // [esp-8h] [ebp-Ch]

  result = (int)a1; /*0x16ef10*/
  if ( a1[1] == 36 && *a1 >= 0 && a1[6] == dword_1E01C4 ) /*0x16ef2a*/
  {
    v5 = a1[8]; /*0x16ef42*/
    v4 = a1[7]; /*0x16ef43*/
    v3 = convert_port_to_host_priv(a1[2]); /*0x16ef48*/
    result = host_adjust_time(v3, v4, v5, a2 + 9); /*0x16ef51*/
    a2[7] = result; /*0x16ef56*/
    if ( !result ) /*0x16ef5b*/
    {
      a2[1] = 44; /*0x16ef5d*/
      a2[8] = dword_1E01C8; /*0x16ef6a*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16ef2c*/
  }
  return result; /*0x16ef6d*/
}
