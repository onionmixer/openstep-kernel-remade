/* GHIDRADEC_FUNCTION index=3250 start=0xf0009194 */

sqword sub_F0009194(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3251 start=0xf000c670 */

undefined8 sub_F000C670(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  switch(param_1) {
  case :
    uVar1 = 0;
    break;
  case :
    uVar1 = 0x54;
    break;
  case :
    uVar1 = 0x56;
    break;
  case :
    uVar1 = 0x55;
    break;
  :
    uVar1 = 0x53;
    break;
  case :
    uVar1 = 0xc;
    break;
  case :
    uVar1 = 0xd;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3252 start=0xf000ea9c */

/* WARNING: Removing unreachable block (ram,0xf000eadc) */
/* WARNING: Removing unreachable block (ram,0xf000ead0) */
/* WARNING: Removing unreachable block (ram,0xf000eae4) */
/* WARNING: Removing unreachable block (ram,0xf000eb00) */

undefined8 sub_F000EA9C(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + 0x13);
    while (cVar1 != '\x06') {
      iVar2 = (int)*(sword *)(iVar2 + 0x30);
      _get_posix_proc();
      iVar2 = *(int *)(iVar2 + 0xc);
      if (iVar2 == 0) goto locret_F000EB18;
      cVar1 = *(char *)(iVar2 + 0x13);
    }
    for (iVar2 = *(int *)(param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      _psignal(iVar2,1);
      _psignal(iVar2,0x13);
      iVar2 = (int)*(sword *)(iVar2 + 0x30);
      _get_posix_proc();
    }
  }
locret_F000EB18:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3253 start=0xf0013fa4 */

/* WARNING: Removing unreachable block (ram,0xf00141ac) */
/* WARNING: Removing unreachable block (ram,0xf0013fd0) */
/* WARNING: Removing unreachable block (ram,0xf001418c) */
/* WARNING: Removing unreachable block (ram,0xf0013fc0) */

undefined8 sub_F0013FA4(undefined *param_1,undefined *param_2)

{
  undefined uVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  undefined4 unaff_l1;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 unaff_l3;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  int iVar12;
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
  bool bVar13;
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
  iVar9 = (int)param_2 - (int)param_1;
  do {
    iVar12 = dword_F010B480;
    iVar2 = iVar9;
    .div(iVar9,dword_F010B480);
    .umul(iVar12,iVar2 >> 1);
    puVar6 = param_1 + iVar12;
    if (dword_F010B488 <= iVar9) {
      puVar7 = param_1;
      (*dword_F010B47C)(param_1,puVar6);
      puVar5 = puVar6;
      if (0 < (int)puVar7) {
        puVar5 = param_1;
      }
      puVar10 = param_2 + -dword_F010B480;
      puVar7 = puVar5;
      (*dword_F010B47C)(puVar5,puVar10);
      if (0 < (int)puVar7) {
        puVar7 = param_1;
        if (puVar5 == param_1) {
          puVar7 = puVar6;
        }
        puVar3 = puVar7;
        (*dword_F010B47C)(puVar7,puVar10);
        puVar5 = puVar7;
        if ((int)puVar3 < 0) {
          puVar5 = puVar10;
        }
      }
      iVar9 = dword_F010B480;
      puVar7 = puVar6;
      if (puVar5 != puVar6) {
        do {
          uVar1 = *puVar7;
          iVar9 = iVar9 + -1;
          *puVar7 = *puVar5;
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar9 != 0);
      }
    }
    puVar5 = param_2 + -dword_F010B480;
    puVar7 = param_1;
    while( true ) {
      for (; puVar7 < puVar6; puVar7 = puVar7 + dword_F010B480) {
        puVar10 = puVar7;
        (*dword_F010B47C)(puVar7,puVar6);
        if (0 < (int)puVar10) goto loc_F0014100;
      }
      iVar9 = (int)puVar5 - (int)puVar6;
      puVar10 = puVar5;
      while (puVar3 = puVar7, puVar6 <= puVar10 && iVar9 != 0) {
        puVar5 = puVar6;
        (*dword_F010B47C)(puVar6,puVar10);
        if (0 < (int)puVar5) {
          bVar13 = puVar7 == puVar6;
          iVar9 = dword_F010B480;
          puVar4 = puVar10;
          puVar8 = puVar6;
          puVar11 = puVar7 + dword_F010B480;
          puVar6 = puVar10;
          puVar5 = puVar10;
          if (bVar13) goto loc_F001412C;
          goto loc_F0014124;
        }
        puVar5 = puVar10 + -dword_F010B480;
loc_F0014100:
        puVar10 = puVar5;
        iVar9 = (int)puVar5 - (int)puVar6;
      }
      puVar4 = puVar6;
      puVar8 = puVar7;
      puVar11 = puVar7;
      if (puVar7 == puVar6) break;
loc_F0014124:
      puVar5 = puVar10 + -dword_F010B480;
      iVar9 = dword_F010B480;
      puVar10 = puVar4;
      puVar6 = puVar8;
loc_F001412C:
      do {
        puVar7 = puVar11;
        uVar1 = *puVar3;
        iVar9 = iVar9 + -1;
        *puVar3 = *puVar10;
        *puVar10 = uVar1;
        puVar10 = puVar10 + 1;
        puVar3 = puVar3 + 1;
        puVar11 = puVar7;
      } while (iVar9 != 0);
    }
    iVar12 = (int)puVar6 - (int)param_1;
    puVar7 = puVar6 + dword_F010B480;
    iVar9 = (int)param_2 - (int)puVar7;
    if (iVar9 < iVar12) {
      bVar13 = dword_F010B484 <= iVar9;
      iVar9 = iVar12;
      puVar5 = param_1;
      puVar10 = puVar6;
      if (bVar13) {
        sub_F0013FA4(puVar7,param_2);
      }
    }
    else {
      puVar5 = puVar7;
      puVar10 = param_2;
      if (dword_F010B484 <= iVar12) {
        sub_F0013FA4(param_1,puVar6);
      }
    }
    param_1 = puVar5;
    param_2 = puVar10;
    if (iVar9 < dword_F010B484) {
      return CONCAT44(puVar10,puVar5);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3254 start=0xf001449c */

/* WARNING: Removing unreachable block (ram,0xf0014500) */
/* WARNING: Removing unreachable block (ram,0xf00144dc) */
/* WARNING: Removing unreachable block (ram,0xf00144c8) */
/* WARNING: Removing unreachable block (ram,0xf00144e4) */
/* WARNING: Removing unreachable block (ram,0xf0014518) */
/* WARNING: Removing unreachable block (ram,0xf00144b4) */

undefined8 sub_F001449C(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
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
  if (_log_open != 0) {
    _splusclock();
    iVar1 = dword_F0135184;
    dword_F0135184 = 0;
    _splx();
    if (iVar1 != 0) {
      _selwakeup(iVar1,0);
      _thread_deallocate_interrupt(iVar1);
    }
    if ((_logsoftc & 4) != 0) {
      _gsignal(dword_F0135188,0x17);
    }
    if ((_logsoftc & 8) != 0) {
      _wakeup(_pmsgbuf);
      _logsoftc = _logsoftc & 0xfffffff7;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3255 start=0xf0014868 */

/* WARNING: Removing unreachable block (ram,0xf0014888) */
/* WARNING: Removing unreachable block (ram,0xf0014890) */
/* WARNING: Removing unreachable block (ram,0xf001486c) */

undefined8 sub_F0014868(undefined4 param_1,undefined4 param_2)

{
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
  _logchar(0x3c);
  sub_F0015074(param_1,10,4,0,0,0);
  _logchar(0x3e);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3256 start=0xf001503c */

/* WARNING: Removing unreachable block (ram,0xf0015050) */

undefined8 sub_F001503C(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
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
  bVar1 = *param_1;
  while( true ) {
    param_1 = param_1 + 1;
    if (bVar1 == 0) break;
    sub_F00152F0((int)((uint)bVar1 * 0x1000000) >> 0x18,param_2,param_3);
    bVar1 = *param_1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3257 start=0xf0015074 */

/* WARNING: Removing unreachable block (ram,0xf0015118) */
/* WARNING: Removing unreachable block (ram,0xf00150b4) */
/* WARNING: Removing unreachable block (ram,0xf00150d0) */
/* WARNING: Removing unreachable block (ram,0xf0015140) */
/* WARNING: Removing unreachable block (ram,0xf0015098) */

undefined8
sub_F0015074(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  char *pcVar5;
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
  undefined auStackX_0 [92];
  char acStack_18 [24];
  
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
  if ((param_2 == 10) && (param_1 < 0)) {
    sub_F00152F0(0x2d,param_3,param_4);
    param_1 = -param_1;
  }
  pcVar2 = (char *)((int)register0x00000038 + -0x18);
  do {
    pcVar5 = pcVar2;
    iVar3 = param_1;
    .urem(param_1,param_2);
    *pcVar5 = DAT_f010b4a8[iVar3];
    .udiv(param_1,param_2);
    pcVar2 = pcVar5 + 1;
  } while (param_1 != 0);
  if (param_6 != 0) {
    for (param_6 = param_6 - ((int)(pcVar5 + 1) - (int)((int)register0x00000038 + -0x18));
        0 < param_6; param_6 = param_6 + -1) {
      uVar4 = 0x20;
      if (param_5 != 0) {
        uVar4 = 0x30;
      }
      sub_F00152F0(uVar4,param_3,param_4);
    }
  }
  do {
    sub_F00152F0((int)*pcVar5,param_3,param_4);
    bVar1 = (char *)((int)register0x00000038 + -0x18) < pcVar5;
    pcVar5 = pcVar5 + -1;
  } while (bVar1);
  return CONCAT44(param_2,(char *)((int)register0x00000038 + -0x18));
}
/* GHIDRADEC_FUNCTION index=3258 start=0xf00152f0 */

/* WARNING: Removing unreachable block (ram,0xf0015350) */
/* WARNING: Removing unreachable block (ram,0xf0015340) */
/* WARNING: Removing unreachable block (ram,0xf0015334) */
/* WARNING: Removing unreachable block (ram,0xf0015348) */
/* WARNING: Removing unreachable block (ram,0xf0015410) */
/* WARNING: Removing unreachable block (ram,0xf0015300) */

undefined8 sub_F00152F0(int param_1,uint param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
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
  if ((param_2 & 2) != 0) {
    iVar4 = param_1;
    _spltty();
    if ((param_3 != (int *)0x0) && ((param_3[0x10] & 0x14U) == 0x14)) {
      if (param_1 == 10) {
        _ttyoutput(0xd,param_3);
      }
      _ttyoutput(param_1,param_3);
      _ttstart(param_3);
    }
    _splx(iVar4);
  }
  piVar1 = _pmsgbuf;
  if (((((param_2 & 4) != 0) && (param_1 != 0)) && (param_1 != 0xd)) && (param_1 != 0x7f)) {
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar2 = 0;
      do {
        uVar3 = uVar2 + 1;
        *(undefined *)((int)_pmsgbuf + uVar2 + 0xc) = 0;
        uVar2 = uVar3;
      } while (uVar3 < 0xff4);
    }
    piVar1 = _pmsgbuf;
    iVar4 = _pmsgbuf[1];
    _pmsgbuf[1] = iVar4 + 1;
    *(char *)((int)piVar1 + iVar4 + 0xc) = (char)param_1;
    if ((_pmsgbuf[1] < 0) || (0xff3 < (uint)_pmsgbuf[1])) {
      _pmsgbuf[1] = 0;
    }
  }
  if (((param_2 & 1) != 0) && (param_1 != 0)) {
    _cnputc(param_1);
  }
  if ((param_2 & 8) != 0) {
    *(char *)*param_3 = (char)param_1;
    *param_3 = *param_3 + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3259 start=0xf001e4ac */

/* WARNING: Removing unreachable block (ram,0xf001e4b4) */

undefined8 sub_F001E4AC(undefined4 *param_1,undefined4 param_2)

{
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
  _kfree(param_1,*param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3260 start=0xf002565c */

/* WARNING: Removing unreachable block (ram,0xf0025670) */

undefined8 sub_F002565C(int param_1,int param_2)

{
  sword sVar1;
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
  if (*(int *)(param_1 + 0x40) == 0) {
    sVar1 = *(sword *)(param_2 + 6);
  }
  else {
    sub_F0025690(param_1);
    sVar1 = *(sword *)(param_2 + 6);
  }
  *(sword *)(param_2 + 6) = sVar1 + 1;
  *(int *)(param_1 + 0x40) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3261 start=0xf0025690 */

/* WARNING: Removing unreachable block (ram,0xf00256a4) */

undefined8 sub_F0025690(int param_1,undefined4 param_2)

{
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
  if (*(int *)(param_1 + 0x40) != 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    _vn_rele();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3262 start=0xf0025df8 */

/* WARNING: Removing unreachable block (ram,0xf0025e50) */
/* WARNING: Removing unreachable block (ram,0xf0025e38) */
/* WARNING: Removing unreachable block (ram,0xf0025e70) */
/* WARNING: Removing unreachable block (ram,0xf0025e2c) */

undefined8 sub_F0025DF8(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
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
  *(int *)(param_1[3] + 8) = param_1[2];
  *(int *)(param_1[2] + 0xc) = param_1[3];
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _vn_rele(param_1[5]);
  param_1[5] = 0;
  _vn_rele(param_1[4]);
  param_1[4] = 0;
  if (param_1[0xf] != 0) {
    _crfree();
    param_1[0xf] = 0;
  }
  if (*(char *)(param_1 + 0x11) != '\0') {
    _kfree(param_1[0x10],(int)*(sword *)((int)param_1 + 0x46));
    *(undefined *)(param_1 + 0x11) = 0;
    *(undefined2 *)((int)param_1 + 0x46) = 0;
  }
  iVar1 = (int)dword_F01355D8;
  piVar2 = param_1;
  param_1[2] = (int)dword_F01355D8;
  dword_F01355D8 = piVar2;
  *(int **)(iVar1 + 0xc) = param_1;
  param_1[3] = (int)&_nc_lru;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  DAT_f0135610._0_4_ = DAT_f0135610._0_4_ + -1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3263 start=0xf0025ec0 */

/* WARNING: Removing unreachable block (ram,0xf0025f84) */
/* WARNING: Removing unreachable block (ram,0xf0025f24) */

undefined8 sub_F0025EC0(int param_1,char *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined *puVar2;
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
  puVar4 = *(undefined4 **)(_nc_hash + param_4 * 8);
  if (puVar4 == (undefined4 *)(_nc_hash + param_4 * 8)) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar1 = puVar4[5];
    while( true ) {
      if (iVar1 == param_1) {
        if (*(char *)(puVar4 + 6) == param_3) {
          if (*(char *)((int)puVar4 + 0x19) == *param_2) {
            puVar2 = (undefined *)((int)puVar4 + 0x19);
            _bcmp(puVar2,param_2,param_3);
            if (puVar2 == (undefined *)0x0) {
              if ((param_5 == -1) || (iVar1 = puVar4[0xf], iVar1 == param_5)) goto locret_F0025FAC;
              if (*(sword *)(param_5 + 2) == *(sword *)(iVar1 + 2)) {
                if (*(sword *)(param_5 + 4) == *(sword *)(iVar1 + 4)) {
                  iVar3 = param_5 + 10;
                  _bcmp(iVar3,iVar1 + 10,0x20);
                  if (iVar3 == 0) goto locret_F0025FAC;
                  puVar4 = (undefined4 *)*puVar4;
                }
                else {
                  puVar4 = (undefined4 *)*puVar4;
                }
              }
              else {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
            else {
              puVar4 = (undefined4 *)*puVar4;
            }
          }
          else {
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)(_nc_hash + param_4 * 8)) break;
      iVar1 = puVar4[5];
    }
    puVar4 = (undefined4 *)0x0;
  }
locret_F0025FAC:
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=3264 start=0xf0027010 */

/* WARNING: Removing unreachable block (ram,0xf0027274) */
/* WARNING: Removing unreachable block (ram,0xf0027234) */
/* WARNING: Removing unreachable block (ram,0xf002719c) */
/* WARNING: Removing unreachable block (ram,0xf002717c) */
/* WARNING: Removing unreachable block (ram,0xf00270ec) */
/* WARNING: Removing unreachable block (ram,0xf0027054) */
/* WARNING: Removing unreachable block (ram,0xf0027028) */
/* WARNING: Removing unreachable block (ram,0xf00270d0) */
/* WARNING: Removing unreachable block (ram,0xf0027130) */
/* WARNING: Removing unreachable block (ram,0xf0027190) */
/* WARNING: Removing unreachable block (ram,0xf00271d0) */
/* WARNING: Removing unreachable block (ram,0xf0027268) */
/* WARNING: Removing unreachable block (ram,0xf0027288) */
/* WARNING: Removing unreachable block (ram,0xf002701c) */

undefined8 sub_F0027010(int *param_1,char *param_2,undefined4 param_3,int *param_4)

{
  char *pcVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
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
  bool bVar5;
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
  _pn_alloc(param_4);
  pcVar1 = param_2;
  _dnlc_lookupSymLink(param_2,param_3);
  if (pcVar1 != (char *)0x0) {
    if (pcVar1[0x44] == '\0') {
      iVar2 = *param_4;
      goto loc_F0027068;
    }
    _bcopy(*(undefined4 *)(pcVar1 + 0x40),*param_4,(int)*(sword *)(pcVar1 + 0x46));
    param_4[2] = (int)*(sword *)(pcVar1 + 0x46);
    param_1 = (int *)0x0;
loc_F00270D8:
    *(undefined *)(*param_4 + param_4[2]) = 0;
    iVar2 = *param_4;
    while( true ) {
      _index(iVar2,0x24);
      bVar5 = param_1 == (int *)0x0;
      if (iVar2 == 0) break;
      if ((iVar2 == *param_4) || (*(char *)(iVar2 + -1) == '/')) {
        bVar5 = param_1 == (int *)0x0;
        if (iVar2 != 0) {
          _pn_alloc((undefined *)((int)register0x00000038 + -0x38));
          bVar5 = param_1 == (int *)0x0;
          if (param_4[2] == 0) goto loc_F0027260;
          param_2 = (char *)((int)register0x00000038 + -0x138);
          goto loc_F0027150;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    }
    goto loc_F0027280;
  }
  iVar2 = *param_4;
loc_F0027068:
  *(int *)((int)register0x00000038 + -0x10) = iVar2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0x400;
  *(undefined **)((int)register0x00000038 + -0x28) = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x400;
  (**(code **)(param_1[7] + 0x44))
            (param_1,(undefined *)((int)register0x00000038 + -0x28),
             *(undefined4 *)(_active_u + 0x1c));
  param_4[2] = 0x400 - *(int *)((int)register0x00000038 + -0x14);
  if (param_1 == (int *)0x0) {
    _dnlc_enterSymLink(param_2,param_3,param_4);
    goto loc_F00270D8;
  }
  goto loc_F0027288;
loc_F0027150:
  do {
    if ((param_4[2] != 0) && (*(char *)param_4[1] == '/')) {
      param_1 = (int *)((int)register0x00000038 + -0x38);
      _pn_append(param_1,&unk_F010C140);
      if (param_1 != (int *)0x0) goto loc_F0027274;
      _pn_skipslash(param_4,*(undefined4 *)((int)register0x00000038 + -0x38));
    }
    param_1 = param_4;
    _pn_getcomponent(param_4,param_2);
    bVar5 = param_1 == (int *)0x0;
    if (!bVar5) goto loc_F0027260;
    pcVar1 = param_2;
    if (*(char *)((int)register0x00000038 + -0x138) != '$') goto loc_F0027234;
    puVar4 = _metalinks;
    iVar2 = _metalinks._0_4_;
    if (_metalinks._0_4_ == 0) {
loc_F00271F8:
      iVar2 = *(int *)puVar4;
    }
    else {
      while( true ) {
        puVar3 = (undefined *)((int)register0x00000038 + -0x137);
        _strcmp(puVar3,iVar2);
        if (puVar3 == (undefined *)0x0) break;
        puVar4 = (undefined *)((int)puVar4 + 0xc);
        if (*(int *)puVar4 == 0) goto loc_F00271F8;
        iVar2 = *(int *)puVar4;
      }
      iVar2 = *(int *)puVar4;
    }
    if (iVar2 == 0) {
      param_1 = (int *)0x2;
      break;
    }
    pcVar1 = *(char **)((int)puVar4 + 4);
    if (**(char **)((int)puVar4 + 4) == '\0') {
      param_1 = (int *)0x2;
      pcVar1 = *(char **)((int)puVar4 + 8);
      if (*(char **)((int)puVar4 + 8) != (char *)0x0) goto loc_F0027234;
    }
    else {
loc_F0027234:
      param_1 = (int *)((int)register0x00000038 + -0x38);
      _pn_append(param_1,pcVar1);
    }
    if (param_1 != (int *)0x0) goto loc_F0027274;
  } while (param_4[2] != 0);
  bVar5 = param_1 == (int *)0x0;
loc_F0027260:
  if (bVar5) {
    param_1 = param_4;
    _pn_set(param_4,*(undefined4 *)((int)register0x00000038 + -0x38));
  }
loc_F0027274:
  _pn_free((undefined *)((int)register0x00000038 + -0x38));
  bVar5 = param_1 == (int *)0x0;
loc_F0027280:
  if (bVar5) goto locret_F0027290;
loc_F0027288:
  _pn_free(param_4);
locret_F0027290:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3265 start=0xf002a26c */

/* WARNING: Removing unreachable block (ram,0xf002a360) */
/* WARNING: Removing unreachable block (ram,0xf002a37c) */
/* WARNING: Removing unreachable block (ram,0xf002a33c) */
/* WARNING: Removing unreachable block (ram,0xf002a2ec) */
/* WARNING: Removing unreachable block (ram,0xf002a2b8) */
/* WARNING: Removing unreachable block (ram,0xf002a2a0) */
/* WARNING: Removing unreachable block (ram,0xf002a310) */
/* WARNING: Removing unreachable block (ram,0xf002a2c8) */
/* WARNING: Removing unreachable block (ram,0xf002a324) */
/* WARNING: Removing unreachable block (ram,0xf002a34c) */
/* WARNING: Removing unreachable block (ram,0xf002a388) */
/* WARNING: Removing unreachable block (ram,0xf002a36c) */
/* WARNING: Removing unreachable block (ram,0xf002a270) */

undefined8 sub_F002A26C(int param_1,undefined4 param_2,sword *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = param_1;
  _if_private();
  iVar3 = *(int *)(iVar3 + 0xc);
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,(undefined *)((int)register0x00000038 + -0x18),0xe);
    *(undefined2 *)((int)register0x00000038 + -0xc) =
         *(undefined2 *)((int)register0x00000038 + -0xc);
  }
  else {
    if (*param_3 != 2) {
      _nb_free(param_2);
      iVar3 = 0x2f;
      goto locret_F002A394;
    }
    *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_3 + 2);
    iVar1 = param_1;
    _if_private();
    *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(iVar1 + 8);
    iVar1 = param_1;
    _if_private(param_1);
    iVar2 = param_1;
    _arpresolve(param_1,iVar1,(undefined *)((int)register0x00000038 + -0x24),param_2,
                (undefined *)((int)register0x00000038 + -0x1c),
                (undefined *)((int)register0x00000038 + -0x18),
                (undefined *)((int)register0x00000038 + -0x20));
    if (iVar2 == 0) {
      iVar3 = 0;
      goto locret_F002A394;
    }
    *(undefined2 *)((int)register0x00000038 + -0xc) = 0x800;
  }
  _nb_grow_top(param_2,0xe);
  _nb_write(param_2,0xc,2,(undefined *)((int)register0x00000038 + -0xc));
  _if_output(iVar3,param_2,(undefined *)((int)register0x00000038 + -0x18));
  if (iVar3 == 0) {
    iVar1 = param_1;
    _if_opackets(param_1);
    _if_opackets_set(param_1,iVar1 + 1);
  }
  else {
    iVar1 = param_1;
    _if_oerrors(param_1);
    _if_oerrors_set(param_1,iVar1 + 1);
  }
locret_F002A394:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3266 start=0xf002a39c */

/* WARNING: Removing unreachable block (ram,0xf002a4c8) */
/* WARNING: Removing unreachable block (ram,0xf002a49c) */
/* WARNING: Removing unreachable block (ram,0xf002a480) */
/* WARNING: Removing unreachable block (ram,0xf002a458) */
/* WARNING: Removing unreachable block (ram,0xf002a440) */
/* WARNING: Removing unreachable block (ram,0xf002a42c) */
/* WARNING: Removing unreachable block (ram,0xf002a3fc) */
/* WARNING: Removing unreachable block (ram,0xf002a3d8) */
/* WARNING: Removing unreachable block (ram,0xf002a3b4) */
/* WARNING: Removing unreachable block (ram,0xf002a3e8) */
/* WARNING: Removing unreachable block (ram,0xf002a420) */
/* WARNING: Removing unreachable block (ram,0xf002a438) */
/* WARNING: Removing unreachable block (ram,0xf002a448) */
/* WARNING: Removing unreachable block (ram,0xf002a470) */
/* WARNING: Removing unreachable block (ram,0xf002a494) */
/* WARNING: Removing unreachable block (ram,0xf002a4b0) */
/* WARNING: Removing unreachable block (ram,0xf002a534) */
/* WARNING: Removing unreachable block (ram,0xf002a3a0) */

undefined8 sub_F002A39C(uint param_1,int param_2,sword *param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
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
  uVar4 = param_1;
  _if_private();
  uVar4 = *(uint *)(uVar4 + 0xc);
  iVar2 = param_2;
  _strcmp(param_2,_IFCONTROL_AUTOADDR);
  if (iVar2 == 0) {
    if (*param_3 == 2) {
      uVar4 = param_1;
      _if_private(param_1);
      _in_bootp(param_1,param_3,uVar4);
    }
    else {
      param_1 = 0x2f;
    }
  }
  else {
    iVar2 = param_2;
    _strcmp(param_2,&_IFCONTROL_SETADDR);
    if (iVar2 == 0) {
      iVar2 = (int)*param_3;
      if (iVar2 == 2) {
        _spltty();
        uVar3 = param_1;
        _if_flags(param_1);
        _if_flags_set(param_1,uVar3 | 0x41);
        _if_init(uVar4);
        uVar4 = param_1;
        _if_private();
        *(undefined4 *)(uVar4 + 8) = *(undefined4 *)(param_3 + 2);
        uVar4 = param_1;
        _if_flags();
        if ((uVar4 & 0x4000) == 0) {
          uVar4 = param_1;
          _if_private();
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(uVar4 + 8);
          uVar4 = param_1;
          _if_private(param_1);
          _arpwhohas(param_1,uVar4,(undefined *)((int)register0x00000038 + -0xc),param_3 + 2);
        }
        _splx(iVar2);
        param_1 = 0;
        param_2 = iVar2;
      }
      else {
        param_1 = 0x2f;
      }
    }
    else {
      iVar2 = param_2;
      _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
      if ((iVar2 == 0) || (iVar2 = param_2, _strcmp(param_2,_IFCONTROL_RMVMULTICAST), iVar2 == 0)) {
        param_1 = 0x2f;
        if (param_3[8] != 2) goto locret_F002A540;
        *(undefined *)((int)register0x00000038 + -0x18) = 1;
        *(undefined *)((int)register0x00000038 + -0x17) = 0;
        *(undefined *)((int)register0x00000038 + -0x16) = 0x5e;
        *(byte *)((int)register0x00000038 + -0x15) = *(byte *)((int)param_3 + 0x15) & 0x7f;
        *(undefined *)((int)register0x00000038 + -0x14) = *(undefined *)(param_3 + 0xb);
        puVar1 = (undefined *)((int)param_3 + 0x17);
        param_3 = (sword *)((int)register0x00000038 + -0x18);
        *(undefined *)((int)register0x00000038 + -0x13) = *puVar1;
      }
      _if_control(uVar4,param_2,param_3);
      param_1 = uVar4;
    }
  }
locret_F002A540:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3267 start=0xf002a548 */

/* WARNING: Removing unreachable block (ram,0xf002a5f4) */
/* WARNING: Removing unreachable block (ram,0xf002a580) */
/* WARNING: Removing unreachable block (ram,0xf002a5c0) */
/* WARNING: Removing unreachable block (ram,0xf002a5dc) */
/* WARNING: Removing unreachable block (ram,0xf002a598) */
/* WARNING: Removing unreachable block (ram,0xf002a600) */
/* WARNING: Removing unreachable block (ram,0xf002a54c) */

undefined8 sub_F002A548(int param_1,sword param_2,sword param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar4;
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
  iVar1 = param_1;
  _nb_map(param_1);
  iVar4 = (int)param_2;
  if (iVar4 < 0x201) {
    _nb_read(param_1,0xe,iVar4,(undefined *)((int)register0x00000038 + -0x208));
    _bcopy(iVar1 + iVar4 + 0x12,iVar1 + 0xe,(int)param_3);
    iVar3 = iVar1 + param_3 + 0xe;
    iVar2 = iVar4;
  }
  else {
    iVar2 = (int)param_3;
    _nb_read(param_1,iVar4 + 0x12,iVar2,(undefined *)((int)register0x00000038 + -0x208));
    iVar3 = iVar1 + 0xe;
    _bcopy(iVar3,iVar1 + iVar2 + 0xe,iVar4);
  }
  _bcopy((undefined *)((int)register0x00000038 + -0x208),iVar3,iVar2);
  _nb_shrink_bot(param_1,4);
  return CONCAT44(iVar4,param_1);
}
/* GHIDRADEC_FUNCTION index=3268 start=0xf002a610 */

/* WARNING: Removing unreachable block (ram,0xf002a61c) */
/* WARNING: Removing unreachable block (ram,0xf002a630) */
/* WARNING: Removing unreachable block (ram,0xf002a614) */

undefined8 sub_F002A610(int param_1,undefined4 param_2)

{
  int iVar1;
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
  _if_private();
  iVar1 = *(int *)(param_1 + 0xc);
  _if_getbuf();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _nb_shrink_top();
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3269 start=0xf002a640 */

/* WARNING: Removing unreachable block (ram,0xf002a7d0) */
/* WARNING: Removing unreachable block (ram,0xf002a7b8) */
/* WARNING: Removing unreachable block (ram,0xf002a7a0) */
/* WARNING: Removing unreachable block (ram,0xf002a78c) */
/* WARNING: Removing unreachable block (ram,0xf002a770) */
/* WARNING: Removing unreachable block (ram,0xf002a75c) */
/* WARNING: Removing unreachable block (ram,0xf002a710) */
/* WARNING: Removing unreachable block (ram,0xf002a6ac) */
/* WARNING: Removing unreachable block (ram,0xf002a668) */
/* WARNING: Removing unreachable block (ram,0xf002a6cc) */
/* WARNING: Removing unreachable block (ram,0xf002a730) */
/* WARNING: Removing unreachable block (ram,0xf002a764) */
/* WARNING: Removing unreachable block (ram,0xf002a77c) */
/* WARNING: Removing unreachable block (ram,0xf002a798) */
/* WARNING: Removing unreachable block (ram,0xf002a7f4) */
/* WARNING: Removing unreachable block (ram,0xf002a7c0) */
/* WARNING: Removing unreachable block (ram,0xf002a7e4) */
/* WARNING: Removing unreachable block (ram,0xf002a644) */

undefined8 sub_F002A640(uint param_1,int param_2,uint param_3)

{
  sword sVar1;
  sword sVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  uVar4 = param_1;
  _if_private();
  if (*(int *)(uVar4 + 0xc) != param_2) {
    uVar6 = 0x2f;
    goto locret_F002A808;
  }
  _nb_read(param_3,0xc,2,(undefined *)((int)register0x00000038 + -0x12));
  sVar1 = *(sword *)((int)register0x00000038 + -0x12);
  if ((word)(sVar1 - 0x1000U) < 0x10) {
    uVar4 = ((int)sVar1 << 0x19) >> 0x10;
    if (uVar4 == 0) {
      uVar6 = 0x2f;
      goto locret_F002A808;
    }
    uVar3 = param_3;
    _nb_size();
    if (uVar4 + 0x12 < uVar3) {
      _nb_read(param_3,uVar4 | 0xe,4,(undefined *)((int)register0x00000038 + -0x10));
      sVar2 = *(sword *)((int)register0x00000038 + -0x10);
      *(sword *)((int)register0x00000038 + -0x12) = sVar2;
      if ((sVar2 != 0x800) && (sVar2 != 0x806)) {
        uVar6 = 0x2f;
        goto locret_F002A808;
      }
      param_2 = (int)*(sword *)((int)register0x00000038 + -0xe);
      iVar5 = sVar1 * 0x2000000 >> 0x10;
      uVar4 = param_3;
      _nb_size();
      if ((uint)(iVar5 + param_2 + 0xe) <= uVar4) {
        sub_F002A548(param_3,iVar5,(param_2 + -4) * 0x10000 >> 0x10);
        goto loc_F002A738;
      }
    }
    uVar6 = 0x2f;
  }
  else {
loc_F002A738:
    if (*(sword *)((int)register0x00000038 + -0x12) == 0x800) {
      _nb_shrink_top(param_3,0xe);
      uVar4 = param_1;
      _if_ipackets(param_1);
      _if_ipackets_set(param_1,uVar4 + 1);
      _inet_queue(param_1,param_3);
      uVar6 = 0;
    }
    else if (*(sword *)((int)register0x00000038 + -0x12) == 0x806) {
      uVar4 = param_1;
      _if_ipackets(param_1);
      _if_ipackets_set(param_1,uVar4 + 1);
      uVar4 = param_1;
      _if_flags();
      if ((uVar4 & 0x4000) == 0) {
        _nb_shrink_top(param_3,0xe);
        uVar4 = param_1;
        _if_private();
        *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(uVar4 + 8);
        uVar4 = param_1;
        _if_private(param_1);
        _arpinput(param_1,uVar4,(undefined *)((int)register0x00000038 + -0x18),param_3);
        uVar6 = 0;
      }
      else {
        _nb_free(param_3);
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0x2f;
    }
  }
locret_F002A808:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=3270 start=0xf002a810 */

/* WARNING: Removing unreachable block (ram,0xf002a8d4) */
/* WARNING: Removing unreachable block (ram,0xf002a8b0) */
/* WARNING: Removing unreachable block (ram,0xf002a84c) */
/* WARNING: Removing unreachable block (ram,0xf002a834) */
/* WARNING: Removing unreachable block (ram,0xf002a820) */
/* WARNING: Removing unreachable block (ram,0xf002a840) */
/* WARNING: Removing unreachable block (ram,0xf002a8a8) */
/* WARNING: Removing unreachable block (ram,0xf002a8c4) */
/* WARNING: Removing unreachable block (ram,0xf002a8f0) */
/* WARNING: Removing unreachable block (ram,0xf002a814) */

undefined8 sub_F002A810(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
  iVar1 = param_2;
  _if_type();
  _strcmp();
  if (iVar1 == 0) {
    uVar2 = 0x10;
    _kalloc();
    iVar1 = param_2;
    _if_name(param_2);
    iVar3 = param_2;
    _if_unit();
    iVar4 = 0;
    _if_attach(0,sub_F002A640,sub_F002A26C,sub_F002A610,sub_F002A39C,iVar1,iVar3,aInternetProtoc_0,
               0x5dc,2,0x1000,uVar2);
    iVar5 = iVar4;
    _if_private();
    *(int *)(iVar5 + 0xc) = param_2;
    _if_private(iVar4);
    _if_control(param_2,&_IFCONTROL_GETADDR,iVar4);
    _printf(aIpProtocolEnab,iVar1,iVar3,a10mbEthernet_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3271 start=0xf002a97c */

/* WARNING: Removing unreachable block (ram,0xf002aba8) */
/* WARNING: Removing unreachable block (ram,0xf002abc4) */
/* WARNING: Removing unreachable block (ram,0xf002ab74) */
/* WARNING: Removing unreachable block (ram,0xf002ab54) */
/* WARNING: Removing unreachable block (ram,0xf002aae4) */
/* WARNING: Removing unreachable block (ram,0xf002aa88) */
/* WARNING: Removing unreachable block (ram,0xf002aa44) */
/* WARNING: Removing unreachable block (ram,0xf002ab40) */
/* WARNING: Removing unreachable block (ram,0xf002a9e4) */
/* WARNING: Removing unreachable block (ram,0xf002a9b4) */
/* WARNING: Removing unreachable block (ram,0xf002a9ec) */
/* WARNING: Removing unreachable block (ram,0xf002aa34) */
/* WARNING: Removing unreachable block (ram,0xf002aa6c) */
/* WARNING: Removing unreachable block (ram,0xf002aacc) */
/* WARNING: Removing unreachable block (ram,0xf002ab0c) */
/* WARNING: Removing unreachable block (ram,0xf002ab6c) */
/* WARNING: Removing unreachable block (ram,0xf002ab94) */
/* WARNING: Removing unreachable block (ram,0xf002abd0) */
/* WARNING: Removing unreachable block (ram,0xf002abb4) */
/* WARNING: Removing unreachable block (ram,0xf002a980) */

undefined8 sub_F002A97C(uint *param_1,undefined4 param_2,sword *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  byte bVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
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
  puVar1 = param_1;
  _if_private();
  uVar6 = puVar1[5];
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,(undefined *)((int)register0x00000038 + -0x26),6);
    DAT_f010c26c._0_2_ = param_3[7];
    if (DAT_f010c26c._0_2_ == 0x806) {
      _nb_write(param_2,0,2,&unk_F010C278);
      puVar1 = param_1;
      _if_private();
      if ((*puVar1 & 1) == 0) {
        *(byte *)((int)register0x00000038 + -0x20) =
             *(byte *)((int)register0x00000038 + -0x20) & 0x7f;
      }
      else {
        *(undefined *)((int)register0x00000038 + -0x1a) = 0x82;
        *(undefined *)((int)register0x00000038 + -0x19) = 0x70;
        *(byte *)((int)register0x00000038 + -0x20) =
             *(byte *)((int)register0x00000038 + -0x20) | 0x80;
      }
    }
  }
  else {
    if (*param_3 != 2) {
      _nb_free(param_2);
      uVar6 = 0x2f;
      goto locret_F002ABDC;
    }
    *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_3 + 2);
    puVar1 = param_1;
    _if_private();
    *(uint *)((int)register0x00000038 + -0x34) = puVar1[4];
    puVar1 = param_1;
    _if_private(param_1);
    puVar2 = param_1;
    _arpresolve(param_1,puVar1 + 2,(undefined *)((int)register0x00000038 + -0x34),param_2,
                (undefined *)((int)register0x00000038 + -0x2c),
                (undefined *)((int)register0x00000038 + -0x26),
                (undefined *)((int)register0x00000038 + -0x30));
    if (puVar2 == (uint *)0x0) {
      uVar6 = 0;
      goto locret_F002ABDC;
    }
    puVar1 = param_1;
    _if_private();
    bVar5 = *(byte *)((int)register0x00000038 + -0x20);
    if ((*puVar1 & 1) == 0) {
loc_F002AB24:
      bVar5 = bVar5 & 0x7f;
loc_F002AB28:
      *(byte *)((int)register0x00000038 + -0x20) = bVar5;
    }
    else {
      if (*(char *)((int)register0x00000038 + -0x26) < '\0') {
        *(undefined *)((int)register0x00000038 + -0x1a) = 0xc2;
        *(undefined *)((int)register0x00000038 + -0x19) = 0x70;
        bVar5 = *(byte *)((int)register0x00000038 + -0x20) | 0x80;
        goto loc_F002AB28;
      }
      puVar1 = param_1;
      _if_private();
      uVar3 = puVar1[1];
      if ((*(byte *)((int)register0x00000038 + -0x26) & 0x80) == 0) {
        _NXHashGet(uVar3,(undefined *)((int)register0x00000038 + -0x26));
        pbVar4 = (byte *)0x0;
        if (uVar3 != 0) {
          pbVar4 = (byte *)(uVar3 + 0xc);
        }
        if (pbVar4 == (byte *)0x0) {
          bVar5 = *(byte *)((int)register0x00000038 + -0x20);
          goto loc_F002AB24;
        }
        _bcopy(pbVar4,(undefined *)((int)register0x00000038 + -0x1a),*pbVar4 & 0x1f);
        bVar5 = *(byte *)((int)register0x00000038 + -0x20) | 0x80;
        goto loc_F002AB28;
      }
    }
    DAT_f010c26c._0_2_ = 0x800;
  }
  _nb_grow_top(param_2,8);
  _nb_write(param_2,0,8,unk_F010C266);
  puVar1 = param_1;
  _if_private();
  *(undefined *)((int)register0x00000038 + -0x28) = *(undefined *)(puVar1 + 6);
  *(undefined *)((int)register0x00000038 + -0x27) = 0x40;
  _if_output(uVar6,param_2,(undefined *)((int)register0x00000038 + -0x28));
  if (uVar6 == 0) {
    puVar1 = param_1;
    _if_opackets(param_1);
    _if_opackets_set(param_1,(int)puVar1 + 1);
  }
  else {
    puVar1 = param_1;
    _if_oerrors(param_1);
    _if_oerrors_set(param_1,(int)puVar1 + 1);
  }
locret_F002ABDC:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=3272 start=0xf002abe4 */

/* WARNING: Removing unreachable block (ram,0xf002ac20) */
/* WARNING: Removing unreachable block (ram,0xf002acec) */
/* WARNING: Removing unreachable block (ram,0xf002acc4) */
/* WARNING: Removing unreachable block (ram,0xf002acac) */
/* WARNING: Removing unreachable block (ram,0xf002ac8c) */
/* WARNING: Removing unreachable block (ram,0xf002ac70) */
/* WARNING: Removing unreachable block (ram,0xf002ac44) */
/* WARNING: Removing unreachable block (ram,0xf002abfc) */
/* WARNING: Removing unreachable block (ram,0xf002ad14) */
/* WARNING: Removing unreachable block (ram,0xf002ac84) */
/* WARNING: Removing unreachable block (ram,0xf002aca0) */
/* WARNING: Removing unreachable block (ram,0xf002acb4) */
/* WARNING: Removing unreachable block (ram,0xf002acdc) */
/* WARNING: Removing unreachable block (ram,0xf002ad00) */
/* WARNING: Removing unreachable block (ram,0xf002ac30) */
/* WARNING: Removing unreachable block (ram,0xf002abe8) */

undefined8 sub_F002ABE4(uint param_1,int param_2,sword *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
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
  uVar3 = param_1;
  _if_private();
  uVar3 = *(uint *)(uVar3 + 0x14);
  iVar1 = param_2;
  _strcmp(param_2,_IFCONTROL_AUTOADDR);
  if (iVar1 == 0) {
    if (*param_3 == 2) {
      uVar3 = param_1;
      _if_private(param_1);
      _in_bootp(param_1,param_3,uVar3 + 8);
      uVar3 = param_1;
    }
    else {
      uVar3 = 0x2f;
    }
  }
  else {
    iVar1 = param_2;
    _strcmp(param_2,&_IFCONTROL_SETADDR);
    if (iVar1 == 0) {
      if (*param_3 == 2) {
        uVar2 = param_1;
        _if_flags(param_1);
        _if_flags_set(param_1,uVar2 | 0x8001);
        _if_init();
        if (uVar3 == 0) {
          uVar3 = param_1;
          _if_flags(param_1);
          _if_flags_set(param_1,uVar3 | 0x40);
        }
        uVar3 = param_1;
        _if_private();
        *(undefined4 *)(uVar3 + 0x10) = *(undefined4 *)(param_3 + 2);
        uVar3 = param_1;
        _if_flags();
        if ((uVar3 & 0x4000) == 0) {
          uVar3 = param_1;
          _if_private();
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(uVar3 + 0x10);
          uVar3 = param_1;
          _if_private(param_1);
          _arpwhohas(param_1,uVar3 + 8,(undefined *)((int)register0x00000038 + -0xc),param_3 + 2);
          uVar3 = 0;
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0x2f;
      }
    }
    else {
      _if_control(uVar3,param_2,param_3);
    }
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3273 start=0xf002ad28 */

/* WARNING: Removing unreachable block (ram,0xf002ad7c) */
/* WARNING: Removing unreachable block (ram,0xf002ad60) */
/* WARNING: Removing unreachable block (ram,0xf002ad38) */
/* WARNING: Removing unreachable block (ram,0xf002ad44) */
/* WARNING: Removing unreachable block (ram,0xf002ad68) */
/* WARNING: Removing unreachable block (ram,0xf002ad88) */
/* WARNING: Removing unreachable block (ram,0xf002ad2c) */

undefined8 sub_F002AD28(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
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
  uVar2 = param_1;
  _if_private();
  uVar2 = *(uint *)(uVar2 + 0x14);
  _if_mtu();
  _if_getbuf();
  if (uVar2 == 0) {
    uVar2 = 0;
  }
  else {
    _nb_shrink_top(uVar2,8);
    uVar1 = uVar2;
    _nb_size();
    if (param_1 < uVar1) {
      uVar1 = uVar2;
      _nb_size(uVar2);
      _nb_shrink_bot(uVar2,uVar1 - param_1);
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3274 start=0xf002b500 */

/* WARNING: Removing unreachable block (ram,0xf002b6f4) */
/* WARNING: Removing unreachable block (ram,0xf002b6d0) */
/* WARNING: Removing unreachable block (ram,0xf002b688) */
/* WARNING: Removing unreachable block (ram,0xf002b654) */
/* WARNING: Removing unreachable block (ram,0xf002b600) */
/* WARNING: Removing unreachable block (ram,0xf002b5e4) */
/* WARNING: Removing unreachable block (ram,0xf002b584) */
/* WARNING: Removing unreachable block (ram,0xf002b540) */
/* WARNING: Removing unreachable block (ram,0xf002b510) */
/* WARNING: Removing unreachable block (ram,0xf002b524) */
/* WARNING: Removing unreachable block (ram,0xf002b54c) */
/* WARNING: Removing unreachable block (ram,0xf002b5dc) */
/* WARNING: Removing unreachable block (ram,0xf002b664) */
/* WARNING: Removing unreachable block (ram,0xf002b618) */
/* WARNING: Removing unreachable block (ram,0xf002b6a8) */
/* WARNING: Removing unreachable block (ram,0xf002b6bc) */
/* WARNING: Removing unreachable block (ram,0xf002b6e0) */
/* WARNING: Removing unreachable block (ram,0xf002b708) */
/* WARNING: Removing unreachable block (ram,0xf002b504) */

undefined8 sub_F002B500(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined *puVar7;
  byte bVar8;
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
  uVar1 = param_2;
  _if_type();
  _strcmp();
  if ((uVar1 == 0) && (uVar1 = param_2, _if_unit(), uVar1 == *param_1)) {
    uVar2 = param_2;
    _if_name(param_2);
    uVar4 = param_2;
    _if_mtu();
    uVar3 = dword_F010C27C;
    if (param_1[2] != 0) {
      uVar3 = param_1[2];
    }
    if ((int)(uVar4 - 8) < (int)uVar3) {
      uVar3 = uVar4 - 8;
    }
    uVar4 = 0x20;
    _kalloc();
    puVar5 = (uint *)0x0;
    _if_attach(0,dword_F002AD98,sub_F002A97C,sub_F002AD28,sub_F002ABE4,uVar2,uVar1,aInternetProtoc_1
               ,uVar3,2,0x1000,uVar4 & 0xfffffffc);
    puVar6 = puVar5;
    _if_private();
    *puVar6 = 0;
    if ((param_1[1] & 1) == 0) {
      puVar6 = puVar5;
      _if_private();
      *puVar6 = *puVar6 & 0xfffffffe;
    }
    else {
      puVar6 = puVar5;
      _if_private();
      *puVar6 = *puVar6 | 1;
      puVar6 = puVar5;
      _if_private();
      puVar7 = (undefined *)((int)register0x00000038 + -0x18);
      *(code **)((int)register0x00000038 + -0x18) = _SRHash;
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0xf002a948;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0xf00edfac;
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      _NXCreateHashTable(puVar7,0,0);
      puVar6[1] = (uint)puVar7;
    }
    param_1 = (uint *)param_1[3];
    puVar6 = puVar5;
    if ((int)param_1 < 8) {
      if (6 < ((uint)param_1 & 0xff)) {
        param_1 = (uint *)0x6;
      }
      _if_private();
      bVar8 = (byte)((int)param_1 << 5) | 0x10;
    }
    else {
      _if_private();
      bVar8 = 0x10;
    }
    *(byte *)(puVar6 + 6) = bVar8;
    puVar6 = puVar5;
    _if_private();
    puVar6[5] = param_2;
    _if_private(puVar5);
    _if_control(param_2,&_IFCONTROL_GETADDR,puVar5 + 2);
    _printf(aIpProtocolEnab_0,uVar2,uVar1);
    _printf(aIeee8022NullSa,uVar2,uVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3275 start=0xf002b93c */

sqword sub_F002B93C(undefined *param_1,uint param_2)

{
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
  *param_1 = param_1[1];
  param_1[1] = 1;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3276 start=0xf002b958 */

/* WARNING: Removing unreachable block (ram,0xf002b9c4) */
/* WARNING: Removing unreachable block (ram,0xf002b9ac) */
/* WARNING: Removing unreachable block (ram,0xf002b998) */
/* WARNING: Removing unreachable block (ram,0xf002b97c) */
/* WARNING: Removing unreachable block (ram,0xf002b9e4) */
/* WARNING: Removing unreachable block (ram,0xf002b970) */
/* WARNING: Removing unreachable block (ram,0xf002b988) */
/* WARNING: Removing unreachable block (ram,0xf002b9a0) */
/* WARNING: Removing unreachable block (ram,0xf002b9bc) */
/* WARNING: Removing unreachable block (ram,0xf002b9d4) */
/* WARNING: Removing unreachable block (ram,0xf002b95c) */

undefined8 sub_F002B958(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
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
  iVar1 = param_1;
  _if_getbuf();
  if (iVar1 == 0) {
    _nb_free(param_2);
    param_1 = 1;
  }
  else {
    iVar2 = param_2;
    _nb_map(param_2);
    iVar3 = iVar1;
    _nb_map(iVar1);
    iVar4 = param_2;
    _nb_size(param_2);
    _bcopy(iVar2,iVar3,iVar4);
    iVar2 = iVar1;
    _nb_size(iVar1);
    iVar3 = param_2;
    _nb_size(param_2);
    _nb_shrink_bot(iVar1,iVar2 - iVar3);
    _nb_free(param_2);
    _if_output(param_1,iVar1,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3277 start=0xf002b9f8 */

/* WARNING: Removing unreachable block (ram,0xf002ba00) */

undefined8 sub_F002B9F8(undefined4 *param_1,undefined4 param_2)

{
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
  _kfree(param_1,*param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3278 start=0xf002bf04 */

undefined8 sub_F002BF04(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  if (dword_F012F414 != (undefined4 *)0x0) {
    pcVar1 = (code *)*dword_F012F414;
    puVar2 = dword_F012F414;
    while( true ) {
      (*pcVar1)(puVar2[1],param_1);
      puVar2 = (undefined4 *)puVar2[2];
      if (puVar2 == (undefined4 *)0x0) break;
      pcVar1 = (code *)*puVar2;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3279 start=0xf002bf68 */

undefined8 sub_F002BF68(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,5);
}
/* GHIDRADEC_FUNCTION index=3280 start=0xf002bf74 */

sqword sub_F002BF74(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3281 start=0xf002fa30 */

/* WARNING: Removing unreachable block (ram,0xf002fba0) */
/* WARNING: Removing unreachable block (ram,0xf002fb50) */
/* WARNING: Removing unreachable block (ram,0xf002fa84) */
/* WARNING: Removing unreachable block (ram,0xf002fabc) */
/* WARNING: Removing unreachable block (ram,0xf002fafc) */
/* WARNING: Removing unreachable block (ram,0xf002fb64) */
/* WARNING: Removing unreachable block (ram,0xf002fbac) */
/* WARNING: Removing unreachable block (ram,0xf002fa44) */

undefined8 sub_F002FA30(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
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
  iVar1 = 2;
  _socreate(2,param_3,2,0);
  if (iVar1 == 0) {
    if ((*(word *)(param_1 + 0xc) & 1) == 0) {
      *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) | 0x21;
      iVar1 = *param_3;
      _ifioctl(iVar1,0x80206910,param_2);
      if (iVar1 != 0) goto locret_F002FBD4;
    }
    else if ((int)((uint)*(word *)(param_1 + 0xc) * 0x10000) < 0) {
      iVar1 = *param_3;
      _ifioctl(iVar1,0xc020690d,param_2);
      if (iVar1 == 0) {
        iVar1 = -1;
        *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
      }
      goto locret_F002FBD4;
    }
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x4000;
    _bzero((undefined *)((int)register0x00000038 + -0x18),0x10);
    *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
    *(undefined2 *)(param_2 + 0x10) = 2;
    *(undefined2 *)(param_2 + 0x12) = *(undefined2 *)((int)register0x00000038 + -0x16);
    *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)((int)register0x00000038 + -0x14);
    *(undefined2 *)(param_2 + 0x16) = *(undefined2 *)((int)register0x00000038 + -0x12);
    *(undefined2 *)(param_2 + 0x18) = *(undefined2 *)((int)register0x00000038 + -0x10);
    *(undefined2 *)(param_2 + 0x1a) = *(undefined2 *)((int)register0x00000038 + -0xe);
    *(undefined2 *)(param_2 + 0x1c) = *(undefined2 *)((int)register0x00000038 + -0xc);
    *(undefined2 *)(param_2 + 0x1e) = *(undefined2 *)((int)register0x00000038 + -10);
    iVar1 = *param_3;
    _ifioctl(iVar1,0x8020690c,param_2);
    iVar2 = 1;
    if (iVar1 == 0) {
      _m_get(1,8);
      param_2 = iVar2;
      if (iVar2 == 0) {
        iVar1 = 0x37;
      }
      else {
        *(undefined2 *)(iVar2 + 8) = 0x10;
        iVar1 = *(int *)(iVar2 + 4);
        *(undefined2 *)(iVar2 + iVar1) = 2;
        iVar1 = iVar2 + iVar1;
        *(undefined2 *)(iVar1 + 2) = 0x44;
        *(undefined4 *)(iVar1 + 4) = 0;
        iVar1 = *param_3;
        _sobind(iVar1,iVar2);
        _m_freem(iVar2);
        if (iVar1 == 0) {
          iVar1 = 0;
          *(word *)(*param_3 + 6) = *(word *)(*param_3 + 6) | 0x100;
        }
      }
    }
  }
  else {
    *param_3 = 0;
  }
locret_F002FBD4:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3282 start=0xf002fbdc */

/* WARNING: Removing unreachable block (ram,0xf002fc84) */
/* WARNING: Removing unreachable block (ram,0xf002fbec) */
/* WARNING: Removing unreachable block (ram,0xf002fc98) */
/* WARNING: Removing unreachable block (ram,0xf002fbe0) */

undefined8 sub_F002FBDC(undefined4 param_1,int param_2,undefined4 param_3)

{
  sword sVar1;
  uint *puVar2;
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
  puVar2 = (uint *)0x148;
  _kalloc();
  _bzero();
  *puVar2 = *puVar2 & 0xffffff | 0x45000000;
  sVar1 = _ip_id + 1;
  *(sword *)(puVar2 + 1) = _ip_id;
  _ip_id = sVar1;
  *(undefined *)(puVar2 + 2) = 0xff;
  *(undefined *)((int)puVar2 + 9) = 0x11;
  puVar2[3] = *(uint *)(param_2 + 4);
  puVar2[4] = 0xffffffff;
  *(undefined2 *)(puVar2 + 5) = 0x44;
  *(undefined2 *)((int)puVar2 + 0x16) = 0x43;
  *(undefined2 *)((int)puVar2 + 0x1a) = 0;
  *(undefined *)(puVar2 + 7) = 1;
  *(undefined *)((int)puVar2 + 0x1d) = 1;
  *(undefined *)((int)puVar2 + 0x1e) = 6;
  puVar2[10] = 0;
  _bcopy(param_3,puVar2 + 0xe,6);
  _bcopy(&aNext_0,puVar2 + 0x42,4);
  *(undefined *)(puVar2 + 0x43) = 1;
  *(undefined *)((int)puVar2 + 0x10e) = 0;
  *(undefined2 *)(puVar2 + 6) = 0x134;
  *(undefined2 *)((int)puVar2 + 2) = 0x148;
  *(undefined2 *)((int)puVar2 + 10) = 0;
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3283 start=0xf002fe88 */

/* WARNING: Removing unreachable block (ram,0xf002fe94) */

undefined8 sub_F002FE88(int *param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = *param_1;
  *param_1 = 0;
  _sbwakeup(iVar1 + 0x24);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3284 start=0xf002fea4 */

sqword sub_F002FEA4(undefined4 *param_1,uint param_2)

{
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
  *param_1 = 0;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3285 start=0xf002feb4 */

/* WARNING: Removing unreachable block (ram,0xf002feec) */

undefined8 sub_F002FEB4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_3;
  *(undefined **)((int)register0x00000038 + -0x28) = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_3;
  _soreceive(param_1,0,(undefined *)((int)register0x00000038 + -0x28),0,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3286 start=0xf002fefc */

/* WARNING: Removing unreachable block (ram,0xf003008c) */
/* WARNING: Removing unreachable block (ram,0xf003021c) */
/* WARNING: Removing unreachable block (ram,0xf0030138) */
/* WARNING: Removing unreachable block (ram,0xf003004c) */
/* WARNING: Removing unreachable block (ram,0xf0030014) */
/* WARNING: Removing unreachable block (ram,0xf002ffa0) */
/* WARNING: Removing unreachable block (ram,0xf002ff8c) */
/* WARNING: Removing unreachable block (ram,0xf002ffc8) */
/* WARNING: Removing unreachable block (ram,0xf0030024) */
/* WARNING: Removing unreachable block (ram,0xf0030124) */
/* WARNING: Removing unreachable block (ram,0xf0030178) */
/* WARNING: Removing unreachable block (ram,0xf0030234) */
/* WARNING: Removing unreachable block (ram,0xf0030248) */
/* WARNING: Removing unreachable block (ram,0xf002ff30) */

undefined8
sub_F002FEFC(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  undefined *puVar7;
  char *pcVar8;
  int iVar9;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(int *)((int)register0x00000038 + 0x4c) = param_3;
  *(int *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  *(int *)((int)register0x00000038 + -0x48) = param_3 + 0x108;
  *(int *)((int)register0x00000038 + -0x4c) = param_4 + 0xec;
  *(undefined4 *)((int)register0x00000038 + -0x50) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x54) = 0;
  _microtime((undefined *)((int)register0x00000038 + -0x10));
  bVar1 = *(byte *)(*(int *)((int)register0x00000038 + 0x54) + 5);
  *(uint *)((int)register0x00000038 + -0x38) =
       (uint)bVar1 ^ *(uint *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
  *(uint *)(*(int *)((int)register0x00000038 + 0x4c) + 0x20) =
       (uint)bVar1 ^ *(uint *)((int)register0x00000038 + -0x10);
  *(undefined2 *)((int)register0x00000038 + -0x28) = 2;
  *(undefined2 *)((int)register0x00000038 + -0x26) = 0x43;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0xffffffff;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 1;
loc_F002FF7C:
  iVar2 = *(int *)((int)register0x00000038 + -0x40);
loc_F002FF80:
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)((int)register0x00000038 + 0x4c);
    _in_bootp_bptombuf();
    *(undefined4 *)((int)register0x00000038 + -0x34) = uVar3;
    piVar4 = *(int **)((int)register0x00000038 + 0x44);
    _if_output_mbuf(piVar4,uVar3,(undefined *)((int)register0x00000038 + -0x28));
    if (piVar4 != (int *)0x0) goto loc_F0030244;
  }
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(dword_F0133DDC + 0x28);
  iVar5 = dword_F0133DDC + 0x28;
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(dword_F0133DDC + 0x2c);
  _setjmp();
  iVar2 = dword_F0133DDC;
  if (iVar5 == 0) {
    pcVar6 = sub_F002FE88;
    puVar7 = (undefined *)((int)register0x00000038 + -0x2c);
    *(undefined4 *)((int)register0x00000038 + -0x2c) =
         *(undefined4 *)((int)register0x00000038 + 0x48);
    iVar2 = _hz;
loc_F0030014:
    _timeout(pcVar6,puVar7,iVar2);
    piVar4 = *(int **)((int)register0x00000038 + 0x48);
loc_F0030020:
    do {
      do {
        while( true ) {
          sub_F002FEB4(piVar4,*(undefined4 *)((int)register0x00000038 + 0x50),300);
          iVar2 = dword_F0133DDC;
          if ((piVar4 != (int *)0x23) ||
             (*(int *)((int)register0x00000038 + -0x2c) != *(int *)((int)register0x00000038 + 0x48))
             ) break;
          _sbwait(*(int *)((int)register0x00000038 + -0x2c) + 0x24);
          piVar4 = *(int **)((int)register0x00000038 + 0x48);
        }
        if ((piVar4 != (int *)0x0) && (piVar4 != (int *)0x23)) {
          *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
          goto loc_F0030084;
        }
        pcVar8 = *(char **)((int)register0x00000038 + 0x50);
        if (*(int *)((int)register0x00000038 + -0x2c) == 0) {
          iVar9 = *(int *)((int)register0x00000038 + -0x40) + 1;
          *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
          *(int *)((int)register0x00000038 + -0x40) = iVar9;
          iVar5 = *(int *)((int)register0x00000038 + -0x3c);
          *(int *)((int)register0x00000038 + -0x44) = *(int *)((int)register0x00000038 + -0x44) + 1;
          *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x14);
          if (iVar9 == iVar5) {
            if (iVar9 < 0x40) {
              *(int *)((int)register0x00000038 + -0x3c) = iVar9 * 2;
              *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
            }
            else {
              *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
            }
          }
          iVar2 = *(int *)((int)register0x00000038 + -0x40);
          if (*(int *)((int)register0x00000038 + -0x44) != 0x14) goto loc_F002FF80;
          piVar4 = *(int **)((int)register0x00000038 + 0x58);
          if ((*piVar4 == 0) && (sub_F0030258(), piVar4 != (int *)0x0)) goto loc_F0030244;
          _printf(aNoResponseFrom);
          *(undefined4 *)((int)register0x00000038 + -0x50) = 1;
          goto loc_F002FF7C;
        }
        piVar4 = *(int **)((int)register0x00000038 + 0x48);
      } while ((*(int *)(pcVar8 + 4) != *(int *)((int)register0x00000038 + -0x38)) ||
              (piVar4 = *(int **)((int)register0x00000038 + 0x48), *pcVar8 != '\x02'));
      pcVar8 = pcVar8 + 0x1c;
      _bcmp(pcVar8,*(undefined4 *)((int)register0x00000038 + 0x54),6);
      iVar2 = dword_F0133DDC;
      piVar4 = *(int **)((int)register0x00000038 + 0x48);
    } while (pcVar8 != (char *)0x0);
    if ((*(char *)(*(int *)((int)register0x00000038 + -0x48) + 6) == '\0') &&
       (*(char *)(*(int *)((int)register0x00000038 + -0x4c) + 6) != '\0')) {
      if (*(int *)((int)register0x00000038 + -0x54) == 0) goto loc_f00301c0;
      piVar4 = *(int **)((int)register0x00000038 + 0x48);
      if (*(int *)((int)register0x00000038 + -0x30) == 1) goto loc_F0030020;
    }
    *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x14);
    _untimeout(sub_F002FE88,(undefined *)((int)register0x00000038 + -0x2c));
    if (*(int *)((int)register0x00000038 + -0x50) != 0) {
      _printf(aNetworkRespond);
    }
    piVar4 = (int *)0x0;
    goto loc_F0030244;
  }
  piVar4 = (int *)0x4;
  *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x18);
loc_F0030084:
  *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x14);
  _untimeout(sub_F002FE88,(undefined *)((int)register0x00000038 + -0x2c));
loc_F0030244:
  _untimeout(sub_F002FEA4,(undefined *)((int)register0x00000038 + -0x30));
  return CONCAT44(param_2,piVar4);
loc_f00301c0:
  *(undefined4 *)((int)register0x00000038 + -0x54) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 1;
  pcVar6 = sub_F002FEA4;
  puVar7 = (undefined *)((int)register0x00000038 + -0x30);
  iVar2 = _hz * 10;
  goto loc_F0030014;
}
/* GHIDRADEC_FUNCTION index=3287 start=0xf0030258 */

/* WARNING: Removing unreachable block (ram,0xf00302b8) */

undefined8 sub_F0030258(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  uVar2 = 0;
  if (dword_F010C4C8 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(dword_F0133DDC + 0x28);
    uVar2 = 0x3c;
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(dword_F0133DDC + 0x2c);
    _alert(0x3c,8,aConfiguringNet,&aL_0,0,0,0,0,0,0,0);
    iVar1 = dword_F0133DDC;
    *(undefined4 *)(dword_F0133DDC + 0x28) = *(undefined4 *)((int)register0x00000038 + -0x10);
    dword_F010C4C8 = 1;
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3288 start=0xf00302e8 */

/* WARNING: Removing unreachable block (ram,0xf00302f0) */

undefined8 sub_F00302E8(undefined4 param_1,undefined4 param_2)

{
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
  dword_F010C4C8 = 0;
  _alert_done();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3289 start=0xf0030300 */

/* WARNING: Removing unreachable block (ram,0xf00303a8) */
/* WARNING: Removing unreachable block (ram,0xf0030338) */
/* WARNING: Removing unreachable block (ram,0xf0030350) */
/* WARNING: Removing unreachable block (ram,0xf00303bc) */
/* WARNING: Removing unreachable block (ram,0xf0030314) */

undefined8 sub_F0030300(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined4 unaff_l0;
  char *pcVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 1;
  iVar6 = 0;
  uVar2 = param_3 + 0xf4U;
  _strlen();
  if (0x37 < uVar2) {
    *(undefined *)(param_3 + 299) = 0;
  }
  _printf(&aS_1,param_3 + 0xf4U);
  iVar3 = 0;
  _kmioctl(0,0x80047410,(undefined *)((int)register0x00000038 + -0xc),0);
  if (iVar3 != 0) goto locret_F003042C;
  bVar1 = *(byte *)(param_3 + 0xf2);
  if (bVar1 == 2) {
    iVar6 = 1;
  }
  else {
    if (2 < bVar1) {
      if (bVar1 == 3) {
        *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
        *(undefined *)(param_2 + 0x10e) = 0;
        *(undefined *)(param_2 + 0x10f) = 0;
      }
      goto locret_F003042C;
    }
    if (bVar1 != 1) goto locret_F003042C;
  }
  iVar3 = 0;
  pcVar5 = (char *)(param_2 + 0x110);
  sub_F003059C(pcVar5,pcVar5,iVar6);
  if (iVar6 != 0) {
    _printf(&asc_F010C598);
  }
  if (*(char *)(param_2 + 0x110) != '\0') {
    cVar4 = *pcVar5;
    do {
      if ((cVar4 == '\n') || (cVar4 == '\r')) {
        *pcVar5 = '\0';
        break;
      }
      pcVar5 = pcVar5 + 1;
      cVar4 = *pcVar5;
    } while (cVar4 != '\0');
  }
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_3 + 0x14);
  *(undefined *)(param_2 + 0x10e) = *(undefined *)(param_3 + 0xf2);
  *(undefined *)(param_2 + 0x10f) = *(undefined *)(param_3 + 0xf3);
locret_F003042C:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3290 start=0xf0030434 */

/* WARNING: Removing unreachable block (ram,0xf003049c) */
/* WARNING: Removing unreachable block (ram,0xf0030480) */
/* WARNING: Removing unreachable block (ram,0xf00304c4) */
/* WARNING: Removing unreachable block (ram,0xf0030454) */

undefined8 sub_F0030434(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) & 0xfffe;
  iVar1 = param_3;
  _ifioctl(param_3,0x80206910,param_2);
  if (iVar1 == 0) {
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
    _bzero(param_2 + 0x10,0x10);
    *(undefined2 *)(param_2 + 0x10) = 2;
    iVar1 = param_3;
    _ifioctl(param_3,0x80206916,param_2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x14) = *param_4;
      _ifioctl(param_3,0x8020690c);
      iVar1 = param_3;
      if (param_3 == 0) {
        iVar1 = 0;
        *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x8000;
      }
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3291 start=0xf00304f4 */

/* WARNING: Removing unreachable block (ram,0xf003054c) */
/* WARNING: Removing unreachable block (ram,0xf0030508) */

undefined8 sub_F00304F4(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  char *pcVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
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
  char acStack_27 [39];
  
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
  pcVar1 = (char *)((int)register0x00000038 + -0x28);
  puVar2 = *(undefined4 **)((int)register0x00000038 + 0x40);
  _strcpy(pcVar1,*param_1);
  if (*(char *)((int)register0x00000038 + -0x28) != '\0') {
    for (pcVar1 = (char *)((int)register0x00000038 + -0x27); *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
    }
  }
  *pcVar1 = (char)*(undefined2 *)(param_1 + 2) + '0';
  pcVar1[1] = '\0';
  _bcopy(param_2,(undefined *)((int)register0x00000038 + -0x18),0x10);
  *puVar2 = *(undefined4 *)((int)register0x00000038 + -0x28);
  puVar2[1] = *(undefined4 *)((int)register0x00000038 + -0x24);
  puVar2[2] = *(undefined4 *)((int)register0x00000038 + -0x20);
  puVar2[3] = *(undefined4 *)((int)register0x00000038 + -0x1c);
  puVar2[4] = *(undefined4 *)((int)register0x00000038 + -0x18);
  puVar2[5] = *(undefined4 *)((int)register0x00000038 + -0x14);
  puVar2[6] = *(undefined4 *)((int)register0x00000038 + -0x10);
  puVar2[7] = *(undefined4 *)((int)register0x00000038 + -0xc);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3292 start=0xf003059c */

/* WARNING: Removing unreachable block (ram,0xf0030660) */
/* WARNING: Removing unreachable block (ram,0xf003067c) */
/* WARNING: Removing unreachable block (ram,0xf0030634) */
/* WARNING: Removing unreachable block (ram,0xf00305ac) */
/* WARNING: Removing unreachable block (ram,0xf003063c) */
/* WARNING: Removing unreachable block (ram,0xf0030650) */
/* WARNING: Removing unreachable block (ram,0xf0030668) */
/* WARNING: Removing unreachable block (ram,0xf00305bc) */

undefined8 sub_F003059C(undefined *param_1,undefined *param_2,int param_3)

{
  uint uVar1;
  undefined uVar2;
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
  while( true ) {
    if (param_3 == 0) {
      uVar1 = 0;
      _kmgetc();
    }
    else {
      uVar1 = 0;
      _kmgetc_silent();
    }
    uVar1 = uVar1 & 0x7f;
    if (uVar1 == 0xd) break;
    uVar2 = (undefined)uVar1;
    if (uVar1 < 0xe) {
      if (uVar1 == 8) {
loc_F0030644:
        if (param_2 == param_1) {
loc_F0030650:
          _cnputc(8);
        }
        else {
          _cnputc(0x20);
          _cnputc(8);
          param_2 = param_2 + -1;
        }
      }
      else {
        if (uVar1 == 10) {
          *param_2 = 0;
locret_F0030694:
          return CONCAT44(param_2,param_1);
        }
        *param_2 = uVar2;
loc_F003068C:
        param_2 = param_2 + 1;
      }
    }
    else {
      if (uVar1 != 0x40) {
        if (uVar1 < 0x41) {
          if (uVar1 == 0x15) goto loc_F003067C;
          *param_2 = uVar2;
        }
        else {
          if (uVar1 == 0x7f) {
            if (param_2 != param_1) {
              _cnputc(8);
              _cnputc(8);
              goto loc_F0030644;
            }
            goto loc_F0030650;
          }
          *param_2 = uVar2;
        }
        goto loc_F003068C;
      }
loc_F003067C:
      _cnputc(10);
      param_2 = param_1;
    }
  }
  *param_2 = 0;
  goto locret_F0030694;
}
/* GHIDRADEC_FUNCTION index=3293 start=0xf00392b4 */

undefined8 sub_F00392B4(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
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
  iVar2 = param_1[1];
  if (iVar2 == 0) {
    if (*param_1 == 0) goto locret_F0039304;
    iVar1 = *param_1;
    while( true ) {
      iVar2 = *(int *)(iVar1 + 0x44);
      iVar1 = *(int *)(iVar1 + 0x40);
      *param_1 = iVar1;
      if (iVar2 != 0) break;
      if (iVar1 == 0) goto locret_F0039304;
      iVar1 = *param_1;
    }
  }
  param_1[1] = *(int *)(iVar2 + 0x14);
locret_F0039304:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3294 start=0xf003930c */

/* WARNING: Removing unreachable block (ram,0xf0039320) */

undefined8 sub_F003930C(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  
  uVar1 = _in_ifaddr;
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
  param_1[1] = 0;
  *param_1 = uVar1;
  sub_F00392B4();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3295 start=0xf003979c */

/* WARNING: Removing unreachable block (ram,0xf00397a4) */

undefined8 sub_F003979C(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar4 = *(int *)(param_1 + 0x30);
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  *(undefined4 *)(iVar4 + 0xc0) = *(undefined4 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(iVar4 + 0xc4) = *(undefined4 *)((int)register0x00000038 + -0xc);
  uVar3 = *(int *)((int)register0x00000038 + -0x10) - *(int *)(iVar4 + 0xa8) >> 4;
  if (*(int *)(param_1 + 0x28) == 2) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    uVar1 = *(uint *)(iVar2 + 0x68);
    if (uVar1 <= uVar3) {
      uVar1 = *(uint *)(iVar2 + 0x6c);
loc_F0039814:
      if (uVar3 <= uVar1) {
        iVar2 = *(int *)(iVar4 + 0xc0);
        goto loc_F0039828;
      }
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
    uVar1 = *(uint *)(iVar2 + 0x60);
    if (uVar1 <= uVar3) {
      uVar1 = *(uint *)(iVar2 + 100);
      goto loc_F0039814;
    }
  }
  iVar2 = *(int *)(iVar4 + 0xc0);
  uVar3 = uVar1;
loc_F0039828:
  *(uint *)(iVar4 + 0xc0) = iVar2 + uVar3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3296 start=0xf0039838 */

/* WARNING: Removing unreachable block (ram,0xf0039880) */
/* WARNING: Removing unreachable block (ram,0xf0039840) */

undefined8 sub_F0039838(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar2 = param_1[0xc];
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  if (*(int *)(iVar2 + 0xc0) <= *(int *)((int)register0x00000038 + -0x10)) {
    if (*(int *)((int)register0x00000038 + -0x10) != *(int *)(iVar2 + 0xc0)) {
      uVar3 = 0;
      goto locret_F00398E4;
    }
    if (*(int *)(iVar2 + 0xc4) <= *(int *)((int)register0x00000038 + -0xc)) {
      uVar3 = 0;
      goto locret_F00398E4;
    }
  }
  _memcpy(param_2,iVar2 + 0x80,0x40);
  *(uint *)(param_2 + 0xc) = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x28) | 0xff00;
  uVar1 = *(uint *)(*param_1 + 0x14);
  if (*(uint *)(param_2 + 0x18) < uVar1) {
    if ((*(uint *)(*param_1 + 0x38) & 0x40000000) == 0) {
      uVar3 = 1;
      if ((*(word *)(iVar2 + 0x60) & 0x10) == 0) goto locret_F00398E4;
      *(uint *)(param_2 + 0x18) = uVar1;
    }
    else {
      *(uint *)(param_2 + 0x18) = uVar1;
    }
  }
  uVar3 = 1;
locret_F00398E4:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3297 start=0xf003a630 */

/* WARNING: Removing unreachable block (ram,0xf003a688) */
/* WARNING: Removing unreachable block (ram,0xf003a694) */
/* WARNING: Removing unreachable block (ram,0xf003a638) */

undefined8 sub_F003A630(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
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
  sub_F003C020(param_1,param_3);
  if (param_1 == 0) {
    *param_2 = 0x46;
  }
  else {
    iVar1 = param_1;
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
              (param_1,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
    if (iVar1 == 0) {
      _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 1);
      *param_2 = 0;
    }
    else {
      *param_2 = iVar1;
    }
    _vn_rele(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3298 start=0xf003a6a4 */

/* WARNING: Removing unreachable block (ram,0xf003a850) */
/* WARNING: Removing unreachable block (ram,0xf003a70c) */
/* WARNING: Removing unreachable block (ram,0xf003a6ec) */
/* WARNING: Removing unreachable block (ram,0xf003a7c4) */
/* WARNING: Removing unreachable block (ram,0xf003a85c) */
/* WARNING: Removing unreachable block (ram,0xf003a6b0) */

undefined8 sub_F003A6A4(undefined *param_1,int *param_2,uint *param_3,int param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  int iVar4;
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
  bool bVar5;
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
  puVar3 = (undefined *)0x0;
  puVar1 = param_1;
  sub_F003C020(param_1,param_3);
  if (puVar1 == (undefined *)0x0) {
    *param_2 = 0x46;
    goto locret_F003A864;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) != 0) {
      iVar4 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar4,param_3 + 6);
      if (iVar4 == 0) {
        iVar4 = 0x1e;
        goto loc_F003A858;
      }
    }
    sub_F003BFCC(param_1 + 0x20,(undefined *)((int)register0x00000038 + -0x48));
    if (*(int *)((int)register0x00000038 + -0x20) == -1) {
loc_F003A74C:
      iVar4 = *(int *)(puVar1 + 0x28);
    }
    else {
      if (*(int *)((int)register0x00000038 + -0x1c) == 1000000) {
        *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0xffffffff;
        *(undefined4 *)((int)register0x00000038 + -0x28) = 0xffffffff;
        *(undefined4 *)((int)register0x00000038 + -0x24) = 0xffffffff;
        goto loc_F003A74C;
      }
      iVar4 = *(int *)(puVar1 + 0x28);
    }
    bVar5 = true;
    if (iVar4 == 1) {
      param_1 = DAT_f0133c00;
      if (*(int *)((int)register0x00000038 + -0x30) != -1) {
        iVar4 = *(int *)(puVar1 + 0x1c);
        uVar2 = *(undefined4 *)(_active_u + 0x1c);
        *(undefined *)((int)register0x00000038 + -0x89) = 0;
        puVar3 = puVar1;
        (**(code **)(iVar4 + 0x14))(puVar1,(undefined *)((int)register0x00000038 + -0x88),uVar2);
        bVar5 = puVar3 == (undefined *)0x0;
        if (!bVar5) goto loc_F003A7EC;
        if (*(uint *)((int)register0x00000038 + -0x70) < *(uint *)((int)register0x00000038 + -0x30))
        {
          puVar3 = (undefined *)0x1;
          _vn_rdwr(1,puVar1,(undefined *)((int)register0x00000038 + -0x89),1,
                   *(uint *)((int)register0x00000038 + -0x30) - 1,1,4,0);
          (**(code **)(*(int *)(puVar1 + 0x1c) + 0x48))(puVar1,*(undefined4 *)(_active_u + 0x1c));
        }
      }
      bVar5 = puVar3 == (undefined *)0x0;
    }
loc_F003A7EC:
    if (bVar5) {
      param_1 = (undefined *)((int)register0x00000038 + -0x48);
      puVar3 = puVar1;
      (**(code **)(*(int *)(puVar1 + 0x1c) + 0x18))
                (puVar1,param_1,*(undefined4 *)(_active_u + 0x1c));
      if (puVar3 == (undefined *)0x0) {
        puVar3 = puVar1;
        (**(code **)(*(int *)(puVar1 + 0x1c) + 0x14))
                  (puVar1,param_1,*(undefined4 *)(_active_u + 0x1c));
        if (puVar3 == (undefined *)0x0) {
          _vattr_to_nattr(param_1,param_2 + 1);
          iVar4 = 0;
          goto loc_F003A858;
        }
        *param_2 = (int)puVar3;
      }
      else {
        *param_2 = (int)puVar3;
      }
    }
    else {
      *param_2 = (int)puVar3;
    }
  }
  else {
    iVar4 = 0x1e;
loc_F003A858:
    *param_2 = iVar4;
  }
  _vn_rele(puVar1);
locret_F003A864:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3299 start=0xf003a86c */

/* WARNING: Removing unreachable block (ram,0xf003a94c) */
/* WARNING: Removing unreachable block (ram,0xf003a924) */
/* WARNING: Removing unreachable block (ram,0xf003a934) */
/* WARNING: Removing unreachable block (ram,0xf003a954) */
/* WARNING: Removing unreachable block (ram,0xf003a89c) */

undefined8 sub_F003A86C(undefined *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
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
  if ((*(char **)((int)param_1 + 0x20) == (char *)0x0) || (**(char **)((int)param_1 + 0x20) == '\0')
     ) {
    *param_2 = 0xd;
    goto locret_F003A95C;
  }
  puVar2 = (undefined4 *)param_1;
  sub_F003C020(param_1,param_3);
  if (puVar2 == (undefined4 *)0x0) {
    *param_2 = 0x46;
    goto locret_F003A95C;
  }
  puVar1 = (undefined4 *)((int)param_1 + 0x20);
  param_1 = DAT_f0133c00;
  puVar3 = puVar2;
  (**(code **)(puVar2[7] + 0x20))
            (puVar2,*puVar1,(undefined *)((int)register0x00000038 + -0x4c),
             *(undefined4 *)(_active_u + 0x1c),0,0);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0x4c);
    param_1 = (undefined *)((int)register0x00000038 + -0x48);
    (**(code **)(puVar3[7] + 0x14))(puVar3,param_1,*(undefined4 *)(_active_u + 0x1c));
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    if (puVar3 == (undefined4 *)0x0) {
      _vattr_to_nattr(param_1,param_2 + 9);
      puVar3 = param_2 + 1;
      _makefh(puVar3,*(undefined4 *)((int)register0x00000038 + -0x4c),param_3);
      goto loc_F003A93C;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
loc_F003A93C:
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  }
  *param_2 = puVar3;
  if (iVar4 != 0) {
    _vn_rele(iVar4);
  }
  _vn_rele(puVar2);
locret_F003A95C:
  return CONCAT44(param_2,param_1);
}

