/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170b60 */

void FUN_00170b60(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e04d4)) {
    uVar1 = _convert_port_to_space(param_1[2]);
    uVar2 = _port_status(uVar1,param_1[7],param_2 + 0x24,param_2 + 0x2c,param_2 + 0x34,
                         param_2 + 0x3c,param_2 + 0x44);
    *(undefined4 *)(param_2 + 0x1c) = uVar2;
    _space_deallocate(uVar1);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x48;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e04d8;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e04dc;
      *(undefined4 *)(param_2 + 0x30) = DAT_001e04e0;
      *(undefined4 *)(param_2 + 0x38) = DAT_001e04e4;
      *(undefined4 *)(param_2 + 0x40) = DAT_001e04e8;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

