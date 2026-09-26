/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e738. */
void __cdecl sub_16E738(int *a1, _DWORD *a2)
{
  int v2; // esi
  processor_set_name_t assigned_set; // [esp+8h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e74f*/
  {
    v2 = convert_port_to_thread(a1[2]); /*0x16e765*/
    a2[7] = thread_get_assignment(v2, &assigned_set); /*0x16e771*/
    thread_deallocate(v2); /*0x16e775*/
    if ( !a2[7] ) /*0x16e77d*/
    {
      *a2 |= 0x80000000; /*0x16e783*/
      a2[1] = 40; /*0x16e789*/
      a2[8] = dword_1E014C; /*0x16e796*/
      a2[9] = convert_pset_name_to_port(assigned_set); /*0x16e7a2*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e751*/
  }
}
