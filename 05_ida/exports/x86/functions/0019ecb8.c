/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19ecb8. */
_DWORD *FBAllocateVBEConsole()
{
  _DWORD *v1; // ebx
  int v2; // eax
  _DWORD v3[34]; // [esp+Ch] [ebp-88h] BYREF

  if ( !MEMORY[0x1285C] || !MEMORY[0x12854] ) /*0x19ecd5*/
    return nullptr; /*0x19ecd7*/
  VBEModeInfo2IODisplayInfo(75864, v3); /*0x19ecec*/
  v3[5] = MEMORY[0x12854]; /*0x19ecf7*/
  v1 = (_DWORD *)IOMalloc(0x20u); /*0x19ed04*/
  if ( !v1 ) /*0x19ed0b*/
    return nullptr; /*0x19ed0d*/
  v2 = IOMalloc(0xE4u); /*0x19ed19*/
  v1[7] = v2; /*0x19ed1e*/
  if ( v2 ) /*0x19ed26*/
  {
    *v1 = sub_19EFA8; /*0x19ed34*/
    v1[1] = sub_19DF7C; /*0x19ed3a*/
    v1[2] = sub_19EFCC; /*0x19ed41*/
    v1[3] = sub_19E23C; /*0x19ed48*/
    v1[4] = sub_19E7CC; /*0x19ed4f*/
    v1[5] = sub_19F050; /*0x19ed56*/
    v1[6] = sub_19F068; /*0x19ed5d*/
    qmemcpy((void *)(v1[7] + 4), v3, 0x88u); /*0x19ed70*/
    *(_DWORD *)v1[7] = 0; /*0x19ed75*/
    return v1; /*0x19ed7b*/
  }
  else
  {
    IOFree((int)v1, 32); /*0x19ed2b*/
    return nullptr; /*0x19ed30*/
  }
}
