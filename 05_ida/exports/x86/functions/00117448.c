/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117448. */
ssize_t __cdecl sendto(int a1, const void *a2, size_t a3, int a4, const sockaddr *a5, socklen_t a6)
{
  _DWORD *v6; // edx
  _DWORD v8[2]; // [esp+0h] [ebp-20h] BYREF
  _DWORD v9[6]; // [esp+8h] [ebp-18h] BYREF

  v6 = *(_DWORD **)(dword_1E875C + 36); /*0x117453*/
  v9[0] = v6[4]; /*0x117459*/
  v9[1] = v6[5]; /*0x11745f*/
  v9[2] = v8; /*0x117465*/
  v9[3] = 1; /*0x117468*/
  v8[0] = v6[1]; /*0x117472*/
  v8[1] = v6[2]; /*0x117478*/
  v9[4] = 0; /*0x11747b*/
  v9[5] = 0; /*0x117482*/
  return sendit(*v6, v9, v6[3]); /*0x117499*/
}
