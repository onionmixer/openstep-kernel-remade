
/* WARNING: Removing unreachable block (ram,0xf0025f84) */
/* WARNING: Removing unreachable block (ram,0xf0025f24) */

undefined8 sub_F0025EC0(int param_1,char *param_2,int param_3,int param_4,int param_5)

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
  undefined4 *puVar4;
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
  puVar4 = *(undefined4 **)(_nc_hash + param_4 * 8);
  if (puVar4 == (undefined4 *)(_nc_hash + param_4 * 8)) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar1 = puVar4[5];
    while( true ) {
      if (iVar1 == param_1) {
        if (*(char *)(puVar4 + 6) == param_3) {
          if (*(char *)((int)puVar4 + 0x19) == *param_2) {
            puVar2 = (undefined *)((int)puVar4 + 0x19);
            _bcmp(puVar2,param_2,param_3);
            if (puVar2 == (undefined *)0x0) {
              if ((param_5 == -1) || (iVar1 = puVar4[0xf], iVar1 == param_5)) goto locret_F0025FAC;
              if (*(sword *)(param_5 + 2) == *(sword *)(iVar1 + 2)) {
                if (*(sword *)(param_5 + 4) == *(sword *)(iVar1 + 4)) {
                  iVar3 = param_5 + 10;
                  _bcmp(iVar3,iVar1 + 10,0x20);
                  if (iVar3 == 0) goto locret_F0025FAC;
                  puVar4 = (undefined4 *)*puVar4;
                }
                else {
                  puVar4 = (undefined4 *)*puVar4;
                }
              }
              else {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
            else {
              puVar4 = (undefined4 *)*puVar4;
            }
          }
          else {
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)(_nc_hash + param_4 * 8)) break;
      iVar1 = puVar4[5];
    }
    puVar4 = (undefined4 *)0x0;
  }
locret_F0025FAC:
  return CONCAT44(param_2,puVar4);
}

