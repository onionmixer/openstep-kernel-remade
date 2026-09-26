
/* WARNING: Removing unreachable block (ram,0xf00c0e0c) */
/* WARNING: Removing unreachable block (ram,0xf00c0d60) */
/* WARNING: Removing unreachable block (ram,0xf00c0e04) */
/* WARNING: Removing unreachable block (ram,0xf00c0e14) */
/* WARNING: Removing unreachable block (ram,0xf00c0d44) */

undefined8 _kbdopen(uint param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar2 = 0;
  puVar1 = _kbddata;
  do {
    iVar2 = iVar2 + 1;
    if (*(int *)(puVar1 + 0x1c) == param_2) {
      iVar2 = 0;
      goto locret_F00C0E1C;
    }
    puVar1 = puVar1 + 0x2c;
  } while (iVar2 < 4);
  iVar2 = 0;
  puVar1 = _kbddata;
  do {
    iVar2 = iVar2 + 1;
    if (*(int *)(puVar1 + 0x1c) == 0) {
      _stop_mon_clock();
      _hz = 100;
      iVar4 = (int)(sword)param_1;
      _zsopen(iVar4,1);
      _kbddevopen = 1;
      iVar3 = ((param_1 & 0xffff) >> 8) * 0x2c;
      iVar2 = iVar4;
      (**(code **)(DAT_f011ca00 + iVar3))
                (iVar4,0x40067408,(undefined *)((int)register0x00000038 + -0x10),0);
      if (iVar2 == 0) {
        *(undefined2 *)((int)register0x00000038 + -0xc) = 0x20;
        *(undefined *)((int)register0x00000038 + -0xf) = 9;
        *(undefined *)((int)register0x00000038 + -0x10) = 9;
        (**(code **)(DAT_f011ca00 + iVar3))
                  (iVar4,0x80067409,(undefined *)((int)register0x00000038 + -0x10),0);
        iVar2 = iVar4;
        if (iVar4 == 0) {
          *(int *)(puVar1 + 0x1c) = param_2;
          *(undefined4 *)(puVar1 + 0x18) = 1;
          *(undefined4 *)(puVar1 + 0x14) = 3;
          _kbd_setwrite();
          _kbdreset(param_2);
          _sunmouse_init();
        }
      }
      goto locret_F00C0E1C;
    }
    puVar1 = puVar1 + 0x2c;
  } while (iVar2 < 4);
  iVar2 = 0x10;
locret_F00C0E1C:
  return CONCAT44(param_2,iVar2);
}
