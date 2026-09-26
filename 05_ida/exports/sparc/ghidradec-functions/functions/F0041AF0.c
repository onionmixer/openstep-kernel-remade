
/* WARNING: Removing unreachable block (ram,0xf0041bd0) */
/* WARNING: Removing unreachable block (ram,0xf0041b68) */
/* WARNING: Removing unreachable block (ram,0xf0041b44) */
/* WARNING: Removing unreachable block (ram,0xf0041b10) */
/* WARNING: Removing unreachable block (ram,0xf0041b28) */
/* WARNING: Removing unreachable block (ram,0xf0041b4c) */
/* WARNING: Removing unreachable block (ram,0xf0041bac) */
/* WARNING: Removing unreachable block (ram,0xf0041bf0) */
/* WARNING: Removing unreachable block (ram,0xf0041af4) */

qword sub_F0041AF0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar4;
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
  uVar1 = param_1;
  _spltty();
  iVar3 = *(int *)(param_1 + 4);
  while (iVar3 == 0) {
    _sleep(param_1,0x18);
    iVar3 = *(int *)(param_1 + 4);
  }
  _splx(uVar1);
  (**(code **)(*(int *)(*(int *)(param_1 + 8) + 0x1c) + 0x5c))
            (*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  uVar2 = *(undefined4 *)(param_1 + 8);
  _vn_rele(uVar2);
  puVar4 = (undefined4 *)(param_1 & 0xffffff80);
  _spltty();
  if (*(sword *)((int)puVar4 + 10) == 0) {
    _panic(&aMfree_8);
  }
  iVar3 = (int)((uint)*(word *)((int)puVar4 + 10) << 0x10) >> 0xf;
  *(sword *)((int)&word_F0134B0C + iVar3) = *(sword *)((int)&word_F0134B0C + iVar3) + -1;
  word_F0134B0C = word_F0134B0C + 1;
  *(undefined2 *)((int)puVar4 + 10) = 0;
  if (0x7f < (uint)puVar4[1]) {
    _mclput(puVar4);
  }
  puVar4[1] = 0;
  puVar4[0x1f] = 0;
  *puVar4 = _mfree;
  _mfree = puVar4;
  _splx(uVar2);
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
  return CONCAT44(param_2,param_1) & 0xffffffffffffff80;
}
