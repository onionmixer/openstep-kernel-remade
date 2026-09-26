
/* WARNING: Removing unreachable block (ram,0xf0041d4c) */
/* WARNING: Removing unreachable block (ram,0xf0041cd8) */
/* WARNING: Removing unreachable block (ram,0xf0041ccc) */
/* WARNING: Removing unreachable block (ram,0xf0041c58) */
/* WARNING: Removing unreachable block (ram,0xf0041c80) */
/* WARNING: Removing unreachable block (ram,0xf0041cf0) */
/* WARNING: Removing unreachable block (ram,0xf0041d74) */
/* WARNING: Removing unreachable block (ram,0xf0041c24) */

undefined8 sub_F0041C1C(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  piVar1 = param_1;
  sub_F0041784(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    uVar4 = 0;
    goto locret_F0041D8C;
  }
  if ((*param_1 == 0) && (*(int *)(param_2 + 0x4c) != 0)) {
    piVar1 = param_1;
    _spltty();
    puVar2 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x1;
      _m_more(1,1);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_16);
      }
      *(undefined2 *)((int)puVar2 + 10) = 1;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
      _mfree = (undefined4 *)*puVar2;
      puVar2[1] = 0xc;
      *puVar2 = 0;
    }
    _splx(piVar1);
    if (puVar2 == (undefined4 *)0x0) {
      _printf(aXdrRrokFailedC);
      uVar4 = 0;
      goto locret_F0041D8C;
    }
    iVar3 = puVar2[1];
    *(code **)((int)puVar2 + iVar3) = sub_F0041AF0;
    iVar3 = (int)puVar2 + iVar3;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 0x50);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_2 + 0x4c);
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_2 + 0x44);
    param_1[2] = iVar3;
    piVar1 = param_1;
    _xdrmbuf_putbuf(param_1,*(undefined4 *)(param_2 + 0x48),*(undefined4 *)(param_2 + 0x44),
                    sub_F0041C00,iVar3);
    if (piVar1 != (int *)0x0) {
      uVar4 = 1;
      goto locret_F0041D8C;
    }
    *(undefined4 *)(iVar3 + 4) = 1;
  }
  _xdr_bytes(param_1,param_2 + 0x48,param_2 + 0x44,0x2000);
  uVar4 = 1;
  if (param_1 == (int *)0x0) {
    uVar4 = 0;
  }
locret_F0041D8C:
  return CONCAT44(param_2,uVar4);
}
