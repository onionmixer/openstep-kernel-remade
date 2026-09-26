/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0e2c. */
int (__cdecl *__cdecl register_keyboard_entries(int a1))(_DWORD)
{
  int (__cdecl *result)(_DWORD); // eax

  result = *(int (__cdecl **)(_DWORD))(a1 + 4); /*0x1a0e34*/
  dword_1E4B78 = *(int (**)(void))a1; /*0x1a0e37*/
  dword_1E4B7C = result; /*0x1a0e3d*/
  return result; /*0x1a0e44*/
}
