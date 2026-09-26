/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c60d4 */

void FUN_001c60d4(undefined4 param_1,undefined4 param_2,ushort *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  _objc_msgSend(param_1,PTR_s_setReadPlane__001f95d4,1);
  uVar1 = (uint)(ushort)~*param_3;
  _objc_msgSend(param_1,PTR_s_setReadPlane__001f95d4,0);
  uVar2 = (uint)(ushort)~*param_3;
  *param_4 = (uVar1 & 0x8000) << 2 | (uVar1 & 0x4000) << 5 | (uVar1 & 0x2000) << 8 |
             (uVar1 & 0x1000) << 0xb | (uVar1 & 0x800) << 0xe | (uVar1 & 0x400) << 0x11 |
             (uVar1 & 0x200) << 0x14 | (uVar1 & 0x100) << 0x17 | (uVar1 & 0x80) >> 6 |
             (uVar1 & 0x40) >> 3 | uVar1 & 0x20 | (uVar1 & 0x10) << 3 | (uVar1 & 8) << 6 |
             (uVar1 & 4) << 9 | (uVar1 & 2) << 0xc | (uVar1 & 1) << 0xf |
             (uVar2 & 0x8000) * 2 | (uVar2 & 0x4000) << 4 | (uVar2 & 0x2000) << 7 |
             (uVar2 & 0x1000) << 10 | (uVar2 & 0x800) << 0xd | (uVar2 & 0x400) << 0x10 |
             (uVar2 & 0x200) << 0x13 | (uVar2 & 0x100) << 0x16 | (uVar2 & 0x80) >> 7 |
             (uVar2 & 0x40) >> 4 | (uVar2 & 0x20) >> 1 | (uVar2 & 0x10) << 2 | (uVar2 & 8) << 5 |
             (uVar2 & 4) << 8 | (uVar2 & 2) << 0xb | (uVar2 & 1) << 0xe;
  return;
}

