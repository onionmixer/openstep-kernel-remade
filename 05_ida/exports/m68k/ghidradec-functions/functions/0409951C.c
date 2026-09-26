
void _getfsname(undefined4 param_1,undefined4 param_2)

{
  if ((byte_40B606F & 1) != 0) {
    _printf(aSKeyS,param_1,param_1);
    _gets(param_2,param_2);
  }
  return;
}
