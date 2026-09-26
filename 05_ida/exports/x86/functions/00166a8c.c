/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x166a8c. */
int thread_init()
{
  thread_zone = zinit(396, 202752, 25344, 0, aThreads); /*0x166aaa*/
  dword_1F6C08 = 0; /*0x166aaf*/
  dword_1F6C24 = 2; /*0x166ab9*/
  dword_1F6C28 = 0; /*0x166ac3*/
  dword_1F6C2C = 0; /*0x166acd*/
  dword_1F6C30 = 0; /*0x166ad7*/
  dword_1F6C3C = 0; /*0x166ae1*/
  dword_1F6C44 = 0; /*0x166aeb*/
  dword_1F6C48 = 0; /*0x166af5*/
  dword_1F6C4C = 258; /*0x166aff*/
  dword_1F6C34 = (int)thread_bootstrap_return; /*0x166b09*/
  dword_1F6C38 = 0; /*0x166b13*/
  dword_1F6C54 = 18; /*0x166b1d*/
  dword_1F6C5C = 0; /*0x166b27*/
  dword_1F6C60 = 1; /*0x166b31*/
  dword_1F6C64 = -1; /*0x166b3b*/
  dword_1F6C68 = 0; /*0x166b45*/
  dword_1F6C6C = 0; /*0x166b4f*/
  dword_1F6C74 = 0; /*0x166b59*/
  dword_1F6C78 = 0; /*0x166b63*/
  dword_1F6C7C = 0; /*0x166b6d*/
  dword_1F6C80 = 0; /*0x166b77*/
  dword_1F6C88 = -1; /*0x166b81*/
  dword_1F6C8C = 1; /*0x166b8b*/
  timer_init(&unk_1F6CE0); /*0x166b9a*/
  timer_init(&unk_1F6CF0); /*0x166ba4*/
  dword_1F6D00 = 0; /*0x166ba9*/
  dword_1F6D04 = 0; /*0x166bb3*/
  dword_1F6D08 = 0; /*0x166bbd*/
  dword_1F6D0C = 0; /*0x166bc7*/
  dword_1F6D10 = 0; /*0x166bd1*/
  dword_1F6D14 = 0; /*0x166bdb*/
  dword_1F6D78 = 0; /*0x166be5*/
  dword_1F6D7C = 0; /*0x166bef*/
  dword_1F6D84 = 0; /*0x166bf9*/
  dword_1F6D88 = 0; /*0x166c03*/
  initKernelStacks(); /*0x166c0d*/
  dword_1E979C = (int)&reaper_queue; /*0x166c12*/
  reaper_queue = (int)&reaper_queue; /*0x166c1c*/
  reaper_lock = 0; /*0x166c29*/
  stack_usage_lock = 0; /*0x166c33*/
  return pcb_module_init(); /*0x166c44*/
}
