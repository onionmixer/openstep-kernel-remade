/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1177b4. */
ssize_t __cdecl recv(int a1, void *a2, size_t a3, int a4)
{
  _DWORD *v4; // edx
  _DWORD v6[2]; // [esp+0h] [ebp-20h] BYREF
  _DWORD v7[6]; // [esp+8h] [ebp-18h] BYREF

  v4 = *(_DWORD **)(dword_1E875C + 36); /*0x1177bf*/
  v7[0] = 0; /*0x1177c2*/
  v7[1] = 0; /*0x1177c9*/
  v7[2] = v6; /*0x1177d3*/
  v7[3] = 1; /*0x1177d6*/
  v6[0] = v4[1]; /*0x1177e0*/
  v6[1] = v4[2]; /*0x1177e6*/
  v7[4] = 0; /*0x1177e9*/
  v7[5] = 0; /*0x1177f0*/
  return recvit(*v4, v7, v4[3], 0, 0); /*0x11780b*/
}
