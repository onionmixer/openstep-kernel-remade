/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001874ec */

uint _PMSetPowerState(int param_1,int param_2)

{
  uint uVar1;
  undefined1 local_34 [4];
  undefined1 local_30;
  byte local_2f;
  ushort local_2c;
  undefined2 local_28;
  undefined2 local_14;
  undefined2 local_12;
  byte local_c;
  undefined4 local_8;
  
  if (param_1 == 1) {
    __io_setDriverPowerState(param_2);
  }
  if (DAT_001e75b8 == 0) {
    uVar1 = 0x3e80003;
  }
  else if ((param_1 == 1) && ((param_2 == 0 || (param_2 == 3)))) {
    uVar1 = 0x3e80060;
  }
  else {
    local_2f = 0x53;
    local_30 = 7;
    local_14 = 0x78;
    local_12 = 0x10;
    local_8 = DAT_001e75b4;
    local_2c = (ushort)param_1 & 0xff | (ushort)((uint)param_1 >> 8) & 0xff00;
    local_28 = (undefined2)param_2;
    _bios32(local_34);
    if ((local_c & 1) == 0) {
      uVar1 = 0;
    }
    else if (local_2f == 0) {
      uVar1 = 0x3e80101;
    }
    else {
      uVar1 = local_2f | 0x3e80000;
    }
  }
  return uVar1;
}

