
/* WARNING: Removing unreachable block (ram,0xf0029728) */
/* WARNING: Removing unreachable block (ram,0xf0029708) */
/* WARNING: Removing unreachable block (ram,0xf00296d0) */
/* WARNING: Removing unreachable block (ram,0xf0029664) */
/* WARNING: Removing unreachable block (ram,0xf0029604) */
/* WARNING: Removing unreachable block (ram,0xf00295e0) */
/* WARNING: Removing unreachable block (ram,0xf002961c) */
/* WARNING: Removing unreachable block (ram,0xf00296c0) */
/* WARNING: Removing unreachable block (ram,0xf00296ec) */
/* WARNING: Removing unreachable block (ram,0xf0029720) */
/* WARNING: Removing unreachable block (ram,0xf00297a4) */
/* WARNING: Removing unreachable block (ram,0xf00295c4) */

undefined8
_physio(undefined4 param_1,uint *param_2,undefined2 param_3,uint param_4,code *param_5,int *param_6)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint *puVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 uVar6;
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
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar5 = 0;
  do {
    if (param_6[1] == 0) {
      puVar4 = (uint *)0x0;
locret_F00297E8:
      return CONCAT44(param_2,puVar4);
    }
    puVar4 = (uint *)*param_6;
    uVar1 = 1;
    if (param_6[3] != 1) {
      uVar1 = *puVar4;
      _useracc(uVar1,puVar4[1],param_4 != 1);
      if (uVar1 == 0) {
        puVar4 = (uint *)0xe;
        goto locret_F00297E8;
      }
    }
    _spltty();
    uVar2 = *param_2;
    while ((uVar2 & 8) != 0) {
      *param_2 = uVar2 | 0x40;
      _sleep(param_2,0x15);
      uVar2 = *param_2;
    }
    _splx(uVar1);
    *(undefined2 *)(param_2 + 7) = 0;
    param_2[0xb] = *_active_u;
    param_2[8] = *puVar4;
    if ((int)puVar4[1] < 1) {
      uVar1 = *param_2;
    }
    else {
      do {
        *param_2 = param_4 | 0x18;
        *(undefined2 *)((int)param_2 + 0x1e) = param_3;
        uVar2 = param_6[2];
        .udiv(uVar2,uVar6);
        param_2[9] = uVar2;
        param_2[5] = puVar4[1];
        (*param_5)(param_2);
        uVar2 = param_2[5];
        if (param_6[3] == 1) {
          *param_2 = *param_2 | 0x4000000;
        }
        else {
          *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x800;
          uVar5 = param_2[8];
          _vslock(uVar5,uVar2);
        }
        _physstrat(param_2,param_1,0x14);
        if (param_6[3] != 1) {
          _vsunlock(uVar5,uVar2,param_4);
          *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) & 0xfffff7ff;
        }
        _spltty();
        if ((*param_2 & 0x40) != 0) {
          _wakeup(param_2);
        }
        _splx(uVar1);
        iVar3 = uVar2 - param_2[10];
        param_2[8] = param_2[8] + iVar3;
        puVar4[1] = puVar4[1] - iVar3;
        param_6[5] = param_6[5] - iVar3;
        param_6[2] = param_6[2] + iVar3;
        if (param_2[10] != 0) {
          uVar1 = *param_2;
          goto loc_F002979C;
        }
        if ((*param_2 & 4) != 0) {
          uVar1 = *param_2;
          goto loc_F002979C;
        }
      } while (0 < (int)puVar4[1]);
      uVar1 = *param_2;
    }
loc_F002979C:
    *param_2 = uVar1 & 0xffffffa7;
    puVar4 = param_2;
    _geterror();
    if ((param_2[10] != 0) || (puVar4 != (uint *)0x0)) goto locret_F00297E8;
    *param_6 = *param_6 + 8;
    param_6[1] = param_6[1] + -1;
  } while( true );
}
