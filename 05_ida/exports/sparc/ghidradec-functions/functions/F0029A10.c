
undefined8 _ifa_ifwithnet(word *param_1,undefined4 param_2)

{
  word wVar1;
  word *pwVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  code *pcVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  word *pwVar5;
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
  if ((*param_1 < 0x11) && (pcVar4 = *(code **)(DAT_f010c154 + (uint)*param_1 * 8), _ifnet != 0)) {
    pwVar5 = *(word **)(_ifnet + 0x18);
    iVar3 = _ifnet;
    while( true ) {
      if (pwVar5 == (word *)0x0) {
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      else {
        wVar1 = *pwVar5;
        while( true ) {
          if (wVar1 == *param_1) {
            pwVar2 = pwVar5;
            (*pcVar4)(pwVar5,param_1);
            if (pwVar2 != (word *)0x0) goto locret_F0029AA8;
            pwVar5 = *(word **)(pwVar5 + 0x12);
          }
          else {
            pwVar5 = *(word **)(pwVar5 + 0x12);
          }
          if (pwVar5 == (word *)0x0) break;
          wVar1 = *pwVar5;
        }
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      if (iVar3 == 0) break;
      pwVar5 = *(word **)(iVar3 + 0x18);
    }
  }
  pwVar5 = (word *)0x0;
locret_F0029AA8:
  return CONCAT44(param_2,pwVar5);
}
