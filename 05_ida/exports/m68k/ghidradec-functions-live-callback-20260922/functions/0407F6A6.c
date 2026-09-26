
void sub_407F6A6(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x42;
  piVar3 = (int *)(_sg_sgd + iVar2);
  _bzero(piVar3,0x42);
  *piVar3 = param_1;
  *(uint *)(_sg_sgd + iVar2 + 4) = iVar2 + 0x40c65efU & 0xfffffff0;
  iVar1 = iVar2 + 0x40c65d0;
  *(int *)(_sg_sgd + iVar2 + 0xc) = iVar1;
  *(int *)iVar1 = iVar1;
  _sg_sgd[iVar2 + 0x15] = 0;
  _sg_sgd[iVar2 + 0x17] = 0;
  *(undefined *)(*piVar3 + 0x1c) = 0xff;
  *(undefined *)(*piVar3 + 0x1d) = 0xff;
  return;
}

