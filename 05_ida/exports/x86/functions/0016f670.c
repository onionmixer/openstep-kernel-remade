/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f670. */
void __cdecl sub_16F670(int *a1, _DWORD *a2)
{
  int v2; // edi
  mach_port_t *v3; // [esp-4h] [ebp-10h]

  if ( a1[1] == 56 /*0x16f6b2*/
    && *a1 < 0
    && a1[6] == dword_1E0304
    && a1[8] == dword_1E0308
    && a1[10] == dword_1E030C
    && (a1[12] & 0x3FFFFFFF) == 0x10012012 )
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f6c9*/
    a2[7] = mach_port_request_notification(v2, a1[7], a1[9], a1[11], a1[13], (mach_msg_type_name_t)(a2 + 9), v3); /*0x16f6e5*/
    space_deallocate(v2); /*0x16f6e9*/
    if ( !a2[7] ) /*0x16f6ee*/
    {
      *a2 |= 0x80000000; /*0x16f6f4*/
      a2[1] = 40; /*0x16f6fa*/
      a2[8] = dword_1E0310; /*0x16f707*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16f6b4*/
  }
}
