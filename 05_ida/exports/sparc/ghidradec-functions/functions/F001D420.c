
undefined8 _pffindproto(int param_1,int param_2,int param_3)

{
  sword sVar1;
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
  sword *psVar4;
  sword *psVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  sword *psVar6;
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
  if (param_1 == 0) {
loc_F001D464:
    psVar5 = (sword *)0x0;
  }
  else if (_domains == (int *)0x0) {
    psVar5 = (sword *)0x0;
  }
  else {
    iVar2 = *_domains;
    piVar3 = _domains;
    while (iVar2 != param_1) {
      piVar3 = (int *)piVar3[7];
      if (piVar3 == (int *)0x0) goto loc_F001D464;
      iVar2 = *piVar3;
    }
    psVar4 = (sword *)piVar3[5];
    if (psVar4 < (sword *)piVar3[6]) {
      sVar1 = psVar4[4];
      psVar6 = (sword *)0x0;
      while ((sVar1 != param_2 || (psVar5 = psVar4, *psVar4 != param_3))) {
        psVar5 = psVar6;
        if ((param_3 == 3) && (((*psVar4 == 3 && (sVar1 == 0)) && (psVar6 == (sword *)0x0)))) {
          psVar5 = psVar4;
        }
        if ((sword *)piVar3[6] <= psVar4 + 0x18) break;
        sVar1 = psVar4[0x1c];
        psVar4 = psVar4 + 0x18;
        psVar6 = psVar5;
      }
    }
    else {
      psVar5 = (sword *)0x0;
    }
  }
  return CONCAT44(param_2,psVar5);
}
