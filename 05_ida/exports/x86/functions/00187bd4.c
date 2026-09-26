/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187bd4. */
void __cdecl set_clock(int a1, __int64 a2)
{
  int v2; // eax
  _DWORD v3[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( !a1 ) /*0x187be7*/
  {
    v2 = splusclock(); /*0x187be9*/
    time_of_boot = a2 - qword_1E75D0; /*0x187bfe*/
    splx(v2); /*0x187c0b*/
    ns_time_to_timeval(a2, HIDWORD(a2), v3); /*0x187c16*/
    writetodc(v3); /*0x187c1c*/
  }
}
