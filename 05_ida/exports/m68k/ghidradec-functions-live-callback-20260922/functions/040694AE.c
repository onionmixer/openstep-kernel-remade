
word sub_40694AE(uint *param_1)

{
  word *pwVar1;
  word wVar2;
  
  pwVar1 = (word *)*param_1;
  if (pwVar1 < (word *)param_1[1]) {
    if (param_1[2] == 0) {
      wVar2 = (word)*(byte *)pwVar1;
      *param_1 = *param_1 + 1;
    }
    else {
      wVar2 = *pwVar1;
      *param_1 = *param_1 + 2;
    }
  }
  else {
    wVar2 = 0;
  }
  return wVar2;
}

