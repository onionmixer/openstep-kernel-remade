/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107ac8. */
pid_t getpid(void)
{
  int v0; // edx
  int v1; // eax
  pid_t result; // eax

  v0 = *(_DWORD *)(active_threads + 132); /*0x107ad0*/
  v1 = *(_DWORD *)active_u; /*0x107adb*/
  *(_DWORD *)(v0 + 96) = *(__int16 *)(*(_DWORD *)active_u + 48); /*0x107ae1*/
  result = *(__int16 *)(v1 + 50); /*0x107ae4*/
  *(_DWORD *)(v0 + 100) = result; /*0x107ae8*/
  return result; /*0x107aed*/
}
