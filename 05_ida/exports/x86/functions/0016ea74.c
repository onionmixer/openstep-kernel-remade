/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ea74. */
void __cdecl sub_16EA74(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E0174 && a1[8] == dword_1E0178 ) /*0x16ea9d*/
  {
    v2 = convert_port_to_task(a1[2]); /*0x16eab1*/
    *(_DWORD *)(a2 + 28) = task_priority(v2, a1[7], a1[9]); /*0x16eac1*/
    task_deallocate(v2); /*0x16eac5*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ea9f*/
  }
}
