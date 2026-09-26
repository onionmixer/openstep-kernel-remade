/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e89c. */
void __cdecl sub_16E89C(int *a1, _DWORD *a2)
{
  int v2; // esi
  processor_set_name_t assigned_set; // [esp+8h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e8b3*/
  {
    v2 = convert_port_to_task(a1[2]); /*0x16e8c9*/
    a2[7] = task_get_assignment(v2, &assigned_set); /*0x16e8d5*/
    task_deallocate(v2); /*0x16e8d9*/
    if ( !a2[7] ) /*0x16e8e1*/
    {
      *a2 |= 0x80000000; /*0x16e8e7*/
      a2[1] = 40; /*0x16e8ed*/
      a2[8] = dword_1E0158; /*0x16e8fa*/
      a2[9] = convert_pset_name_to_port(assigned_set); /*0x16e906*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e8b5*/
  }
}
