
void _ttyoutstr(char *param_1,undefined4 param_2)

{
  while( true ) {
    if (*param_1 == '\0') break;
    _ttyoutput((int)*param_1,param_2);
    param_1 = param_1 + 1;
  }
  return;
}
