
void unsupp(void)

{
  if (_cpu_type == '\0') {
    std_trap();
    return;
  }
  fpsp_unsupp();
  return;
}
