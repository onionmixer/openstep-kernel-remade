
/* WARNING: Removing unreachable block (ram,0xf005d478) */
/* WARNING: Removing unreachable block (ram,0xf005d460) */
/* WARNING: Removing unreachable block (ram,0xf005d494) */
/* WARNING: Removing unreachable block (ram,0xf005d3ec) */

undefined8
_ipc_right_copyin_two(int param_1,undefined4 param_2,uint *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  int iVar4;
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
  uVar3 = *param_3;
  iVar4 = 0;
  if (((uVar3 & 0x10000) == 0) || ((uVar3 & 0xffff) < 2)) {
    uVar5 = 0x11;
  }
  else {
    puVar2 = (undefined4 *)param_3[1];
    iVar1 = param_1;
    _ipc_right_check(param_1,puVar2,param_2,param_3);
    if (iVar1 == 0) {
      if ((uVar3 & 0xffff) == 2) {
        if ((uVar3 & 0x20000) == 0) {
          if (param_3[2] != 0) {
            iVar4 = param_1;
            _ipc_right_dncancel(param_1,puVar2,param_2,param_3);
          }
          _ipc_hash_delete(param_1,puVar2,param_2,param_3);
          if ((uVar3 & 0x200000) == 0) {
            iVar1 = puVar2[7];
          }
          else {
            _ipc_marequest_cancel(param_1,param_2);
            iVar1 = puVar2[7];
          }
          puVar2[7] = iVar1 + 1;
          puVar2[1] = puVar2[1] + 1;
          param_3[1] = 0;
        }
        else {
          puVar2[7] = puVar2[7] + 1;
          puVar2[1] = puVar2[1] + 2;
        }
        uVar3 = uVar3 & 0xfffe0000;
      }
      else {
        puVar2[7] = puVar2[7] + 2;
        puVar2[1] = puVar2[1] + 2;
        uVar3 = uVar3 - 2;
      }
      *param_3 = uVar3;
      *puVar2 = 0;
      *param_4 = puVar2;
      *param_5 = iVar4;
      uVar5 = 0;
    }
    else {
      uVar5 = 0xf;
      if ((uVar3 & 0x400000) == 0) {
        uVar5 = 0x11;
      }
    }
  }
  return CONCAT44(param_2,uVar5);
}

