
/* WARNING: Removing unreachable block (ram,0xf0017d60) */
/* WARNING: Removing unreachable block (ram,0xf0017d1c) */
/* WARNING: Removing unreachable block (ram,0xf0017cf4) */
/* WARNING: Removing unreachable block (ram,0xf0017cb0) */
/* WARNING: Removing unreachable block (ram,0xf0017bb8) */
/* WARNING: Removing unreachable block (ram,0xf0017cdc) */
/* WARNING: Removing unreachable block (ram,0xf0017d6c) */
/* WARNING: Removing unreachable block (ram,0xf0017d48) */
/* WARNING: Removing unreachable block (ram,0xf0017d74) */
/* WARNING: Removing unreachable block (ram,0xf0017ba0) */

sqword _ttyopen(undefined2 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
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
  uVar1 = param_2;
  _ttynty();
  puVar7 = (uint *)*_active_u;
  iVar2 = (int)*(sword *)(puVar7 + 0xc);
  _get_posix_proc();
  if ((puVar7[5] & 0x4000) == 0) {
    puVar3 = _active_u;
    if ((puVar7[10] & 0x40000000) != 0) goto loc_F0017CF4;
    _active_u[0x59] = param_2;
    *(undefined2 *)(_active_u + 0x5a) = param_1;
    *(undefined4 *)(uVar1 + 8) = *(undefined4 *)(*(int *)(iVar2 + 0x10) + 8);
    *(uint *)(*(int *)(*(int *)(iVar2 + 0x10) + 8) + 8) = param_2;
    iVar5 = (int)*(sword *)(param_2 + 0x44);
    if (iVar5 == 0) {
      _enterpgrp(puVar7,(int)*(sword *)(puVar7 + 0xc),1);
      *(undefined4 *)(uVar1 + 0xc) = *(undefined4 *)(iVar2 + 0x10);
      *(sword *)(param_2 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0xc);
    }
    else if (iVar5 != *(sword *)((int)puVar7 + 0x2e)) {
      _enterpgrp(puVar7,iVar5,0);
    }
    uVar4 = puVar7[10];
  }
  else {
    iVar5 = *(int *)(*(int *)(iVar2 + 0x10) + 8);
    puVar3 = *(uint **)(iVar5 + 4);
    if ((((puVar3 != puVar7) || (puVar3 = *(uint **)(iVar5 + 8), puVar3 != (uint *)0x0)) ||
        (puVar3 = *(uint **)(uVar1 + 8), *(uint **)(uVar1 + 8) != (uint *)0x0)) ||
       (puVar3 = _active_u, (*(uint *)(iVar2 + 0x18) & 0x40000000) != 0)) goto loc_F0017CF4;
    _active_u[0x59] = param_2;
    *(undefined2 *)(_active_u + 0x5a) = param_1;
    *(undefined4 *)(uVar1 + 8) = *(undefined4 *)(*(int *)(iVar2 + 0x10) + 8);
    *(uint *)(*(int *)(*(int *)(iVar2 + 0x10) + 8) + 8) = param_2;
    *(undefined4 *)(uVar1 + 0xc) = *(undefined4 *)(iVar2 + 0x10);
    *(sword *)(param_2 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0xc);
    uVar4 = puVar7[10];
  }
  puVar7[10] = uVar4 | 0x40000000;
  puVar3 = (uint *)(uVar4 | 0x40000000);
loc_F0017CF4:
  *(undefined2 *)(param_2 + 0x38) = param_1;
  _spltty();
  uVar4 = *(uint *)(param_2 + 0x40);
  uVar6 = uVar4 & 0xfffffffd;
  *(uint *)(param_2 + 0x40) = uVar6;
  if ((uVar4 & 4) == 0) {
    *(uint *)(param_2 + 0x40) = uVar6 | 4;
    _splx(puVar3);
    *(undefined4 *)(uVar1 + 0x10) = 0x1c251a1c;
    *(undefined *)(uVar1 + 0x14) = 0x5c;
    *(undefined *)(uVar1 + 0x15) = 1;
    *(undefined *)(uVar1 + 0x16) = 0;
    _bzero(param_2 + 0x5c,8);
    if (*(char *)(param_2 + 0x47) != '\x02') {
      _ttywflush(param_2);
    }
  }
  else {
    _splx(puVar3);
  }
  _ttysetspec(uVar1);
  return (qword)param_2 << 0x20;
}

