
/* WARNING: Removing unreachable block (ram,0xf0034a90) */
/* WARNING: Removing unreachable block (ram,0xf0034a64) */
/* WARNING: Removing unreachable block (ram,0xf0034ae0) */
/* WARNING: Removing unreachable block (ram,0xf0034b30) */
/* WARNING: Removing unreachable block (ram,0xf0034aa0) */
/* WARNING: Removing unreachable block (ram,0xf0034b70) */
/* WARNING: Removing unreachable block (ram,0xf0034b40) */

undefined8 _rip_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

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
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar3;
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
  iVar2 = 0;
  iVar3 = *(int *)(param_2 + 8);
  if (param_3 == 0) {
    if (param_1 == 0) {
      if (param_4 == 1) {
        iVar1 = 1;
        _m_get(1,10);
        *param_5 = iVar1;
        if (*(int *)(iVar3 + 0x34) == 0) {
          *(undefined2 *)(iVar1 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(*(int *)(iVar3 + 0x34) + 4);
          *(undefined2 *)(*param_5 + 8) = *(undefined2 *)(*(int *)(iVar3 + 0x34) + 8);
          iVar1 = *param_5;
          _bcopy(*(int *)(iVar3 + 0x34) + *(int *)(*(int *)(iVar3 + 0x34) + 4),
                 iVar1 + *(int *)(iVar1 + 4),(int)*(sword *)(iVar1 + 8));
        }
      }
      else {
        if (param_4 < 1) goto loc_F0034B50;
        iVar2 = 0x16;
        if ((param_4 < 8) && (2 < param_4)) {
          _ip_getmoptions(param_4,*(undefined4 *)(iVar3 + 0x50),param_5);
          iVar2 = param_4;
        }
      }
    }
    else if (param_1 == 1) {
      if (param_4 == 1) {
        iVar2 = iVar3 + 0x34;
        _ip_pcbopts(iVar2,*param_5);
        goto locret_F0034B78;
      }
      if (((param_4 < 1) || (7 < param_4)) || (param_4 < 3)) {
        _ip_mrouter_cmd(param_4,param_2,*param_5);
        iVar2 = param_4;
      }
      else {
        _ip_setmoptions(param_4,iVar3 + 0x50,*param_5);
        iVar2 = param_4;
      }
    }
  }
  else {
loc_F0034B50:
    iVar2 = 0x16;
  }
  if ((param_1 == 1) && (*param_5 != 0)) {
    _m_free();
  }
locret_F0034B78:
  return CONCAT44(param_2,iVar2);
}
