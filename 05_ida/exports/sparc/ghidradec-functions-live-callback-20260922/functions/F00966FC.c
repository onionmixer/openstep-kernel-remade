
int _ocsum(word *param_1,int param_2)

{
  word wVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  
  uVar5 = 0;
  if (param_2 < 0x1f) {
    bVar8 = false;
    bVar7 = param_2 == 0;
    bVar6 = param_2 < 0;
  }
  else {
    for (; ((uint)param_1 & 0x1f) != 0; param_1 = param_1 + 1) {
      uVar5 = uVar5 + *param_1;
      param_2 = param_2 + -1;
    }
    do {
      param_2 = param_2 + -0x10;
      uVar2 = (uint)((qword)*(undefined8 *)param_1 >> 0x20);
      uVar3 = uVar5 + uVar2;
      uVar4 = (uint)*(undefined8 *)param_1;
      bVar6 = CARRY4(uVar3,uVar4) || CARRY4(uVar3 + uVar4,(uint)CARRY4(uVar5,uVar2));
      uVar5 = uVar3 + uVar4 + (uint)CARRY4(uVar5,uVar2);
      uVar3 = (uint)((qword)*(undefined8 *)(param_1 + 4) >> 0x20);
      bVar7 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar6);
      uVar5 = uVar5 + uVar3 + (uint)bVar6;
      uVar3 = (uint)*(undefined8 *)(param_1 + 4);
      bVar6 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar7);
      uVar5 = uVar5 + uVar3 + (uint)bVar7;
      uVar3 = (uint)((qword)*(undefined8 *)(param_1 + 8) >> 0x20);
      bVar7 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar6);
      uVar5 = uVar5 + uVar3 + (uint)bVar6;
      uVar3 = (uint)*(undefined8 *)(param_1 + 8);
      bVar6 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar7);
      uVar5 = uVar5 + uVar3 + (uint)bVar7;
      uVar3 = (uint)((qword)*(undefined8 *)(param_1 + 0xc) >> 0x20);
      bVar7 = CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar6);
      uVar5 = uVar5 + uVar3 + (uint)bVar6;
      uVar3 = (uint)*(undefined8 *)(param_1 + 0xc);
      uVar5 = uVar5 + uVar3 + (uint)bVar7 +
              (uint)(CARRY4(uVar5,uVar3) || CARRY4(uVar5 + uVar3,(uint)bVar7));
      param_1 = param_1 + 0x10;
    } while (0xf < param_2);
    bVar8 = false;
    bVar7 = param_2 == 0;
    bVar6 = param_2 < 0;
  }
  while (!bVar7 && bVar6 == bVar8) {
    wVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar5 = uVar5 + wVar1 + (uint)CARRY4(uVar5,(uint)wVar1);
    bVar8 = SBORROW4(param_2,1);
    param_2 = param_2 + -1;
    bVar6 = param_2 < 0;
    bVar7 = param_2 == 0;
  }
  return (uVar5 * 0x10001 >> 0x10) + (uint)CARRY4(uVar5 * 0x10000,uVar5);
}

