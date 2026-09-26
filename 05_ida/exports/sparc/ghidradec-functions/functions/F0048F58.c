
/* WARNING: Removing unreachable block (ram,0xf0049068) */
/* WARNING: Removing unreachable block (ram,0xf004903c) */
/* WARNING: Removing unreachable block (ram,0xf0048ff8) */
/* WARNING: Removing unreachable block (ram,0xf0048fc0) */
/* WARNING: Removing unreachable block (ram,0xf0048fdc) */
/* WARNING: Removing unreachable block (ram,0xf0049014) */
/* WARNING: Removing unreachable block (ram,0xf0049048) */
/* WARNING: Removing unreachable block (ram,0xf004907c) */
/* WARNING: Removing unreachable block (ram,0xf0048fa8) */

undefined8 _ialloc(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar6;
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
  iVar4 = *(int *)(param_1 + 0x50);
  if (((*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) ||
      (*(int *)(iVar4 + 0x94) < *(int *)(iVar4 + 200))) && (*(int *)(iVar4 + 200) != 0)) {
    uVar5 = *(undefined4 *)(iVar4 + 0xb8);
    uVar1 = *(uint *)(iVar4 + 0x2c);
    .umul(uVar1,uVar5);
    uVar6 = param_2;
    if (uVar1 <= param_2) {
      uVar6 = 0;
    }
    uVar1 = uVar6;
    .udiv(uVar6,uVar5);
    param_2 = param_1;
    _hashalloc(param_1,uVar1,uVar6,param_3,_ialloccg);
    if (param_2 != 0) {
      iVar2 = (int)*(sword *)(param_1 + 0x46);
      _iget(iVar2,*(undefined4 *)(param_1 + 0x50),param_2);
      if (iVar2 == 0) {
        _ifree(param_1,param_2,0);
        iVar2 = 0;
      }
      else {
        if (*(sword *)(iVar2 + 100) == 0) {
          iVar3 = *(int *)(iVar2 + 0xcc);
        }
        else {
          _printf(aMode0OInumDFsS,*(sword *)(iVar2 + 100),*(undefined4 *)(iVar2 + 0x48),iVar4 + 0xd4
                 );
          _panic(aIallocDupAlloc);
          iVar3 = *(int *)(iVar2 + 0xcc);
        }
        if (iVar3 != 0) {
          _printf(aFreeInodeSDHad,iVar4 + 0xd4,param_2);
          *(undefined4 *)(iVar2 + 0xcc) = 0;
        }
        *(undefined4 *)(iVar2 + 200) = 0;
      }
      goto locret_F0049088;
    }
  }
  _fsfull(iVar4,2);
  iVar2 = 0;
locret_F0049088:
  return CONCAT44(param_2,iVar2);
}
