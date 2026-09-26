
/* WARNING: Removing unreachable block (ram,0xf0037b4c) */
/* WARNING: Removing unreachable block (ram,0xf0037b24) */
/* WARNING: Removing unreachable block (ram,0xf0037a8c) */
/* WARNING: Removing unreachable block (ram,0xf0037a04) */
/* WARNING: Removing unreachable block (ram,0xf0037b78) */
/* WARNING: Removing unreachable block (ram,0xf0037c10) */
/* WARNING: Removing unreachable block (ram,0xf0037ad8) */
/* WARNING: Removing unreachable block (ram,0xf0037b40) */
/* WARNING: Removing unreachable block (ram,0xf0037c50) */
/* WARNING: Removing unreachable block (ram,0xf0037b68) */

undefined8 _tcp_timers(int param_1,uint param_2)

{
  word wVar1;
  int iVar2;
  sword sVar4;
  uint uVar3;
  undefined2 uVar5;
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
  if (param_2 == 1) {
    DAT_f013a7c4._8_4_ = DAT_f013a7c4._8_4_ + 1;
    _tcp_setpersist(param_1);
    *(undefined *)(param_1 + 0x1a) = 1;
    _tcp_output(param_1);
    *(undefined *)(param_1 + 0x1a) = 0;
    goto locret_F0037C5C;
  }
  if ((int)param_2 < 2) {
    if (param_2 != 0) goto locret_F0037C5C;
    sVar4 = *(sword *)(param_1 + 0x12) + 1;
    *(sword *)(param_1 + 0x12) = sVar4;
    if (sVar4 < 0xd) {
      DAT_f013a7c4._4_4_ = DAT_f013a7c4._4_4_ + 1;
      iVar2 = ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x13) +
              (int)*(sword *)(param_1 + 0x62);
      .umul(iVar2,*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4));
      sVar4 = (sword)iVar2;
      *(sword *)(param_1 + 0x14) = sVar4;
      if ((int)sVar4 < (int)(uint)*(word *)(param_1 + 100)) {
        *(word *)(param_1 + 0x14) = *(word *)(param_1 + 100);
      }
      else if (0x80 < sVar4) {
        *(undefined2 *)(param_1 + 0x14) = 0x80;
      }
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x14);
      if (3 < *(sword *)(param_1 + 0x12)) {
        _in_losing(*(undefined4 *)(param_1 + 0x20));
        *(sword *)(param_1 + 0x62) = *(sword *)(param_1 + 0x62) + (*(sword *)(param_1 + 0x60) >> 2);
        *(undefined2 *)(param_1 + 0x60) = 0;
      }
      *(undefined2 *)(param_1 + 0x5a) = 0;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      uVar3 = (uint)*(word *)(param_1 + 0x3c);
      if ((uint)*(word *)(param_1 + 0x54) < (uint)*(word *)(param_1 + 0x3c)) {
        uVar3 = (uint)*(word *)(param_1 + 0x54);
      }
      wVar1 = *(word *)(param_1 + 0x18);
      param_2 = (uint)wVar1;
      uVar3 = uVar3 >> 1;
      .div(uVar3,param_2);
      if (uVar3 < 2) {
        uVar3 = 2;
      }
      uVar5 = (undefined2)uVar3;
      *(word *)(param_1 + 0x54) = wVar1;
      *(undefined2 *)(param_1 + 0x16) = 0;
      .umul();
      *(undefined2 *)(param_1 + 0x56) = uVar5;
      _tcp_output(param_1);
      goto locret_F0037C5C;
    }
    *(undefined2 *)(param_1 + 0x12) = 0xc;
    DAT_f013a7c4._0_4_ = DAT_f013a7c4._0_4_ + 1;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        if ((*(sword *)(param_1 + 8) == 10) || (_tcp_maxidle < *(sword *)(param_1 + 0x58))) {
          _tcp_close(param_1);
        }
        else {
          *(sword *)(param_1 + 0x10) = (sword)_tcp_keepintvl;
        }
      }
      goto locret_F0037C5C;
    }
    DAT_f013a7c4._12_4_ = DAT_f013a7c4._12_4_ + 1;
    if (3 < *(sword *)(param_1 + 8)) {
      if (((*(word *)(*(int *)(*(int *)(param_1 + 0x20) + 0x1c) + 2) & 8) == 0) ||
         (5 < *(sword *)(param_1 + 8))) {
        *(sword *)(param_1 + 0xe) = (sword)_tcp_keepidle;
        goto locret_F0037C5C;
      }
      if ((int)*(sword *)(param_1 + 0x58) < _tcp_keepidle + _tcp_maxidle) {
        DAT_f013a7c4._16_4_ = DAT_f013a7c4._16_4_ + 1;
        _tcp_respond(param_1,*(undefined4 *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 0x40),
                     *(int *)(param_1 + 0x24) + -1,0);
        *(sword *)(param_1 + 0xe) = (sword)_tcp_keepintvl;
        goto locret_F0037C5C;
      }
    }
    DAT_f013a7c4._20_4_ = DAT_f013a7c4._20_4_ + 1;
  }
  _tcp_drop(param_1,0x3c);
locret_F0037C5C:
  return CONCAT44(param_2,param_1);
}
