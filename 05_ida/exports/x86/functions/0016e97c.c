/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e97c. */
void __cdecl sub_16E97C(int *a1, int a2)
{
  int v2; // esi

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E0168 && a1[8] == dword_1E016C ) /*0x16e9a5*/
  {
    v2 = convert_port_to_thread(a1[2]); /*0x16e9b9*/
    *(_DWORD *)(a2 + 28) = thread_priority(v2, a1[7], a1[9]); /*0x16e9c9*/
    thread_deallocate(v2); /*0x16e9cd*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e9a7*/
  }
}
