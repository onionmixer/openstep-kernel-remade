
/* WARNING: Removing unreachable block (ram,0xf00f3964) */

void __sel_unloadSelectors(void)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (uVar2 < (uint)DAT_f012f154._0_4_) {
    if (*(int *)(uVar2 * 4 + DAT_f012f164._0_4_) == 0) {
      uVar2 = uVar2 + 1;
    }
    else {
      piVar1 = *(int **)(uVar2 * 4 + DAT_f012f164._0_4_);
      do {
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
      uVar2 = uVar2 + 1;
    }
  }
  return;
}
