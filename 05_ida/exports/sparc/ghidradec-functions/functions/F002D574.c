
/* WARNING: Removing unreachable block (ram,0xf002d650) */
/* WARNING: Removing unreachable block (ram,0xf002d618) */
/* WARNING: Removing unreachable block (ram,0xf002d5e4) */
/* WARNING: Removing unreachable block (ram,0xf002d5c8) */
/* WARNING: Removing unreachable block (ram,0xf002d608) */
/* WARNING: Removing unreachable block (ram,0xf002d630) */
/* WARNING: Removing unreachable block (ram,0xf002d67c) */
/* WARNING: Removing unreachable block (ram,0xf002d584) */

undefined8 _arpwhohas(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l3;
  undefined *puVar4;
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
  iVar1 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *param_3;
  _m_get(0,1);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    *(undefined2 *)((int)register0x00000038 + -0x18) = 0x806;
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    puVar4 = (undefined *)((int)register0x00000038 + -0x18);
    _bcopy(puVar4,puVar4 + (uint)DAT_f010c358[0] * 2 + 2,2);
    _bcopy((uint)DAT_f010c358[0] + (uint)DAT_f010c358[1] + -0xfef3ca4,
           (undefined *)((int)register0x00000038 + -0x16));
    iVar3 = 0x7c - *(sword *)(iVar1 + 8);
    *(int *)(iVar1 + 4) = iVar3;
    iVar2 = iVar1 + iVar3;
    _bcopy(_arpethertempl,iVar2,(int)*(sword *)(iVar1 + 8));
    _bcopy(param_2,iVar2 + 8,DAT_f010c358[0]);
    _bcopy((undefined *)((int)register0x00000038 + -0x1c),iVar2 + DAT_f010c358[0] + 8,
           DAT_f010c358[1]);
    _bcopy(param_4,iVar2 + (uint)DAT_f010c358[0] * 2 + (uint)DAT_f010c358[1] + 8);
    *(undefined2 *)(iVar1 + iVar3) = *(undefined2 *)(iVar1 + iVar3);
    *(undefined2 *)(iVar2 + 2) = *(undefined2 *)(iVar2 + 2);
    *(undefined2 *)(iVar2 + 6) = *(undefined2 *)(iVar2 + 6);
    *(undefined2 *)((int)register0x00000038 + -0x18) = 0;
    _if_output_mbuf(param_1,iVar1,puVar4);
  }
  return CONCAT44(param_2,param_1);
}

