
/* WARNING: Removing unreachable block (ram,0xf00ef7b0) */
/* WARNING: Removing unreachable block (ram,0xf00ef848) */
/* WARNING: Removing unreachable block (ram,0xf00ef82c) */
/* WARNING: Removing unreachable block (ram,0xf00ef814) */
/* WARNING: Removing unreachable block (ram,0xf00ef804) */
/* WARNING: Removing unreachable block (ram,0xf00ef7f0) */
/* WARNING: Removing unreachable block (ram,0xf00ef7e0) */
/* WARNING: Removing unreachable block (ram,0xf00ef740) */
/* WARNING: Removing unreachable block (ram,0xf00ef7e8) */
/* WARNING: Removing unreachable block (ram,0xf00ef7fc) */
/* WARNING: Removing unreachable block (ram,0xf00ef80c) */
/* WARNING: Removing unreachable block (ram,0xf00ef820) */
/* WARNING: Removing unreachable block (ram,0xf00ef838) */
/* WARNING: Removing unreachable block (ram,0xf00ef898) */
/* WARNING: Removing unreachable block (ram,0xf00ef778) */
/* WARNING: Removing unreachable block (ram,0xf00ef734) */

undefined8 _class_poseAs(int *param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
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
  __objc_headerCount();
  __objc_headerVector(0);
  if (param_1 != param_2) {
    if ((int *)param_1[1] == param_2) {
      if (param_1[6] == 0) {
        *(undefined2 *)((int)register0x00000038 + -0x108) = 0x5f25;
        *(undefined *)((int)register0x00000038 + -0x106) = 0;
        puVar4 = (undefined *)((int)register0x00000038 + -0x108);
        _strcat(puVar4,param_2[2]);
        _strlen(puVar4);
        sub_F00EFBA0(puVar4 + 1);
        _strcpy();
        sub_F00EF6A4(param_2);
        piVar2 = param_1;
        sub_F00EF6A4(param_1);
        _objc_getClasses();
        _NXHashRemove();
        _NXHashRemove(piVar2,param_2);
        piVar3 = param_1;
        _object_copy(param_1,0);
        _NXHashInsert(piVar2,piVar3);
        param_1[4] = param_1[4] | 8;
        *(uint *)(*param_1 + 0x10) = *(uint *)(*param_1 + 0x10) | 8;
        param_1[2] = param_2[2];
        *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_2 + 8);
        param_1[3] = param_2[3];
        _NXInitHashState((undefined *)((int)register0x00000038 + -0x110),piVar2);
                    /* WARNING: Does not return */
        pcVar1 = (code *)IllegalInstructionTrap(8);
        (*pcVar1)();
      }
      _objc_msgSend(param_1,paError,aSPoseasSSDefin,param_1[2],param_2[2],param_1[2]);
    }
    else {
      _objc_msgSend(param_1,paError,aSPoseasSTarget,param_1[2],param_2[2]);
    }
  }
  return CONCAT44(param_2,param_1);
}
