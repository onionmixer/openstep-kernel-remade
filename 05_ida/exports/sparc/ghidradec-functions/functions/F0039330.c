
/* WARNING: Removing unreachable block (ram,0xf00393a0) */
/* WARNING: Removing unreachable block (ram,0xf0039358) */
/* WARNING: Removing unreachable block (ram,0xf0039390) */
/* WARNING: Removing unreachable block (ram,0xf00393b4) */
/* WARNING: Removing unreachable block (ram,0xf0039348) */

undefined8 _igmp_fasttimo(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
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
  if (dword_F010C9CC != 0) {
    iVar1 = dword_F010C9CC;
    _splnet();
    dword_F010C9CC = 0;
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    sub_F003930C();
    if (puVar2 != (undefined *)0x0) {
      iVar3 = *(int *)(puVar2 + 0x10);
      while( true ) {
        if (iVar3 != 0) {
          *(int *)(puVar2 + 0x10) = iVar3 + -1;
          if (iVar3 + -1 == 0) {
            _igmp_sendreport(puVar2);
          }
          else {
            dword_F010C9CC = 1;
          }
        }
        puVar2 = (undefined *)((int)register0x00000038 + -0x10);
        sub_F00392B4();
        if (puVar2 == (undefined *)0x0) break;
        iVar3 = *(int *)(puVar2 + 0x10);
      }
    }
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
