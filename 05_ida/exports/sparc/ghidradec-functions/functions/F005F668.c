
/* WARNING: Removing unreachable block (ram,0xf005f684) */

undefined8 _mach_port_dnrequest_info(int param_1,undefined4 param_2,uint *param_3,int *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
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
  if (param_1 == 0) {
    param_1 = 0x10;
  }
  else {
    _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      puVar1 = *(undefined4 **)((int)register0x00000038 + -0xc);
      iVar3 = puVar1[0xb];
      if (iVar3 == 0) {
        uVar5 = 0;
        iVar4 = 0;
      }
      else {
        uVar2 = 1;
        uVar5 = **(uint **)(iVar3 + 4);
        iVar4 = 0;
        if (1 < uVar5) {
          do {
            if (*(int *)(iVar3 + 0xc) != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar2 = uVar2 + 1;
            iVar3 = iVar3 + 8;
          } while (uVar2 < uVar5);
        }
        puVar1 = *(undefined4 **)((int)register0x00000038 + -0xc);
      }
      param_1 = 0;
      *puVar1 = 0;
      *param_3 = uVar5;
      *param_4 = iVar4;
    }
  }
  return CONCAT44(param_2,param_1);
}
