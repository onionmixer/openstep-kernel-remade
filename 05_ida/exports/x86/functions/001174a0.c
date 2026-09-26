/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1174a0. */
ssize_t __cdecl send(int a1, const void *a2, size_t a3, int a4)
{
  _DWORD *v4; // edx
  _DWORD v6[2]; // [esp+0h] [ebp-20h] BYREF
  _DWORD v7[6]; // [esp+8h] [ebp-18h] BYREF

  v4 = *(_DWORD **)(dword_1E875C + 36); /*0x1174ab*/
  v7[0] = 0; /*0x1174ae*/
  v7[1] = 0; /*0x1174b5*/
  v7[2] = v6; /*0x1174bf*/
  v7[3] = 1; /*0x1174c2*/
  v6[0] = v4[1]; /*0x1174cc*/
  v6[1] = v4[2]; /*0x1174d2*/
  v7[4] = 0; /*0x1174d5*/
  v7[5] = 0; /*0x1174dc*/
  return sendit(*v4, v7, v4[3]); /*0x1174f3*/
}
