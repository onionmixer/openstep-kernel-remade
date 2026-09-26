/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106168. */
pid_t __cdecl wait(int *a1)
{
  int v1; // eax
  int v3; // [esp+0h] [ebp-4h] BYREF

  v1 = wait1(0, 0, &v3, 0, wait); /*0x10617d*/
  *(_DWORD *)(dword_1E875C + 100) = v3; /*0x10618c*/
  return unix_syscall_return(v1); /*0x106195*/
}
