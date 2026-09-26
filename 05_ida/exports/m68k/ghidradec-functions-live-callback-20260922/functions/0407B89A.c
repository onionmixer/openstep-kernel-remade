
void sub_407B89A(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
  iVar3 = *(int *)((int)param_1 + 0x226);
  if (((*(byte *)((int)param_1 + 0x223) & 7) != 6) && (*(char *)((int)param_1 + 0x21f) == '\x02')) {
    *(undefined *)((int)param_1 + 0x21f) = 0;
  }
  *(undefined *)(iVar2 + 3) = 1;
  bVar4 = *(byte *)((int)param_1 + 0x223) & 7;
  if (iVar3 != 0) {
    if (bVar4 < 8) goto loc_407B8FA;
loc_407B926:
    iVar5 = *(int *)((int)param_1 + 0x21a);
    puVar6 = (undefined *)(iVar3 + 0x26);
    while (0 < iVar5) {
      *(undefined *)(iVar2 + 2) = *puVar6;
      iVar5 = iVar5 + -1;
      puVar6 = puVar6 + 1;
    }
    for (iVar5 = 0xe - *(int *)((int)param_1 + 0x21a); 0 < iVar5; iVar5 = iVar5 + -1) {
      *(undefined *)(iVar2 + 2) = 0;
    }
    *(undefined *)(iVar2 + 3) = 0;
    *(undefined *)(iVar2 + 3) = 0x10;
    *(undefined *)((int)param_1 + 0x21e) = 3;
    goto loc_407B9EA;
  }
  if (bVar4 != 7) {
    puVar6 = aNoConnection;
    goto loc_407B97C;
  }
loc_407B8FA:
  switch(bVar4) {
  case :
    if ((*(byte *)(iVar3 + 0x24) & 8) == 0) {
      uVar7 = 0;
loc_407B98E:
      sub_407BA0A(param_1,uVar7);
      return;
    }
    break;
  case :
    if ((*(byte *)(iVar3 + 0x24) & 8) != 0) {
      uVar7 = 0x40000;
      goto loc_407B98E;
    }
    break;
  :
    goto loc_407B926;
  case :
    *(undefined *)((int)param_1 + 0x21e) = 5;
    *(undefined *)(iVar2 + 3) = 0x11;
    goto loc_407B9EA;
  case :
    if (*(char *)((int)param_1 + 0x21f) == '\0') {
      *(undefined *)(iVar2 + 2) = 8;
      *(undefined *)(param_1 + 0x88) = 3;
    }
    else {
      *(undefined *)(iVar2 + 2) = *(undefined *)((int)param_1 + 0x221);
      *(undefined *)((int)param_1 + 0x21f) = 2;
    }
    *(undefined *)((int)param_1 + 0x21e) = 8;
    goto loc_407B9E0;
  case :
    if (iVar3 == 0) {
      *(undefined *)((int)param_1 + 0x21e) = 0xb;
    }
    else {
      *(undefined *)((int)param_1 + 0x21e) = 10;
    }
loc_407B9E0:
    *(undefined *)(iVar2 + 3) = 0;
    *(undefined *)(iVar2 + 3) = 0x10;
loc_407B9EA:
    *(int *)(iVar1 + 0x5c) = _hz * *(int *)(iVar3 + 0x42);
    *(undefined *)(iVar1 + 0x5b) = 1;
    return;
  }
  puVar6 = aBadIODirection;
loc_407B97C:
  sub_407BCB6(iVar1,0,puVar6);
  return;
}

