/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012470c */

int FUN_0012470c(undefined4 param_1,int param_2,int param_3,char *param_4,void *param_5,int *param_6
                )

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  code *pcVar9;
  int local_90;
  int local_8c;
  int local_88;
  int local_7c;
  char *local_78;
  undefined4 local_74;
  char **local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  int local_58;
  uint local_54 [2];
  undefined2 local_4c;
  undefined2 local_4a;
  undefined4 local_48;
  undefined4 local_3c [14];
  
  bVar2 = false;
  bVar1 = false;
  _microtime(local_54);
  uVar3 = *(byte *)((int)param_5 + 5) ^ local_54[0];
  *(uint *)(param_3 + 0x20) = uVar3;
  local_4c = 2;
  local_4a = 0x4300;
  local_48 = 0xffffffff;
  local_88 = 1;
  local_8c = 0;
  local_90 = 0;
LAB_001247a4:
  if (local_8c == 0) {
    uVar4 = _in_bootp_bptombuf(param_3);
    iVar5 = _if_output_mbuf(param_1,uVar4,&local_4c);
    if (iVar5 != 0) goto LAB_00124a43;
  }
  puVar7 = (undefined4 *)(DAT_001e875c + 0x28);
  puVar8 = local_3c;
  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar5 = _set_label((int *)(DAT_001e875c + 0x28));
  if (iVar5 == 0) {
    local_58 = param_2;
    pcVar9 = FUN_00124de0;
LAB_00124846:
    _timeout((int)pcVar9);
LAB_00124850:
    while( true ) {
      local_78 = param_4;
      local_74 = 300;
      local_70 = &local_78;
      local_6c = 1;
      local_64 = 1;
      local_68 = 0;
      local_5c = 300;
      iVar5 = _soreceive(param_2,0,&local_70,0,0);
      if ((iVar5 != 0x23) || (param_2 != local_58)) break;
      _sbwait(local_58 + 0x24);
    }
    if ((iVar5 != 0) && (iVar5 != 0x23)) {
      puVar7 = local_3c;
      puVar8 = (undefined4 *)(DAT_001e875c + 0x28);
      for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      _untimeout(FUN_00124de0,&local_58);
      goto LAB_00124a43;
    }
    if (local_58 != 0) {
      if ((*(uint *)(param_4 + 4) != uVar3) || (*param_4 != '\x02')) goto LAB_00124850;
      iVar5 = _bcmp(param_4 + 0x1c,param_5,6);
      if (iVar5 != 0) goto LAB_00124850;
      if ((*(char *)(param_3 + 0x10e) == '\0') && (param_4[0xf2] != '\0')) {
        if (!bVar1) goto code_r0x001249cf;
        if (local_7c == 1) goto LAB_00124850;
      }
      puVar7 = local_3c;
      puVar8 = (undefined4 *)(DAT_001e875c + 0x28);
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      _untimeout(FUN_00124de0,&local_58);
      if (bVar2) {
        _printf(s_Network_responded__001dbb2e);
      }
      iVar5 = 0;
      goto LAB_00124a43;
    }
    puVar7 = local_3c;
    puVar8 = (undefined4 *)(DAT_001e875c + 0x28);
    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    local_8c = local_8c + 1;
    local_90 = local_90 + 1;
    if (local_88 == local_8c) {
      if (local_8c < 0x40) {
        local_88 = local_8c * 2;
      }
      local_8c = 0;
    }
    if (local_90 == 0x14) {
      if (*param_6 == 0) {
        iVar5 = FUN_00124a60(param_6);
        if (iVar5 != 0) goto LAB_00124a43;
      }
      _printf(s_No_response_from_network_configu_001dbaba);
      bVar2 = true;
    }
    goto LAB_001247a4;
  }
  puVar7 = local_3c;
  puVar8 = (undefined4 *)(DAT_001e875c + 0x28);
  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  _untimeout(FUN_00124de0,&local_58);
  iVar5 = 4;
LAB_00124a43:
  _untimeout(FUN_00124dfc,&local_7c);
  return iVar5;
code_r0x001249cf:
  bVar1 = true;
  local_7c = 1;
  pcVar9 = FUN_00124dfc;
  goto LAB_00124846;
}

