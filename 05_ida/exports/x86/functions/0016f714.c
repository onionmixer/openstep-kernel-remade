/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f714. */
void __cdecl sub_16F714(int a1, int a2)
{
  int v2; // edx
  int v3; // esi

  v2 = *(_DWORD *)a1 >> 31; /*0x16f724*/
  if ( *(_DWORD *)(a1 + 4) == 40 && *(_DWORD *)(a1 + 24) == dword_1E0314 ) /*0x16f738*/
  {
    if ( (*(_BYTE *)(a1 + 35) & 0x30) == 0x10 /*0x16f767*/
      && ((unsigned __int8)(*(_BYTE *)(a1 + 32) - 16) > 5u || (LOBYTE(v2) = *(_DWORD *)a1 >= 0, !v2))
      && (*(_DWORD *)(a1 + 32) & 0xFFFFF00) == 0x12000 )
    {
      v3 = convert_port_to_space(*(_DWORD *)(a1 + 8)); /*0x16f77d*/
      *(_DWORD *)(a2 + 28) = mach_port_insert_right( /*0x16f792*/
                               v3,
                               *(_DWORD *)(a1 + 28),
                               *(_DWORD *)(a1 + 36),
                               *(unsigned __int8 *)(a1 + 32));
      space_deallocate(v3); /*0x16f796*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x16f769*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f73a*/
  }
}
