
void sub_407F042(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  _bcopy(*(undefined4 *)(param_1 + 0xd2),*(undefined4 *)(param_2 + 0xd2),0x1c48);
  puVar1 = *(undefined4 **)(param_2 + 0xca);
  uVar2 = (*(undefined4 **)(param_1 + 0xca))[1];
  *puVar1 = **(undefined4 **)(param_1 + 0xca);
  puVar1[1] = uVar2;
  uVar3 = *(uint *)(param_2 + 8) & 0xfffff3fb;
  *(uint *)(param_2 + 8) = uVar3;
  *(uint *)(param_2 + 8) =
       CONCAT22((sword)(uVar3 >> 0x10),(word)*(undefined4 *)(param_1 + 8) & 0xc04 | (word)uVar3) |
       0x80;
  *(undefined4 *)(param_2 + 0xe) = *(undefined4 *)(param_1 + 0xe);
  return;
}

