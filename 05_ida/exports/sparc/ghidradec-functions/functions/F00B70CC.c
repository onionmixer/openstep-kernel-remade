
/* WARNING: Removing unreachable block (ram,0xf00b7190) */
/* WARNING: Removing unreachable block (ram,0xf00b7174) */
/* WARNING: Removing unreachable block (ram,0xf00b7158) */
/* WARNING: Removing unreachable block (ram,0xf00b7188) */
/* WARNING: Removing unreachable block (ram,0xf00b71e4) */
/* WARNING: Removing unreachable block (ram,0xf00b7130) */

undefined8 _esp_runpoll(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
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
  iVar6 = *(int *)(((param_2 << 0x10) >> 0xe) + param_1 + 0xb8);
  iVar4 = *(int *)(param_1 + 0x80) + 1;
  iVar5 = *(int *)(iVar6 + 0x18);
  *(int *)(param_1 + 0x80) = iVar4;
  if (iVar4 == 0) {
loc_F00B71C8:
    if (*(char *)(param_1 + 0x41) == '\0') {
      _esp_ustart(param_1,(int)(sword)param_2 + 1U & 0x3f);
    }
locret_F00B71EC:
    return CONCAT44(param_2,param_1);
  }
  cVar1 = *(char *)(param_1 + 0x41);
  do {
    if (cVar1 != '\0') {
      iVar4 = param_1;
      _esp_dopoll(param_1,180000000);
      puVar2 = aRunpollTimeout;
      if (iVar4 != 0) {
loc_F00B7188:
        _printf(puVar2);
        _esp_abort_curcmd(param_1);
        goto locret_F00B71EC;
      }
    }
    if (*(int *)(param_1 + 0x80) == 0) goto loc_F00B71C8;
    iVar4 = param_1;
    _esp_ustart(param_1,(int)(sword)param_2);
    iVar3 = *(int *)(param_1 + 0x80);
    if (iVar4 == 1) {
      do {
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x80);
          break;
        }
        iVar4 = param_1;
        _esp_dopoll(param_1,iVar5 * 1000000);
        puVar2 = aRunpollTimeout_0;
        if (iVar4 != 0) goto loc_F00B7188;
        iVar3 = *(int *)(param_1 + 0x80);
      } while (*(char *)(iVar6 + 0x29) != '\0');
    }
    if (iVar3 == 0) goto loc_F00B71C8;
    cVar1 = *(char *)(param_1 + 0x41);
  } while( true );
}
