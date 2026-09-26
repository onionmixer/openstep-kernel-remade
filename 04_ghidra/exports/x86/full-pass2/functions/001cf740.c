/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf740 */

void * __objc_headerVector(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint local_8;
  
  pvVar3 = DAT_001e55f8;
  if (DAT_001e55f8 == (void *)0x0) {
    iVar5 = 0;
    iVar1 = *param_1;
    while (iVar1 != 0) {
      DAT_001e55fc = DAT_001e55fc + 1;
      iVar5 = iVar5 + 1;
      iVar1 = param_1[iVar5];
    }
    iVar1 = __objc_create_zone();
    uVar2 = __objc_create_zone(DAT_001e55fc * 0x18);
    pvVar3 = (void *)(**(code **)(iVar1 + 4))(uVar2);
    if (pvVar3 == (void *)0x0) {
      __objc_fatal("unable to allocate module vector");
    }
    uVar6 = 0;
    if (DAT_001e55fc != 0) {
      do {
        iVar1 = uVar6 * 0x18;
        *(int *)((int)pvVar3 + iVar1) = param_1[uVar6];
        *(undefined4 *)((int)pvVar3 + iVar1 + 0x10) = 0;
        pcVar4 = _getsectdatafromheader
                           ((mach_header *)param_1[uVar6],"__OBJC","__module_info",&local_8);
        *(char **)((int)pvVar3 + iVar1 + 4) = pcVar4;
        *(uint *)((int)pvVar3 + iVar1 + 8) = local_8 >> 4;
        pcVar4 = _getsectdatafromheader
                           ((mach_header *)param_1[uVar6],"__OBJC","__runtime_setup",&local_8);
        *(char **)((int)pvVar3 + iVar1 + 0xc) = pcVar4;
        iVar5 = FUN_001cf6b0(param_1[uVar6]);
        if (iVar5 == 0) {
          *(undefined4 *)((int)pvVar3 + uVar6 * 0x18 + 0x14) = 0;
        }
        else {
          *(undefined4 *)((int)pvVar3 + iVar1 + 0x14) = *(undefined4 *)(iVar5 + 0x24);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < DAT_001e55fc);
    }
    _qsort(pvVar3,DAT_001e55fc,0x18,(int *)FUN_001cf6fc);
  }
  return pvVar3;
}

