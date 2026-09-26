
/* WARNING: Removing unreachable block (ram,0xf00d3198) */
/* WARNING: Removing unreachable block (ram,0xf00d3150) */
/* WARNING: Removing unreachable block (ram,0xf00d3184) */
/* WARNING: Removing unreachable block (ram,0xf00d3168) */

undefined8
-[EventDriver evDispatch:command:](int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined (*pauVar1) [21];
  int iVar2;
  undefined (*pauVar3) [24];
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar6;
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
  
  pauVar1 = paSetbrightnessT;
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
  iVar5 = *(int *)(param_1 + 0x180);
  iVar4 = param_3 * 0x14;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    iVar2 = *(int *)(param_1 + 0x168);
    *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar2 + 0x18);
    *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar2 + 0x1a);
    if (*(int *)(iVar5 + iVar4) != 0) {
      pauVar3 = paShowcursorFram;
      if (param_4 != 2) {
        if (param_4 < 3) {
          if (param_4 == 1) {
            _objc_msgSend(*(undefined4 *)(iVar5 + iVar4),paHidecursor,param_3 + 0x100);
          }
          goto locret_F00D31A0;
        }
        pauVar3 = paMovecursorFram;
        if (param_4 != 3) {
          if (param_4 == 4) {
            uVar6 = *(undefined4 *)(iVar5 + iVar4);
            iVar4 = param_1;
            _objc_msgSend(param_1,paCurrentbrightn);
            _objc_msgSend(uVar6,pauVar1,iVar4,param_3 + 0x100);
          }
          goto locret_F00D31A0;
        }
      }
      _objc_msgSend(*(undefined4 *)(iVar5 + iVar4),pauVar3,
                    (undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x1c),param_3 + 0x100);
    }
  }
locret_F00D31A0:
  return CONCAT44(param_2,param_1);
}

