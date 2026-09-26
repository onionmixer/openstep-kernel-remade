/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16eb34. */
void __cdecl sub_16EB34(int a1, int a2)
{
  int v2; // esi
  mach_msg_type_number_t v3; // [esp-4h] [ebp-10h]
  boolean_t v4; // [esp+0h] [ebp-Ch]

  if ( *(_DWORD *)(a1 + 4) == 40 /*0x16eb5d*/
    && *(int *)a1 >= 0
    && *(_DWORD *)(a1 + 24) == dword_1E0184
    && *(_DWORD *)(a1 + 32) == dword_1E0188 )
  {
    v2 = convert_port_to_thread(*(_DWORD *)(a1 + 8)); /*0x16eb71*/
    *(_DWORD *)(a2 + 28) = thread_policy(v2, *(_DWORD *)(a1 + 28), *(policy_base_t *)(a1 + 36), v3, v4); /*0x16eb81*/
    thread_deallocate(v2); /*0x16eb85*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16eb5f*/
  }
}
