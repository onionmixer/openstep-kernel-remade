
undefined4 _sel_isMapped(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined (*pauVar4) [28];
  
  pauVar4 = off_F012F16C;
  if (param_1 != 0) {
    while (pauVar4 != (undefined (*) [28])0x0) {
      if (((undefined (*) [28])0xf012f14f < pauVar4) && (pauVar4 < unk_F012F150)) {
        return 1;
      }
      if (pauVar4 == &unk_F012F150) {
        uVar3 = 0;
        pauVar4 = (undefined (*) [28])DAT_f012f154._20_4_;
        if (DAT_f012f154._0_4_ != 0) {
          iVar1 = 0;
          do {
            piVar2 = *(int **)(DAT_f012f154._16_4_ + iVar1);
            if (piVar2 != (int *)0x0) {
              iVar1 = piVar2[1];
              while( true ) {
                if (param_1 == iVar1) {
                  return 1;
                }
                piVar2 = (int *)*piVar2;
                if (piVar2 == (int *)0x0) break;
                iVar1 = piVar2[1];
              }
            }
            uVar3 = uVar3 + 1;
            iVar1 = uVar3 * 4;
          } while (uVar3 < (uint)DAT_f012f154._0_4_);
        }
      }
      else {
        pauVar4 = *(undefined (**) [28])(*pauVar4 + 0x18);
      }
    }
  }
  return 0;
}

