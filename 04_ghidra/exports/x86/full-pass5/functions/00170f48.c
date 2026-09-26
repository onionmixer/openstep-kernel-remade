/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170f48 */

void FUN_00170f48(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0520)) {
    uVar1 = _convert_port_to_space(param_1[2]);
    uVar2 = _port_extract_receive(uVar1,param_1[7],param_2 + 9);
    param_2[7] = uVar2;
    _space_deallocate(uVar1);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e0524;
      iVar3 = param_1[3];
      if (((iVar3 != 0) && (iVar3 != -1)) &&
         ((uVar2 = param_2[9], uVar2 != 0 && (uVar2 != 0xffffffff)))) {
        iVar3 = _ipc_port_check_circularity(uVar2,iVar3);
        if (iVar3 != 0) {
          *param_2 = *param_2 | 0x40000000;
        }
      }
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

