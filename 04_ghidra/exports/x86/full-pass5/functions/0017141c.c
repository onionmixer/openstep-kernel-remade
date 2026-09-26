/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017141c */

void FUN_0017141c(int *param_1,uint *param_2)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  uint local_814;
  undefined1 *local_810;
  uint local_80c;
  uint *local_808;
  undefined1 local_804 [2048];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e0728)) &&
     (param_1[8] == DAT_001e072c)) {
    puVar1 = param_2 + 0xb;
    local_80c = 0xaa;
    if ((uint)param_1[7] < 0xaa) {
      local_80c = param_1[7];
    }
    puVar2 = local_804;
    local_814 = 0x100;
    if ((uint)param_1[9] < 0x100) {
      local_814 = param_1[9];
    }
    local_810 = puVar2;
    local_808 = puVar1;
    uVar3 = _convert_port_to_host(param_1[2],&local_808,&local_80c,&local_810,&local_814);
    uVar4 = _host_zone_free_space_info(uVar3);
    param_2[7] = uVar4;
    if (uVar4 == 0) {
      param_2[8] = DAT_001e0730;
      param_2[9] = (uint)PTR_s__62I__001e0734;
      param_2[10] = DAT_001e0738;
      bVar6 = local_808 != puVar1;
      if (bVar6) {
        *(byte *)((int)param_2 + 0x23) = *(byte *)((int)param_2 + 0x23) & 0xef | 0x40;
        param_2[0xb] = (uint)local_808;
      }
      param_2[10] = local_80c * 3;
      iVar5 = 4;
      if ((*(byte *)((int)param_2 + 0x23) & 0x10) != 0) {
        iVar5 = local_80c * 0xc;
      }
      *(undefined4 *)((int)param_2 + iVar5 + 0x2c) = DAT_001e073c;
      *(undefined **)((int)param_2 + iVar5 + 0x30) = PTR_s__62I__001e0740;
      *(undefined4 *)((int)param_2 + iVar5 + 0x34) = DAT_001e0744;
      bVar7 = local_810 == puVar2;
      if (bVar7) {
        _memcpy((void *)((int)param_2 + iVar5 + 0x38),local_810,local_814 * 8);
      }
      else {
        *(byte *)((int)param_2 + iVar5 + 0x2f) =
             *(byte *)((int)param_2 + iVar5 + 0x2f) & 0xef | 0x40;
        *(undefined1 **)((int)param_2 + iVar5 + 0x38) = local_810;
      }
      *(uint *)((int)param_2 + iVar5 + 0x34) = local_814 * 2;
      if ((*(byte *)((int)param_2 + iVar5 + 0x2f) & 0x10) == 0) {
        uVar4 = iVar5 + 0x3c;
      }
      else {
        uVar4 = iVar5 + 0x38 + local_814 * 8;
      }
      if (!bVar7 || bVar6) {
        *param_2 = *param_2 | 0x80000000;
      }
      param_2[1] = uVar4;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

