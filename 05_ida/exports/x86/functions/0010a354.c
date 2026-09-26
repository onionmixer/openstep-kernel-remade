/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a354. */
int __cdecl sigpending(sigset_t *a1)
{
  char v1; // dl
  int result; // eax

  v1 = copyout(*(_DWORD *)active_u + 24, **(_DWORD **)(dword_1E875C + 36), 4); /*0x10a374*/
  result = dword_1E875C; /*0x10a376*/
  *(_BYTE *)(dword_1E875C + 104) = v1; /*0x10a37b*/
  return result; /*0x10a380*/
}
