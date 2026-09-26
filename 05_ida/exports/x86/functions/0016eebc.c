/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16eebc. */
int __cdecl sub_16EEBC(int *a1, int a2)
{
  int result; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-8h]

  result = (int)a1; /*0x16eec0*/
  if ( a1[1] == 36 && *a1 >= 0 && a1[6] == dword_1E01C0 ) /*0x16eeda*/
  {
    v5 = a1[8]; /*0x16eeee*/
    v4 = a1[7]; /*0x16eeef*/
    v3 = convert_port_to_host_priv(a1[2]); /*0x16eef4*/
    result = host_set_time(v3, v4, v5); /*0x16eefd*/
    *(_DWORD *)(a2 + 28) = result; /*0x16ef02*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16eedc*/
  }
  return result; /*0x16ef05*/
}
