/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171a24 */

void FUN_00171a24(int *param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_c;
  uint *local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0760)) {
    puVar1 = param_2 + 0xd;
    local_c = 0x200;
    if ((uint)param_1[7] < 0x200) {
      local_c = param_1[7];
    }
    local_8 = puVar1;
    uVar2 = _convert_port_to_host(param_1[2],param_2 + 9,&local_8,&local_c);
    uVar3 = _host_ipc_marequest_info(uVar2);
    param_2[7] = uVar3;
    if (uVar3 == 0) {
      param_2[8] = DAT_001e0764;
      param_2[10] = DAT_001e0768;
      param_2[0xb] = (uint)PTR_s__62I__001e076c;
      param_2[0xc] = DAT_001e0770;
      if (local_8 != puVar1) {
        *(byte *)((int)param_2 + 0x2b) = *(byte *)((int)param_2 + 0x2b) & 0xef | 0x40;
        param_2[0xd] = (uint)local_8;
      }
      param_2[0xc] = local_c;
      if ((*(byte *)((int)param_2 + 0x2b) & 0x10) == 0) {
        uVar3 = 0x38;
      }
      else {
        uVar3 = local_c * 4 + 0x34;
      }
      param_2[1] = uVar3;
      if (local_8 != puVar1) {
        *param_2 = *param_2 | 0x80000000;
      }
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

