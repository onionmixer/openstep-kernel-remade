/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11771c. */
ssize_t __cdecl recvfrom(int a1, void *a2, size_t a3, int a4, sockaddr *a5, socklen_t *a6)
{
  _DWORD *v6; // ebx
  int v7; // edx
  ssize_t result; // eax
  _DWORD v9[2]; // [esp+4h] [ebp-24h] BYREF
  int v10; // [esp+Ch] [ebp-1Ch] BYREF
  int v11; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-14h]
  _DWORD *v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  int v15; // [esp+20h] [ebp-8h]
  int v16; // [esp+24h] [ebp-4h]

  v6 = *(_DWORD **)(dword_1E875C + 36); /*0x117728*/
  v7 = v6[5]; /*0x11772b*/
  if ( v7 ) /*0x117730*/
    *(_BYTE *)(dword_1E875C + 104) = copyin(v7, &v10, 4); /*0x117745*/
  else
    v12 = 0; /*0x117750*/
  result = dword_1E875C; /*0x117757*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11775c*/
  {
    v11 = v6[4]; /*0x117765*/
    v12 = v10; /*0x11776b*/
    v13 = v9; /*0x117771*/
    v14 = 1; /*0x117774*/
    v9[0] = v6[1]; /*0x11777e*/
    v9[1] = v6[2]; /*0x117784*/
    v15 = 0; /*0x117787*/
    v16 = 0; /*0x11778e*/
    return recvit(*v6, &v11, v6[3], v6[5], 0); /*0x1177a6*/
  }
  return result; /*0x1177ab*/
}
