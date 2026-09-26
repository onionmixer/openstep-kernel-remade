
/* WARNING: Removing unreachable block (ram,0xf002c4e8) */
/* WARNING: Removing unreachable block (ram,0xf002c474) */
/* WARNING: Removing unreachable block (ram,0xf002c488) */
/* WARNING: Removing unreachable block (ram,0xf002c4f0) */
/* WARNING: Removing unreachable block (ram,0xf002c458) */

undefined8 _raw_attach(int param_1,undefined4 param_2)

{
  int iVar1;
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
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  _m_getclr(0,4);
  if (iVar1 == 0) {
    uVar5 = 0x37;
  }
  else {
    iVar4 = param_1 + 0x3c;
    iVar3 = iVar4;
    _sbreserve(iVar4,0x800);
    iVar2 = param_1 + 0x24;
    if (iVar3 != 0) {
      _sbreserve(iVar2,0x824);
      if (iVar2 != 0) {
        iVar2 = *(int *)(iVar1 + 4);
        iVar3 = iVar1 + iVar2;
        *(int *)(iVar3 + 8) = param_1;
        *(int *)(param_1 + 8) = iVar3;
        *(undefined4 *)(iVar3 + 0x30) = 0;
        *(sword *)(iVar3 + 0x2c) = (sword)**(undefined4 **)(*(int *)(param_1 + 0xc) + 4);
        *(sword *)(iVar3 + 0x2e) = (sword)param_2;
        *(int *)(iVar1 + iVar2) = _rawcb;
        *(int **)(iVar3 + 4) = &_rawcb;
        uVar5 = 0;
        *(int *)(_rawcb + 4) = iVar3;
        _rawcb = iVar3;
        goto locret_F002C4FC;
      }
      _sbrelease(iVar4);
    }
    _m_free(iVar1);
    uVar5 = 0x37;
  }
locret_F002C4FC:
  return CONCAT44(param_2,uVar5);
}

