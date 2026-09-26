/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001876d8 */

uint _PMSetPowerManagement(int param_1,int param_2)

{
  undefined1 local_34 [4];
  undefined1 local_30;
  byte local_2f;
  undefined2 local_2c;
  ushort local_28;
  undefined2 local_14;
  undefined2 local_12;
  byte local_c;
  undefined4 local_8;
  
  if (DAT_001e75b8 == 0) {
    return 0x3e80003;
  }
  if (param_1 != 1) {
    return 0x3e80009;
  }
  local_2f = 0x53;
  local_30 = 8;
  local_14 = 0x78;
  local_12 = 0x10;
  local_8 = DAT_001e75b4;
  local_28 = (ushort)(param_2 != 0);
  local_2c = 0xffff;
  _bios32(local_34);
  if ((local_c & 1) == 0) {
    return 0;
  }
  if (local_2f == 0) {
    return 0x3e80101;
  }
  return local_2f | 0x3e80000;
}

