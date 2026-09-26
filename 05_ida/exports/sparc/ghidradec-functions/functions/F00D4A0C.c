
/* WARNING: Removing unreachable block (ram,0xf00d4ab8) */
/* WARNING: Removing unreachable block (ram,0xf00d4ac8) */
/* WARNING: Removing unreachable block (ram,0xf00d4a64) */

undefined8
-[EventDriver keyboardEvent:flags:keyCode:charCode:charSet:originalCharCode:originalCharSet:repeat:atTime:]
          (int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined2 param_5,
          undefined2 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *(undefined2 *)((int)register0x00000038 + -0x18) = param_5;
  uVar2 = *(uint *)((int)register0x00000038 + 0x6c);
  uVar3 = *(uint *)((int)register0x00000038 + 0x70);
  *(undefined2 *)((int)register0x00000038 + -0x1a) = param_6;
  *(sword *)((int)register0x00000038 + -0x1e) =
       (sword)(char)*(undefined4 *)((int)register0x00000038 + 0x68);
  *(sword *)((int)register0x00000038 + -0x1c) =
       (sword)*(undefined4 *)((int)register0x00000038 + 0x5c);
  *(sword *)((int)register0x00000038 + -0x20) =
       (sword)*(undefined4 *)((int)register0x00000038 + 100);
  *(sword *)((int)register0x00000038 + -0x16) =
       (sword)*(undefined4 *)((int)register0x00000038 + 0x60);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock,
                *(undefined4 *)((int)register0x00000038 + 0x5c),
                *(undefined4 *)((int)register0x00000038 + 100),uVar2 >> 0x18);
  uVar1 = paPosteventAtAtt;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
         *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_4 & 0x7f007f;
    _objc_msgSend(param_1,uVar1,param_3,param_1 + 0x1a8,uVar2 << 8 | uVar3 >> 0x18,
                  (undefined *)((int)register0x00000038 + -0x20));
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  return CONCAT44(param_2,param_1);
}
