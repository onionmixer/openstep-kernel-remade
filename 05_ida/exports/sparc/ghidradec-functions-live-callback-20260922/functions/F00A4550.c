
undefined8 _copy_memlist(qword *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  qword qVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  qword *pqVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
  undefined4 unaff_i3;
  qword *pqVar5;
  undefined4 unaff_i4;
  undefined4 *puVar6;
  undefined4 unaff_i5;
  qword *pqVar7;
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
  pqVar5 = (qword *)*param_2;
  if (param_3 == 0) {
    if (param_1 == (qword *)0x0) {
      *param_2 = pqVar5;
      goto locret_F00A4640;
    }
    puVar1 = (undefined4 *)((int)pqVar5 + 0x14);
    qVar2 = *param_1;
    pqVar3 = param_1;
    pqVar7 = pqVar5;
    while( true ) {
      *pqVar5 = qVar2;
      *(qword *)(puVar1 + -3) = pqVar3[1];
      puVar1[-1] = 0;
      if (pqVar7 == pqVar5) {
        *puVar1 = 0;
      }
      else {
        *puVar1 = pqVar7;
        *(qword **)(pqVar7 + 2) = pqVar5;
        pqVar7 = pqVar7 + 3;
      }
      pqVar5 = pqVar5 + 3;
      puVar1 = puVar1 + 6;
      pqVar3 = *(qword **)(pqVar3 + 2);
      param_1 = (qword *)0x0;
      if (pqVar3 == (qword *)0x0) break;
      qVar2 = *pqVar3;
    }
  }
  else {
    puVar6 = (undefined4 *)((int)pqVar5 + 0x14);
    puVar1 = param_2;
    if (param_1 != (qword *)0x0) {
      uVar4 = *(uint *)param_1;
      pqVar3 = pqVar5;
      while( true ) {
        *pqVar5 = (qword)uVar4;
        puVar1 = *(undefined4 **)((int)param_1 + 4);
        *(qword *)(puVar6 + -3) = ZEXT48(puVar1);
        puVar6[-1] = 0;
        if (pqVar3 == pqVar5) {
          *puVar6 = 0;
        }
        else {
          *puVar6 = pqVar3;
          *(qword **)(pqVar3 + 2) = pqVar5;
          pqVar3 = pqVar3 + 3;
        }
        puVar6 = puVar6 + 6;
        pqVar5 = pqVar5 + 3;
        param_1 = *(qword **)(param_1 + 1);
        if (param_1 == (qword *)0x0) break;
        uVar4 = *(uint *)param_1;
      }
      *param_2 = pqVar5;
      param_1 = (qword *)0x0;
      param_2 = puVar1;
      goto locret_F00A4640;
    }
  }
  *param_2 = pqVar5;
  param_2 = puVar1;
locret_F00A4640:
  return CONCAT44(param_2,param_1);
}

