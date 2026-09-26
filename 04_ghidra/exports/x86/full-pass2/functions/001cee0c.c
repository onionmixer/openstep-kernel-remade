/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cee0c */

int * _objc_getModules(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  if (DAT_001e874c == (int *)0x0) {
    uVar4 = 0;
    if (DAT_001e55fc != 0) {
      do {
        DAT_001e8748 = DAT_001e8748 + *(int *)(DAT_001e55f8 + 8 + uVar4 * 0x18);
        uVar4 = uVar4 + 1;
      } while (uVar4 < DAT_001e55fc);
    }
    iVar1 = __objc_create_zone();
    uVar2 = __objc_create_zone((DAT_001e8748 + 1) * 4);
    DAT_001e874c = (int *)(**(code **)(iVar1 + 4))(uVar2);
    if (DAT_001e874c == (int *)0x0) {
      __objc_fatal("unable to allocate module vector");
    }
    uVar4 = 0;
    piVar5 = DAT_001e874c;
    if (DAT_001e55fc != 0) {
      do {
        iVar1 = *(int *)(DAT_001e55f8 + 4 + uVar4 * 0x18);
        uVar3 = 0;
        if (*(int *)(DAT_001e55f8 + 8 + uVar4 * 0x18) != 0) {
          do {
            *piVar5 = uVar3 * 0x10 + iVar1;
            uVar3 = uVar3 + 1;
            piVar5 = piVar5 + 1;
          } while (uVar3 < *(uint *)(DAT_001e55f8 + 8 + uVar4 * 0x18));
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < DAT_001e55fc);
    }
    *piVar5 = 0;
  }
  return DAT_001e874c;
}

