
void sub_40635B6(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  
  if (param_1._0_1_ != '\0') {
    iVar1 = 0;
    if (0 < dword_40B06E8) {
      puVar3 = unk_40B4E40;
      do {
        if (param_1._0_1_ == *puVar3) {
          uVar2 = *(uint *)puVar3 & 0xffffff;
          if (uVar2 < (param_1 & 0xffffff)) {
            uVar2 = param_1 & 0xffffff;
          }
          *(uint *)puVar3 = uVar2 | *(uint *)puVar3 & 0xff000000;
          return;
        }
        puVar3 = (undefined *)((int)puVar3 + 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < dword_40B06E8);
    }
    *(uint *)(unk_40B4E40 + dword_40B06E8 * 4) = param_1;
    dword_40B06E8 = dword_40B06E8 + 1;
  }
  return;
}

