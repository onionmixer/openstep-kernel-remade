
/* WARNING: Removing unreachable block (ram,0xf002993c) */
/* WARNING: Removing unreachable block (ram,0xf0029910) */

undefined8 _ifa_ifwithaddr(sword *param_1,undefined4 param_2)

{
  sword sVar1;
  sword *psVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar4;
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
  if (_ifnet != 0) {
    psVar4 = *(sword **)(_ifnet + 0x18);
    iVar3 = _ifnet;
    while( true ) {
      if (psVar4 == (sword *)0x0) {
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      else {
        sVar1 = *psVar4;
        while( true ) {
          if (sVar1 == *param_1) {
            psVar2 = psVar4 + 1;
            _bcmp(psVar2,param_1 + 1,0xe);
            if (psVar2 == (sword *)0x0) goto locret_F0029974;
            if ((*(word *)(iVar3 + 0xc) & 2) == 0) {
              psVar4 = *(sword **)(psVar4 + 0x12);
            }
            else {
              psVar2 = psVar4 + 9;
              _bcmp(psVar2,param_1 + 1,0xe);
              if (psVar2 == (sword *)0x0) goto locret_F0029974;
              psVar4 = *(sword **)(psVar4 + 0x12);
            }
          }
          else {
            psVar4 = *(sword **)(psVar4 + 0x12);
          }
          if (psVar4 == (sword *)0x0) break;
          sVar1 = *psVar4;
        }
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      if (iVar3 == 0) break;
      psVar4 = *(sword **)(iVar3 + 0x18);
    }
  }
  psVar4 = (sword *)0x0;
locret_F0029974:
  return CONCAT44(param_2,psVar4);
}
