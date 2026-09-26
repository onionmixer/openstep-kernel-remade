
/* WARNING: Removing unreachable block (ram,0xf003082c) */
/* WARNING: Removing unreachable block (ram,0xf00308c0) */
/* WARNING: Removing unreachable block (ram,0xf003076c) */

undefined8 _in_pcbbind(int param_1,int param_2)

{
  sword *psVar1;
  undefined2 uVar2;
  int iVar3;
  word wVar4;
  undefined4 unaff_l0;
  word wVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  iVar7 = *(int *)(param_1 + 0x1c);
  wVar5 = 0;
  iVar6 = *(int *)(param_1 + 8);
  if (_in_ifaddr == 0) {
loc_F0030780:
    uVar8 = 0x31;
  }
  else {
    if (*(sword *)(param_1 + 0x18) != 0) {
      uVar8 = 0x16;
      goto locret_F00308DC;
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      uVar8 = 0x16;
      goto locret_F00308DC;
    }
    if (param_2 != 0) {
      psVar1 = (sword *)(param_2 + 8);
      param_2 = param_2 + *(int *)(param_2 + 4);
      if (*psVar1 != 0x10) {
        uVar8 = 0x16;
        goto locret_F00308DC;
      }
      if (*(int *)(param_2 + 4) != 0) {
        uVar2 = *(undefined2 *)(param_2 + 2);
        *(undefined2 *)(param_2 + 2) = 0;
        iVar3 = param_2;
        _ifa_ifwithaddr();
        if (iVar3 == 0) goto loc_F0030780;
        *(undefined2 *)(param_2 + 2) = uVar2;
      }
      wVar5 = *(word *)(param_2 + 2);
      if (wVar5 == 0) {
        uVar8 = *(undefined4 *)(param_2 + 4);
      }
      else {
        uVar8 = 0;
        if (wVar5 < 0x400) {
          if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
            wVar4 = *(word *)(iVar7 + 2);
          }
          else {
            if ((*(word *)(iVar7 + 6) & 0x80) == 0) {
              uVar8 = 0xd;
              goto locret_F00308DC;
            }
            wVar4 = *(word *)(iVar7 + 2);
          }
        }
        else {
          wVar4 = *(word *)(iVar7 + 2);
        }
        if (((wVar4 & 4) == 0) &&
           (((*(word *)(*(int *)(iVar7 + 0xc) + 10) & 4) == 0 || ((wVar4 & 2) == 0)))) {
          uVar8 = 1;
        }
        *(undefined4 *)((int)register0x00000038 + -0xc) = _zeroin_addr;
        *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_2 + 4);
        iVar7 = iVar6;
        _in_pcblookup(iVar6,(undefined *)((int)register0x00000038 + -0xc),0,
                      (undefined *)((int)register0x00000038 + -0x10),wVar5,uVar8);
        if (iVar7 != 0) {
          uVar8 = 0x30;
          goto locret_F00308DC;
        }
        uVar8 = *(undefined4 *)(param_2 + 4);
      }
      *(undefined4 *)(param_1 + 0x14) = uVar8;
    }
    if (wVar5 == 0) {
      param_2 = 0xa00;
      wVar5 = *(word *)(iVar6 + 0x18);
      while( true ) {
        *(word *)(iVar6 + 0x18) = wVar5 + 1;
        if ((wVar5 < 0xa00) || (5000 < (word)(wVar5 + 1))) {
          *(undefined2 *)(iVar6 + 0x18) = 0xa00;
        }
        uVar2 = *(undefined2 *)(iVar6 + 0x18);
        *(undefined4 *)((int)register0x00000038 + -0x10) = _zeroin_addr;
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
        iVar7 = iVar6;
        _in_pcblookup(iVar6,(undefined *)((int)register0x00000038 + -0x10),0,
                      (undefined *)((int)register0x00000038 + -0xc),uVar2,0);
        if (iVar7 == 0) break;
        wVar5 = *(word *)(iVar6 + 0x18);
      }
      *(undefined2 *)(param_1 + 0x18) = uVar2;
    }
    else {
      *(word *)(param_1 + 0x18) = wVar5;
    }
    uVar8 = 0;
  }
locret_F00308DC:
  return CONCAT44(param_2,uVar8);
}

