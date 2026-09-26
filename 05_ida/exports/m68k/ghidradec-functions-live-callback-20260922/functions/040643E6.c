
undefined4 sub_40643E6(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  word unaff_D2w;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar5 = (uint *)(_slot_id + 0x2208028);
  puVar4 = (undefined4 *)(_slot_id + 0x2208020);
  uVar3 = *(uint *)(_slot_id + 0x2208000);
  *(uint *)(_slot_id + 0x2208000) = uVar3;
  uVar2 = *puVar5;
  *puVar4 = 0x10;
  if (dword_40B0858 == 0) {
    if ((uVar3 & 4) == 0) {
      if ((uVar2 & 0x20) != 0) {
        return 1;
      }
    }
    else {
      iVar1 = dword_40B0834 * 10;
      if ((uVar2 & 8) != 0) {
        uVar3 = *(uint *)(_slot_id + 0x2208038) >> 3;
        if (uVar3 != 0) {
          uStack_c = *(undefined4 *)(_slot_id + 0x2208080);
        }
        if (4 < uVar3) {
          uStack_8 = *(undefined4 *)(_slot_id + 0x2208088);
        }
        (**(code **)(unk_40B0838 + *(int *)((int)&unk_40B4E92 + iVar1) * 4))(&uStack_c,uVar3);
      }
      if ((uVar2 & 2) == 0) {
        dword_40B0834 = dword_40B0830;
      }
      else {
        dword_40B0834 = *(uint *)((int)&dword_40B4E98 + iVar1);
      }
    }
    sub_40645EA(unaff_D2w & 0xcff | (word)((dword_40B0834 & 0xf) << 0xc) | 0xc00,0,0,0);
  }
  return 1;
}

