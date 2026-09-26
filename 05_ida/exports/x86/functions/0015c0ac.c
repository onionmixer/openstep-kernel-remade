/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c0ac. */
int __cdecl sub_15C0AC(_DWORD *a1)
{
  int v1; // edx
  int (__stdcall *v2)(int, int); // ebx
  int v3; // esi
  int v5; // [esp-4h] [ebp-10h]

  v1 = splsched(); /*0x15c0ba*/
  do /*0x15c0d5*/
  {
    while ( dword_1E5BA8 ) /*0x15c0c3*/
      ; /*0x15c0c1*/
  }
  while ( _InterlockedExchange(&dword_1E5BA8, 1) == 1 ); /*0x15c0d5*/
  v2 = (int (__stdcall *)(int, int))a1[8]; /*0x15c0d7*/
  v3 = a1[9]; /*0x15c0da*/
  a1[11] = 0; /*0x15c0dd*/
  _InterlockedExchange(&dword_1E5BA8, 0); /*0x15c0e6*/
  splx(v1); /*0x15c0ed*/
  return v2(v3, v5); /*0x15c0f8*/
}
