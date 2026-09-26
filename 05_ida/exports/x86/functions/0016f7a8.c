/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f7a8. */
void __cdecl sub_16F7A8(int *a1, _DWORD *a2)
{
  int v2; // edi
  int v3; // edi
  int v4; // edx
  int v5; // eax
  mach_msg_type_name_t polyPoly; // [esp+Ch] [ebp-4h] BYREF

  if ( a1[1] == 40 && *a1 >= 0 && a1[6] == dword_1E0318 && a1[8] == dword_1E031C ) /*0x16f7d4*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f7ed*/
    a2[7] = mach_port_extract_right(v2, a1[7], a1[9], a2 + 9, &polyPoly); /*0x16f805*/
    space_deallocate(v2); /*0x16f809*/
    if ( !a2[7] ) /*0x16f811*/
    {
      v3 = 1; /*0x16f817*/
      a2[1] = 40; /*0x16f81c*/
      a2[8] = dword_1E0320; /*0x16f829*/
      if ( polyPoly == 16 ) /*0x16f830*/
      {
        v4 = a1[3]; /*0x16f832*/
        if ( v4 ) /*0x16f837*/
        {
          if ( v4 != -1 ) /*0x16f83c*/
          {
            v5 = a2[9]; /*0x16f83e*/
            if ( v5 ) /*0x16f843*/
            {
              if ( v5 != -1 && ipc_port_check_circularity(v5, a1[3]) ) /*0x16f84c*/
                *a2 |= 0x40000000u; /*0x16f855*/
            }
          }
        }
      }
      if ( polyPoly - 16 <= 5 ) /*0x16f864*/
        v3 = 0; /*0x16f866*/
      *((_BYTE *)a2 + 32) = polyPoly; /*0x16f868*/
      if ( !v3 ) /*0x16f86d*/
        *a2 |= 0x80000000; /*0x16f86f*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16f7d6*/
  }
}
