
/* WARNING: Removing unreachable block (ram,0xf00299d0) */

undefined8 _ifa_ifwithdstaddr(sword *param_1,undefined4 param_2)

{
  word wVar1;
  sword sVar2;
  sword *psVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar5;
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
    wVar1 = *(word *)(_ifnet + 0xc);
    iVar4 = _ifnet;
    while( true ) {
      if ((wVar1 & 0x10) == 0) {
        iVar4 = *(int *)(iVar4 + 0x5c);
      }
      else {
        psVar5 = *(sword **)(iVar4 + 0x18);
        if (psVar5 == (sword *)0x0) {
          iVar4 = *(int *)(iVar4 + 0x5c);
        }
        else {
          sVar2 = *psVar5;
          while( true ) {
            if (sVar2 == *param_1) {
              psVar3 = psVar5 + 9;
              _bcmp(psVar3,param_1 + 1,0xe);
              if (psVar3 == (sword *)0x0) goto locret_F0029A08;
              psVar5 = *(sword **)(psVar5 + 0x12);
            }
            else {
              psVar5 = *(sword **)(psVar5 + 0x12);
            }
            if (psVar5 == (sword *)0x0) break;
            sVar2 = *psVar5;
          }
          iVar4 = *(int *)(iVar4 + 0x5c);
        }
      }
      if (iVar4 == 0) break;
      wVar1 = *(word *)(iVar4 + 0xc);
    }
  }
  psVar5 = (sword *)0x0;
locret_F0029A08:
  return CONCAT44(param_2,psVar5);
}
