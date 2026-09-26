
/* WARNING: Removing unreachable block (ram,0xf004367c) */

undefined8
_pmap_kgetport(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  *(undefined2 *)((int)register0x00000038 + -0x2a) = 0;
  uVar5 = 0;
  if (word_F012F52C == 0) {
    iVar4 = 0xf;
    iVar3 = 0x1e;
    do {
      *(undefined2 *)(unk_F012F536 + iVar3) = 0xffff;
      iVar4 = iVar4 + -1;
      iVar3 = iVar3 + -2;
    } while (-1 < iVar4);
    word_F012F52C = word_F012F52C + 1;
  }
  piVar1 = (int *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x28) = *param_1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_1[1];
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1[2];
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_1[3];
  *(undefined2 *)((int)register0x00000038 + -0x26) = 0x6f;
  _clntkudp_create(piVar1,100000,2,4,&word_F012F52C);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x18) = param_2;
    *(undefined4 *)((int)register0x00000038 + -0x14) = param_3;
    *(undefined4 *)((int)register0x00000038 + -0x10) = param_4;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x38) = dword_F010DD40;
    *(undefined4 *)((int)register0x00000038 + -0x34) = DAT_f010dd44;
    piVar2 = piVar1;
    (**(code **)piVar1[1])();
    if (piVar2 == (int *)0x0) {
      if (*(sword *)((int)register0x00000038 + -0x2a) == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        *(sword *)((int)param_1 + 2) = *(sword *)((int)register0x00000038 + -0x2a);
      }
    }
    else {
      uVar5 = 1;
    }
    (**(code **)(*(int *)(*piVar1 + 0x20) + 0x10))();
    (**(code **)(piVar1[1] + 0x10))(piVar1);
  }
  return CONCAT44(param_2,uVar5);
}
