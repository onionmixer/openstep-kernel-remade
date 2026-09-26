
/* WARNING: Removing unreachable block (ram,0xf00ea9f0) */
/* WARNING: Removing unreachable block (ram,0xf00ea9ac) */
/* WARNING: Removing unreachable block (ram,0xf00ea974) */
/* WARNING: Removing unreachable block (ram,0xf00ea9bc) */
/* WARNING: Removing unreachable block (ram,0xf00eaa10) */
/* WARNING: Removing unreachable block (ram,0xf00ea938) */

undefined8
-[HashTable _insertKeyNoRehash:value:]
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  iVar6 = param_1[5];
  iVar1 = param_1[2];
  sub_F00EA210(iVar1,param_3,param_1[4]);
  iVar5 = *(int *)(iVar6 + iVar1 * 8);
  *(int *)((int)register0x00000038 + -0x18) = iVar5;
  puVar2 = *(undefined4 **)(iVar6 + iVar1 * 8 + 4);
  *(undefined4 **)((int)register0x00000038 + -0x14) = puVar2;
  do {
    iVar5 = iVar5 + -1;
    if (iVar5 == -1) {
      puVar2 = param_1;
      _objc_msgSend(param_1,paZone);
      puVar4 = param_1;
      _objc_msgSend(param_1,paZone);
      (*(code *)puVar2[1])();
      if (*(int *)((int)register0x00000038 + -0x18) != 0) {
        _memmove(puVar4 + 2,*(undefined4 *)((int)register0x00000038 + -0x14),
                 *(int *)((int)register0x00000038 + -0x18) << 3);
      }
      *puVar4 = param_3;
      puVar4[1] = param_4;
      if (*(int *)((int)register0x00000038 + -0x18) != 0) {
        _free(*(undefined4 *)((int)register0x00000038 + -0x14));
      }
      iVar1 = iVar1 * 8;
      *(int *)(iVar6 + iVar1) = *(int *)(iVar6 + iVar1) + 1;
      *(undefined4 **)(iVar6 + iVar1 + 4) = puVar4;
      param_1[1] = param_1[1] + 1;
      uVar7 = 0;
locret_F00EAA40:
      return CONCAT44(param_2,uVar7);
    }
    iVar3 = param_1[2];
    sub_F00EA2E8(iVar3,param_3,*puVar2);
    if (iVar3 != 0) {
      uVar7 = puVar2[1];
      *puVar2 = param_3;
      puVar2[1] = param_4;
      goto locret_F00EAA40;
    }
    puVar2 = puVar2 + 2;
  } while( true );
}

