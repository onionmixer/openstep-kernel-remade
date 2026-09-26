/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182c34 */

void FUN_00182c34(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if ((((param_1[1] == 0x6c) && (-1 < *param_1)) && (param_1[6] == DAT_001e1144)) &&
     ((param_1[8] == DAT_001e1148 && (param_1[0x19] == DAT_001e114c)))) {
    local_8 = 0x200;
    uVar1 = _convert_port_to_host
                      (param_1[2],param_1[7],param_1 + 9,param_1[0x1a],param_2 + 0x24,&local_8);
    iVar2 = _kern_IOGetCharValues(uVar1);
    *(int *)(param_2 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x20) = DAT_001e1150;
      *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) & 0xf000 | (ushort)local_8 & 0xfff;
      *(uint *)(param_2 + 4) = (local_8 + 3U & 0xfffffffc) + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

