/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171248 */

void FUN_00171248(int *param_1,uint *param_2)

{
  zone_name_array_t pzVar1;
  zone_info_t *pzVar2;
  host_priv_t host;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  zone_name_array_t *names;
  mach_msg_type_number_t *namesCnt;
  zone_info_t **info;
  mach_msg_type_number_t *infoCnt;
  mach_msg_type_number_t local_7f4;
  zone_info_t *local_7f0;
  mach_msg_type_number_t local_7ec;
  zone_name_array_t local_7e8;
  zone_info_t local_7e4 [56];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e0708)) &&
     (param_1[8] == DAT_001e070c)) {
    pzVar1 = (zone_name_array_t)(param_2 + 0xb);
    local_7ec = 0x19;
    if ((uint)param_1[7] < 0x19) {
      local_7ec = param_1[7];
    }
    pzVar2 = local_7e4;
    local_7f4 = 0x38;
    if ((uint)param_1[9] < 0x38) {
      local_7f4 = param_1[9];
    }
    infoCnt = &local_7f4;
    info = &local_7f0;
    namesCnt = &local_7ec;
    names = &local_7e8;
    local_7f0 = pzVar2;
    local_7e8 = pzVar1;
    host = _convert_port_to_host(param_1[2]);
    uVar3 = _host_zone_info(host,names,namesCnt,info,infoCnt);
    param_2[7] = uVar3;
    if (uVar3 == 0) {
      param_2[8] = DAT_001e0710;
      param_2[9] = DAT_001e0714;
      param_2[10] = DAT_001e0718;
      bVar4 = local_7e8 != pzVar1;
      if (bVar4) {
        *(byte *)((int)param_2 + 0x23) = *(byte *)((int)param_2 + 0x23) & 0xef | 0x40;
        param_2[0xb] = (uint)local_7e8;
      }
      param_2[10] = local_7ec * 0x50;
      uVar3 = 4;
      if ((*(byte *)((int)param_2 + 0x23) & 0x10) != 0) {
        uVar3 = local_7ec * 0x50;
      }
      *(undefined4 *)((int)param_2 + uVar3 + 0x2c) = DAT_001e071c;
      *(undefined **)((int)param_2 + uVar3 + 0x30) = PTR_s__62I__001e0720;
      *(undefined4 *)((int)param_2 + uVar3 + 0x34) = DAT_001e0724;
      bVar5 = local_7f0 == pzVar2;
      if (bVar5) {
        _memcpy((void *)((int)param_2 + uVar3 + 0x38),local_7f0,local_7f4 * 0x24);
      }
      else {
        *(byte *)((int)param_2 + uVar3 + 0x2f) =
             *(byte *)((int)param_2 + uVar3 + 0x2f) & 0xef | 0x40;
        *(zone_info_t **)((int)param_2 + uVar3 + 0x38) = local_7f0;
      }
      *(mach_msg_type_number_t *)((int)param_2 + uVar3 + 0x34) = local_7f4 * 9;
      if ((*(byte *)((int)param_2 + uVar3 + 0x2f) & 0x10) == 0) {
        uVar3 = uVar3 + 0x3c;
      }
      else {
        uVar3 = uVar3 + 0x38 + local_7f4 * 0x24;
      }
      if (!bVar5 || bVar4) {
        *param_2 = *param_2 | 0x80000000;
      }
      param_2[1] = uVar3;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

