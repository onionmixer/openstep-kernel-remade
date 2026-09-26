/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187c74. */
int (__stdcall *__cdecl set_timer_expire_func(
        int a1,
        int (__stdcall *a2)(_DWORD, _DWORD, _DWORD)))(_DWORD, _DWORD, _DWORD)
{
  int (__stdcall *result)(_DWORD, _DWORD, _DWORD); // eax

  if ( !dword_1E75E4 ) /*0x187c7e*/
  {
    dword_1E75E4 = a2; /*0x187c83*/
    return a2; /*0x187c80*/
  }
  return result; /*0x187c8a*/
}
