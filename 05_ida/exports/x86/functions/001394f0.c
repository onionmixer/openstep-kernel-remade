/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1394f0. */
_DWORD *__cdecl fifosp(int a1)
{
  _DWORD *v1; // esi
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  _BYTE v6[32]; // [esp+8h] [ebp-40h] BYREF
  int v7; // [esp+28h] [ebp-20h]
  int v8; // [esp+2Ch] [ebp-1Ch]
  int v9; // [esp+30h] [ebp-18h]
  int v10; // [esp+34h] [ebp-14h]
  int v11; // [esp+38h] [ebp-10h]
  int v12; // [esp+3Ch] [ebp-Ch]

  v1 = (_DWORD *)kalloc(0x8Cu); /*0x139505*/
  bzero(v1, 0x8Cu); /*0x13950d*/
  v1[8] = &fifo_vnodeops; /*0x139512*/
  (*(void (__cdecl **)(int, _BYTE *, _DWORD))(*(_DWORD *)(a1 + 28) + 20))(a1, v6, *(_DWORD *)(active_u + 28)); /*0x13952e*/
  v2 = v8; /*0x139533*/
  v1[19] = v7; /*0x139536*/
  v1[20] = v2; /*0x139539*/
  v3 = v10; /*0x13953f*/
  v1[21] = v9; /*0x139542*/
  v1[22] = v3; /*0x139545*/
  v4 = v12; /*0x13954b*/
  v1[23] = v11; /*0x13954e*/
  v1[24] = v4; /*0x139551*/
  return v1; /*0x139559*/
}
