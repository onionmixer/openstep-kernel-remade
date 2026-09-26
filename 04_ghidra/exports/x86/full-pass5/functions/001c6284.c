/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6284 */

void FUN_001c6284(undefined4 param_1,undefined4 param_2,uint *param_3,undefined2 *param_4)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  _objc_msgSend(param_1,PTR_s_setWritePlane__001f95d0,1);
  uVar1 = *param_3;
  bVar2 = (byte)uVar1;
  uVar4 = uVar1 >> 0x10;
  bVar3 = (byte)(uVar1 >> 0x10);
  *param_4 = CONCAT11(~((byte)(uVar1 >> 0x1f) | (byte)((uVar4 & 0x2000) >> 0xc) |
                        (byte)((uVar4 & 0x800) >> 9) | (byte)((uVar4 & 0x200) >> 6) |
                        (byte)((uVar4 & 0x80) >> 3) | bVar3 & 0x20 | (bVar3 & 8) << 3 |
                       (bVar3 & 0xaa) << 6),
                      ~((byte)((uVar1 & 0x8000) >> 0xf) | (byte)((uVar1 & 0x2000) >> 0xc) |
                        (byte)((uVar1 & 0x800) >> 9) | (byte)((uVar1 & 0x200) >> 6) |
                        (byte)((uVar1 & 0x80) >> 3) | bVar2 & 0x20 | (bVar2 & 8) << 3 |
                       (bVar2 & 0xaa) << 6));
  _objc_msgSend(param_1,PTR_s_setWritePlane__001f95d0,0);
  uVar1 = *param_3;
  bVar2 = (byte)uVar1;
  uVar4 = uVar1 >> 0x10;
  bVar3 = (byte)(uVar1 >> 0x10);
  *param_4 = CONCAT11(~((byte)((uVar4 & 0x4000) >> 0xe) | (byte)((uVar4 & 0x1000) >> 0xb) |
                        (byte)(uVar1 >> 0x18) & 4 | (byte)((uVar4 & 0x100) >> 5) |
                        (byte)((uVar4 & 0x40) >> 2) | (bVar3 & 0x10) * '\x02' | (bVar3 & 4) << 4 |
                       bVar3 << 7),
                      ~((byte)((uVar1 & 0x4000) >> 0xe) | (byte)((uVar1 & 0x1000) >> 0xb) |
                        (byte)(uVar1 >> 8) & 4 | (byte)((uVar1 & 0x100) >> 5) |
                        (byte)((uVar1 & 0x40) >> 2) | (bVar2 & 0x10) * '\x02' | (bVar2 & 4) << 4 |
                       bVar2 << 7));
  return;
}

