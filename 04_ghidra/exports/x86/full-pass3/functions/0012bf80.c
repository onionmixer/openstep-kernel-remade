/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012bf80 */

void _igmp_fasttimo(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  if (DAT_001dbf44 != 0) {
    uVar4 = _splnet();
    DAT_001dbf44 = 0;
    local_8 = 0;
    iVar5 = 0;
    local_c = _in_ifaddr;
    while (local_c != 0) {
      iVar5 = *(int *)(local_c + 0x44);
      local_c = *(int *)(local_c + 0x40);
      if (iVar5 != 0) goto LAB_0012c009;
    }
LAB_0012c030:
    if (iVar5 != 0) {
      iVar2 = *(int *)(iVar5 + 0x10);
      iVar3 = local_8;
      if (iVar2 != 0) {
        *(int *)(iVar5 + 0x10) = iVar2 + -1;
        if (iVar2 == 1) {
          _igmp_sendreport(iVar5);
        }
        else {
          DAT_001dbf44 = 1;
        }
      }
      while (iVar5 = iVar3, iVar5 == 0) {
        if (local_c == 0) goto LAB_0012c030;
        piVar1 = (int *)(local_c + 0x44);
        local_c = *(int *)(local_c + 0x40);
        iVar3 = *piVar1;
      }
LAB_0012c009:
      local_8 = *(int *)(iVar5 + 0x14);
      goto LAB_0012c030;
    }
    _splx(uVar4);
  }
  return;
}

