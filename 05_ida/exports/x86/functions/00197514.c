/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197514. */
int kminit()
{
  dword_1E777C = 1; /*0x197517*/
  basicConsole = FBAllocateVBEConsole(); /*0x197526*/
  if ( !basicConsole ) /*0x19752d*/
    basicConsole = BasicAllocateConsole(); /*0x197534*/
  if ( MEMORY[0x1114C] ) /*0x197540*/
  {
    basicConsoleMode = 2; /*0x197542*/
    return (*(int (__stdcall **)(int, int, _DWORD, _DWORD, char *))(basicConsole + 4))( /*0x197562*/
             basicConsole,
             2,
             0,
             0,
             mach_title);
  }
  else
  {
    basicConsoleMode = 1; /*0x197568*/
    return (*(int (__stdcall **)(int, int, int, int, char *))(basicConsole + 4))(basicConsole, 1, 1, 1, mach_title); /*0x197584*/
  }
}
