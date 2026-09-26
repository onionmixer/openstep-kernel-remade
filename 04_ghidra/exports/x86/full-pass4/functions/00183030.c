/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00183030 */

void FUN_00183030(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e118c)) {
    local_8 = 0x1000;
    uVar1 = _convert_port_to_host(param_1[2],param_1[7],param_2 + 0x2c,&local_8);
    iVar2 = _kern_IOGetSystemConfig(uVar1);
    *(int *)(param_2 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x20) = DAT_001e1190;
      *(undefined4 *)(param_2 + 0x24) = DAT_001e1194;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e1198;
      *(int *)(param_2 + 0x28) = local_8;
      *(uint *)(param_2 + 4) = (local_8 + 3U & 0xfffffffc) + 0x2c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

