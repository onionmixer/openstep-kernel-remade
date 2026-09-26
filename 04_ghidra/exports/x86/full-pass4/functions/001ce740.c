/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ce740 */

void _objc_unregisterModule(mach_header *param_1,code *param_2)

{
  int *piVar1;
  uint32_t uVar2;
  char *pcVar3;
  uint32_t uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int local_1c;
  uint32_t local_c;
  uint32_t local_8;
  
  pcVar5 = _getsectdatafromheader(param_1,"__OBJC","__module_info",&local_8);
  pcVar10 = pcVar5;
  for (uVar2 = local_8; (pcVar3 = pcVar5, uVar4 = local_8, pcVar10 != (char *)0x0 && (uVar2 != 0));
      uVar2 = uVar2 - *piVar1) {
    local_1c = *(int *)(pcVar10 + 0xc);
    uVar8 = (uint)*(ushort *)(local_1c + 8);
    if (uVar8 < *(ushort *)(local_1c + 10) + uVar8) {
      do {
        iVar7 = *(int *)(local_1c + 0xc + uVar8 * 4);
        if (param_2 != (code *)0x0) {
          uVar6 = _objc_getClass(*(undefined4 *)(iVar7 + 4),iVar7);
          (*param_2)(uVar6);
        }
        FUN_001ce014(iVar7);
        uVar8 = uVar8 + 1;
        local_1c = *(int *)(pcVar10 + 0xc);
      } while ((int)uVar8 <
               (int)((uint)*(ushort *)(local_1c + 8) + (uint)*(ushort *)(local_1c + 10)));
    }
    piVar1 = (int *)(pcVar10 + 4);
    pcVar10 = pcVar10 + *(int *)(pcVar10 + 4);
  }
  for (; (pcVar10 = pcVar5, uVar2 = local_8, pcVar3 != (char *)0x0 && (uVar4 != 0));
      uVar4 = uVar4 - *piVar1) {
    iVar7 = *(int *)(pcVar3 + 0xc);
    iVar9 = 0;
    if (*(short *)(iVar7 + 8) != 0) {
      do {
        uVar6 = *(undefined4 *)(iVar7 + 0xc + iVar9 * 4);
        if (param_2 != (code *)0x0) {
          (*param_2)(uVar6,0);
        }
        FUN_001cdfd8(uVar6);
        iVar9 = iVar9 + 1;
        iVar7 = *(int *)(pcVar3 + 0xc);
      } while (iVar9 < (int)(uint)*(ushort *)(iVar7 + 8));
    }
    piVar1 = (int *)(pcVar3 + 4);
    pcVar3 = pcVar3 + *(int *)(pcVar3 + 4);
  }
  for (; (uVar4 = local_8, pcVar10 != (char *)0x0 && (uVar2 != 0)); uVar2 = uVar2 - *piVar1) {
    local_1c = *(int *)(pcVar10 + 0xc);
    uVar8 = (uint)*(ushort *)(local_1c + 8);
    if (uVar8 < *(ushort *)(local_1c + 10) + uVar8) {
      do {
        __objc_remove_category(*(undefined4 *)(local_1c + 0xc + uVar8 * 4),*(undefined4 *)pcVar10);
        uVar8 = uVar8 + 1;
        local_1c = *(int *)(pcVar10 + 0xc);
      } while ((int)uVar8 <
               (int)((uint)*(ushort *)(local_1c + 8) + (uint)*(ushort *)(local_1c + 10)));
    }
    piVar1 = (int *)(pcVar10 + 4);
    pcVar10 = pcVar10 + *(int *)(pcVar10 + 4);
  }
  for (; (pcVar5 != (char *)0x0 && (uVar4 != 0)); uVar4 = uVar4 - *piVar1) {
    iVar7 = *(int *)(pcVar5 + 0xc);
    iVar9 = 0;
    if (*(short *)(iVar7 + 8) != 0) {
      do {
        __objc_removeClass(*(undefined4 *)(iVar7 + 0xc + iVar9 * 4));
        iVar9 = iVar9 + 1;
        iVar7 = *(int *)(pcVar5 + 0xc);
      } while (iVar9 < (int)(uint)*(ushort *)(iVar7 + 8));
    }
    piVar1 = (int *)(pcVar5 + 4);
    pcVar5 = pcVar5 + *(int *)(pcVar5 + 4);
  }
  pcVar10 = _getsectdatafromheader(param_1,"__OBJC","__meth_var_names",&local_c);
  if (pcVar10 != (char *)0x0) {
    __sel_unloadSelectors(pcVar10,pcVar10 + local_c);
  }
  pcVar10 = _getsectdatafromheader(param_1,"__OBJC","__selector_strs",&local_c);
  if (pcVar10 != (char *)0x0) {
    __sel_unloadSelectors(pcVar10,pcVar10 + local_c);
  }
  __objc_removeHeader(param_1);
  return;
}

