/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192438. */
int __cdecl sub_192438(_DWORD *a1)
{
  void (__usercall *v1)(int@<eax>, int@<edx>, int@<ecx>, int, int); // eax
  int result; // eax
  int v3; // eax

  __writedr(6u, 0); /*0x192444*/
  if ( a1[12] == 1 ) /*0x19244b*/
  {
    v1 = (void (__usercall *)(int@<eax>, int@<edx>, int@<ecx>, int, int))a1[14]; /*0x19244d*/
    if ( v1 == unix_syscall_ || v1 == mach_kernel_trap_ || v1 == machdep_call_ ) /*0x192463*/
    {
      result = *(_DWORD *)(active_threads + 40); /*0x19246a*/
      *(_BYTE *)(result + 240) |= 1u; /*0x19246d*/
      a1[16] &= ~0x100u; /*0x192474*/
      return result; /*0x19247b*/
    }
    v3 = 1; /*0x192480*/
  }
  else
  {
    v3 = 3; /*0x192488*/
  }
  return kdp_raise_exception(6u, v3, 0, (int)a1); /*0x192498*/
}
