
/* WARNING: Removing unreachable block (ram,0xf0076bbc) */
/* WARNING: Removing unreachable block (ram,0xf0076ab8) */
/* WARNING: Removing unreachable block (ram,0xf0076b44) */
/* WARNING: Removing unreachable block (ram,0xf0076bcc) */
/* WARNING: Removing unreachable block (ram,0xf0076a94) */

undefined8 _calloutDispatchUnique(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
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
  if (dword_F0110BB0 != 0) {
    iVar1 = dword_F0110BB0;
    _splusclock();
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar4 = &dword_F0130F20;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    puVar4 = dword_F0130F2C;
    if ((undefined4 **)dword_F0130F2C != &dword_F0130F2C) {
      iVar2 = dword_F0130F2C[2];
      do {
        if (iVar2 == param_1) {
          if (puVar4[3] == param_2) break;
          puVar4 = (undefined4 *)*puVar4;
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
        if ((undefined4 **)puVar4 == &dword_F0130F2C) break;
        iVar2 = puVar4[2];
      } while( true );
    }
    if ((undefined4 **)puVar4 == &dword_F0130F2C) {
      if ((int **)dword_F0130F24 == &dword_F0130F24) {
        _panic(aInternalentrya);
      }
      if ((int **)dword_F0130F24 == &dword_F0130F24) {
        piVar3 = (int *)0x0;
      }
      else {
        *(int ***)(*dword_F0130F24 + 4) = &dword_F0130F24;
        piVar3 = dword_F0130F24;
        dword_F0130F24 = (int *)*dword_F0130F24;
      }
      piVar3[2] = param_1;
      piVar3[3] = param_2;
      piVar3[4] = 0;
      piVar3[6] = 0;
      piVar3[7] = 0;
      *piVar3 = (int)&dword_F0130F2C;
      piVar3[1] = (int)DAT_f0130f30;
      *DAT_f0130f30 = (int)piVar3;
      dword_F0130F3C = dword_F0130F3C + 1;
      DAT_f0130f30 = piVar3;
      piVar3[8] = 1;
      sub_F00773A8();
    }
    else {
      dword_F0130F20 = 0;
    }
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
