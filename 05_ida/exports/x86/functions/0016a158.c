/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a158. */
_BOOL4 __cdecl kern_timestamp(int a1)
{
  __int64 v1; // rax
  _DWORD v3[2]; // [esp+8h] [ebp-8h] BYREF

  v1 = clock_value(1); /*0x16a165*/
  ns_time_to_tsval(v1, HIDWORD(v1), v3); /*0x16a170*/
  return copyout(v3, a1, 8) != 0; /*0x16a190*/
}
