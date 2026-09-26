/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018762c */

uint _PMGetPowerStatus(uint *param_1)

{
  uint uVar1;
  undefined1 local_38 [4];
  undefined1 local_34;
  byte local_33;
  undefined2 local_30;
  byte local_2c;
  undefined2 local_18;
  undefined2 local_16;
  byte local_10;
  undefined4 local_c;
  byte local_7;
  byte local_6;
  byte local_5;
  
  if (DAT_001e75b8 == 0) {
    uVar1 = 0x3e80003;
  }
  else {
    local_33 = 0x53;
    local_34 = 10;
    local_18 = 0x78;
    local_16 = 0x10;
    local_c = DAT_001e75b4;
    local_30 = 1;
    _bios32(local_38);
    if ((local_10 & 1) == 0) {
      local_5 = local_30._1_1_;
      local_6 = (byte)local_30;
      local_7 = local_2c;
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
    *param_1 = (uint)local_5;
    param_1[1] = (uint)local_6;
    uVar1 = 0xffffffff;
    if (local_7 != 0xff) {
      uVar1 = (uint)local_7;
    }
    param_1[2] = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}

