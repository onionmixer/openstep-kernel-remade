
/* WARNING: Removing unreachable block (ram,0xf0017e8c) */
/* WARNING: Removing unreachable block (ram,0xf0017e78) */
/* WARNING: Removing unreachable block (ram,0xf0017e14) */
/* WARNING: Removing unreachable block (ram,0xf0017e84) */
/* WARNING: Removing unreachable block (ram,0xf0017e94) */
/* WARNING: Removing unreachable block (ram,0xf0017da0) */

undefined8 _ttyclose(undefined *param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  puVar1 = param_1;
  _ttynty();
  if (param_1 == _cons_tp) {
    _cons_tp = _cons;
    (**(code **)(DAT_f011ca00 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))
              ((int)(sword)*(word *)(param_1 + 0x38),0x20006b08,0,0);
  }
  _ttyflush(param_1,3);
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  puVar1 = (undefined *)_active_u[0x59];
  if (puVar1 == param_1) {
    puVar1 = (undefined *)(*(uint *)(*_active_u + 0x28) & 0xbfffffff);
    *(undefined **)(*_active_u + 0x28) = puVar1;
    *(undefined2 *)(param_1 + 0x44) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x44) = 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  param_1[0x47] = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  _spltty();
  _selthreadclear(param_1 + 0x2c);
  _selthreadclear(param_1 + 0x28);
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}

