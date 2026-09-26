
void sub_400BB74(char *param_1,undefined4 param_2,undefined4 param_3)

{
  while( true ) {
    if (*param_1 == '\0') break;
    sub_400BDAC((int)*param_1,param_2,param_3);
    param_1 = param_1 + 1;
  }
  return;
}

