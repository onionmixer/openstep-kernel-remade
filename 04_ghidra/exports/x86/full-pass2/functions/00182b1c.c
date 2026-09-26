/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182b1c */

void FUN_00182b1c(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_1[1] == 0x6c) && (-1 < *param_1)) && (param_1[6] == DAT_001e1128)) {
    uVar1 = _convert_port_to_host(param_1[2],param_1 + 7,param_2 + 0x24,param_2 + 0x2c);
    iVar2 = _kern_IOLookupByDeviceName(uVar1);
    *(int *)(param_2 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 4) = 0x7c;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e112c;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e1130;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

