
/* WARNING: Removing unreachable block (ram,0xf00994a8) */
/* WARNING: Removing unreachable block (ram,0xf00993ec) */
/* WARNING: Removing unreachable block (ram,0xf0099494) */
/* WARNING: Removing unreachable block (ram,0xf00994b4) */
/* WARNING: Removing unreachable block (ram,0xf00993dc) */

undefined8
_bp_alloc(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  int iVar6;
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
  iVar4 = 0;
  uVar5 = 0xffffffff;
  uVar1 = 0;
  if (_vac != 0) {
    param_2 = *(uint *)(param_2 + 0x20);
    uVar1 = 0xf0119000;
    if (param_2 != 0) {
      uVar1 = param_2 & _shm_alignment - 1;
      uVar5 = uVar1 >> 0xc;
    }
  }
  if (uVar5 == 0xffffffff) {
    _splusclock();
    _rmalloc(param_1,param_3);
  }
  else {
    if (_vac != 0) {
      param_6 = (_shm_alignment >> 0xc) - 1;
    }
    puVar3 = (uint *)(param_1 + 8);
    if (*(int *)(param_1 + 8) != 0) {
      uVar1 = *puVar3;
      while( true ) {
        if (param_3 <= (int)uVar1) {
          uVar2 = puVar3[1];
          iVar4 = (uVar2 & ~param_6) + uVar5;
          if (iVar4 < (int)uVar2) {
            iVar4 = iVar4 + 1 + param_6;
          }
          if (iVar4 + param_3 <= (int)(uVar2 + uVar1)) {
            uVar1 = *puVar3;
            goto loc_F0099488;
          }
        }
        puVar3 = puVar3 + 2;
        if (*puVar3 == 0) break;
        uVar1 = *puVar3;
      }
    }
    uVar1 = *puVar3;
loc_F0099488:
    iVar6 = 0;
    if (uVar1 == 0) goto locret_F00994BC;
    _splusclock();
    _rmget(param_1,param_3,iVar4);
  }
  _splx(uVar1);
  iVar6 = param_1;
  param_2 = uVar1;
locret_F00994BC:
  return CONCAT44(param_2,iVar6);
}
