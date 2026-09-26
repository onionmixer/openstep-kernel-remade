/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a280. */
unsigned int __cdecl thread_read_times(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // [esp+10h] [ebp-Ch]
  unsigned int v5; // [esp+14h] [ebp-8h]
  unsigned int v6; // [esp+14h] [ebp-8h]
  int v7; // [esp+18h] [ebp-4h]

  do /*0x16a2ac*/
  {
    v5 = a1[56]; /*0x16a2a0*/
    v4 = a1[57]; /*0x16a2a6*/
  }
  while ( a1[58] != v4 ); /*0x16a2ac*/
  *a2 = v4 + v5 / 0xF4240; /*0x16a2bd*/
  a2[1] = v5 % 0xF4240; /*0x16a2c6*/
  do /*0x16a2e1*/
  {
    v7 = a1[61]; /*0x16a2d3*/
    v6 = a1[60]; /*0x16a2d8*/
  }
  while ( a1[62] != v7 ); /*0x16a2e1*/
  *a3 = v6 / 0xF4240 + v7; /*0x16a2f1*/
  a3[1] = v6 % 0xF4240; /*0x16a2fc*/
  return v6 / 0xF4240; /*0x16a302*/
}
