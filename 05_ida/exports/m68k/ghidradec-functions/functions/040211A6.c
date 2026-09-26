
void _ip_drain(void)

{
  if ((undefined4 **)_ipq != &_ipq) {
    do {
      dword_40B68BC = dword_40B68BC + 1;
      _ip_freef(_ipq);
    } while ((undefined4 **)_ipq != &_ipq);
  }
  return;
}
