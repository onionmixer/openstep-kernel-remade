/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd25c. */
void __cdecl __noreturn sub_1CD25C(void *a1, SEL sel)
{
  const char *Name; // eax

  Name = sel_getName(sel); /*0x1cd268*/
  __objc_error(a1, "message %s sent to freed object=0x%lx", Name); /*0x1cd277*/
}
