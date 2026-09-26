/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e848. */
void __cdecl sub_16E848(int *a1, int a2)
{
  int v2; // ebx

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E0154 ) /*0x16e867*/
  {
    v2 = convert_port_to_task(a1[2]); /*0x16e87d*/
    *(_DWORD *)(a2 + 28) = task_assign_default(v2, a1[7]); /*0x16e889*/
    task_deallocate(v2); /*0x16e88d*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e869*/
  }
}
