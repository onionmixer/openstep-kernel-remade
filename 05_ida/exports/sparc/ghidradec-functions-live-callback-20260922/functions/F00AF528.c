
/* WARNING: Removing unreachable block (ram,0xf00af5a0) */
/* WARNING: Removing unreachable block (ram,0xf00af568) */
/* WARNING: Removing unreachable block (ram,0xf00af5b4) */
/* WARNING: Removing unreachable block (ram,0xf00af560) */

undefined8 _prom_findnode_byname(int param_1,undefined4 param_2,uint *param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
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
  bVar1 = false;
loc_F00AF578:
  do {
    if (param_1 == -1) {
      piVar3 = (int *)*param_3;
    }
    else {
      piVar3 = (int *)*param_3;
      if (param_1 != 0) {
        *param_3 = (uint)(piVar3 + 1);
        *piVar3 = param_1;
        if (param_3[2] < *param_3) {
          _panic(aMaxstackExceed);
        }
        _prom_childnode();
        goto loc_F00AF578;
      }
    }
    if ((int *)param_3[1] < piVar3) {
      *param_3 = (uint)(piVar3 + -1);
      param_1 = piVar3[-1];
      iVar2 = param_1;
      _prom_getnode_byname(param_1,param_2);
      if (iVar2 != 0) goto locret_F00AF5D8;
      _prom_nextnode();
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      param_1 = 0;
locret_F00AF5D8:
      return CONCAT44(param_2,param_1);
    }
  } while( true );
}

