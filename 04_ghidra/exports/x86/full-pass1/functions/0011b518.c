/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b518 */

void _dnlc_enterSymLink(char *param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  
  sVar2 = param_3[2];
  if (sVar2 != 0) {
    uVar6 = 0xffffffff;
    pcVar7 = param_1;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar4 = ~uVar6 - 1;
    if (iVar4 < 0x21) {
      iVar4 = FUN_0011b8dc(param_2,param_1,iVar4,
                           (int)*param_1 + (int)param_1[~uVar6 - 2] + iVar4 + param_2 & 0x3f,
                           0xffffffff);
    }
    else {
      iVar4 = 0;
    }
    if (iVar4 != 0) {
      if (*(char *)(iVar4 + 0x44) != '\0') {
        if ((param_3[2] == (int)*(short *)(iVar4 + 0x46)) &&
           (iVar5 = _bcmp((void *)*param_3,*(void **)(iVar4 + 0x40),(int)*(short *)(iVar4 + 0x46)),
           iVar5 == 0)) {
          return;
        }
        _kfree(*(undefined4 *)(iVar4 + 0x40),(int)*(short *)(iVar4 + 0x46));
      }
      iVar5 = _kalloc(sVar2);
      *(int *)(iVar4 + 0x40) = iVar5;
      if (iVar5 != 0) {
        *(undefined1 *)(iVar4 + 0x44) = 1;
        *(short *)(iVar4 + 0x46) = (short)sVar2;
        _bcopy((void *)*param_3,*(void **)(iVar4 + 0x40),sVar2);
        *(undefined4 *)(*(int *)(iVar4 + 0xc) + 8) = *(undefined4 *)(iVar4 + 8);
        *(undefined4 *)(*(int *)(iVar4 + 8) + 0xc) = *(undefined4 *)(iVar4 + 0xc);
        iVar3 = DAT_001e9bec;
        iVar5 = *(int *)(DAT_001e9bec + 8);
        *(int *)(DAT_001e9bec + 8) = iVar4;
        *(int *)(iVar4 + 8) = iVar5;
        *(int *)(iVar5 + 0xc) = iVar4;
        *(int *)(iVar4 + 0xc) = iVar3;
      }
    }
  }
  return;
}

