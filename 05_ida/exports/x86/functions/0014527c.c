/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14527c. */
int __cdecl rdwri(unsigned int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  unsigned int v7; // ebx
  int v8; // esi
  __int16 v9; // ax
  int v10; // edi
  __int16 v11; // ax
  __int16 v12; // ax
  int result; // eax
  _DWORD v14[2]; // [esp+Ch] [ebp-20h] BYREF
  _DWORD v15[5]; // [esp+14h] [ebp-18h] BYREF
  int v16; // [esp+28h] [ebp-4h]

  v14[0] = a3; /*0x14528e*/
  v14[1] = a4; /*0x145291*/
  v15[0] = v14; /*0x145297*/
  v15[1] = 1; /*0x14529a*/
  v15[2] = a5; /*0x1452a4*/
  v15[3] = a6; /*0x1452aa*/
  v16 = a4; /*0x1452ad*/
  if ( a1 == 1 && **(_DWORD **)(a2 + 12) ) /*0x1452bf*/
    vnode_uncache(a2 + 12); /*0x1452c5*/
  v7 = *(_DWORD *)(a2 + 60); /*0x1452cd*/
  if ( (*(_WORD *)(v7 + 100) & 0xF000) == 0x8000 ) /*0x1452d8*/
  {
    v8 = 1; /*0x1452de*/
    while ( 1 ) /*0x1452f9*/
    {
      v9 = *(_WORD *)(v7 + 68); /*0x1452f9*/
      if ( (v9 & 1) == 0 ) /*0x1452ff*/
        break; /*0x1452ff*/
      LOBYTE(v9) = v9 | 0x10; /*0x1452e8*/
      *(_WORD *)(v7 + 68) = v9; /*0x1452ea*/
      sleep(v7); /*0x1452f1*/
    }
    *(_BYTE *)(v7 + 68) |= 1u; /*0x145301*/
  }
  else
  {
    v8 = 0; /*0x145308*/
  }
  v10 = sub_143E24(v7, v15, a1, 0); /*0x145317*/
  v11 = *(_WORD *)(v7 + 68); /*0x145319*/
  if ( (v11 & 0x46) != 0 ) /*0x145322*/
  {
    LOBYTE(v11) = v11 | 8; /*0x145324*/
    *(_WORD *)(v7 + 68) = v11; /*0x145326*/
    microtime(&iuniqtime); /*0x14532f*/
    if ( (*(_BYTE *)(v7 + 68) & 4) != 0 ) /*0x14533b*/
      *(_DWORD *)(v7 + 116) = iuniqtime; /*0x145343*/
    if ( (*(_BYTE *)(v7 + 68) & 2) != 0 ) /*0x14534a*/
      *(_DWORD *)(v7 + 124) = iuniqtime; /*0x145352*/
    if ( (*(_BYTE *)(v7 + 68) & 0x40) != 0 ) /*0x145359*/
    {
      *(_DWORD *)(v7 + 76) = 0; /*0x14535b*/
      *(_DWORD *)(v7 + 132) = iuniqtime; /*0x145368*/
    }
    *(_BYTE *)(v7 + 68) &= 0xB9u; /*0x14536e*/
  }
  if ( v8 ) /*0x145374*/
  {
    v12 = *(_WORD *)(v7 + 68); /*0x145376*/
    *(_WORD *)(v7 + 68) = v12 & 0xFFFE; /*0x14537f*/
    if ( (v12 & 0x10) != 0 ) /*0x145385*/
    {
      LOBYTE(v12) = v12 & 0xEE; /*0x145387*/
      *(_WORD *)(v7 + 68) = v12; /*0x145389*/
      wakeup(v7); /*0x14538e*/
    }
  }
  result = v10; /*0x145393*/
  if ( a7 ) /*0x145399*/
  {
    *a7 = v16; /*0x1453a1*/
  }
  else if ( v16 ) /*0x1453ac*/
  {
    return 5; /*0x1453ae*/
  }
  return result; /*0x1453b6*/
}
