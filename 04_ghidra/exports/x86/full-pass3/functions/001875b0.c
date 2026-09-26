/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001875b0 */

uint _PMGetPowerEvent(uint *param_1)

{
  uint uVar1;
  undefined1 local_38 [4];
  undefined1 local_34;
  byte local_33;
  ushort local_30;
  undefined2 local_18;
  undefined2 local_16;
  byte local_10;
  undefined4 local_c;
  ushort local_6;
  
  if (DAT_001e75b8 == 0) {
    uVar1 = 0x3e80003;
  }
  else {
    local_33 = 0x53;
    local_34 = 0xb;
    local_18 = 0x78;
    local_16 = 0x10;
    local_c = DAT_001e75b4;
    _bios32(local_38);
    if ((local_10 & 1) == 0) {
      local_6 = local_30;
    }
    else {
      if (local_33 == 0) {
        uVar1 = 0x3e80101;
      }
      else {
        uVar1 = local_33 | 0x3e80000;
      }
      if (uVar1 != 0) {
        return uVar1;
      }
    }
    *param_1 = (uint)local_6;
    uVar1 = 0;
  }
  return uVar1;
}

