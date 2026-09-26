
void operr(void)

{
  if (_cpu_type == '\0') {
    func_0x040a0a38();
    return;
  }
  fpsp_operr();
  return;
}
