/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f068. */
int __cdecl sub_16F068(int *a1, int a2)
{
  int result; // eax
  int v3; // esi
  mach_msg_type_number_t typesCnt; // [esp+8h] [ebp-8h] BYREF
  mach_msg_type_number_t namesCnt; // [esp+Ch] [ebp-4h] BYREF

  result = (int)a1; /*0x16f070*/
  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16f07f*/
  {
    v3 = convert_port_to_space(a1[2]); /*0x16f099*/
    *(_DWORD *)(a2 + 28) = mach_port_names( /*0x16f0b1*/
                             v3,
                             (mach_port_name_array_t *)(a2 + 44),
                             &namesCnt,
                             (mach_port_type_array_t *)(a2 + 60),
                             &typesCnt);
    result = space_deallocate(v3); /*0x16f0b5*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16f0ba*/
    {
      *(_DWORD *)a2 |= 0x80000000; /*0x16f0c0*/
      *(_DWORD *)(a2 + 4) = 64; /*0x16f0c6*/
      *(_DWORD *)(a2 + 32) = dword_1E027C; /*0x16f0d3*/
      *(_DWORD *)(a2 + 36) = off_1E0280; /*0x16f0dc*/
      *(_DWORD *)(a2 + 40) = dword_1E0284; /*0x16f0e5*/
      *(_DWORD *)(a2 + 40) = namesCnt; /*0x16f0eb*/
      *(_DWORD *)(a2 + 48) = dword_1E0288; /*0x16f0f4*/
      *(_DWORD *)(a2 + 52) = off_1E028C; /*0x16f0fd*/
      *(_DWORD *)(a2 + 56) = dword_1E0290; /*0x16f106*/
      *(_DWORD *)(a2 + 56) = typesCnt; /*0x16f10c*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f081*/
  }
  return result; /*0x16f112*/
}
